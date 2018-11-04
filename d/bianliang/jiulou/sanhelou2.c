// Room:
// 山猫Adx 99-11-22 

inherit ROOM;

void create()
{
	set("short", "叁合楼二楼");
	set("long", @LONG
这里是雅座，文人学士经常在这里吟诗作画，富商土豪也在这里边吃
喝边作交易。达官要员公子哥们在这里消磨时光，你站在楼上眺望，窗外
一望无尽，同如玉带，塔湖倒影，远处画栋雕梁，飞檐崇脊只觉得心旷神
怡。酒楼得掌柜胡老板亲自在这里招待客人。
LONG
	);

         set("valid_startroom", 1);
	set("objects", ([
		__DIR__"xiaoer" : 1,
	]));

         set("area", "汴梁");
	set("exits", ([
		"down" : __DIR__"sanhelou",
	]));

	setup();
	replace_program(ROOM);
}
