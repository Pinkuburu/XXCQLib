// Room: /d/shaolin/shijie1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这里是嵩山南麓的少室山山脚。一条长长的石阶如巨龙般蜿蜒而上，
直没云端。嵩山群峰壁立，翠色满山，令人俯仰间顿生渺小之意。路的西
面有一间土屋，屋外挂着一个幌子，上面写着嵩山驿站四个大字。
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"northup" : __DIR__"shijie2",
		"west" : __DIR__"ssyizhan",
         "southdown" : "/d/bianliang/guandao10",
		"east" : __DIR__"kys",
	]));
	set("outdoors", "shaolin");
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

//    if (myfam && (myfam["family_name"] == "少林派" ) && !me->query("passmuren") && dir != "northup")
//       return notify_fail("少林弟子没有通过木人巷或是十八罗汉阵是不许离开嵩山的，怎么，你想触犯门规？\n");

	return ::valid_leave(me, dir);
}
