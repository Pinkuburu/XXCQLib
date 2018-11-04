//bingqifang.c		四川唐门—兵器房

inherit ROOM;

void create()
{
	set("short", "兵器房");
	set("long", @LONG
这里是蜀中唐门的兵器房，房间很大却充满了一股萧杀之气，靠
墙摆放着几个兵器架，其中一个架子上面摆放着一些唐门秘制的暗器
和兵器，其它的几个架子上则是江湖中常用的兵器。
LONG
	);
	set("exits", ([
		"south" : __DIR__"nzlange2",
	]));
	set("objects", ([
		"/clone/weapon/changjian" : 4]));

	set("no_fight", 1);
	set("area", "蜀中");	
	setup();
	replace_program(ROOM);
}