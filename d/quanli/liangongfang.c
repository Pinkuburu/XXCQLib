//liangongfang。c          

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "练功房");
	set("long", @LONG
这里是权力帮东侧的练功房。这里较别的地方又安静了许多，原来是
因为两边乃派内弟子修炼内功，心法的静室。
LONG);
        set("valid_startroom",1);
	set("exits", ([
                        "east" : __DIR__"dati",
	]));
        set("area", "权力帮");
	setup();
	replace_program(ROOM);
}
