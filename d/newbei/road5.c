// 山猫ADX by snow 99-12-4

inherit ROOM;

void create ()
{
	set("short",  "官道");
	set("long",  @LONG
这是一条宽阔笔直的官道，黄土路面，足可容得下十马并驰。往北通向
朝廷的皇城，往南通向汴梁城。
LONG);
	set("exits",  ([
		"west"  :  __DIR__"road6",
		"east"  :  __DIR__"road4",
	]));
	set("outdoors",  1);
	setup();
	replace_program(ROOM);
}
