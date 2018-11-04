// Room: 药王谷
// By 山猫adx @ 宁波小雪 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "西厅");
	set("long", @LONG
这里是药王谷的西厅，北面是药王谷谷主的书房，是谷主休息的地方，谷主也一
般在这里传授弟子技艺。西面是一间练功房，是药王谷弟子练习技能的地方。
LONG );
	set("area", "药王谷");
	set("areb", "西厅");
	set("no_fight", 1);
	set("exits", ([
		"west" : __DIR__"liangongfang",
		"east" : __DIR__"dating",
		"north" : __DIR__"shufang",
	]));

	setup();
	replace_program(ROOM);
}
