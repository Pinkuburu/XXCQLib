// save.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
	object link_ob;

	seteuid(getuid());

	if( !objectp(link_ob = me->query_temp("link_ob")) )
	{
		if(!objectp(me->query_temp("link_ob1")))
			return notify_fail(HIY"你未经正常连线进入，不能存储！\n"NOR);
		else
		{
			write("启用备用连线物件！\n");
			link_ob=me->query_temp("link_ob1");
			me->set_temp("link_ob",link_ob);
		}
	}

	if( environment(me)->query("valid_startroom") ) {
		me->set("startroom", base_name(environment(me)));
		write(HIY"当你下次连线进来时，会从这里开始。\n"NOR);
	}

	if( (int)link_ob->save() && (int)me->save() ) {
        write(HIY"档案储存完毕。\n"NOR);
		return 1;
	} else {
		write("储存失败。\n");
		return 0;
	}
}

int help()
{
	write(@HELP
指令格式：save

把你辛苦奋斗的结果存起来。
HELP
	);
	return 1;
}
