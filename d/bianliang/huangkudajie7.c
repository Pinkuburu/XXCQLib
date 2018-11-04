// huangkudajie7.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "黄裤大街");
      set("long",@LONG
大街从这里往东突然开阔起来，路边开始出现一些店铺之类的房屋，
由于车辆，行人繁多，这里的店铺生意也比别处红火，南面就是一家专
为武林人士提供兵器的店铺，往东则是著名的菜市口了。
LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"south" : __DIR__"tieqipu",
		"west" : __DIR__"huangkudajie6",
		"east" : __DIR__"caishikou",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
