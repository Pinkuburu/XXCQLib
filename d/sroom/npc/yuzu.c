// 狱卒 
// 还可以留有余地，比如受贿放人啦，被人劫狱啦什么的。
// jackyboy@cuterabbit Studio 1999/6/6
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("狱卒", ({ "yu zu","yu","zu" }) );
	set("long",
		"狱卒眼神里带着股杀气。\n");
	set("age",34);
	set("attitude", "peaceful");
	setup();
set("combat_exp",200);
	carry_object(NCLOTH)->wear();
}
