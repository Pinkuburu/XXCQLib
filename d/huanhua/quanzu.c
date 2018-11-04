// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "犬吠堂");
	set("long", @LONG
这里虽说是浣花五堂之一，但大小，装饰完全不能和其他四堂相提并
论，堂内只有那块金匾表明着它的身份。十几个年轻的弟子抱着兵器在墙
角做片刻休息，而去换班和归来的弟子则走来走去。安排这一切的就是犬
组的组长阮行月。
LONG
	);

	set("valid_startroom", 1);
	set("exits", ([
		"north" : __DIR__"southyuan",
	]));

        set("objects", ([
		"/kungfu/class/huanhua/ruan" : 1,
	]));

	setup();
	replace_program(ROOM);
}