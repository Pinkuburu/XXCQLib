// Room: 药王谷
// By 山猫adx @ 宁波小雪 17:00 99-10-26

#include <ansi.h>
inherit ROOM;
string* npcs = ({
	__DIR__"npc/xiong",
	__DIR__"npc/he",
	__DIR__"npc/lu",
	__DIR__"npc/xie",
	__DIR__"npc/she",
});
void create()
{
        set("short", "饲养场");
        set("long",@LONG
这里是药王谷的饲养场，用于饲养一些可以取药材的动物，你可以把动物
捉(zhuo)到屠宰场去杀了取药。
LONG );
	set("area", "药王谷");
	set("areb", "饲养场");
	set("exits", ([
         "south" : __DIR__"xiaolu2",
	]));
        set("objects", ([
	npcs[random(sizeof(npcs))] :random(2),
	npcs[random(sizeof(npcs))] :random(2),
	npcs[random(sizeof(npcs))] :random(2),
	npcs[random(sizeof(npcs))] :random(2),
	npcs[random(sizeof(npcs))] :random(2),
	]) );
        setup();
}

void init()
{
	add_action("do_zhiliao", "zhuo");
}

int do_zhiliao(string arg)
{
	object me, ob;
	me=this_player();

	if(me->query("party/party_name")!=HIB"药王谷"NOR
         || me->query("party/level")<3 ) {
		return notify_fail("你还不会取药呢！捉动物干什么？\n");
	}

	if( !arg || !objectp(ob = present(arg, environment(me))) )
		return notify_fail("指令格式：zhuo <ID> \n");

        if( !ob->query("yaowang_zhuo") )
                return notify_fail("这个东西不能捉！\n");

        if( me->is_fighting() || me->is_busy() )
                return notify_fail("你正忙着呢！\n");

	ob->set_leader(me);
	message_vision("$N对$n召唤了两声，$n就乖乖得跟着$N。\n", me, ob);
	return 1;
}
