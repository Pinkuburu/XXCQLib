//zhuang。c  by god

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "大厅");
	set("long", @LONG
此处为权力帮的大厅。其结构别具一格,四通八达。 
两边通向走廊，里面就是天下第一大堂。
LONG);	
	set("valid_startroom",1);
	set("objects",([
	]));
	set("exits", ([
		"north" : __DIR__"dati",
		"west" :  __DIR__"zoulang1",
		"south" :  __DIR__"qilingtang",
		"east" :  __DIR__"zoulang2",
	]));
        set("objects",([
          __DIR__"npc/tu" : 1,
          __DIR__"npc/xing" : 1,
          __DIR__"npc/xue" : 1,
      ]));
        set("area", "归昧");
        setup();
            replace_program(ROOM);
}
