// box.c 蛊盒
// by mulan

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_gudu","gudu");
}

void create()
{
        set_name("蛊盒", ({ "gu he", "he","box" }) );
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","个");
        set("sworm",5);
        set("value",0);
        set("material","wood");
        set("long", "这是一个看上去很普通的盒子，\n"
                    "但里面养的却是为武林中人最为头痛的毒物____［蛊］。\n"
                    "可以用来(gudu) ! \n");
        }
        setup();
}

int do_gudu(string arg)
{
    object me, obj;
    int myexp , objexp ;
    int mylev , objlev ;
    int myforce , obforce ;
    int steps ;

        me = this_player();
        if( environment(me)->query("no_fight") )
                return notify_fail("这里禁止战斗。\n");
        if( !arg )
                return notify_fail("你想攻击谁？\n");

        if( this_object()->query("sworm") <=0)
                return notify_fail("盒里的蛊已经没有了。\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

        if(obj == me)
                return notify_fail("你没有问题吧。\n");

        myexp =  me -> query ("combat_exp" ) ;
        objexp = obj -> query ("combat_exp" ) ;
        mylev =  me -> query_skill("gudu" ) ;
        objlev = obj -> query_skill("gudu" ) ;
        myforce =  me -> query_skill("force" ) ;
        obforce = obj -> query_skill("force" ) ;

        if ( mylev <= 0 )
                return notify_fail("你不会蛊毒之术，不能遥控蛊虫攻击敌人！\n");

        myexp = 30 * objexp / myexp ;
        if ( myexp < 30 ) myexp = 30 ;

        if ((int) me ->query("jingli") < myexp )
                return notify_fail("你的精不足以遥控蛊虫！\n");

        if ((myforce + 30) <= obforce)
                return notify_fail("对手的内功太深厚了，蛊毒对他不起作用！\n");

        this_object()->add("sworm", -1);
        
        steps =  mylev / 10  ;
        if ( steps < 5 ) steps = 5 ;
        if ( steps > 15 ) steps = 15 ;
        message_vision(HIY "\n$N的双手伸了出去，立即就发生了一件很诡秘的事．\n\n"
                   HIW"忽然如一层薄薄的暗青，迅速地游移前来，乍看似一层薄雾，\n"
                   "但仔细看去，又像千万条小虫一齐向前蠕游而来。\n\n"
                   HIB"$n忍不往失声叫了起来，    "+HIR"“蛊毒！”\n"NOR,
                   me, obj);
        me -> start_busy (3) ;

        if( userp(obj) )
        {       obj -> fight_ob(me) ;
                me->fight_ob(obj);
        }
        else
        {       obj->kill_ob(me);
                me->fight_ob(obj);
        }
        if (  random ( mylev ) < random(obj->query_dex()) )
                message_vision(YEL "\n但$n 仗着高深的轻功躲闪过去!。\n" NOR, me, obj);
        else
        {
         tell_object (obj , HIR "\n你周围刹那间尽是蛊虫，千万只地蠕动，怎么也赶不走，\n"
               "你只觉得脚上微微一痛，已被蛊虫咬伤了！\n" NOR  ) ;
         obj->apply_condition("sworm_poison", 30);
         tell_object(obj, HIG "你觉得胸中痒痛,不好，你中了蛊毒！\n" NOR );
         obj -> receive_damage ("jingli", steps * 8 ) ;
         obj -> receive_damage ("qi", steps * 10 ) ;
         obj -> start_busy (3) ;
         me -> start_busy (1) ;
        }
        me -> receive_damage ("jingli" , mylev ) ;
        me -> add("neili" , - mylev ) ;
        return 1;
}
