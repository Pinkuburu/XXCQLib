// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "家和绸缎行");
	set("long", @LONG
	这是一家豪华的丝绸行，走入屋内便有小二迎了上来。环顾四周，见庄内
堆满了各种布料和成衣，绸缎行的老板缠丝大侠蔡玉丹在柜台后忙忙碌碌的似乎在
算着什么，这里的衣服布料质量非常好，你可以随便走一走，挑点什么。
LONG
	);

	set("valid_startroom", 1);
	set("exits", ([
		"north" : __DIR__"shalan-w1",
	]));
        set("objects", ([
                 __DIR__"npc/xiaoer2": 1,
                 __DIR__"npc/cai": 1,]));

	setup();
	replace_program(ROOM);
}

