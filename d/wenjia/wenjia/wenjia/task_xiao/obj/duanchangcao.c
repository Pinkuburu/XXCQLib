// Item duanchangcao.c
// Created by Zeus 1999.7.31
// Modified by Zeus 1999.7.31
// 
// 

inherit ITEM;

void init();
int do_eat(string arg);

void create()
{
        set_name( "�ϳ���",({ "duanchangcao"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�öϳ��ݡ�\n");
                set("value", 10000);
                set("material", "");
        }
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me;
        me=this_player();
        message_vision("$N����һ�öϳ��ݣ��ֽ������˼��£��ж����ˡ�",me);
        me->die();
        destruct(this_object());
        return 1;
}
