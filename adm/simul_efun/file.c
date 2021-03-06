// file.c

void cat(string file)
{
	seteuid(geteuid(this_player()));
	write(read_file(file));
}

void log_file(string file, string text)
{
	write_file(LOG_DIR + file, text);
}

void assure_file(string file)
{
	string path, *dir;
	int i;

	if( file_size(file)!=-1 ) return;

	seteuid(ROOT_UID);
	dir = explode(file, "/");

        if (file[strlen(file) -1] != '/')
                // the file is refer to a file, not directory
	        dir = dir[0..sizeof(dir)-2];

	path = "/";
	for(i=0; i<sizeof(dir); i++) {
		path += dir[i];
		mkdir(path);
		path += "/";
	}

        dir = 0;
}
string base_name(object ob)
{
	string file;

	if( sscanf(file_name(ob), "%s#%*d", file)==2 )
		return file;
	else
		return file_name(ob);
}

string resolvePath(string path,int op)
{
	string *dn,tmp;
	int i;
	if(path=="/")//对这个情况特殊处理
		return (op)?"/":"*";
	dn=explode(path,"/");
	if(op)//op为非0表示需要返回路径
	{
		//dn=dn-({dn[sizeof(dn)-1]});
		//tmp=implode(dn,"/")+"/";
		//上面的程序不好，不能对同名路径正确处理，比如不能在/log/log文件里搜索
		tmp="/";
		for(i=0;i<sizeof(dn)-1;i++)
		{
			//write("合并"+dn[i]+"\n");
			tmp+=dn[i]+"/";
		}
		return tmp;
	}
	else
		return dn[sizeof(dn)-1];
}
