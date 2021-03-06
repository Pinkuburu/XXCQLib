// zaotang.c  by winder

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "华清池男部");
	set("long", @LONG
走进这里，发现这里弥漫着浓浓的热雾，隐隐看到几步远的地方就是
一个大理石砌成的池子，大约有十几个人正泡在池子里。看到这些，你也
想洗上一洗，洗去一身的疲惫。
LONG);	
	set("valid_startroom",1);

	set("exits", ([
		"south" : __DIR__"zaotang",
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
	if (me->query("gender") == "女性")
	{
		message("channel:chat",
			HIW"【惊讶声】汴梁城华清池的方向传来了一阵男人喧闹的声音，听说有个女的叫什么"
			+me->name(1)+"的跑到男澡堂子里去了，哎，真是世风日下呀！\n"NOR,users());
		tell_object(me, "\n你正好奇的左管右看，几个不怀好意的男子已经围了上来，你吓得赶快跑了出去，真羞死了。\n\n");
		message("vision",
			me->query("name")+"正好奇的左管右看，几个不怀好意的男子已经围了上去，"+me->query("name")+"吓得赶快跑了出去。",
			environment(me), ({me}) );
		me->move("/d/bianliang/zaotang");
		message("vision",
			me->query("name")+"满脸通红的从男澡堂子里跑了出来，后面还传来了阵阵男人的笑声。",
			environment(me), ({me}) );
	}
}