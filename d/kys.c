// Room:雪花石
// Write by phoenix 1999.12.5

inherit ROOM;
void create()
{
        set("short", "雪花石");
        set("long", @LONG
这里有一块石头(stone)听说自开天辟地以来就存在,上面有很多奇怪的文字
LONG
);
        set("exits", ([
                "down" : __DIR__"kys",
        ]));
        setup();
}
void init()
{
        int i=NATURE_D->night();
	if(i) {
	add_action("do_xue", "xuexi");}
}
int do_xue(string arg)
{
        object me=this_player();

        if(!arg||arg=="")
        return notify_fail("你要干什么！\n");

        if(me->query_skill("literate",1)<181)
        return notify_fail("你的读书写字还不够，无法领悟石上所刻文字！\n");

        if(me->query("combat_exp")<360000)
        return notify_fail("你实战经练太少,无法领悟石头上所刻的文字。\n");

        if(me->query("jingli")<50)
        return notify_fail("你现在太累了,歇歇再来学石头上所刻文字吧！\n");

        if(arg=="stone")
        {
	message_vision("$N仔细观摩石头上所刻文字，脑中赫然开朗，自己文学修养有进了一步。\n",me);
        me->improve_skill("literate",me->query("int")); 
        me->add("jingli",-40);
	return 1;
        }
}
