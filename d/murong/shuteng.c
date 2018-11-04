// shuteng.c

#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",GRN"树藤"NOR);
         set("long",@long
这里长满了树藤，一枝一枝的树藤(teng)遮住了阳光，树藤盘根错节,你
只能在树藤上爬上爬下。
long);
         set("item_desc",([
         "teng" : "树藤遮住了阳光，几乎没有一点光线，使你极力的拨开藤枝(zhi)。\n",
]));
         setup();
}           

void init()
{
        add_action("do_move", "pa");
        add_action("do_move", "move");
        add_action("do_bo", "bo");    
}                                    

int do_move(string arg)
{
        object me;
        me = this_player();
        if (arg !="down")
        return notify_fail("你要往那里爬？\n");
        if (arg == "down")
        message_vision("$N小心地攀住树藤，向下爬去。\n" , me);
        me->move(__DIR__"hhyuan");                            
        message("vision", "$N小心地攀住树藤，爬了下来。\n" , environment(me), ({me}));
        return 1; 
}                                     

int do_bo(string arg)
{
        object me;
        me = this_player();
        if (arg !="teng")
        return notify_fail("你要干什么？\n");
        if (arg =="teng")
        write("你拨开树藤，勉强露出一丝阳光，这时你看到一片盛开的桃花。\n");
        return 1;
}

