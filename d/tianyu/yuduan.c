// Room: 云端
// Date: by godzilla 1999.11.18

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"云端"NOR);
	set("long",
HIW"只见四周的云飞快的向着身后移动......\n"NOR
 );

	setup();
	replace_program(ROOM);
}
