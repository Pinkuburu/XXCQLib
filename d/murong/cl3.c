// cl3.c
#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIW"长廊"NOR);
         set("long", @long
这是一条长廊，上面画着江南秀美的工笔画。绿色的柱子朱红色的琉璃
瓦，使得你不由得对江南艺术工匠的创造惊叹不已。在长廊里面，丫鬟、家
丁们走来走去，都忙着自己的事情，不敢有一点怠慢。
long);
         set("exits", ([
             "north" : __DIR__"cl2",
             "east" : __DIR__"fenmu",
]));
         setup();
         replace_program(ROOM);
}
