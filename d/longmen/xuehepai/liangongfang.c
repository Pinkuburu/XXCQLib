//liangongfang。c         龙门血河派--练功房

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "练功房");
	set("long", @LONG
这里是血河派东侧的练功房。这里较别的地方又安静了许多，原来是
因为两边乃派内弟子修炼内功，心法的静室，血河内功强调“静以养气”
、“气运全身”，所以没人敢在此处喧哗。
LONG);
        set("valid_startroom",1);
	set("exits", ([
                        "east" : __DIR__"zoulang3",
	]));
        set("area", "龙门");
	setup();
	replace_program(ROOM);
}
