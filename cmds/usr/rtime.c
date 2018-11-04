// rtime.c
inherit F_CLEAN_UP;
int main(object ,string arg)
{
	int i;

	if(!arg||sscanf(arg,"%d",i)!=1)
		i=1;
	write("现在是" + CHINESE_D->chinese_time(i,(string)localtime(time())) + "。\n");
	return 1;
}

int help()
{
     write(@HELP
指令格式: rtime

这个指令让你(你)知道现在的实际时间。
可以带参数1-6以不同的格式显示。

HELP
    );
    return 1;
}

