//sleep转化为user身上的一个函数了int sleep()
//Write by JackyBoy@Cuterabbit Studio 1999/6/6
int main(object me)
{
	me->sleep();
	return 1;
}

int help()
{
	write(
@HELP	
这个命令可以让你在可以睡觉的地方睡觉，在旅馆可以连续睡觉，在非旅馆或非可以睡觉的房间
里只有“丐帮”的人才可以睡，如果不是在旅馆里，三分钟内不能连续睡觉，否则不能起到补充
精气的效果，反而有损身体健康。
HELP
);
	return 1;
}

