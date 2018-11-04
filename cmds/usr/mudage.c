// mudage.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int sec, min, hrs, day, mon, age;
	string out_str;
	
	age = (int)me->query("mud_age");		
	sec = age % 60;
	age /= 60;
	min = age % 60;
	age /= 60;
	hrs = age % 24;
	age /= 24;
	day = age % 30;
	mon = age / 30;
	
	out_str = (mon? chinese_number(mon)+"月":"")
		+ (day? chinese_number(day)+"天":"")
		+ (hrs? chinese_number(hrs)+"小时":"");
	
	write("你已经在《小雪初晴》的世界里生活了" + out_str + "了。\n");
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : mudage
 
让你知道自己在小雪的世界里实际生活了多久。 
HELP
    );
    return 1;
}
