// xuetang.c

#include <ansi.h>

string *reject_msg = ({
	"道可道，非常道。名可名，非常名。\n",
	"无名天地之始；有名万物之母。\n",
	"故常无，欲以观其妙；常有，欲以观其徼。\n",
	"此两者，同出而异名，同谓之玄。玄之又玄，众妙之门。\n",
	"天下皆知美之为美，斯恶已。皆知善之为善，斯不善已。\n",
	"天地不仁，以万物为刍狗；圣人不仁，以百姓为刍狗。\n",
	"天地之间，其犹橐龠乎？虚而不屈，动而愈出。\n",
	"天长地久。天地所以能长且久者，以其不自生，故能长生。\n",
	"上善若水。水善利万物而不争，处众人之所恶，故几于道。\n",
	"何谓宠辱若惊？宠为下，得之若惊，失之若惊，是谓宠辱若惊。\n",
	"故贵以身为天下，若可寄天下；爱以身为天下，若可托天下。\n",
});

string *reject_msg_2 = ({
	"空即是色、色即是空。\n",
	"佛云：我不入地狱，谁入地狱。\n",
	"断断断！四大皆空，了却一切因缘。\n",
	"般若般罗密、般若般罗密。\n",
	"菩提本无树，明镜亦非台；本来无一物，何处惹尘埃？\n",
});

int update_condition(object me, int duration)
{
	if ((int)me->query("jingli")<40)
	{
		if (me->query("family") && me->query("family/family_name")=="少林派")
			message_vision("$N实在是太疲劳了，只得跟铁庭申请中断了这次学习。\n\n", me);
		else
			message_vision("$N实在是太疲劳了，只得跟先生申请中断了这次学习。\n\n", me);
		me->apply_condition("xuetang", 0);
		me->delete_temp("xuet");
		return 0;
	}

	if( (int)me->query("learned_points") >= (int)me->query("potential") )
	{
		if (me->query("family") && me->query("family/family_name")=="少林派")
			message_vision("$N看来没有能力再学下去了，只得跟铁庭申请中断了这次学习。\n\n", me);
		else
			message_vision("$N看来没有能力再学下去了，只得跟先生申请中断了这次学习。\n\n", me);
		me->apply_condition("xuetang", 0);
		me->delete_temp("xuet");
		return 0;
	}

	me->add("jingli", ((int)me->query("int")-50));
	me->add("learned_points", 1);
	me->apply_condition("xuetang", duration - 1);
	me->improve_skill("literate", ((int)me->query("int") + random((int)me->query("int"))));
	if (me->query("family") && me->query("family/family_name")=="少林派")
		message_vision("$N合十默念："+ reject_msg_2[random(sizeof(reject_msg_2))], me);
	else
		message_vision("$N摇头晃脑的念道："+ reject_msg[random(sizeof(reject_msg))], me);

	if ( duration < 1 )
	{
		if (me->query("family") && me->query("family/family_name")=="少林派")
			message_vision("\n铁庭赞许的朝$N点点头道：阿弥陀佛，今天就到这里吧。\n\n", me);
		else
			message_vision("\n先生赞许的朝$N点点头道：好孩子，不错不错，今天就到这里吧。\n\n", me);
		me->delete_temp("xuet");
		return 0;
	}
	return 1;
}