//changan city

inherit ROOM;

void create ()
{
        set ("short", "北厢院");
        set ("long", @LONG
一踏入北厢院，一阵肃穆之感油然而生，因为权力帮大举攻打剑庐，
伤亡日益增加，每个浣花弟子的心头都是沉甸甸的。剑庐的龙组和鹰组更
是忙得不可开交。连西厢凤组的女弟子们也失去了往日的笑声，每个人都
只有一个念头——保护剑庐。
LONG);
	set("valid_startroom", 1);

        set("objects", ([
	]));

        set("exits", 
        ([
		"north" : __DIR__"longzu",
		"east" : __DIR__"yingzu",
		"west" : __DIR__"fengzu",
		"south" : __DIR__"northlang",
	]));

        set("outdoors", "xiao");

        setup();

	replace_program(ROOM);
}