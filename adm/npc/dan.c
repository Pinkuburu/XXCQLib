// adx @cctx
// 用于恢复玩家生命一次恢复武功及exp  任何巫师不得随意复制
// 使用记录在/log/cmds/dan

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIB "还魂丹" NOR, ({"huanhun dan","dan"}));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","这是一颗蓝色的丹药可以恢复一次生命。\n");
                set("unit", "颗");
		set("nopawn", 1);
        set("no_drop", 1);

        set("no_give", 1);
		set("no_get", 1);
                set("value", 0);
        }
}

void init()
{
        add_action("do_eat","eat");
        add_action("do_eat","chi");
        add_action("do_work","give");
}

int do_work()
{
	if (!wizardp(this_player()))
	{
                write(HIR"你要干什么？\n"NOR);
		return 1;
	}
}

int do_eat(string arg)
{
        string skill;
        mapping skl;
        int max;
        object me=this_player();
        if(!arg)
                return notify_fail("你要吃什么？\n");
        if(!id(arg))
                return 0;

	max = me->query("max_jingli");
	me->set("eff_jingli",max);
	me->set("jingli",max);
/*
	max = me->query("max_jing");
	me->set("eff_jing",max);
	me->set("jing",max);
*/
	max = me->query("max_neili");
	me->set("eff_neili",max);
	me->set("neili",max);

	max = me->query("max_qi");
	me->set("eff_qi",max);
	me->set("qi",max);

	me->add("combat_exp",me->query("combat_exp")/25);
	me->add("potential", (me->query("potential")-me->query("learned_points")) );

	skl=me->query_skills();
	if(mapp(skl))
		foreach(skill in keys(skl))
		me->set_skill(skill, (int)(me->query_skill(skill,1)+1));

	message_vision("$N服下一颗"+HIB"还魂丹"NOR+"顿觉神清气爽。\n",me);
/*
	log_file("cmds/dan",
	sprintf("%s(%s) 服下一颗还魂丹 on %s\n",
	me->name(1), //记录使用命令的人名
	geteuid(me), //记录使用命令的ID
	ctime(time()) ) ); //记录使用命令的时间
*/	
	destruct(this_object());
        return 1;
}
