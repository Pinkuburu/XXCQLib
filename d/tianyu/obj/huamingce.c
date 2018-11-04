// 花名册
// Write by godzilla 1999.9.29

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"花名册"NOR, ({ "huaming ce"}));    
	set_weight(200);       
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("value", 500);
		set("long","这是一本天羽派的花名册，记录了天羽派历代的弟子。(read)\n");
		set("material", "paper");
	  }
}
void init()
{
        add_action("do_look", "read");
        add_action("do_write","write");
}    
int do_look(string arg)
{
        object me = this_player();
        if(arg=="huaming ce"||me->query("family/family_name")=="天羽派")
        {
        	if(me->query("write_name"))
        	{
        		tell_object(me,"这是一本天羽派的花名册，记录了天羽派历代的弟子，在八代弟子一栏末行上正写着你的大名----"HIR+me->name()+NOR"。\n");
        	         return 1;
        	}
        	else 
        	{
        		tell_object(me,"这是一本天羽派的花名册，记录了天羽派历代的弟子，\n上面居然还没有你的名字，看来只有自己添上了(write)。\n");        
                         return 1;
                 }        
        }
        return 1;
}        
int do_write()
{
	object me=this_player();
	if(me->query("write_name"))
        return notify_fail("天羽派花册上已经有你的名字了。\n");
        if(me->query("family/family_name")!="天羽派")
	return notify_fail("天羽派花册上其能留下你的狗名!\n");
	tell_object(me,"你大笔一挥，在册上留下了你的名字。\n");
	set("write_name",me->query("id"));
	me->set("write_name",1);
	return 1;
}	