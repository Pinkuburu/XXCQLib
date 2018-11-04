// Room: fantang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.7.13
// 
// 

inherit ROOM;

void init();
int do_zhao(string);
void delete_served(object);

void create ()
{
        set ("short", "����");
        set ("long", @LONG
�����Ƿ��á���Ϊ¯���µĲ��ͣ����ȼ�յ�ԭ�����������е�
�ȡ����������ʱҪ�ṩ��ʳ�ġ������в������ڳԷ������ǲ�ͣ�İǷ�
�������ǲ�Ը�����������ڳԷ��ϰɡ��������߶���һ���ſڣ���������
��Ϣ�ң�������Ů��Ϣ�ҡ�
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/wenchifan" : 1,
        ]));

        set("exits", ([
                "south" : __DIR__"xiaojing",
                "east" : __DIR__"nvxiuxishi",
                "west" : __DIR__"nanxiuxishi",
        ]));

        setup();
}

void init()
{
        add_action("do_zhao", "zhao");
}

int do_zhao(string arg)
{

        object me;
        object chifan;

        if (!arg || (arg != "shou" && arg != "hand"))
        {
                return notify_fail("��Ҫ��ʲô��\n");	
        }
		
        me = this_player();	
        if( !objectp(chifan = present("wen chifan", environment(me))) )
                return notify_fail("������֣�������Ǳ��������֣���������û�����㡣���ǲ��Ǻ����ģ�\n");
	 	
        if( me->query_temp("marks/served") )
        {
                message_vision("�³Է���$N˵�����ոո����Ϲ��ˣ���ô����꣬С�����θ��\n", me);
                return notify_fail("");
        }

        message_vision("$N������ǰ�������֣�������Ǳ��������֣��³Է��첽�߹����к��㡣\n", me);
 
        chifan->serve_tea(me) ;

        me->set_temp("marks/served", 1);
//      remove_call_out("delete_served");
        call_out("delete_served", 10, me);

        return 1;
}


void delete_served(object me)
{
        if ( objectp(me) ) me->delete_temp("marks/served");
}

int valid_leave(object me, string dir)
{
        object *obj;
        int i;

        me=this_player();

        if (dir == "west" && ((string)me->query("gender") =="Ů��") )
                return notify_fail("���²��³�һ������ﵽ�����ǵĵط�ȥ����\n");

        if (dir == "east" && ((string)me->query("gender") =="����") )
                return notify_fail("������վס��������ȥ���˹뷿����\n");

        if (  ((dir == "south") || (dir == "west") || (dir == "east") )
                && ( present("zhu", this_player())
                || present("tea", this_player()) || present("ji", this_player()) ))
        {
        message_vision("����������涨�����ǲ��ܴ������õģ����Զ��Ծ��İ������ȥ�Ķ������¡�\n", me);
        obj=all_inventory(me);
        for (i=0;i<sizeof(obj);i++){
                if (obj[i]->query("id")=="tea" || obj[i]->query("id")=="ji" ||
                    obj[i]->query("id")=="zhu" ) destruct(obj[i]);
                }
        }
        return ::valid_leave(me, dir);
}