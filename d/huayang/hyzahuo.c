// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "华阳杂货铺");
	set("long", @LONG
这是一家小小的杂货铺，别看它小，由于它特殊的地理位置，使得它
的生意非常的不错，而货架上摆放的那些东西虽不高贵却也实用，胡老板
在此开店数十年，声誉是不用说的。
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"north" : __DIR__"hyroad3",
	]));

	set("objects", ([
		__DIR__"npc/hu": 1,
	]));

	setup();
	replace_program(ROOM);
}