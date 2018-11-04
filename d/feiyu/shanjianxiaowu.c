// Room: shanjianxianwu.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "山间小屋");
        set ("long", @LONG
这里是一个山间小村，大概是过去的山民住的吧，现在由于气氛紧张，
山民们都出山避难去了，小屋里空无一人。只剩下一些破旧的家具用品了。
看到这满布蛛网的破房，你不禁有些“无处话苍凉”的感觉。东面是一座大
山，阵阵凉风从上面吹下来,向西北走便是山谷了。
LONG);
        set("area","飞鱼");
        set("outdoors", "feiyu");

        

        set("exits", ([
                "eastup" : __DIR__"shanlu2",
                "northwest" : __DIR__"shangu2",
        ]));
        setup();
        replace_program(ROOM);
}
