//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "金银街");
        set ("long", @LONG
这里是金银街的东端，向东就要出了秭归镇了，路南有一家小茶馆，
飘舞着的幌子写着闲来茶馆，里面人声鼎沸，看来很是热闹。路北是一户
民居。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"east" : __DIR__"zgeast",
		"west" : __DIR__"jinyin2",
	]));

        set("outdoors", "zigui");
        setup();
}