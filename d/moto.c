// By 山猫Adx 16:53 99-10-25

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
int save()
{
	object *inv;
	int i;

	inv = all_inventory(this_object());
	for(i=0; i<sizeof(inv); i++) destruct(inv[i]);

	::save();
}

string query_save_file()
{
	return "/data/npc/moto";
}
void create()
{
	restore();

	set_name("天行者", ({ "motobaby", "moto" }) );
	set("title", HIG"千嬉小雪风云人物"+HIY"收费处"NOR);
	set("gender", "男性" );
	set("age", 5430);
	set("attitude", "heroism");
	set("generation",0);
	set("winner","NONE");

	setup();
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
	add_action("do_list","list");
}

void greeting(object ob)
{
       object obj;
        if( !ob || environment(ob) != environment() ) return;

	if(!ob->query("pingxuan") && !present("xuanchuan dan",ob)) {
		obj=new(__DIR__"xuanchuan");
		obj->move(ob);
		message_vision(YEL"$N给了$n一张"+HIG"《千嬉小雪风云人物》"NOR+YEL"宣传单。\n"NOR,
			this_object(),ob);
	}
}

int accept_object(object me, object ob)
{
	int i=query("cixu")+1;
	command("oh");

	if( ob->query("money_id"))
	{
		if(me->query("combat_exp")<100000) {
			command("say 你的实战经验不够，不符合参选小雪风云人物条件！");
			return 1;
		}
		if(me->query("pingxuan")) {
			command("say 你已经参选了！");
			return 1;
		}
		if(ob->value() < 50000)
		{
			command("xiaoqi "+me->query("id")+"");
			command("say 要付五两黄金的参选费的哦！");
			return 0;
		} else {
			add("cixu", 1);
			set("pingxuan/"+me->query("name")+"/cixu", i);
			set("pingxuan/"+me->query("name")+"/name", me->query("name"));
			set("pingxuan/"+me->query("name")+"/id", me->query("id"));
			set("pingxuan/"+me->query("name")+"/exp", me->query("combat_exp"));
			me->set("pingxuan",1);
			save();
			return 1;
		}
	}
	command("kick "+me->query("id")+"");
	command("kick1 "+me->query("id")+"");
	command("kick2 "+me->query("id")+"");
	return 1;
}
