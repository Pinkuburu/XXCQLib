// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "账房");
	set("long", @LONG
这里是剑庐的账房，浣花萧家门下产业甚多，每日的账目也是繁多，
三个家丁分别趴在三张桌案之前认的计算核对着，一个精壮的汉子在在旁
边不时的巡视着。他就是萧家的管家——马竟终。这里也是萧家门下每月
领生活费的地方，如果你到了领钱的时候，不妨问马管家要一下。
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
	set("exits", ([
		"west" : __DIR__"wuroad2",
	]));
        set("objects", ([
                 "/kungfu/class/huanhua/jingzhong" : 1,
	]));

	setup();
	replace_program(ROOM);
}