// xingbu.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "��ү��");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"xb_datang",
		"south" : __DIR__"xb_lukou",
		"east" : __DIR__"xb_tianlao",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}