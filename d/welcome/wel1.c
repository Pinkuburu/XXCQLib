//注册房间 感谢Bigfoot@SDXL的支持和帮助
//JackyBoy@CuteRabbit Studio for CCTX 1999/5/16

#include <mudlib.h>
#include <ansi.h>

inherit REGROOM;

void create()
{
    set("short",  CHINESE_MUD_NAME+"注册处" );
    set("long", 
    NOR"欢迎光临"+CHINESE_MUD_NAME+"的注册处。\n"+
    "请你先阅读注册须知("HIR"输入look notes命令"NOR")。\n"+
    "并请仔细阅读江湖规则("HIR"输入look rules命令"NOR")。\n"+
    "如果你同意江湖规则，则请你注册你的电子邮箱地址：\n"+
    "("HIR"register 电子信箱地址"NOR")\n"+
    "("HIR"zhuce 电子信箱地址"NOR")\n"+
    "否则请你输入"HIR"suicide -f"NOR"命令退出江湖。\n"+
    "\t\t\t\t"+CHINESE_MUD_NAME+"巫师公会\n"+
    "\t\t\t\t\t\t"+"一九九九年九月九日\n"
        );
	set("exits",([
		"开始游戏":"/d/bianliang/guangming",
	]));
	set("no_fight", 1);
	setup();
}

void init()
{
	::init();
	add_action("do_read","look");
	add_action("do_read","l");
}

int do_read(string arg)
{
	switch(arg)
	{
		case "notes":
			write(
				"请务必输入正确的电子信箱地址，以确保注册信件能正确送到你手里。\n"+
				"如果你没有得到注册密码，请以原来的密码登录重新注册。\n"+
				"有问题请与巫师联系，并尽量到主页上留言。\n"+
				"snowmud@126.com\n"+
				"snowmud@soim.net\n"
				);
			break;
		case "rules":
			write(
				"请输入help 来获取详细的游戏规则。请勿违反，违反必究。\n"+
				"如果你不同意规则，请与巫师联系或输入suicide -f退出江湖。\n"
				);
			break;
		default:
			return 0;
	}
	return 1;
}
