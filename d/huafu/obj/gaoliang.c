// gaoliang.c

inherit ITEM;

void create()
{
	set_name("高粱", ({"gaoliang"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "一根高粱。首先要磨碎(mo)，然后和面粉搅拌(ban)。\n");
		set("unit", "根");
		set("value", 40);
		set("food_remaining", 5);
		set("food_supply", 15);
	}
}

void init()
{
	add_action("do_mo","mo");
        add_action("do_bann","ban");
}

int do_mo(string arg)
{
	object me;
	me=this_player();
	
        if ( (arg!="高粱") && (arg!="gaoliang") )
		return 0;
	me->set_temp("do-mo",1);
                        me->add("jingli",-5);
	message_vision("$N将高粱磨成了粉末状。\n",me);
        destruct(this_object());
	return 1;
}
  
/*
int do_bann(string arg)
{
	object me;
	object ob2;
	object ob;
	me=this_player();
	
        if ( (arg!="面粉") && (arg!="mianfen") )
		return 0;
	if ( !ob2=present("mianfen",me) )
		return notify_fail("你要把高粱和哪种东西拌在一起？\n");
	if ( !me->query_temp("do-mo") )
		return notify_fail("你还没把高粱磨碎呢。\n");
	message_vision("$N将磨碎的高粱和面粉掺拌在一起，搅拌均匀。\n",me);
	ob=new("/d/huafu/obj/gaoliangfan");
	ob->move(me);
	me->delete_temp("do-mo");
                        me->add("jingli",-5);
	destruct(this_object());
	destruct(ob2);
	return 1;
}
*/
