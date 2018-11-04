//tianshu.c
//by mulan
inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>; 
void setup()
{}
void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}
void create()
{
        set_name(YEL"「忘情天书」"NOR"", ({ "wangqing tianshu","tianshu","book" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("material", "paper");
                set("no_drop", "这样东西不能离开你。\n");
                set("no_get", "这样东西不能离开那儿。\n");
                set("no_put", "这样东西不能放在那儿。\n");
                set("no_pawn", "这样东西不能当。\n");
                set("long",
        "这是一本用薄纸写成的书。上书：「忘情天书」。\n"
        "书皮泛黄，看来已经保存很久了。\n", );
        }
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        int pxlevel; 
        int neili_lost;
	int i;

	if (!(arg=="wangqing tianshu" || arg == "tianshu"))
	return 0;
        if (where->query("pigging")){
                write("你还是专心拱猪吧！\n");
                return 1;
        }
        if (me->is_busy()) {
                write("你现在正忙着呢。\n");
                return 1;
        }
        if( me->is_fighting() ) {
                write("你无法在战斗中专心下来研读新知！\n");
                return 1;
        }
        if (!id(arg)) {	
                write("你要读什么？\n");
                return 1;
        }
        if( me->query_skill("literate", 1) < 180 ){
                write("你对文字的理解还不够，再学点文化(literate)吧。\n");
                return 1;
        }
        if(me->query_int() < 40){
          write("你得悟性不能领阅如此高深得秘籍。\n");
          return 1;
        }
        message("vision", me->name() + "正专心地研读忘情天书。\n", environment(me), me);
        if( (int)me->query("jingli") < 100 ) {
                write("你现在过于疲倦，无法专心下来研读新知。\n");
                return 1;
        }
	neili_lost = 5;
        if( (int)me->query("neili") < neili_lost) {
		write("你内力不够，无法钻研这么高深的武功。\n");
                return 1;
        }
        pxlevel = me->query_skill("wangqing-jian", 1);
        if( (int)me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel/10 ) {
                write("你的实战经验不足，再怎么读也没用。\n");
                return 1;
        }
        if( me->query_skill("force", 1) < 180){
                write("你研读了一会儿，但是发现上面所说你的内功太低了，去学学force 吧。\n");
                return 1;
        }
        if( me->query_skill("wangqing-jian", 1) > 199){
                write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
                return 1;
        }
	i=random(me->query_skill("literate",1)/2);
	if(i>90) i=90;
	if(i<10) i=10;
        me->receive_damage("jingli", (100-i));
	  me->set("neili",(int)me->query("neili")-neili_lost);
        me->improve_skill("wangqing-jian", (int)me->query_skill("literate", 1)/5+1);
        write("你研读忘情天书，对其中的奥秘颇有心得。\n");
        return 1;
}

