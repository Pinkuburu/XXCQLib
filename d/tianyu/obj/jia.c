// Obj: 兵器架
// Date: by godzilla 1999.11.18

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL"兵器架"NOR, ({ "bingqi jia", "jia" }) );         
        set_weight(30000000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "个");
        set("long", "这是一个专门用来放各种兵器的架子。
上面放着：\n
       长剑 (changjian)，
       短剑 (duanjian)，
       \n");
         set("number",15);
        set("material","wood");
        set("no_get",1);
        }
        setup();
}
void init()
{
	add_action("do_get",({"get","na"}));
}
int do_get(string arg)
{
	object me,ob;
	string arg1,arg2;
	me=this_player();
	if(!arg || sscanf(arg,"%s from %s", arg1, arg2)!=2)
	return notify_fail("命令格式: get <兵器名称> from jia。\n");
	if (arg2!="jia")
	return notify_fail("命令格式: get <兵器名称> from jia。\n");
	if(present(arg1, me) || present(arg1, environment()))
	return notify_fail("已经有这样东西了。\n");
    if(this_object()->query("number")<0)
           return notify_fail("已经没有了。\n");
     if(me->query("family/family_name")!="天羽派")
    return notify_fail("已经没有了。\n");
	switch (arg1){
          case"changjian": ob=new("/clone/weapon/changjian");
          break;             
          case"duanjian": ob=new("/clone/weapon/duanjian");
          break;   
          default :
          return notify_fail("没有这种兵器。\n");
          }
        if(ob)
        ob->move(me);
        message_vision("$N从"YEL"兵器架"NOR"上拿出一把$n。\n",me,ob);  
        this_object()->add("number",-1);
        return 1;
}

