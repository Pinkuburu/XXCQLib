// Room: /city/daxiao.c

inherit ROOM;

void create()
{
	set("short", "得意赌坊");
	set("long", @LONG
得意赌坊是一家不算豪华的赌坊，一间大屋子里摆放着一张大大的方
桌，赌坊老板司徒通就站在桌子的一侧，二十余名赌客则围在周围，所有
人的注意力都在赌桌上，不时的爆出震天的叫喊声，对你的到来根本无动
于衷。如果你也是来赌钱(gamble)的就快加入吧。墙上贴着一张已经有些
破损的告示(gaoshi)。
LONG );
	set("valid_startroom",1);
	set("item_desc", ([
                "gaoshi" :
"　　　　＃得意赌坊游戏规则＃\n\n"
"本赌场现只设立「大小」赌局：\n"
"共用三粒骰子撒在一只碗里，骰子点数总和：\n"
"       四 至 十 为「小」，\n"
"       十一 至 十七 为「大」，\n"
"       三粒色子点数相同，则大小通吃。\n"
"\n开大赔大，开小赔小，一赔一。\n"
"\n本赌场接受各种货币为赌注。\n"
"\n赌注为一两银子到十两金子。\n",
        ]));

	set("exits", ([
		"east" : __DIR__"huangshanjie2",
	]));

        set("no_fight", 1);

	set("objects", ([
		__DIR__"npc/situ" : 1,
	]));

	set("area", "汴梁");

        setup();

	replace_program(ROOM);
}