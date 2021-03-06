// Room: 药王谷
// By 山猫adx @ 宁波小雪 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "药房");
	set("long", @LONG
你一走进这里就闻到一股浓重的药味，这里是药王谷存放药材的地方，
屋内全部是有一个个小抽屉的药柜，药材的品种真够多的。这里由药王
萘药儿的二弟子负责，未经许可不能乱动。
LONG );
	set("area", "药王谷");
	set("areb", "药房");
	set("no_fight", 1);
	set("exits", ([
		"southwest" : __DIR__"dongting",
	]));

	set("objects", ([
        __DIR__"npc/huoji4" : 1,
	]));
	setup();
	replace_program(ROOM);
}
