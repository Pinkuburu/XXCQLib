// Room: 青石路
// Date: by godzilla 1999.11.18

inherit ROOM;

void create()
{
	set("short", "青石路");
	set("long", @LONG
一条用青石砌成的大道，看来年岁已久，又加上少已修补，已经
变得坑坑洼洼，颠簸不平了，四周杂草丛生，只看见几个老仆在清扫
树叶，北边就是前院了。
LONG );
        set("outdoors", "tianyu");
	set("exits", ([
	        "south" : __DIR__"damen", 
		"north"  : __DIR__"qianyuan",
	]));
	set("objects",([
	        __DIR__"npc/puren" : 1,
	        ]));
	setup();
	replace_program(ROOM);
}
