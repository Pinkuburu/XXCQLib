//zoulang1。c              

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是权力帮南侧的走廊。两边栽种着大片的竹林，清风徐徐，竹影
婆娑，着实令人惬意，还有不少边陲稀有的名花夹间其中，花香竹韵，让
人留恋忘返。 
LONG);
	set("valid_startroom",1);
	set("outdoors","归昧");
	set("exits", ([
                        "west" : __DIR__"enter",
                        "east" : __DIR__"zhuang",
	]));
        set("objects",([
          __DIR__"npc/liuqianbian" : 1,
      ]));
        replace_program(ROOM);
	setup();
}
