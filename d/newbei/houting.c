// Room: /welcome/houting.c
//By adx @ CuteRabbit 15:57 99-5-18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",WHT"神雪后厅"NOR);
    set("long",
"这里是武馆的后厅，你可以在这里学习怎么解一个简单的迷题，解迷重要的\n"
"是多看可以看的东西"+HIC"（l xxxx）"NOR+"比如：下面这个"
"简单的迷题，你来试试。\n"
"房间中央摆着一张檀木桌子"+HIM"（table）。\n"NOR
    );
        set("exits", ([
                "west":__DIR__"houyuan",
                "east":__DIR__"dating",
                "north":__DIR__"beilang1",
                "south":__DIR__"nanlang1",
        ]));
	set("item_desc",([
	"table" : "桌上好象放着一本书"+HIM"（book）"NOR+"你可以拿"+
		HIW"（pick）"NOR+"起来看看。\n",
	"book" : "书的封面好象写着"+WHT"《三字经》\n"NOR,
	]));
        set("no_fight", 1);
        set("valid_startroom", 1);
      setup();
}

void init()
{
            add_action("do_pick","pick");
}
void reset()
{
        ::reset();
        set("get_available" , 1);
}

int do_pick(string arg)
{
       object me,obj;

       me = this_player();
       if( !arg || arg!="book" )
              return notify_fail("你要拿什么?\n");
       if ( query("get_available") )  {
       obj = new (__DIR__"npc/obj/szjing");
       obj->move(me);
       add("get_available", -1);
       message_vision(YEL"$N从桌上拿起一本"+WHT"《三字经》。\n"NOR,me );
       }
       else
       return notify_fail("桌上什么也没有，不知道被谁拿走了。\n");
       return 1;
}