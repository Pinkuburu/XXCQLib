//zoulang1。c             血河派--走廊

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是血河派南侧的走廊。两边栽种着大片的竹林，清风徐徐，竹影
婆娑，着实令人惬意，还有不少边陲稀有的名花夹间其中，花香竹韵，让
人留恋忘返。这里通向西厢房。
LONG);
        set("valid_startroom",1);
        set("outdoors","龙门");
	set("exits", ([
                        "east" : __DIR__"dongxiangfang",
                        "west" : __DIR__"xuehuatang",
	]));
        replace_program(ROOM);
	setup();
}
