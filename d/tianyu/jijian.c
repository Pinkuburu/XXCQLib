// Room: 祭剑堂
// Date: by godzilla 1999.11.18

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "祭剑堂");
        set("long", @LONG
只见整个大堂灯火辉煌，正面的墙上挂着一副侍剑图，墙下面摆
放着历代天羽门人的祭位，整个房间烟雾迷绕。大堂中间放着一坛，
是用来祭剑(jijian)之用。
LONG );
        set("exits", ([
                "south" : __DIR__"pianyuan", 
                ]));
        setup();

}
void init()
{
       add_action("do_jijian","jijian");
       add_action("do_fang","fang");
}
int do_jijian()
{
        object me=this_player();
        if(me->query_temp("ji_jian"))
        return notify_fail("你正在祭剑。\n");
        if(!me->query_temp("jijian"))
        return notify_fail("你先要把长剑放入祭坛(fang)!\n");
        if(me->query_temp("overjijian"))
        return notify_fail("今天你已经祭过了。\n");
        message_vision(CYN"$N双膝跪地，两手合十，面对先祖灵位，静心祭剑。\n",me);
        me->set_temp("ji_jian",1);
        call_out("jijian_1",3,me);
//      remove_call_out("jijian_1");
        return 1;
}       
int do_fang()
{
        object me=this_player();
        object ob=present("long sword",me);
        if(!present("long sword", me))
        return notify_fail("你身上没有长剑，无法放进祭坛。\n");
        if(ob->query("sword"))
        return notify_fail("这把剑已经祭过了。\n");  
        if(me->query("family/family_name")!="天羽派")
        return notify_fail("你不是天羽弟子不能祭剑。\n");  
        message_vision(CYN"$N把身上的长剑恭恭敬敬的放进了祭坛。\n"NOR,me);
        me->set_temp("jijian",1);
        destruct(ob);
        return 1;
 }
 int jijian_1(object me)
 {
        message_vision(HIR"$N高声念道：弟子乃天羽派第八代弟子"+me->name()+"在此祭剑。\n"NOR,me);
        message_vision(HIR"弟子我一心要为天羽派发扬光大，创立不朽的基业，望各位师组在天之灵，保佑弟子。\n"NOR,me);
        message_vision(HIR"希望赐予弟子，剑之灵气，更能发挥其剑法之精髓。特此拜祭。\n"NOR,me);
        call_out("jijian_2",3,me);
 //     remove_call_out("jijian_2");
        return 1;
 }
 int jijian_2(object me)        
 {
        object obj;
        obj=new(__DIR__"obj/changjian");
        message_vision(HIY"良久......，只见祭坛中剑气环绕，突然“铛”的一声，一把长剑从坛中跃入$N手中。\n"NOR,me);
        obj->move(me);
        obj->set("long","这是一柄赋予天羽灵气的长剑，上面刻着天羽派"+me->name()+"的名字。\n");
        obj->set("sword",me->query("id"));
        me->set_temp("jijian",0);
        me->set_temp("overjijian",1);
        me->set_temp("ji_jian",0);
        message("channel:chat",HIW"【传闻】"+HIC+me->query("name")+"在【祭剑堂】获得天羽前辈赋予灵气得天羽剑。\n"NOR,users());   
        return 1;
}
int valid_leave(object me, string dir)
{
        if (me->query_temp("ji_jian") && dir == "south" )
        {
                   return notify_fail("你正在祭剑，不能离开。\n");
        }
        return ::valid_leave(me, dir);
}
