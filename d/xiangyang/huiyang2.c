//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "惠阳街");
        set ("long", @LONG
由于金银钱庄的威慑，秭归镇的县衙门也相当于一个摆设，虽然每天
官差也象模象样的出来巡查，但似乎只会为虎作伥，帮钱庄欺压百姓。由
于衙门就在路西，所以人们连这段街都懒得来。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"huiyang1",
		"south" : __DIR__"qugongci",
	]));

        set("outdoors", "zigui");
        setup();
}