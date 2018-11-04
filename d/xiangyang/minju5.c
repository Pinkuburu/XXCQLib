// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "茅草屋");
	set("long", @LONG
这是一间普通的茅草房，房子家徒四壁，看来非常的脏乱，屋子没有
锁门，因为屋子里实在是没有什么东西可偷的，屋子里没有人，也许是出
去参加赛龙舟了。
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"west" : __DIR__"tulu5",
	]));

        set("objects",([
          "/d/quanli/npc/wang" : 1
         ]));
	setup();
	replace_program(ROOM);
}
