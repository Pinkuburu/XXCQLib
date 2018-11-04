//changan city

inherit ROOM;
int do_da(string);

void create ()
{
        set ("short", "练武场");
        set ("long", @LONG
这是一个极宽敞的练武场，练武场上有许多人在汗流浃背的练着功。
在场子的中央有四个大柱子，每个上面都贴着厚厚的一沓千层纸，几个弟
子围着柱子一拳一拳的打(da zhi)着，你要愿意也可以加入。在练武场的
南面有一间小屋，那是剑庐的兵器房，你也可以进去拿一件适合的兵器。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"wuchang1",
		"south" : __DIR__"wuqiku",
	]));

        set("outdoors", "xiao");

        setup();
}

void init()
{
	add_action("do_da", "da");
}

int do_da(string arg)
{
	object me;
       int a,b,my_skill;

	me = this_player();

	if ( !arg || ( arg != "zhi" ) )
                return notify_fail("你想打什么？要打就打千层纸(zhi)吧。\n");

	a = random(20)+20;
	b = random(20)+20;

        if((int)me->query("jingli") < a)
	{
                return notify_fail("你现在精神无法集中，别再练功了吧！\n");
                return 1;
	}
        if((int)me->query("qi") < b)
	{
                return notify_fail("你都快累死了，快歇歇吧！\n");
                return 1;
	}
       my_skill=me->query_skill("cuff",1);
       if(my_skill*my_skill*my_skill/10>(int)me->query("combat_exp"))
        {
                 tell_object(me, "你的战斗经验不够无法领会高深武功了！\n");
         return 1;
       }

        me->add("jingli", -a);
        me->add("qi", -b);

        message_vision("$N清喝一声，摆好架势，一拳打在千层纸上。\n", me);

        if ( (int)me->query_skill("cuff", 1) < 101)
        {
                me->improve_skill("cuff", ((me->query("int"))+ random(me->query("int"))));
                tell_object(me, "你觉得你的手有些疼！\n你的拳法进步了！\n");
        }
        else
        { 
                tell_object(me, "你一拳差不多把千层纸打烂了，看来这样练功对你没什么帮助了。\n");
        }
        return 1;
}
