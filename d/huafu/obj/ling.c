
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name( "令牌", ({ "ling" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
               seteuid(geteuid());
                set("long","这是一把拥有无上权力的令牌。\n");
                set("value", 0);
                set("fam","发梦二党");
                set("par",HIG"发梦二党"NOR);
                set("material", "iron");
              }
}

void init()
{
        add_action("do_buzhi","buzhi");
        add_action("do_cancel","cancel");
        add_action("do_zhiyuan","zhiyuan");
        add_action("do_zhanling","zhanling");
}

int do_buzhi(string arg)
{
        object ob,me;
        string dest,place;
        mapping fam,party;
        me=this_player();
        
        if (!arg || arg=="") return notify_fail("指令格式：buzhi 玩家或npc to 位置\n");
       if( sscanf(arg, "%s to %s", dest, place)==2 || sscanf(arg, "%s %s", dest,place)==2 );
         else return notify_fail("指令格式：buzhi 玩家或npc to 位置\n"); 
                ob=find_living(dest);
                if(!objectp(ob))
                {
                        tell_object(me,"找不到这个人。\n");
                        return 0;
                }
                fam=(mapping)ob->query("family");
                party=(mapping)ob->query("party");
                if (( !fam || fam["family_name"]!="发梦二党") && (!party || party["party_name"]!=HIG"发梦二党"NOR) )
                return notify_fail("你不能指挥这个人。\n");
//              arg=resolve_path("/d/huafu",arg);
//              if ( file_size(arg+".c")==-1)
//              return notify_fail("没有这个地方。\n");

//              if (!(ob->query_temp("compaign_start")))
//              {
                tell_object(ob,HIC"发梦二党正遭受袭击，请速到"+place+"阻击敌人。\n");
                ob->set_temp("buzhile",1);
//              }
                return 1;
}

int do_zhiyuan(string arg)
{
        object ob,me;
        string dest;
        mapping fam,party;
        me=this_player();
        
        if( !arg ) return notify_fail("指令格式：zhiyuan 玩家或npc 位置\n");    
        if(sscanf(arg,"%s %s",dest,arg)==2)
        {
                ob=find_living(dest);
                if(!objectp(ob))
                {
                        tell_object(me,"找不到这个人。\n");
                        return 0;
                }
                fam=(mapping)ob->query("family");
                party=(mapping)ob->query("party");
                if (( !fam || fam["family_name"]!="发梦二党") && (!party || party["party_name"]!=HIG"发梦二党"NOR) )
                return notify_fail("你不能指挥这个人。\n");
//              arg=resolve_path("/d/huafu",arg);
//              if ( file_size(arg+".c")==-1)
//              return notify_fail("没有这个地方。\n");

//              if (!(ob->query_temp("compaign_start")))
//              {
                tell_object(ob,HIC"发梦二党正遭受袭击，请速到"+arg+"支援。\n");
//              if (file_name(environment(me))=="/d/huafu/dating")
//              {
                ob->set_temp("buzhile",1);
//              }
//              }
                return 1;
        }
        return notify_fail("指令格式：zhiyuan 玩家或npc 位置\n");       
}

int do_zhanling(object me)
{
         int i;
         mapping fam,party;
         object *obb;
        object where;
        me=this_player();
        where=environment(me);
        
                        obb=all_inventory(where);
                        for(i=0; i<sizeof(obb); i++) {
                                if (obb[i]->is_character() )
                                {
                                  if (obb[i]==me) continue;
                                fam=(mapping)obb[i]->query("family");
                                party=(mapping)obb[i]->query("party");
                                if ((fam && fam["family_name"]=="发梦二党") || (party && party["party_name"]==HIG"发梦二党"NOR ))
				return notify_fail("这地方还有"+fam["family_name"]+"的人守着，先把他解决再说。\n");
                                }
                        }

        if (where->query("class")==this_object()->query("fam"))
        return notify_fail("这地方已经是你的地盘了。\n");
        
        where->set("class",query("fam"));
        where->set("long","这里已经被"+query("fam")+"占领。\n");
	message("channel:chat",			HIY"【旁白】"HIC+query("fam")+"已经占领了"+where->query("short")+"。\n"NOR,users());
        return 1;
}


int do_cancel(object me)
{
           object *obb;

           int i;
           me=this_player();

       obb=users();
        for(i=0; i<sizeof(obb); i++) {
          obb[i]->delete_temp("killwei");
          obb[i]->delete_temp("compaign_start");
        }
     return 1;
}
