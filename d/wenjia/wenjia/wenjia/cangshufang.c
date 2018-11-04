// Room: cangshufang.c
// Created by Zeus 1999.3.28
// Modified by Zeus 1999.7.22
// 
// 

inherit ROOM;

string* books = ({
        "forcebook",
        "dodgebook",
        "lphandbook",
});

void create ()
{
        set ("short", "藏书房");
        set ("long", @LONG
这里有一排一排得书架，里面收藏得书有关于学问的和关于武功的。
北面是学堂。
LONG);
        set("area","岭南");
        set("valid_startroom", 1);

        set("exits", ([
                "north" : __DIR__"xuetang",
        ]));

        set("objects", ([
                __DIR__"obj/"+books[random(sizeof(books))] : 1,
        ]));

        setup();
        replace_program(ROOM);
}
