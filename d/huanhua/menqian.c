// by mulan

inherit ROOM;

void create ()
{
        set ("short", "黄河小轩门前");
        set ("long", @LONG
黄河小轩门前，也有一人在低着头，屈着腰，在扫着地，很小心很小心
地在扫着地，好像扫地是一件很伟大很专注的工作一般，天下间谁也不
能惊扰他去做这件事.
LONG);

        set("exits", 
        ([
                "north" : __DIR__"huanghe",
         "south" : __DIR__"qqlang_1",
        ]));
        set("objects", ([
                "/d/huanhua/npc/guang" : 1,
       ]));

        setup();
}
