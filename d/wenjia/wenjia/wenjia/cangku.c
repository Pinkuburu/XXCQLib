// Room: cangku.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�ֿ�");
        set ("long", @LONG
�����ǻ��ֺ��ղ������ƵĽⶾҩ�ĵط�������һ�㶼�ǲ��ܸ��˽�
���ġ�
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("exits", ([
                "north" : __DIR__"yanjiushi",
        ]));
        setup();
        replace_program(ROOM);
}