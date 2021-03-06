// 饲养宠物指南！
// By 山猫Adx @ snow 99-12-12

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"饲养宠物"NOR, ({ "pet book", "book" }));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("value", 0);
		set("long", "这是一本教你怎么饲养宠物的小册子！\n"
			+"你可以一页一页的往下看：kan <p1>\n\n"
			+"p1	第一页	购买你喜欢的宠物\n"
			+"p2	第二页	设定好你的宠物\n"
			+"p3	第三页	饲养你的宠物\n"
			+"p4	第四页	教会你的宠物武功\n"
			+"p5	第五页	对你的宠物下命令\n");
	}
}

void init()
{
	add_action("do_kan","kan");
}

int do_kan(string arg)
{
	if( !arg ) return notify_fail("指令格式：du <p1>|<p2>|<p3>。\n");
	
        switch( arg ) {
                case "p1":
	return notify_fail("		第一页	购买你喜欢的宠物\n"
			+"	你要先找到那个贩卖宠物的小贩，他经常在汴梁附近走动。\n"
			+"每只宠物要一百两黄金。饲养宠物重要的是你要怎样去培养它，让\n"
			+"他成为你的战斗帮手，如果饲养得不好反而成为你的累赘！\n"
			+"找到小贩后，你拿出一百两黄金给他，然后按部就班输入你要什么\n"
			+"宠物！最后输入你要的宠物的性别。最后吹声口哨，你的宠物就会\n"
			+"跑到你的跟前！再吹声口哨，你的宠物就消失了！如果你不想要你\n"
			+"的宠物了就带它到肉铺的大胡子屠夫哪里让他杀了<sha>。\n\n"
			+"例如：你想要一只雄性的宠物狗，操作步骤是：\n"
			+"give xiaofan 100 gold\n"
			+"answer 小狗\n"
			+"answer 雄性\n"
			+"whistle\n"
			+"最后查看一下你宠物的状态：<status>\n");
		case "p2":
	return notify_fail("		第二页	设定好你的宠物\n"
			+"	你可以像设定你自己一样给你的宠物设定title、nick、long。\n"
			+"例如：你要设定你的宠物为\n"
			+YEL"  一条凶狠的狼狗"NOR+"「"+WHT"江湖恶霸之帮凶"NOR+"」"
				+"山猫的宠物狗(Adx's dog)\n"
			+"操作步骤是：\n"
			+"  shezhi title $YEL$一条凶狠的狼狗\n"
			+"  shezhi nick $WHT$江湖恶霸之帮凶\n");
		case "p2":
	return notify_fail("		第二页	设定好你的宠物\n"
			+"	你可以像设定你自己一样给你的宠物设定title、nick、long。\n"
			+"例如：你要设定你的宠物为\n"
			+YEL"  一条凶狠的狼狗"NOR+"「"+WHT"江湖恶霸之帮凶"NOR+"」"
				+"山猫的宠物狗(Adx's dog)\n"
			+"操作步骤是：\n"
			+"  shezhi title $YEL$一条凶狠的狼狗\n"
			+"  shezhi nick $WHT$江湖恶霸之帮凶\n");
		case "p3":
	return notify_fail("		第三页	饲养你的宠物\n"
			+"	你的宠物当然也会饿，你要喂它食物。方法是把它带到你可\n"
			+"以装水的地方，然后就可以喂它食物和水了。如果你不是带它去正\n"
			+"确的地方就喂食，会它会产生对你的不满。你长时间不喂食宠物也\n"
			+"产生不满，当它对你很不满时，就不听从你的指令了。但是你的宠\n"
			+"物毕竟还是你的，你只要多喂它吃些东西，它就会对你很温顺啦！\n"
			+"操作步骤是：\n"
			+"  wei food\n"
			+"  wei water\n");
		case "p4":
	return notify_fail("		第四页	教会你的宠物武功\n"
			+"	要让你的宠物成为你的好帮手，除了要让它服从你的指令外\n"
			+"还要教会它武功。它能学会战斗攻击，和战斗防御这些。\n"
			+"例如：你要教会它战斗攻击\n"
			+"操作步骤：\n"
			+"  lianxi gongji\n");
		case "p5":
	return notify_fail("		第五页	对你的宠物下命令\n"
			+"	下面是你能对你的宠物下达的其他指令！\n"
			+"攻击(adx)	gongji adx \n"
			+"跟着(adx)	gen adx\n"
			+"停止跟随	gen none\n"
			+"还有别忘了设置宠物的wimpy哦！指令格式：shezhi wimpy <40>\n"
			+"以上五页是宠物的基本介绍，呢么赶快去领养一只吧！\n");
		default:
	return notify_fail("没有这一页！\n");
	}
}
