// Room: 药王谷
// By 山猫adx @ 宁波小雪 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "炼丹房");
	set("long", @LONG
这里是药王谷的炼丹房，周围墙壁都是用石块砌成的，青砖铺地，
房间中央放着一尊青铜筑成的大丹炉。
LONG );
	set("area", "药王谷");
	set("areb", "炼丹房东");
	set("no_fight", 1);
	set("exits", ([
		"west" : __DIR__"xiaolu1",
	]));
	set("objects", ([
		__DIR__"npc/obj/danlu2" : 1,
	]));
	setup();
	replace_program(ROOM);
}
