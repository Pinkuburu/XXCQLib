// invite.c

#include <ansi.h>
#include <net/dns.h>

//inherit F_CLEAN_UP;

void create() {seteuid(getuid());}

int main(object me, string arg)
{	object where;
	string target;
	object obj;
	if(me->query_temp("marks/主人2")||me->query_temp("marks/主人3")){
	if( !arg || sscanf(arg, "%s", target)!=1 ) return notify_fail("你要邀请什么人？\n");

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("没有这个人....。\n");
	write(HIG "你邀请" + obj->name(1) + "参加你在西城大酒楼的宴会。\n" NOR);
	tell_object(obj, sprintf( HIG "你接到%s在西城大酒楼的宴会请帖。\n" NOR,
		me->name(1)));
	where = environment(obj);
	obj->set_temp("marks/赴宴",1);
	me->set_temp("marks/邀",1);
	message("vision",obj->query("name")+"接到"+me->name(1)+"在西城大酒楼的宴会请帖。\n",where,({obj}));
	obj->set_temp("reply", me->query("id"));
	return 1;
	}return 0;
}

