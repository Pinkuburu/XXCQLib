// jifaforce.c 特殊内功
// By Star

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	return notify_fail("这是实际战斗的创造，无理无论，怎么学习？\n");
}