#include <ansi.h>
inherit ITEM;
void init()
{
        add_action("do_fang","fang");
}

void create()
{
        set_name("����佻����", ({ "shen jian", "jian" }) );
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "֧");
        set("value", 0);
        set("no_give","���.....");
        set("jian",5) ;
        set("material", "��");
        set("times",10);
        set("long", "����һ��佻�����������������Ѷ�ŵĹ��ߡ�\n"
 	"ֻҪfang jian �ͻᷢ������������ź�!\n") ;
        }
        setup();
}

int do_fang(string arg)
{
          object me,ob;
      mapping fam;
      ob = this_object();
    me = this_player();
    if( !arg || arg !="jian") return 0;
      if(ob->query("times")<1)
        {  message_vision("����!,�������Ѿ�������!\n",me,ob);
      destruct(ob);
        return 1;
        }
      fam = me->query("family");
        if ( fam = ob->query("family") || fam["family_name"] != "佻�����")
      return 0;
    message_vision(HIW "\n$N�Ի����ͳ�佻�������ַ�����������쬵�һ�������ϰ�գ���ر���ǧ����������!\n"NOR, me);
      message("channel:party", HIG"��佻����ɡ���"+this_player()->query("name")+"��"+environment(me)->query("short")+"���������ź�!\n"NOR, users());
    me->start_busy(2);	
      ob->set("times",ob->query("times") -1);
   return 1;
}
	