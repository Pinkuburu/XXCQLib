// zaotang.c  by winder

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "华清池女部");
	set("long", @LONG
走进这里，发现这里弥漫着浓浓的热雾，隐隐看到几步远的地方就是
一个大理石砌成的池子，大约有十几个女子正泡在池子里。看到这些，你
也想洗上一洗，洗去一身的疲惫。
LONG);	
	set("valid_startroom",1);

	set("exits", ([
		"north" : __DIR__"zaotang",
	]));

	set("area", "汴梁");

	setup();
}

void init()
{
	object me;
	me = this_player();
	call_out("check",1,me);
}

void check(object me)
{
	if (me->query("gender") == "男性")
	{
		message("channel:chat",
			HIW"\n【尖叫声】汴梁城华清池的方向传来了一阵女人震天的抓流氓的声音，听说"
			+me->name(1)+"跑到女澡堂子里去了，哎，真是不要脸！\n"NOR,users());
		tell_object(me, "\n你正待大饱眼福一番，女澡堂子里的人已经醒悟过来，一拥而上，将你扔了出去，真没面子。\n\n");
		message("vision",
			me->query("name")+"正色迷迷的左管右看，十几个大胆的女人已经冲了上去，将"+me->query("name")+"扔了出去。\n",
			environment(me), ({me}) );
		me->move("/d/bianliang/zaotang");
		message("vision",
			"只听“砰”的一声，"+me->query("name")+"被人从女澡堂子扔了出来，后面还传来了女人的叫骂声。\n",
			environment(me), ({me}) );
	}
}