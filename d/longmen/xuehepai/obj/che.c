
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIR"血河车"NOR, ({ "xuehe che","che" }));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "辆");
                set("long","这是血河派的镇派至宝--血河车。\n");
                set("value",100000);
                set("no_sell",1);
                set("material", "steel");
                set("no_get","你搬得起它吗？\n");
              }
}

void init()
{
        add_action("do_ride","ride");
        add_action("do_enter","enter");
        add_action("do_xiache","xiache");
}

int do_ride(string arg)
{
        object me;
             mapping fam,famm;
           object *obb;
           int i;
        
           me=this_player();
        fam=(mapping)me->query("family");

          if( !arg || (arg!="che" && arg!="血河车") ) return notify_fail("你要干嘛？\n"); 

           if (!me->query_temp("ask1") ) {
                  if (fam && fam["family_name"]=="血河派" && present("ren kuang",environment(me)))
                         return notify_fail("任狂还没答应让你开呢。\n");
                if(!fam || fam["family_name"]!="血河派") {
                message_vision("$N蹑手蹑脚的想把血河车开走！\n",me);
                obb=all_inventory(environment(me));
                for(i=0; i<sizeof(obb); i++) {
                        if (obb[i]->is_character() )
                        {
                                famm=(mapping)obb[i]->query("family");

                                if (famm && famm["family_name"]=="血河派") 
                                {
                                        message_vision("$N对着$n大喝一声：竟敢偷觑本派宝物！\n",obb[i],me);
                                        obb[i]->kill_ob(me);
                                        me->kill_ob(obb[i]);
                                }
                        }                               
                }
                if (!(me->is_fighting()))
                {
                message_vision("$N见周围没有了血河派弟子，放心大胆的跃上血河车的车厢！\n",me);
                me->set_temp("xueheche",1);
                return 1;
            }
                return notify_fail("你先把血河派弟子解决了去驾车也不迟。\n");
        }
              }
 
            if (me->query_temp("xueheche"))
                 return notify_fail("你已经在车上了。\n");
            if (query("ride"))
                 return notify_fail("这车子已经有人上去了。\n");
        message_vision("$N一个跃步,跨上了血河车车厢前的座椅。\n",me);
                set("ride",1);
        me->set_temp("xueheche",1);
           return 1;
}

int do_enter(string arg)
{
        object *obb;
        object me;
        mapping fam,famm;
        int i;

        me=this_player();
        fam=(mapping)me->query("family");
        
          if( !arg || (arg!="che" && arg!="血河车") ) return notify_fail("你要干嘛？\n"); 

            if (me->query_temp("xueheche"))
                     return notify_fail("你正在驾车，不能进车厢。\n");
        if(!fam || fam["family_name"]!="血河派")
        {
                message_vision("$N蹑手蹑脚的想钻进血河车！\n",me);
                obb=all_inventory(environment(me));
                for(i=0; i<sizeof(obb); i++) {
                        if (obb[i]->is_character() )
                        {
                                famm=(mapping)obb[i]->query("family");

                                if (famm && famm["family_name"]=="血河派") 
                                {
                                        message_vision("$N对着$n大喝一声：竟敢偷觑本派宝物！\n",obb[i],me);
                                        obb[i]->kill_ob(me);
                                        me->kill_ob(obb[i]);
                                }
                        }                               
                }
                if (!(me->is_fighting()))
                {
                message_vision("$N见周围没有了血河派弟子，放心大胆的进入血河车！\n",me);
me->move("/d/longmen/xuehepai/chenei");
            }
                return notify_fail("你先把血河派弟子解决了再进去也不迟。\n");
        }
        message_vision("$N大摇大摆的钻进了血河车！\n",me);
                me->move("/d/longmen/xuehepai/chenei");
}
int do_xiache()
{
        object ob;
        mapping fam;
        
        ob=this_player();
        fam=(mapping)ob->query("family");

        if (!(ob->query_temp("xueheche")))
                return notify_fail("什么？\n"); 

          if (environment(this_object())!=environment(ob))
                return notify_fail("什么？\n"); 

        message_vision("$N一个跃步,从血河车车厢前的座椅上跳了下来。\n",ob);
        message_vision(HIG"然后$N向空中发出一道响箭，通知弟子取回血河车。\n"NOR,ob);
        message_vision(HIY"突然几个弟子对$N点点头，把血河车带回去了。\n"NOR,ob);

        this_object()->move("/d/longmen/xuehepai/xueheting");

                  set("ride",0);
          ob->delete_temp("xueheche");
            ob->delete_temp("ask1");
             return 1;
}

