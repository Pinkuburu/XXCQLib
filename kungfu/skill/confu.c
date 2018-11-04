// confu.c 儒家思想
// By Star

inherit FORCE;

int valid_learn(object me)
{
	if ( me->query_skill("buddha",1)
	|| me->query_skill("tao",1))
		return notify_fail("儒、释、道三家互不相容，你还在信仰别家思想，怎么学习儒家理论？！\n");

	return 1;
}