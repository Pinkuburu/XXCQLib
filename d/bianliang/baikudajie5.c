// baikudajie5.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�׿���");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"west" : __DIR__"xd_lukou",
		"east" : __DIR__"baikudajie6",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}