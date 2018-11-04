
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","血河密室");
        set("long",@LONG
从洞府里踏进这里，眼前一亮:室内岩壁上写着几行小字(zi)，写
得逸意神妙，娟秀无比。字画下有一架朱红古筝。左方岩壁处有几个
字，过时已久，模糊不清了。洞内有一石床，床上盘膝坐着一个人。这
洞凹之处，显然是水底，上有急流，旁有旋涡。根本不可能出去。
LONG );
        set("class","血河派");
        set("exits",([
                  "out" : __DIR__"jiliu",
                  "west" : __DIR__"chucangshi",
        ]));
/*
       set("item_desc"，([
                "zi"         : @LONG
欲得血河派绝招，先安葬余，后掘此处。
即为我派第十三代掌门。龙门卫悲同字。
LONG
，
        ]));
*/
        setup();
}

void init()
{
/*
	string temp;
	temp=read_file("/log/MISHI",1,1);
	if ( temp )  return;
*/
	add_action("do_kan","qiao");
	add_action("do_wa","wa");
	add_action("do_ketou","kneel");
	add_action("do_mai","mai");
}

int do_kan(string arg)
{
           object me;
           
           me=this_player();
           if ((!arg) && (arg!="chuang") && (arg!="石床") && (arg!="zi"))
           return notify_fail("你要看什么？\n");

           if ((arg=="chuang") || (arg=="石床") )
           {
               if (query("find"))   return notify_fail("床上已经没有人了。\n");
                tell_object(me,"只见石床上坐着一个中年模样的男子。盘\n");
                tell_object(me,"膝打坐，手指好象指向岩壁上的小字。\n");
                me->set_temp("look-chuang",1);
                return 1;
           }

           if (arg=="zi")
           {
               if (!(me->query_temp("look-chuang")))
                      return notify_fail("没事不要偷看别人的东西。\n");
               tell_object(me,"欲得血河派绝招，先安葬余，后掘此处。\n");
                tell_object(me,"即为我派第十三代掌门。龙门卫悲同字。\n");
                me->set_temp("look-zi",1);
                return 1;
           }
           return 0;
}

int do_wa(string arg)
{
            object me;

            me=this_player();

                 if (me->query_temp("digg"))
                       return notify_fail("你已经挖了一个坑了。\n");
              if(!(me->query_temp("look-zi")))
            return notify_fail("这是人家的地方，你想干嘛？\n");
            if (!arg && arg!="west" && arg!="east")
                   return notify_fail("东边和西边都有一块空地，西边的稍微大一点。你要挖哪边？\n");

            if (arg=="west")
            {
                  message_vision("$N拣起一块锋利的石头，在西边的空地上挖了起来。\n",me);
                  message_vision("不一会儿，$N就挖了一个洞。\n",me);

                  me->set_temp("digg",1);
                  return 1;
            }
            if (arg=="east")
            {
                 message_vision("$N拣起一块锋利的石头，在东边的空地上挖了起来。\n",me);
                 message_vision("突然，地下射出一枚暗器，正中你的咽喉。\n",me);
                  me->delete_temp("look-chuang");
                  me->delete_temp("zi");
                  me->die();
            }
            return 0;
}

int do_mai(string arg)
{
           object me;
           object ob;
         mapping fam;
          string temp;

           me=this_player();
          fam=me->query("family");

           if (!arg && arg!="yiti" && arg!="遗体")
                 return notify_fail("你要埋什么东西？\n");
           if (this_player()->query("zhangmen"))
                 return notify_fail("你已经来过一次了。\n")
;
           if (arg=="yiti" || arg=="遗体")
           {
               if(!(me->query_temp("ketou")))
                     return notify_fail("还没磕头就搬动遗体，好象不太好吧 ?\n");
               message_vision("$N上前恭恭敬敬的清清的移动遗体。\n",me);
               message_vision("突然，$N发现自己的手被粘在遗体上了，一股力量从遗体中冲了过来。\n",me);
	message("channel:chat",			HIM"【奇遇】"HIC"据说"+me->query("name")+"找到了卫悲回的遗体。得到了血河三宝和不少好处。\n"NOR,users());
          temp=read_file("/log/MISHI",1,1);
          if (!(temp)) {
//             me->add("max_neili",2);
              me->set("zhangmen",1);
              if (me->query("max_neili")>(me->query("con")*me->query_skill("force",1)+1) )
               me->set("max_neili",(me->query("con")*me->query_skill("force",1)+1));
                 me->set("title","血河派第十三代"HIR"掌门"NOR);
           message_vision("突然任狂不知从哪冒了出来，对你笑道：掌门师侄，这血河三宝我还是帮你保管吧。\n",me);
            if (!fam || fam["family_name"]!="血河派")  {
                   fam["family_name"]="血河派";
                   me->set("family",fam);
             }
              }
             else   {
           message_vision("突然任狂不知从哪冒了出来，对你笑道：这血河三宝我还是帮你保管吧。\n",me);
//            me->add("max_neili",1);
            }

            me->delete_temp("look_chuang");
            me->delete_temp("look_zi");
            me->delete_temp("ketou");
            me->delete_temp("digg");
               me->unconcious();
/*
               ob=new("/wiz/baby/obj/huangling");
               ob->move(environment(me));
               ob=new("/d/longmen/xuehepai/obj/jieniu-dao");
               ob->move(environment(me));
               ob=new("/d/longmen/xuehepai/obj/yudi-whip");
               ob->move(environment(me));
               ob=new("/wiz/lks/xuehepai/arrow");
               ob->move(environment(me));
*/
                ob=new("/d/longmen/xuehepai/obj/miji1");
                ob->move(environment(me));
              log_file("MISHI",sprintf("opened.\n"));
               set("find",1);
                  me->set("findyiti",1);
                  me->save();
               return 1;
           }
           return 0;
}

int do_ketou()
{
           object me;

           me=this_player();

           if (!(me->query_temp("digg")))
                 return notify_fail("把坑挖好了再来磕头吧。\n");

               message_vision("$N神色严肃，对着卫悲回的遗体咚咚地磕了九个响头。\n",me);
           me->set_temp("ketou",1);
           return 1;
}

