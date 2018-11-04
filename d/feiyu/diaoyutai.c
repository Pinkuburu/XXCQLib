// Room: daoyutai.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21

inherit ROOM;

void init();

void create()
{
	set("short", "钓鱼台");
	set("long", @LONG
走过树林，你的眼前豁然开朗起来，这里被叫作钓鱼台，大概就是因
为这里有一条小溪，溪里游着一些不多见的鱼吧，台上已经有几个人在垂
钓了。有兴趣的话你也可以试试。远远望出去，隐隐看见雾中的山峰，使
人感到心旷神怡。
LONG
	);
       
	set("valid_startroom", 1);
	set("exits", ([
		"north" : __DIR__"shulin",
	]));

	setup();
}

void init()
{
        object me = this_player();
        if (me->query_temp("feiyutask/given")) me->set_temp("di2mark", 1);
        return;
}
