// yanziwu.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",WHT"燕子坞"NOR);
         set ("long",@long
燕子坞是幕容氏世居之地, 幕容氏乃夕日大燕国的后裔, 后来日见式微, 
但其弟子却一心一意想光复大燕。其武功见长于以彼之道, 还施彼身, 端的
十分厉害。
long);
         set("exits",([
        "north" : __DIR__"houyuan1",
        "south" : __DIR__"houting",
]));
        set("dest_room", "/u/beyond/workroom");
	set("objects",([
	__DIR__"npc/murong-fu" :1,
]));
        setup();
        replace_program(ROOM);
}
