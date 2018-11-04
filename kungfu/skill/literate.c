// literate.c

inherit SKILL;
#include <ansi.h>

string type() { return "knowledge"; }

void skill_improved(object me)
{	switch(me->query_skill("literate",1))
	{
		case 30:
		{
			write(HIY"你已经过了识字启蒙的阶段，已经有一定的基础了，也许
自己读书提高的会更快一点。\n"NOR);
			break;
		}
		case 110:
		{
			write(HIC"恭喜你，这寒窗苦读的时期差不多过去了，为什么不试试
进京赶考呢？也许可以种状元呢！\n"NOR);
			break;
		}
		case 200:
		{
			write(HIW"佩服佩服！你在文学方面已经达到了融会贯通的阶段，从
此后可以自己提高了。\n"NOR);
			break;
		}
	}
}

int valid_learn(object me)
{
	return 1;
}