// Room: 小径
// Date: by godzilla 1999.11.18
#include <ansi.h>
inherit ROOM;
string *skill_msg = ({
         "南边墙上刻着天下第一攻招「玉石俱焚」，你依照其练法，演绎了一遍!\n\n",
         "西边墙上刻着天下第一快招「闪电惊虹」，你依照其练法，演绎了一遍!\n\n",
         "北边墙上刻着天下第一守招「海天一线」，你依照其练法，演绎了一遍!\n\n",
         "东边墙上刻着天下第一慢招「老牛破车」，你依照其练法，演绎了一遍!\n\n",
         "一柱香功夫，你慢慢对其四招已有所悟！\n\n",
});

void create()
{
        set("short", "密室");
        set("long", @LONG
没想到你居然到了一间密室，四周墙上(wall)刻满了文字，东南
西北四个方向记录了不同的四招，尽述一代大侠萧秋水所创的天下第
一攻、快、守、慢四种不同绝招。
LONG );
        set("no_fight",1);
        setup();
}
void init()
{
         add_action("do_kan","look");
}
int do_kan(string arg)
{
        object me=this_player();
        int stage;
        if(!arg||arg=="")
        return 0;
        if(me->query_temp("start_lingwu"))
        return 0;
        if(me->query("lingwu_perform"))
        { 
                tell_object(me,HIW"你已经领悟过了四大绝招，上面所刻已经对你无所用了。还是回去吧\n"NOR);
                me->move(__DIR__"xiaojing10");
                return 1;
        }       
        if(arg=="wall")
        {
                write("你开始慢慢琢磨墙上的剑招！\n");
                me->set_temp("start_lingwu",1);
                remove_call_out("do_yanxi");
                call_out("do_yanxi",5,me,stage);
                return 1;
        }       
}       
int do_yanxi(object me,int stage)
{
                        
        tell_object(me, skill_msg[stage]);
        if( ++stage < sizeof(skill_msg) )
        {
                call_out( "do_yanxi", 5, me, stage );
                return 1;
        }       
        else
        me->move(__DIR__"xiaojing10");
        me->set("lingwu_perform",1);
        tell_object(me,HIW"四大绝招你已经全部学会，使用perfrom gong、kuai、shou、man发出绝招！\n"NOR);
        message("channel:chat",HIM"【奇遇】"+HIC+me->query("name")+"从石壁上领悟了天下第一攻,快,守,慢的绝招。\n"NOR,users());   
        me->set_temp("start_lingwu",0);
}
        


