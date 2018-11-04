// liangong-fu.c

inherit ITEM;
#include <ansi.h>

int do_jin(string);
int do_cuo(string);
int do_tou(string);

void create()
{
	set_name(YEL"���·�"NOR, ({ "zang yifu", "zang", "yifu", "cloth" }));
	set("long", "����һ�����·�������Խ�����ȥ�ӱ߽�ʪ(jin)��Ȼ���һ\n��(cuo)������ɾ��˾�Ͷ����(tou)�·��͸ɾ��ˡ�\n");
	set("jobnum", "0");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("no_drop", "�ӵ����ǻᰤ��ģ��������˰ɡ�\n");
		set("no_give", "��ô������Ķ��������˲���Ц���𣿡�\n");

	}
	setup();
}

void init()
{
	add_action("do_jin", "jin");
	add_action("do_cuo", "cuo");
	add_action("do_tou", "tou");
}

int do_jin(string arg)
{
	object ob, me;
	me = this_player();
	ob = this_object();

	if (!environment(me)->query("hhjob"))
	{
		return notify_fail("����ط�û��ˮ����ôϴ�·���\n");
	}
	else if ( this_player()->is_busy() )
	{
		return notify_fail("����һ��������û����ɡ�\n");
	}
	else if ((ob->query("jobnum"))=="1")
	{
		return notify_fail("���·��Ѿ���ʪ�ˣ���ʼ��ɡ�\n");
	}
	else if ((ob->query("jobnum"))=="2")
	{
		return notify_fail("���·��Ѿ�����ˣ�����ͶͶ�ɡ�\n");
	}
	else if (me->query("jingli")<15)
	{
		return notify_fail("���Ѿ�����,����Ъ��ɡ�\n");
	}
	else
	{
		message_vision(CYN"$N�����·��򿪣��ŵ�Ϫˮ�������һ����ʪ�ˡ�\n"NOR, me);
		ob->set("jobnum","1");
	}
	me->add("jingli", -(5+random(10)));
	return 1;
}

int do_cuo(string arg)
{
    object ob, me;
	me = this_player();
	ob = this_object();

	if (!environment(me)->query("hhjob"))
	{
		return notify_fail("����ط�û��ϴ�·���\n");
	}
	else if ( this_player()->is_busy() )
	{
		return notify_fail("����һ��������û����ɡ�\n");
	}
	else if ((ob->query("jobnum"))=="0")
        message_vision(HIW"$N�����·�û��ʪ�ʹ�������������·����ư���\n"NOR, me);
	else if ((ob->query("jobnum"))=="2")
	{
		return notify_fail("���·��Ѿ�����ˣ�����ͶͶ�ɡ�\n");
	}
	else if (me->query("jingli")<15)
	{
		return notify_fail("���Ѿ�����,����Ъ��ɡ�\n");
	}
	else
	{
		int a;
		a = random(100);
        if ( a >65)
		{
			message_vision(HIC"$N���·����˼��£����������˿�������ɾ��ˡ�\n"NOR, me);
			ob->set("jobnum","2");
		}
		else
		{
			message_vision(CYN"$N�����·��ŵ�ʯͷ�Ϸ����Ĵ���������һ�¡����¡�\n"NOR, me);
			me->start_busy(1 + random(1));
		}
	}
	me->add("jingli", -(5+random(10)));
	return 1;
}

int do_tou(string arg)
{
	object ob, me, ob2;
	me = this_player();
	ob = this_object();

	if (!environment(me)->query("hhjob"))
	{
		return notify_fail("����ط�û��ϴ�·���\n");
	}
	else if ( this_player()->is_busy() )
	{
		return notify_fail("����һ��������û����ɡ�\n");
	}
	else if ((ob->query("jobnum"))=="0" || (ob->query("jobnum"))=="1")
	{
		return notify_fail("�·�ûϴ��ҪͶ����ʲô��ѽ��\n");
	}
	else if (me->query("jingli")<15)
	{
		return notify_fail("���Ѿ�����,����Ъ��ɡ�\n");
	}
	else
	{
		int b;
		b = random(100);
		if (b<5)
		{
			message_vision(HIW"$Nһ��С�ģ��·���Ȼ��Ϫˮ���ˣ��������ǰ�ϴ�ˡ�\n"NOR, me);
			me->set_temp("jobcloth", "3");
			destruct(ob);
		}
		else
		{
			message_vision(HIG"$N��ϴ�õ��·�Ͷ��Ͷ������·���ϴ���ˣ�Ӧ�ÿ����û�ȥ�����ˡ�\n"NOR, me);
			me->set_temp("jobcloth", "2");
			ob2 = new("/d/huanhua/npc/obj/jobcloth2");
			ob2->move(me);
			destruct(ob);
		}
	}
	me->add("jingli", -(5+random(10)));
	return 1;
}