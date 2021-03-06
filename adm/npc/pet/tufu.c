// 删除宠物！NPC
// By 山猫Adx @ snow 99-12-12

inherit NPC;

void create()
{
        set_name("屠夫", ({ "tufu" }) );
        set("gender", "男性" );
        set("age", 35);
        set("long", "一个满脸大胡子，和横肉的家伙。\n");
        set("str", 29);
        set("int", 14);
        set("combat_exp", 25000);
        set("attitude", "heroism");
        set_skill("unarmed", 200);

        setup();
        add_money("silver", 2);
        add_money("coin", 500);
        carry_object("/clone/misc/cloth")->wear();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_sha","sha");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 2:
                        say( "屠夫咧开大嘴, 笑着道：这位"  
                                + RANK_D->query_respect(ob)
                                + "，要买肉是吗? \n");
                        break;
        }
}

int do_sha(string arg)
{
	object me;
	object obj;
	string file;
	me = this_player();
	if(!arg) return notify_fail("指令格式：sha <name>\n");
	        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有"+arg+"。\n");
	if(base_name(obj) == "/adm/npc/pet/pet" && obj->query("owner") == me->query("id")
	&& obj->query("possessed") == me)
	{
	message_vision("$N对屠夫说：帮我处理掉$n，我自己不忍动手！\n",me,obj);
	message_vision("$N伸手一抄起一个木棒，往$n的头上一棍！\n",this_object(),obj);
	message_vision("$N的眼中流出几滴眼泪……\n",obj);
	obj->die();
	me->delete("pet");
	seteuid(ROOT_UID);
	file = obj->query_save_file()+".o";
	rm(file);
	seteuid(getuid());
	destruct(obj);
	return 1;
	}
	return notify_fail("你不可以这么做！\n");
}
