// NPC 伙计
// By 山猫Adx 16:53 99-10-25

#include <ansi.h>
inherit NPC;
//inherit F_DEALER;

int ask_me();
void create()
{
	set_name("伙计", ({ "huo ji", "huo", "ji" }) );
	set("title", HIB"药王谷"NOR+YEL"跑堂"NOR);
	set("gender", "男性" );
	set("age", 22);
	set("combat_exp", 100);
	set("attitude", "friendly");

        set("inquiry", ([
		"草籽" : (: ask_me :),
		"种药" : (: ask_me :),
        ]));

	set("foor_count", 35);
	setup();
        add_money("silver", 5);
	carry_object("/clone/misc/cloth")->wear();
}

int ask_me()
{
	object ob, me;
	me = this_player();

	if( me->query("party/party_name")!=HIB"药王谷"NOR ) {
		command("say 你不是这里的伙计，这种活怎么能让你干呢？\n");
		return 1; }

	if (query("foor_count") < 1) {
		command("抱歉，你来得不是时候，这里已经没有草籽了。\n");
		return 1; }

	if (  present("cao zi", me) ) {
		command("你现在身上不是有吗，怎麽又来要了？真贪心！\n");
		return 1; }

	add("foor_count", -1);
	ob = new(__DIR__"obj/caozi");
	ob->move(me);
	message_vision(YEL"伙计给了$N一颗草籽。\n"NOR, me);
	return 1;
}
