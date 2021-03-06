#include <ansi.h>
 
inherit F_CLEAN_UP;
int time_period(int, object);
int main(object me)
{
	int nowtime = time();
	mapping quest;
	if(!(quest =  me->query("quest")))
		return notify_fail("你现在没有任何任务！\n");
	switch(quest["quest_type"])
	{
	case "送":
		write("你现在的任务是送『" + quest["quest_obj_name"] + 
			"("+quest["quest_obj_id"]+")』给『"+quest["quest_npc_name"]+
			"("+quest["quest_npc_id"]+")』。\n");
		break;
	case "寻":
		write("你现在的任务是寻『" + quest["quest_obj_name"] + 
			"("+quest["quest_obj_id"]+")』。\n");
		break;
	case "杀":
		write("你现在的任务是杀『" + quest["quest_npc_name"] + 
			"("+quest["quest_npc_id"]+")』。\n");
		break;
	default:
		write("没有这种任务的，请向巫师报告出错！\n");
	}
	nowtime = (int) me->query("task_time") - time();
	if( nowtime  > 0 )
		time_period(nowtime, me);
	else
		write("但是你已经没有足够的时间来完成它了。\n");
	return 1;
}

int time_period(int timep, object me)
{
	int t, d, h, m, s;
	string time;
	t = timep;
	s = t % 60;             t /= 60;
	m = t % 60;             t /= 60;
	h = t % 24;             t /= 24;
	d = t;
	if(d) 
		time = chinese_number(d) + "天";
	else 
		time = "";
	if(h) time += chinese_number(h) + "小时";
	if(m) time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";
	tell_object(me,"你还有" + time + "去完成它。\n");
	return 1;
}
 
int help()
{
        write(@HELP
指令格式 : quest  这个指令可以显示出你当前的任务。
HELP
        );
        return 1;
}
