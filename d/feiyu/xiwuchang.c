// Room : xiwuchang.c	
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
//

inherit ROOM;

void init();
int do_tiao(string);

void create ()
{
        set ("short", "西练武场");
        set ("long", @LONG
这是一个宽敞的西练武场。场子的中央竟是一个立满了木桩的大沙池
几个飞鱼弟子正在上面练习轻功身法，在木桩上跳来跳去，但不时也有几
个摔了下来，好在下面是沙池。否则要摔伤的。你也可以去跳木桩练练轻
功身法(tiao)。
LONG);
//	set("outdoors", "feiyu");
	set("exits", ([
                "north" : __DIR__"cailiaofang",
                "south" : __DIR__"fanting",
                "east" :__DIR__"qianting", 
                "west" :__DIR__"wroad", 
        ]));
        setup();
}

void init()
{
        add_action("do_tiao", "tiao");
}

int do_tiao(string arg)
{
        object me;
        int jingli_cost;

        me = this_player();

        if ( !arg || ( arg != "muzhuang" ) )
                return notify_fail("你想跳什么？\n");

        jingli_cost = (-1) * (10 + random(5));

	if ( me->query("jingli") <= ( - jingli_cost ) )
		return notify_fail("你太累了，要休息一会儿。\n");

	if ( (int)me->query_skill("dodge", 1) < 11 )  
        {
		write("你深吸了一口气，一纵身跳上一根较矮的木桩，但是脚下不停的晃，险些摔了下来！\n不过你对轻功身法有了一点了解。\n");
	        me->add("jingli", jingli_cost);
                me->improve_skill("dodge", (5 + random(me->query("int") / 2)));
        }
	else
		if ( (int)me->query_skill("dodge", 1) < 31 )  
        	{
			write("你气运全身，一晃身跃上一根木桩，稍顿了顿，又提气跳上了另一根！\n你对轻功身法有了一些认识。\n");
		        me->add("jingli", jingli_cost);
        	        me->improve_skill("dodge", (10 + random(me->query("int") / 2)));
	        }
		else
			write("你随意的在木桩上飞奔跳跃，感到已经没有困难。\n你在这里已经学不到什么了！\n");
        return 1;
}