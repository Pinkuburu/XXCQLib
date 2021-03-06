// lead.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) return notify_fail("指令格式：lead <某人>|none。\n");

	if( arg=="none")
		if( me->query_temp("leader") ) {
			me->delete_temp("leader");
			write("你不再带领任何人行动了。\n");
			return 1;
		} else {
			write("你现在并没有带领任何人。\n");
			return 1;
		}

	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("这里没有 " + arg + "。\n");

	if( !userp(ob) )
		return notify_fail("带领" + ob->name() + "，放心！他决不会跟你走的。\n");

	if( ob==me )
		return notify_fail("带领自己？\n");

	if ( me->query_temp("leader") && me->query_temp("leader") != ob )
		tell_object(me->query_temp("leader"), me->query("name") + "改变主意，决定不再带领你行动了。\n");

	me->set_temp("leader",ob);
	message_vision("$N对$n说：“跟我来吧，我带你去你想去的地方！”\n", me, ob);
	tell_object(ob, "如果你愿意跟随" + HIG + me->query("name") + NOR + "行动，请输入follow " + me->query("id") + "。\n");

	return 1;
}

int help (object me)
{
        write(@HELP
指令格式 : lead [<生物>|none]
 
这个指令让你能带领某人或生物行动。
如果输入 lead none 则停止带领。
 
HELP
);
        return 1;
}
