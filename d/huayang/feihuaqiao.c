//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "飞花桥");
        set ("long", @LONG
飞花桥是一座约四人宽、七步长的石拱桥，因其是方圆五里过浣花溪
的唯一一座桥而闻名。桥下就是百里飘花的锦江浣花溪，溪水清澈，淡香
飘摇。过桥往东可以到华阳小镇，向西则是有名的浣花萧家了。"
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"westdown" : __DIR__"hhxroad1",
		"eastdown" : __DIR__"feihua",
       ]));

        set("outdoors", "xiao");
        setup();
}