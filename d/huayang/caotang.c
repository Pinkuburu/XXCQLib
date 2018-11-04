// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "杜甫草堂");
	set("long", @LONG
这里说是草堂，实际是一间时年已久的木板房，堂前有杜甫游锦江时
的题写的“杜甫草堂”的匾额，现在这里是一间私塾，草堂主人杜先生在
这里免费教授十八岁以下的乡童。
LONG
	);

	set("valid_startroom", 1);
	set("no_fight", 1);
        set("no_sleep_room",1);

	set("exits", ([
		"west" : __DIR__"fhroad3",
	]));

	set("objects", ([
		__DIR__"npc/du": 1,
	]));

	setup();
	replace_program(ROOM);
}