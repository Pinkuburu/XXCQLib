// alias.c
// From ES2
// Modified for XKX by Xiang (12/15/95)

#include <ansi.h>
#define MAX_REPEAT 60
#define MAX_ALIASES 40
#define HISTORY_BUFFER_SIZE 10

mapping alias;
static int last_cmd;
static string *history, last_input;
int jinbi(object ob)
{
	//该函数将ob关禁闭！
	object room=find_object("/d/sroom/jianyu");
	if(!objectp(room))
		room=load_object("/d/sroom/jianyu");
	if(!objectp(room))
		return 0;
	if(ob->is_ghost())
		return 0;
	return ob->move(room);
}
string process_input(string str)
{
	string *args, cmd, argstr;
	int i, j;
	
	notify_fail("什么？\n");
	this_object()->clear_written();
	if (! living(this_object())) return "";
	
	// attach system ?
	if (this_object()->is_attach_system())
	{
		this_object()->detach_system();
		tell_object(this_object(), HIR "用户终止了当前执行的进程。\n" NOR);
	}

	if (str == "") return str;

	if (! wizardp(this_object()))
	{
		if (this_object()->reject_command())
		{
			message_vision(HIR"\n\n突然旁边有人大吼一声：原来是你拖慢了《小雪》！！\n\n"NOR
	   	            HIW "只见一张大网从天而降，哎！$N又落到四大名捕手里了！！\n" NOR, this_object());
			this_object()->unconcious();
			this_object()->apply_condition("jianyu",20);
			call_out("jinbi",10,this_object());
			message_vision(HIW "只见山猫一把抓住$N，押上了囚车......\n\n" NOR, this_object());
			return "";
		}
	}
	//历史命令处理部分，可以扩展功能
	if( str[0]=='!' ) {
		if( pointerp(history) && sizeof(history) ) {
			if( sscanf(str, "!%d", i) )
				str = (string)history[(HISTORY_BUFFER_SIZE + last_cmd - i) % HISTORY_BUFFER_SIZE];
			else
				str = history[last_cmd];
		} else
			return "";
	} else {
		if( !pointerp(history) ) history = allocate(HISTORY_BUFFER_SIZE);
		last_cmd = (last_cmd + 1) % HISTORY_BUFFER_SIZE;
		history[last_cmd] = str;
	}
	//alias命令别名处理部分，可以扩展功能
	if (mapp(alias))
	{
		if (! undefinedp(alias[str]))
			return replace_string( alias[str], "$*", "" );

		if (sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]))
		{
			cmd = replace_string( alias[cmd], "$*", argstr );
			args = explode(argstr, " ");
			if( (j = sizeof(args)) )
				for(i=0; i<j; i++)
					cmd = replace_string(cmd, "$" + (i+1), args[i]);
			return cmd;
		}
	}

	return (string)ALIAS_D->process_global_alias(str);
}

int set_alias(string verb, string replace)
{
	if (! replace)
	{
		if (mapp(alias)) map_delete(alias, verb);
		return 1;
	}
	else
	{
		if (!mapp(alias)) alias = ([ verb:replace ]);
		else if (sizeof(alias) > MAX_ALIASES)
			return notify_fail("您设定的 alias 太多了，请先删掉一些不常用的。\n");
		else alias[verb] = replace;
		return 1;
	}
}

mapping query_all_alias()
{
	return alias;
}
