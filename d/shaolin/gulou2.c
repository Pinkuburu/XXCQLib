// Room: /d/shaolin/gulou2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "鼓楼二层");
	set("long", @LONG
每个楼层上都铺设了结实的木楼板，八角形的墙身上则开了四扇大窗
。从窗孔看，墙体也是极为厚实。从这里往外眺望，可以看到围绕塔周的
小园以及北边的竹林，随风飘来阵阵竹叶的清香。
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"up" : __DIR__"gulou3",
		"down" : __DIR__"gulou1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

