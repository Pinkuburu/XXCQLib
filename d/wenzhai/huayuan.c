// huayuan.c 花园
// mlf设计,lks 编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","花园");
	set("long",
	"花园里相当开阔，假山花木，池沼小河，九曲长桥。。。。花园中心
有一坐三角小亭，以汉白玉为栏，飞檐翘角，非常精致。亭中还有石桌和
石凳，桌上刻着一张棋盘，供人小坐下棋。\n"NOR
     	);
     	set("outdoors","wenzhai");
	set("valid_startroom",1);
	set("exits",([
     		"north" : __DIR__"dating",
     		"west"  : __DIR__"sxge",
     		"east"  : __DIR__"fotang",
     		"south" : __DIR__"jiashan",
     	]));
     	setup();
     	replace_program(ROOM);
}

