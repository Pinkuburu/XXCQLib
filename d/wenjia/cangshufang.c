// Room: cangshufang.c
// Created by Zeus 1999.3.28
// Modified by Zeus 1999.4.10
// 修改长描述。
// 

inherit ROOM;

string* books = ({
        "handbook",
        "forcebook",
        "bladebook",
        "swordbook",
        "dodgebook",
        "laozi",
        "lunyu",
        "sanzijing",
});

void create ()
{
        set ("short", "藏书房");
        set ("long", @LONG
这里有一排一排得书架，里面收藏得书有关于学问的和关于
武功的。北面是学堂。
LONG);
        set("area","岭南");
        set("exits", ([
                "north" : __DIR__"xuetang",
        ]));

        set("objects", ([
                __DIR__"obj/"+books[random(sizeof(books))] : 1,
                __DIR__"obj/"+books[random(sizeof(books))] : 1,
                __DIR__"obj/"+books[random(sizeof(books))] : 1
        ]));

        setup();
        replace_program(ROOM);
}
