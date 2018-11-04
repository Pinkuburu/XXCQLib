// zoulang1.c
// made by lks

inherit ROOM;
void create()
{
	set("short","走廊");
	set("long",@LONG
这是一条长长的走廊，通向温府的议事厅。地上铺着毛毡，毛毡已经
换成纯白，两侧木壁上或刻有花鸟鱼虫，或挂了些许时人的字画，每隔七
八步，就有一个香炉，缕缕青烟从铜鹤嘴里游出，闻之精神一振。
LONG);
	set("valid_startroom",1);
	set("outdoors","wenzhai");
	set("exits",([
	    "north"      : __DIR__"jiashan",
	    "east"      : __DIR__"zoulang2",
	]));
	setup();
	replace_program(ROOM);
}
