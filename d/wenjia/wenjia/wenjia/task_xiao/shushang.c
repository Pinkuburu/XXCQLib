// Room: shushang.c
// Created by Zeus 1999.7.17
// Modified by Zeus 1999.6.17
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "树上");
        set ("long", @LONG
这里是一片树林的树顶。树枝茂密得可以在上面站稳，但是轻功不好
的人还是会掉下来。
LONG);
        set("area","岭南");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        setup();
        replace_program(ROOM);
}
