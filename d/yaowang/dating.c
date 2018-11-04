// Room: 药王谷
// By 山猫adx @ 宁波小雪 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "药王谷大厅");
	set("long", @LONG
你走进一间非常宽敞的房间，中央铺着一条大红的地毯，正前方放着一张太师椅
一看就知道这是谷主的座位，两边各放着一排椅子。旁边墙上挂着一块留言扳
（board）是专门供药王谷弟子交流使用的。
LONG );
	set("area", "药王谷");
	set("areb", "大厅");
	set("no_fight", 1);
	set("exits", ([
		"north" : __DIR__"houyuan",
		"south" : __DIR__"yaowanggu",
		"west" : __DIR__"xiting",
		"east" : __DIR__"dongting",
	]));
         set("objects", ([
                 __DIR__"npc/zongguan" : 1,
         ]));

	setup();
         call_other("/clone/board/yaowang_b", "???");
	replace_program(ROOM);
}
