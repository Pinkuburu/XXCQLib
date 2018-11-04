// Room: 内堂
// Date: by godzilla 1999.11.18


inherit ROOM;

void create()
{
	set("short", "内堂");
	set("long", @LONG
穿过小径来到内堂初，只见整个大堂灯火辉煌，正面的墙上挂着
一副侍剑图，上面栩栩如生的画着几个小人练剑的姿势，正中摆着一
张太师椅一个男人正高坐上面。两旁摆设格调典雅，与西墙上挂满的
兵器极不协调。
LONG );
	set("exits", ([
	        "south" : __DIR__"xiaojing1", 
            "west" : __DIR__"qingxinge", 
		"east" :__DIR__"lgsw",
	]));
	set("objects",([
	        __DIR__"npc/songzixue" : 1,
	        ]));
	setup();
	replace_program(ROOM);
}
