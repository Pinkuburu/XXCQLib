// Room: /d/shaolin/guangchang3.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "勤修场");
	set("long", @LONG
这是戒律院前的勤修场。这里是全寺交通最密集的地方，只见一队队
僧人来来去去，身着各种服色，有的携带刀，枪，棍，杖等兵器，个个身
姿矫健，神态庄重。北面的大殿就是普渡天下众生的普渡堂。西边通向斋
厅。
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"guangchang2",
		"north" : __DIR__"guangchang4",
		"northup" : __DIR__"pdtang",
		"west" : __DIR__"fanting",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
}