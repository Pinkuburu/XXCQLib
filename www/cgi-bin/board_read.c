#include <ansi.h>
#include <mudlib.h>
#include <net/httpd.h>

#define SHOW_BOARD_HTML "/www/html/showboard.htm"
#define BOARD_CAPACITY 1024

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SAVE;

string long(int);
string short();
string read(int);
string get_menu(int);
string query_save_file();
void setup();

private mapping notes;

string gateway(string arg) {
	int bn,pn,select=0;
	string str,board;
	mapping vaild_board = "/www/cgi-bin/board_list.c"->query_boards();

	if( sscanf(arg,"%s&%d&%d",board,pn,bn) == 3 )
		select = 1;//判断是否是读取具体留言。

	if( undefinedp(vaild_board[board]) )
		return sprintf("留言板(%s)不存在。", board);

	set("board_id",board);
	setup();

	str = read_file(SHOW_BOARD_HTML);
	str = replace_string(str,"$BOARD_NAME",query("name"));
	str = replace_string(str,"$CHINESE_MUD_NAME",CHINESE_MUD_NAME);
	if( !select )
	{
		str = replace_string(str,"$LIST_INSERT", read(pn) );
		str = replace_string(str,"$MENU",get_menu(pn));
	}
	else
	{
		str = replace_string(str,"$LIST_INSERT", long(bn) );
		str = replace_string(str,"$MENU", get_menu(pn));
	}
	return str;
}

void create() {
	seteuid( geteuid() );
}

string query_save_file()
{
	string id;
	if( !stringp(id = query("board_id")) ) return 0;
	return DATA_DIR + "board/" + id;
}

void setup() {
	if( restore() )
		notes = query("notes");
	else
		notes = ([]);
}

string short()
{
	if( !pointerp(notes) || !sizeof(notes) )
		return " [ 没有任何留言 ]";

	return sprintf("[ 共 %d 张留言 ]", sizeof(notes) );
}

string get_menu(int arg)
{
	int i,bof,eof;
	string msg;mapping board;
	HTTP_DEBUG("被请求调用啦");
	eof = arg - 1;
	if( eof > sizeof(notes)-1 )
		eof = sizeof(notes)-1;
	bof = eof - 20;
	if( bof < 0 ) {
		eof = sizeof(notes) > 19 ? 19 : sizeof(notes)-1;
		bof = 0;
	}
	board="/www/cgi-bin/board_list"->query_boards();
	if(undefinedp(board[query("board_id")]))
		return "错误，版区BOARD ID不存在！";
	msg=sprintf("<a href=board_read?%s&0&%d>%s</a> | %s"
		"<a href=board_list>选择留言板</a> | "
		"<a href=board_read?%s&0&%d>%s</a> | ",
		query("board_id"),
		(bof == 0) ? 9999 : eof - 20 + 1,
		(bof == 0) ? "转到最后一页" : "上一页",
		board[query("board_id")][1]?"<a href=post?"+query("board_id")+">发表文章</a> | ":"<font color=red>(只读）无法留言</font> |",
		query("board_id"),
		eof == sizeof(notes)-1 ? 20 : eof + 20 + 1,
		eof == sizeof(notes)-1 ? "转到第一页" : "下一页");
	return msg;
}

string long(int arg)
{
	int i,bof,eof;
	string msg;

	msg = "<tr>\n<td>序号</td>\n<td>标题</td>\n<td>作者</td>\n</tr>";
	if( !pointerp(notes) || !sizeof(notes) ) return query("long");
	eof = arg - 1;
	if( eof > sizeof(notes)-1 )
		eof = sizeof(notes)-1;
	bof = eof - 20;
	if( bof < 0 ) {
		eof = sizeof(notes) > 19 ? 19 : sizeof(notes)-1;
		bof = 0;
	}

	for( i=eof; i+1>bof; i-- )
		msg += sprintf("<tr><td>%d<td><a href=board_read?%s&%d>%s</a><td>%s",
			i+1,
			query("board_id"),
			i+1,
			notes[i]["title"],
			notes[i]["author"],
			);
	return clean_color(msg);
}

string read(int arg)
{
	int num=arg;
	string body,str,myid,*msg,note_body="";

	myid = query("board_id");

	if( !pointerp(notes) || !sizeof(notes) )
		return "留言板上目前没有任何留言。";

	if( num < 1 || num > sizeof(notes) )
		return "没有这张留言。";

	num--;
	msg = explode(notes[num]["msg"],"\n");
	for( int i=0;i<sizeof(msg);i++ ) {
		note_body += sprintf("%s<br>",msg[i]);
	}

	if( note_body=="" ) note_body= "无内容。<br>";
	HTTP_DEBUG(note_body);
	body =  "<table border=1><tr><td>序号</td><td>"+(num+1)+"</td></tr>"
			"<tr><td>标题</td><td>"+notes[num]["title"]+"</td></tr>"
			"<tr><td>作者</td><td>"+notes[num]["author"]+"</td></tr>"
			"<tr><td>发表时间</td><td>"+ctime(notes[num]["time"])+"</td></tr></table>"
			"<table border=1 width=500><center><th>内容<tr><td>"+note_body+"</td>"
			"</table><br><br>";
	num ++;
	str =		"【<a href=board_read?"+query("board_id")+"&"+((num == 1) ? sizeof(notes) : num-1)+">"+
			((num == 1) ? "转到最后一篇" : "上一篇")+"</a> |"
			"<a href=board_read?"+query("board_id")+"&0&"+num+">返回"+query("name")+"</a> |"
			"<a href=board_read?"+query("board_id")+"&"+((num == sizeof(notes)) ? 1 : num+1)+
			">"+((num == sizeof(notes)) ? "转到第一篇" : "下一篇")+"</a> 】<br><br>";
	body=str+body+str;
	return clean_color(body);
}
