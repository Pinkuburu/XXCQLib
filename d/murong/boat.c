// Room: /d/murong/boat.c

inherit ROOM;

int do_turn(string);
int do_save();
int do_quit();
int do_goto();
int do_home();
int do_gg();
int do_tiaowang();

void create()
{
	set("short", "船上");
	set("long", @LONG
小船已经来到了茫茫大海上。四周除了偶尔掠过头顶的海鸟外，就只剩下
你所乘坐的这艘小船和正在聚精会神地摇着橹的梢公了。海风阵阵袭来，你不
禁感到一丝凉意。
LONG
	);
	set("objects", ([
		__DIR__"npc/shaogong.c":1,
	]));
	set("no_fight",1);
	set("no_sleep_room",1);
	set("outdoors","姑苏慕容");

	setup();
}

void init()
{
	object ob = this_player();

	if (!userp(ob)) return;
	if (query_temp("busy")) {
		if (!wizardp(ob)) {
			message_vision("艄公对$N喝道：怎么？想白坐吗！\n",ob);
			message_vision("艄公一桨将$N打落到湖里。\n",ob);
			ob->unconcious();
			ob->move(__DIR__"xd");
			message("vision","忽然碧波将一个被水泡得半死的家伙冲到了岸边。\n",environment(ob),ob);
			return;
		}
		else {
			message_vision("艄公无奈地对$N说道：当巫师就是好，船都可以白坐。\n",ob);
			return;
		}
	}
	set_temp("busy", 1);
	add_action("do_turn","turn");
	add_action("do_turn","zhuan");
	add_action("do_save","save");
	add_action("do_quit","quit");
	add_action("do_goto", "goto");
	add_action("do_gg", "gg");
	add_action("do_home", "home");
	add_action("do_tiaowang","tiaowang");
	ob->delete_temp("mr_dir");
	ob->set_temp("mr_locx", 1);
	ob->set_temp("mr_locy", 1);
	
	call_out("time_limit1", 300, ob);
	call_out("location", 3, ob);
}

int abs(int num)
{
	if (num < 0) return (0 - num);
	else return num;
}

int do_save()
{
	write("这里不准存盘！\n");
	return 1;
}

int do_quit()
{
	write("这里不准退出！\n");
	return 1;
}

int do_goto()
{
	if (wiz_level(this_player()) > 0)
		delete_temp("busy");
	return 0;
}

int do_home()
{
	if (wiz_level(this_player()) > 1)
		delete_temp("busy");
	return 0;
}

int do_gg()
{
	if (wiz_level(this_player()) > 2)
		delete_temp("busy");
	return 0;
}

void time_limit1(object ob)
{
	if (!present(ob, this_object())) return;
	message_vision("艄公对$N说道：客官，湖面上看样子要起风了，我们回去吧！\n", ob);
	call_out("time_limit2", 120, ob);
}

void time_limit2(object ob)
{
	if (!present(ob, this_object())) return;
	message_vision("艄公对$N说道：客官，再划下去咱们可都要死在这里了，你不要命我还要哪！\n", ob);
	write("艄公再也不理会你的命令，径直划回了岸边。\n");
	ob->delete_temp("mr_dir");
	remove_call_out("location");
	delete_temp("busy");
	ob->move(__DIR__"xd");
	ob->delete("mr/x");
	ob->delete("mr/y");                
	ob->delete_temp("mr_locx");
	ob->delete_temp("mr_locy");	
}

int do_turn(string arg)
{
	string dir;
	object ob = this_player();

	switch(arg) {
		case "e": 
		case "east": 
			dir = "东";
			break;
		case "w": 
		case "west": 
			dir = "西";
			break;
		case "n": 
		case "north": 
			dir = "北";
			break;
		case "s": 
		case "south": 
			dir = "南";
			break;
		default:
			return notify_fail("你要往哪个方向开？\n");
	}
	ob->set_temp("mr_dir", arg[0..0]);
	message_vision("$N对艄公说：向" + dir + "开。\n", ob);
	message_vision("艄公对$N应道：好的，到了位置(location)我自然会告诉您。您要想眺望(tiaowang)也随便您。\n",ob);
	return 1;
}

int do_tiaowang()
{
	int viewdist = 4;
	object ob = this_player();

	if ((abs(ob->query_temp("mr_locx") - ob->query("mr/x"))
	+ abs(ob->query_temp("mr_locy") - ob->query("mr/y")) <= viewdist) ) 
	{
		message_vision("艄公指着远处对$N说道：客官，那边就是燕子坞了，我这就划过去。\n", ob);
		write("艄公一撑竹杆，将船慢慢地划向了岸边。\n");
		remove_call_out("time_limit1");
		remove_call_out("time_limit2");
		ob->move(__DIR__"ab1");
		delete_temp("busy");   
		ob->delete("mr/x");
		ob->delete("mr/y");        
		ob->delete_temp("mr_locx");
		ob->delete_temp("mr_locy");		
		return 1;
	}
	return notify_fail("你极目远眺，可是除了湖面上茂密的荷花外却什么也看不到。\n");
}

void location(object ob)
{
	int locx=ob->query_temp("mr_locx");
	int locy=ob->query_temp("mr_locy");
	string dir = ob->query_temp("mr_dir");

	if (!present(ob, this_object())) {
		delete_temp("busy");
		remove_call_out("time_limit1");
		remove_call_out("time_limit2");
		return;
	}
	if (!dir) {
		call_out("location", 3, ob);
		if (!random(3))
			message_vision("艄公不耐烦地对$N说：客官到底走不走啊？\n", ob);
		return;
	}
	switch (dir) {
		case "e": 
			dir = "东";
			if (locy > 0) locx++;
			break;
		case "w": 
			dir = "西";
			if (locx == 1) message_vision("艄公对$N说：客官,要撞到岸边了。\n", ob);
			if (locx > 0 && locy > 0) locx--;
			break;
		case "n": 
			dir = "北";
			if (locy == 1) message_vision("艄公对$N说：客官,要撞到岸边了。\n", ob);
			if (locy > 0 && locx > 0) locy--;
			break;
		case "s": 
			dir = "南";
			if (locx > 0) locy++;
			break;
	}
	if (locx < 1 || locy < 1) message_vision("小船停在了岸边。\n", ob);
	else message_vision("小船正向着" + dir + "方前进。\n", ob);
	if (locx == ob->query("mr/x") && locy == ob->query("mr/y"))
	{
		message_vision("艄公对$N说道：客官，燕子坞到了，请下船吧。\n", ob);
		remove_call_out("time_limit1");
		remove_call_out("time_limit2");
		ob->move(__DIR__"ab1");
		delete_temp("busy");
		ob->delete("mr/x");
		ob->delete("mr/y");	
		ob->delete_temp("mr_locx");
		ob->delete_temp("mr_locy");			
		return;
	}
	ob->set_temp("mr_locx", locx);
	ob->set_temp("mr_locy", locy);
	call_out("location", 2, ob);
}
