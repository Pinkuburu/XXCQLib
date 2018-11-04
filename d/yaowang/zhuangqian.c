// Room: 药王谷
// By 山猫adx @ 宁波小雪 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "庄前");
	set("long", @LONG
这里是药王山庄的大门，由于药王谷地处偏僻少有人来，所以也无所戒备。
并不高大的庄门上写着『药王谷』。
LONG );
	set("area", "药王谷");
	set("areb", "庄前");
	set("no_fight", 1);
	set("exits", ([
		"north" : __DIR__"yaowanggu",
		"south" : __DIR__"gukou",
	]));

	setup();
	replace_program(ROOM);
}
