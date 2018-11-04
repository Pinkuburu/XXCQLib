// Room: 药王谷
// By 山猫adx @ 宁波小雪 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
你走进一间书房，这里是药王谷谷主萘药儿传授弟子技艺的地方，房间周围的墙
边全是摆着装满书的书架，谷主萘药儿就坐在桌子后面的太师椅上。
LONG );
	set("area", "药王谷");
	set("areb", "书房");
	set("no_fight", 1);
	set("exits", ([
		"south" : __DIR__"xiting",
	]));

	set("objects", ([
		__DIR__"npc/naiyaoer" : 1,
	]));
	setup();
	replace_program(ROOM);
}
