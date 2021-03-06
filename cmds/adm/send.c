//Write By JackyBoy @ ludos 2000/6/24
#include <net/dns.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <net/socket_errors.h>
#include <socket_err.h>

inherit F_DBASE;

static int my_socket=0;

//程序中一旦出现错误就直接返回出错信息
int do_connect(string arg);
int write_message(string arg);
int close_socket();
void chat(string arg,string opt);
void write_callback(int fd);
void read_callback(int nouse,mixed message);

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string ip,msg;
	int port;
	if(!arg||arg==""||sscanf(arg,"%s %d %s",ip,port,msg)!=3)
		return notify_fail("Send ip port msg");
	do_connect(sprintf("%s %d",ip,port));
	if(query("connected")!=1)
		return notify_fail("无法建立连接");
	write_message("give me a kiss");
	//call_out(time_out_function);

	//如何等待呢？
}

int do_connect(string arg)
{
	int err;
	if( query("connected") )
		socket_close(my_socket);
	my_socket = socket_create( STREAM, "in_read_callback","in_close_callback" );
	if ( my_socket < 0 ) 
	{
		chat("创建socket失败。\n","debug");
		return 1;
	}
	err = socket_connect( my_socket, arg , "read_callback","write_callback" );
	if( err==EESUCCESS ) 
	{
		chat("已经连接" + arg + "\n","debug");
		set("connected",1);
	}
	else
	{
		chat("无法连接" + arg + "\n","debug");
		close_socket();
	}
	return 1;
}

int write_message(string arg)
{
	if( !arg ) arg="";
	socket_write(my_socket,arg+"\n");
	return 1;
}
int close_socket()
{
	if( query("connected") )
	{
		if( socket_close(my_socket) ) 
		{
			chat("关闭socket，恢复断线状态。\n","debug");
			delete("connected");
		}
		else
			chat("关闭socket失败。\n","debug");
	}
	else
		chat("还没有连接。\n","debug");
	my_socket=0;
	return 1;
}
void chat(string arg,string opt)
{
	CHANNEL_D->do_channel(this_object(),opt,arg);
	return;
}

void read_callback(int nouse,mixed message)
{
        message = "→" + message;
        chat( (string) message ,"sys");
        close_socket();//只收一句回应！
        
}

void write_callback(int fd)
{
        int res;
        if(query("connect"))return ;
        res = socket_write( fd,"");
        if (res == EESUCCESS || res == EECALLBACK) {
                set("connected",1);
        }
}

int help()
{
	write(@HELP
	发送指定字符串到指定IP和PORT里。
HELP
	);
	return 1;
}
