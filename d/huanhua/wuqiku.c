// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "兵器房");
	set("long", @LONG
这里是剑庐的兵器房，兵器架上及地上都散乱的摆放着一些普通的兵
器，比如长剑、钢刀，你可以随便的挑上一件，如果现在没有你可以稍微
等一下，也许会有别人来归还的。
LONG
	);

	set("valid_startroom", 1);
	set("exits", ([
		"north" : __DIR__"wuchang2",
	]));
        set("objects", ([
		__DIR__"npc/obj/zhujian" : 2,
		__DIR__"npc/obj/ruanjian" : 2,
	]));

	setup();
	replace_program(ROOM);
}
