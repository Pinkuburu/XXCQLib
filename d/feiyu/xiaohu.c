// ROOM xiaohu.c

inherit ROOM;

void create()
{
        set("short","小湖");
        set("long",@LONG
这是竟是一个碧绿的小湖，下雨时雨水落入湖中，清脆的水珠声有如
玉珠落盘般悦耳。水气朦胧中抬头西望，只见远处苍山如黛，若隐若现，
雨景妙趣无穷。月下似乎站着一位书生。
LONG);
		set("valid_startroom", 1);

		set("exits",([
                "southeast" : __DIR__"houshan",
        ]));
        set("outdoors", "huashan");

        set("objects", ([
              __DIR__"npc/baiqingyi" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
 
