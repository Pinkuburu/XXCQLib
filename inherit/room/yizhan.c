// yizhan.c

// Changed by Rest 99.10.15

inherit ROOM;



void init()

{

        add_action("do_gu", "gu");

	add_action("do_qu", "qu");
 
}



void check_trigger(object me)

{

	object room, where;

        where = environment(me);

	if( !(room = find_object("/clone/room/mache")) )

		room = load_object("/clone/room/mache");

	if( room = find_object("/clone/room/mache") )

	{

		if((int)room->query("che_trigger")==0)

		{

                  	message_vision("小二高叫一声：“来喽！”声音未落，小二已经牵着一辆两匹马的乌篷车转了出来。\n", me);

			message_vision("小二笑着说：您真是好运气，本驿站刚刚开张，免费大酬宾，您说去哪就行了(type qu XXX)。\n", me);

                        message_vision("小二说：现在我们在汴梁(bl)华阳(hy)嵩山(ss)龙门(lm)设有分站，您可以雇车到那里。\n\n", me);

			me->set_temp("guche", 1);

                 }        

               	else if(where->query("short")==room->query_temp("envname"))

                    {

                     message_vision("小二歉意地说：“现在没车了,不过马车已经往这来了，请您等会儿吧。”\n",me);

                    }

             else

             {

		message_vision("小二满脸歉意地说：“这位客官，现在车都出去了,您等会好吗?”\n", me);

             }

        }

        else

            message("vision", "ERROR: che not found\n", this_object() );

}


int do_gu(string arg)

{

	object me;

	me = this_player();



	if(!arg || arg != "che")

		return notify_fail("你要雇什么？这里只有马车(che)可以雇。\n");

	

	message_vision("$N拍拍门板，叫道：喂，有人吗？雇车！！！\n", me);

        check_trigger(me);

        return 1;

}



int do_qu(string arg, int num)

{

	object room, me,where;

        string startname;

        me = this_player();

        where = environment(me);

        startname = where->query("short");

        switch(startname)

        {

         case "华阳驿站": startname = "/d/huayang/hyyizhan";

                          break;

         case "汴梁驿站": startname = "/d/bianliang/blyizhan";

                          break;

         case "嵩山驿站": startname = "/d/shaolin/ssyizhan";

                          break;

         case "龙门驿站": startname = "/d/longmen/lmyizhan";

                          break;



        }   

        	



	if (!me->query_temp("guche"))

		return notify_fail("根本没有人理你，你觉得自己真傻。\n");



	if (!arg)

		return notify_fail("你倒是说去哪呀！\n");



        if ( where->query("short") == "华阳驿站")

           {

            if(arg == "hy" || arg == "huayang")

              return notify_fail("你现在不就是在这吗？\n");

           }

        else if ( where->query("short") == "汴梁驿站")

           {

            if(arg == "bl" || arg == "bianliang")

              return notify_fail("你现在不就是在这吗？\n");

           }

        else if ( where->query("short") == "龙门驿站")

           {

            if(arg == "lm" || arg == "longmen")

              return notify_fail("你现在不就是在这吗？\n");

           }

        else if ( where->query("short") == "嵩山驿站")

           {

            if(arg == "ss" || arg == "songshan")

              return notify_fail("你现在不就是在这吗？\n");

           }



	if( !(room = find_object("/clone/room/mache")) )

		room = load_object("/clone/room/mache");



        if( room->query("che_trigger"))

             {

                message_vision("小二对$N满脸歉意地说：“这位客官，现在车都出去了,您等会好吗?”\n", me);

                return 1;

             }

        else if(where->query("short")==room->query_temp("envname"))

              {

                     message_vision("小二歉意地说：“现在没车了，不过马车已经往这来了，请您等会儿吧。”\n",me);

              }

       else

       {

	if( room = find_object("/clone/room/mache") )

	{

           if(!room->query_temp("mached"))

             {

                

                if ( arg == "huayang" || arg == "hy" )

		{

			message_vision("$N坐进了马车，对马夫说：“去华阳县。”\n\n", me);

			message_vision("马夫笑着说道：“好的客官，马上就上路。”\n\n", me);

			me->set_temp("mache", "huayang");

                        room->set_temp("envname","华阳驿站");

                        room->set_temp("mached","huayang");

                        room->set_temp("wherename","华阳县");

                        room->set_temp("machedshort","hy");

		}

                else if ( arg == "longmen" || arg == "lm" )

                {

                        message_vision("$N坐进了马车，对马夫说：“去龙门镇。”\n\n", me);

                        message_vision("马夫笑着说道：“好的客官，马上就上路。”\n\n", me);

                        me->set_temp("mache", "longmen");

                        room->set_temp("envname","龙门驿站");

                        room->set_temp("mached","longmen");

                        room->set_temp("wherename","龙门镇");

                        room->set_temp("machedshort","lm");

                }

		else if ( arg == "bianliang" || arg == "bl" )

		{

			message_vision("$N坐进了马车，对马夫说：“去汴梁城。”\n\n", me);

			message_vision("马夫笑着说道：“好的客官，马上就上路。”\n\n", me);

			me->set_temp("mache", "bianliang");

                        room->set_temp("mached","bianliang");

                        room->set_temp("envname","汴梁驿站");

                        room->set_temp("wherename","汴梁城");

                        room->set_temp("machedshort","bl");

		}

		else if ( arg == "songshan" || arg == "ss" )

		{

			message_vision("$N坐进了马车，对马夫说：“去嵩山。”\n\n", me);

			message_vision("马夫笑着说道：“好的客官，马上就上路。”\n\n", me);

			me->set_temp("mache", "songshan");

                        room->set_temp("envname","嵩山驿站");

                        room->set_temp("mached","songshan");

                        room->set_temp("wherename","嵩山");

                        room->set_temp("machedshort","ss");

		}

		else

		{

                       message_vision("车夫抱歉的笑了笑道：我们驿站只有汴梁(bl)华阳(hy)嵩山(ss)龙门四家驿站，真抱歉。\n", me);

			return 1;

		}

                call_out("leave", 10, me);

                me->set_temp("startid",startname);

		me->move("/clone/room/mache");

		return 1;

             }

           else

            {

              if(arg == "huayang" || "hy" || "bianliang" || "bl" || "songshan" || "ss" || "longmen" || "lm")

              {

               if(arg == (string)room->query_temp("mached") || arg == (string)room->query_temp("machedshort"))

                {

                message_vision("$N坐进了马车，对马夫说：“去" + room->query_temp("wherename") + "。”\n\n", me);

		message_vision("马夫笑着说道：“正好车里的客官也要去" + room->query_temp("wherename") + "，你们就一道走吧，我马上就上路。”\n\n", me);

                me->set_temp("mache", room->query_temp("mached"));

                me->move("/clone/room/mache");

                message("vision",me->name() + "坐进了马车，对马夫说：“去" + room->query_temp("wherename") + "。”\n\n", environment(me),({me}));

		message("vision","马夫笑着说道：“正好车里的客官也要去" + room->query_temp("wherename") + "，你们就一道走吧，我马上就上路。”\n\n", environment(me),({me}));

                return 1;

                }

               else

                {

                 message_vision("马夫对$N歉意地说：“对不起，这位客官，车里的客官要去" + room->query_temp("wherename") + ",你既然不去那里，就请您等一等吧。”\n\n",me);

                 return 1;

                }

               }

             else

               {

                       message_vision("车夫抱歉的笑了笑道：我们驿站只有汴梁(bl)华阳(hy)嵩山(ss)龙门四家驿站，真抱歉。\n", me);

		return 1;

               }

                

            }

	}

   }

}



int leave(object me)

{

   object room;

   remove_call_out("leave");

   if( !(room = find_object("/clone/room/mache")) )

		room = load_object("/clone/room/mache");

             if ( (string)me->query_temp("mache") == "huayang")

		{                           

			message_vision("车夫利索的上了车，一扬鞭子：走喽，去华阳县喽！\n\n",me);

			message_vision("不一会，车就消失在了门外。\n\n",me);

			me->set_temp("mache", "huayang");

                        me->set_temp("block_msg/all",1);

                        me->move(me->query_temp("startid"));

                        me->delete_temp("block_msg/all",1);

                        message("vision","车夫利索的上了车，一扬鞭子：走喽，去华阳县喽！\n\n",environment(me),({me}));

			message("vision","不一会，车就消失在了门外。\n\n",environment(me),({me}));       

		}

             else if ( (string)me->query_temp("mache") == "longmen")

                {                           

                        message_vision("车夫利索的上了车，一扬鞭子：走喽，去龙门镇喽！\n\n",me);

                        message_vision("不一会，车就消失在了门外。\n\n",me);

                        me->set_temp("mache", "longmen");

                        me->set_temp("block_msg/all",1);

                        me->move(me->query_temp("startid"));

                        me->delete_temp("block_msg/all",1);

                        message("vision","车夫利索的上了车，一扬鞭子：走喽，去龙门镇喽！\n\n",environment(me),({me}));

                        message("vision","不一会，车就消失在了门外。\n\n",environment(me),({me}));       

                }


		else if ( (string)me->query_temp("mache") == "bianliang")

		{

			message_vision("车夫利索的上了车，一扬鞭子：走喽，去汴梁城喽！\n\n", me);

			message_vision("不一会，车就消失在了门外。\n\n", me);

			me->set_temp("mache", "bianliang");

                        me->set_temp("block_msg/all",1);

                        me->move(me->query_temp("startid"));

                        me->delete_temp("block_msg/all",1);

                        message("vision","车夫利索的上了车，一扬鞭子：走喽，去华阳县喽！\n\n",environment(me),({me}));

			message("vision","不一会，车就消失在了门外。\n\n",environment(me),({me}));  

		}

		else if ( (string)me->query_temp("mache")== "songshan")

		{

			message_vision("车夫利索的上了车，一扬鞭子：走喽，去嵩山喽！\n\n", me);

			message_vision("不一会，车就消失在了门外。\n\n", me);

			me->set_temp("mache", "songshan");

                        me->set_temp("block_msg/all",1);

                        me->move(me->query_temp("startid"));

                        me->delete_temp("block_msg/all",1);

                        message("vision","车夫利索的上了车，一扬鞭子：走喽，去华阳县喽！\n\n",environment(me),({me}));

			message("vision","不一会，车就消失在了门外。\n\n",environment(me),({me}));  

		}

            call_out("arrived", 15,me);

            me->set_temp("block_msg/all",1);

            me->move("/clone/room/mache");

            me->delete_temp("block_msg/all",1);

            room->set("che_trigger", 1);

            room->delete_temp("mached");

            room->delete_temp("wherename");

            room->delete_temp("machedshort");

            return 1;



}







int arrived(object me)

{

        int i;

	object room, env, *inv;

        env = environment(me);

        inv = all_inventory(env);

	if( room = find_object("/clone/room/mache") )

	{

		if (me->query_temp("mache") == "huayang")

		{

		  for(i=0;i< sizeof(inv);i++)

                    {

                      if(inv[i]->is_character())

                      inv[i]->move("/d/huayang/hyyizhan");

                    }    

		}


                else if (me->query_temp("mache") == "longmen")

                {

                  for(i=0;i< sizeof(inv);i++)

                    {

                      if(inv[i]->is_character())

                      inv[i]->move("/d/longmen/lmyizhan");

                    }    

                }


		else if (me->query_temp("mache") == "bianliang")

		{

                    for(i=0;i< sizeof(inv);i++)

                          {

                            if(inv[i]->is_character())

                            inv[i]->move("/d/bianliang/blyizhan");

                           }    

		}

		else if (me->query_temp("mache") == "songshan")

                {

                    for(i=0;i< sizeof(inv);i++)

                          {

                            if(inv[i]->is_character())

                            inv[i]->move("/d/shaolin/ssyizhan");

                           }    

		}

		me->delete_temp("mache");

		me->delete_temp("guche");

                me->delete_temp("startid");

                message_vision("\n马车渐渐停了下来，车夫高叫一声：到了！\n\n", me);

		message_vision("马车一停，$N从上面走了下来。\n\n", me);

	        room->delete("che_trigger"); 

                room->delete_temp("envname");

		return 1;

	}

}



void reset()

{

    object room;



    ::reset();

    if( room = find_object("/clone/room/mache") )

        room->delete("che_trigger"); 

}




