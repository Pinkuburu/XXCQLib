// Room: /welcome/bingqiku.c
//By adx @ CuteRabbit 15:57 99-5-18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",WHT"兵器库"NOR );
    set("long", @LONG
这里是武馆的兵器库，存放着许多的武器供武馆弟子练习使用。
看来这里经常有人打扫，显得非常的干净，每件武器都闪闪发光。
LONG
    );
        set("exits", ([
                "east":__DIR__"houyuan",
        ]));
        set("no_fight", 1);
        set("valid_startroom", 1);
      setup();
}

void init()
{
           add_action("do_job","ca");
}
int do_job(string arg)
{
        object *inv;
        object me;
         int i, jingli;

	me = this_player();
	jingli = ( random(me->query("str"))/3 );
	inv = all_inventory(me);
	if (jingli <= 0)
		jingli = 5;

	if (me->query("jingli")<=10) {
	message_vision ("你没有气力了，先去休息室睡一下吧！"+HIC"(sleep)\n"NOR, me );
        return 1;
	}
	   //判断是否wield了工具
	if( (string)(inv[i]->query("id"))=="mabu" && 
		(int) inv[i]->query("equipped") ) 
	{
		if( !arg || arg!="兵器" )
			{return notify_fail ("你要擦什么？\n");
		}
		else {
			me->add_temp("wancheng", jingli);
			me->add("jingli", -jingli);
			me->add("combat_exp", jingli);
			me->add("potential", (jingli/2));
			message_vision ("$N拿起抹布，擦着刀、剑！\n", me );
			if (me->query_temp("wancheng") >= 100)
			{
				me->set_temp("renwu",100);   //设100表示完成任务
				return notify_fail (WHT"你可以回去复命了！(ask moto about ok)\n"NOR);
				}
			}
	}
	else {
		return notify_fail ("你空手怎么擦？\n");
		}
        return 1;
}

int valid_leave(object me, string dir)
{
         if ( (dir == "east") &&
		(me->query("wancheng") >= 100) )
	{
		if ( !present("mabu", me) ) {return 1;}
			message_vision ("$N放下手中的抹布。\n", me);
			destruct(present("mabu", me));
	}
	return ::valid_leave(me, dir);
}
