//qilingbang。c            

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "权力帮总坛");
	set("long", @LONG
这里是权力帮的总坛,属于权力帮重地。为防止外敌来袭，要来此地
关卡重重。这里是一个庄重，又很典雅的建筑，四周用红幔包裹，显得极
为森严，顶梁上雕了意气风发的“君临天下”四个大字.
LONG);
	set("exits", ([	
        	"north" : __DIR__"zhuang",
        	"south" : __DIR__"damen",
	]));
        set("objects",([
          __DIR__"npc/yan" : 1,
          __DIR__"npc/yu" : 1,
          __DIR__"npc/zuo" : 1,
       ]));
	setup();
	replace_program(ROOM);
}
