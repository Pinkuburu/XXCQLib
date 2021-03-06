// xupdate.c 
//write by JackyBoy@CuteRabbit Studio for SDXL & CCTX 1999/6/2
inherit F_CLEAN_UP;
int help();
int UpdateDir(object,string );
int update_player(object);
int UpdateFile(object,string );
static int flag,encode; //判断是否终止递归调用，并限制递归层数(只允许低于16层的调用)

int main(object me, string file)
{
	object obj;
	string tmp,path;
	seteuid(geteuid(me));
	write("X update 命令 v0.1  \nWrite By JackyBoy@CuteRabbit for CCTX & SDXL 1999/7/20\n"+
		"主页：http://mud.yn.cninfo.net/jackyboy\n邮件：jackyboy@126.com\n");
	if (!file) file = me->query("cwf");
	if (!file)
		return notify_fail("你要重新编译什麽档案？\n");
	
	//在这里解析开关选项
	if(sscanf(file,"-d%d %s",flag,file)!=2)
	{
		if(sscanf(file,"-d %s",file)==1)
		{
			flag=15;
			encode=1;
		}
		else
		{
			encode=0;
			if(sscanf(file,"-%d %s",flag,file)!=2)
				flag=15;
		}
	}
	else
	{
		encode=1;
	}
	if(flag>15) flag=15;
	if(flag<0) flag=0;
	
	if( (obj = present(file, environment(me))) && interactive(obj) )
		return update_player(obj);
	if( file == "me" )
		return update_player(me);
	if( lower_case(file) == "here")
		file = base_name(environment(me));
	file=resolve_path(me->query("cwd"),file);
	tmp=file;
	path=resolvePath(file,1);
	foreach(file in get_dir(tmp))
	{
		write("重新载入"+path+file+"中...");
		if(sscanf(file,"%*s.c.bak")||!sscanf(file,"%*s.c"))
		{
			write("不是可载入的程序文件！\n");
			continue;
		}
		switch(file_size(path+file))
		{
			case -1:
				write("对不起，你无权载入这个目录(或文件)："+path+file+"。\n");
				break;
			case -2:
				write("载入"+path+file+"中...");
				if(UpdateDir(me,path+file)==0)
					write("载入失败。\n");
				else
					write("载入成功。\n");
				break;
			default:
				if(UpdateFile(me,path+file))
					write("完成。\n");
				else
					write("失败。\n");
		}
	}
	return 1;
}

int UpdateDir(object me,string file)
{
	string tmp;
	if(flag>15)
		return 0;
	reset_eval_cost();
	switch(file_size(file))
	{
		case -1 : 
			flag=16;//设置出错中断
			write("部分文件("+file+")无权载入，错误！\n");
			return 0;
			break;
		case -2 :
			//载入此目录下的文件和目录
			if(file[sizeof(file)]!='/')
				file=file+"/";
			if(sscanf(file,"%*s/.")||sscanf(file,"%*s/.."))
				return 1;
			foreach(tmp in get_dir(file))
			{
				if(!UpdateDir(me,file+tmp))
				{
					flag=16;//中断，因为载入出错
					return 0;
				}
			}
			break;
		default :
			if(!UpdateFile(me,file))
			{
				write("文件"+file+"重新载入出错！\n");
				flag=16;//中断，因为载入出错
				return 0;
			}
			break;
	}
	return 1;
}

int UpdateFile(object me,string file)
{
	string bfile,err;
	int i;
	object obj,*inv;
	if( !sscanf(file, "%s.c",bfile) )
	{
		bfile="/binaries"+file+".b";
		file += ".c"; 
	}
	else
		bfile="/binaries"+bfile+".b";
	if( file_size(file)==-1 )
		return notify_fail("没有这个档案。\n");
	if( file_size(bfile)!=-1&&encode)
	{
		rm(bfile);
	}
	me->set("cwf", file);
	if (obj = find_object(file)) {
		if( obj==environment(me) ) {
			if( file_name(obj)==VOID_OB )
				return notify_fail("你不能在 VOID_OB 里重新编译 VOID_OB。\n");
			inv = all_inventory(obj);
			i = sizeof(inv);
			while(i--)
				if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1);
				else inv[i] = 0;
		}
		destruct(obj);
	}
	if (obj) return notify_fail("无法清除旧程式码。\n");

    err = catch( call_other(file, "???") );
	if (err)
	{
		printf( "发生错误：\n%s\n", err );
		return 0;
	}
	else 
	{
		if( (i=sizeof(inv)) && (obj = find_object(file))) 
		{
			while(i--)
				if( inv[i] && userp(inv[i]) ) inv[i]->move(obj, 1);
		}
	}
	//再次删除该.b文件
	if( file_size(bfile)!=-1&&encode)
	{
		rm(bfile);
	}
	return 1;
}
	
int update_player(object me)
{
	object env, link_ob, obj;

	env = environment(me);

	// First, create the new body.
	link_ob = me->query_temp("link_ob");
	if(!objectp(link_ob))
		return notify_fail("query_temp(link_ob)错误!\n");
	if(!link_ob->query("body"))
		return notify_fail("query link_ob's body prop error!\n");
	write("body file: "+link_ob->query("body")+"\n");
	obj = LOGIN_D->make_body(link_ob);
	if (!obj) return 0;

	// Save the data and exec the player to his/her link object.
	me->save();
	exec(link_ob, me);
	destruct(me);

	// Restore new body and exec to it via enter_world in LOGIN_D
	obj->restore();
	LOGIN_D->enter_world(link_ob, obj, 1);

	write("身体更新完毕。\n\n");
	obj->move(env);
	obj->write_prompt();

	return 1;
}

int help()
{
  write(@HELP

X update 命令 v0.1
Write By JackyBoy@CuteRabbit for CCTX & SDXL 1999/7/20
主页：http://mud.yn.cninfo.net/jackyboy
邮件：jackyboy@126.com


指令格式 : xupdate <档名>
此指令可让你载入有权读取的档案，并可以载入带目录的档案。
注意：此命令会造成系统占用大量内存，请仅在调试期间使用该命令。
HELP
    );
    return 1;
}
