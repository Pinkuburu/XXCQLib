#include <ansi.h>
inherit ITEM;
int do_songxin(string arg);
void create()
{
	set_name(RED"密函"NOR, ({ "mi han", "letter" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "封");
                set("long", "这是一封用红皮封好的密函。(song xxx)\n");
		set("value", 100);
		set("material", "steel");
	}
	setup();
}
void init()
{
        add_action("do_songxin","song");
        add_action("do_kan","read")
;
}
int do_songxin(string arg)
{
	object who,me,where;
	int exp,exp1,pot,pot1;
	exp=80+random(50);
	exp1=350+random(100);
	pot=30+random(30);
	pot1=150+random(60);
	me=this_player();
	where = environment(me);
	if(!arg||arg=="")
	return notify_fail("你要把密函给谁？\n");
	if(!objectp(who = present(arg, environment(me))) || !living(who))
        return notify_fail("这里没有这个人。\n");
        if(who->query("name")!=this_object()->query("human"))
        return notify_fail("这个封信不是送给他的。\n");
        if (file_name(where)!=this_object()->query("where"))
        return notify_fail("这里给他太显眼了，还是送到该送的地方去吧。\n");
        if (!me->query_temp("do_job2"))
        {
        	message_vision(HIW"$N把密函恭恭敬敬的交给了$n。\n"NOR,me,who);
        	message_vision(HIR"$n看了看密函，突然对$N大喝一声：“你竟然敢假冒密函，拿命来吧！！\n"NOR,me,who);
        	who->kill_ob(me);
        	destruct(this_object());
                return 1;
        }	
        if(me->query_temp("jiefei_1"))
        {
        	message_vision(CYN"$N把"+RED+"密函"+CYN+"恭恭敬敬的交给了$n。 \n"NOR,me,who);
                message_vision(CYN"$n看了看"+RED+"密函"+CYN+"满意的对$N点了点头说道：“$N请转告你家师父，到时一定附会”\n"NOR,me,who);
        	tell_object(me,HIW"你被奖励了"+chinese_number(exp1)+"点经验。\n你被奖励了"+chinese_number(pot1)+"点浅能。\n"NOR);
        	me->add("combat_exp",exp1);
                me->add("potential",pot1);
                me->delete_temp("do_job2");
                me->delete_temp("jiefei_1");
                me->apply_condition("do_songxin", 0);
                destruct(this_object());
                return 1;
        }
        message_vision(CYN"$N把"+RED+"密函"+CYN+"恭恭敬敬的交给了$n。 \n"NOR,me,who);
        message_vision(CYN"$n看了看"+RED+"密函"+CYN+"满意的对$N点了点头说道：“请转告你家师父，到时一定附会”\n"NOR,me,who);
        tell_object(me,HIW"你被奖励了"+chinese_number(exp)+"点经验。\n你被奖励了"+chinese_number(pot)+"点浅能。\n"NOR);
        me->delete_temp("do_job2");
        me->start_busy(3);        
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->apply_condition("do_songxin", 8);
        destruct(this_object());
        return 1;
}         

int do_kan(string arg)
{
         if(!arg||arg=="")
       return 0;
       if(arg=="mi han")
        {
        tell_object(this_player(),"这是一封用红皮封好的密函。上面写着"+this_object()->query("human")+"亲收。\n");
        return 1;
        }
}
