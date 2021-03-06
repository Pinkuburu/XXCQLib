// Room: /d/shaolin/wuchang3.c
// Date: YZC 96/01/19

inherit ROOM;
int do_da(string);

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是少林寺的东练武场。由无数块巨大的花岗岩石板铺就。上千年
的踩踏已使得这些石板如同镜子般平整光滑。练武场中间竖立着不少木人
，十来个僧人正在击打木人(da muren)练习武艺。西面就是出了无数武林
高手的般若堂。南北是两道走廊。
LONG
	);
	set("valid_startroom", 1);
	set("exits", ([
		"east" :__DIR__"luohan",
		"south" : __DIR__"zoulang4",
		"west" : __DIR__"wuchang2",
		"north" : __DIR__"zoulang8",
	]));

	set("outdoors", "shaolin");

	set("objects",([
		"/kungfu/class/shaolin/tianlong" : 1,
        "/kungfu/class/shaolin/tianguan" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_da", "da");
}

int do_da(string arg)
{
	object me;
	int a, b;

	me = this_player();

	if ( !arg || ( arg != "muren" ) )
                return notify_fail("你想打什么？要打就打眼前的这个木人(muren)吧。\n");

	a = random(20)+25;
	b = random(20)+25;

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

        me->add("jingli", -a);
        me->add("qi", -b);

        message_vision("$N面对木人马步蹲裆，吐气开声，一掌一掌的向木人打去。\n", me);

        if ( (int)me->query_skill("strike", 1) < 101)
        {
                me->improve_skill("strike", (me->query_int()+ random(me->query("int"))));
                tell_object(me, "你的手掌打的生疼！基本掌法有了一定的进步了！\n");
        }
        else
        { 
                tell_object(me, "你一掌险些将木人打倒了，看来再也不能通过打木人练掌法了。\n");
        }
        return 1;
}
