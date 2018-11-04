// Room: 棋轩厅
// Date: by godzilla 1999.11.18


inherit ROOM;

void create()
{
	set("short", "棋轩厅");
	set("long", @LONG
你走进这间小小的厅室, 看到里面放着一张紫檀木茶几和几张湘
妃竹椅子，紫檀木的茶几上摆放着茶壶和几只白玉杯，专供客人饮用
。你忍不住想坐在竹椅上，让疲惫的身心得到充分的休息。
LONG );
	set("exits", ([
	        "east" : __DIR__"dating", 
		"west" : __DIR__"xiaojing",
		]));
	set("objects",([
	        __DIR__"npc/xiaohe" : 1,
	        ]));
	setup();
	
}
int valid_leave(object me, string dir)
{
	if (me->query("family/family_name") != "天羽派" && dir == "west" )
	{
		if(objectp(present("xiao he", environment(me))))
		return notify_fail("萧河伸手拦住你，说道：里面乃天羽派重地，外人不得进入。这为"+RANK_D->query_respect(me)+"还是请回吧！\n");
	}
	return ::valid_leave(me, dir);
}
