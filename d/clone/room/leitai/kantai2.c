
inherit ROOM;
#include <ansi.h>
#include <org.h>
void create()	
{
	set("short", HIR"比武看台"NOR);
	set("long", @LONG
这里是天下帮会比武的的看台。旁边还有两个看台，望台上
望去，只见两个武林高手正打的热闹，旁边的人群不时爆发出叫
好的声音。这里人声鼎沸，非常热闹。朝台脚望去，只见几个武
林高手正在那里做准备活动，准备下一场去一显身手了。
LONG);
        set("exits",([
          "east":__DIR__"kantai3",
          "west":__DIR__"kantai1",
          ]));
        
        set("no_fight",1);
 	set("no_death",1);
 	set("no_sleep",1);
 	set("no_channel","还是好好看比武吧！\n");
 	set("no_get",1);
 	set("no_quit",1);
 	set("can_receive_fight_msg",1);
      setup();
	
}

void init()
{
 add_action("do_list","list");
}	

int do_list()
{
  int i;
  mapping wins;
  string *wins_list;
  string msg;
  object ob;
  object room;
  
  room=load_object(__DIR__"leitai");
  ob=this_player();
  wins=room->query("win_list");
  if(!mapp(wins))
  return notify_fail("还没有进行任何比赛！\n");
  wins_list=keys(wins);
  msg="━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
  msg+=HIR"                   天下英雄比武大会                   \n"NOR;
  msg+="比武大会目前胜负情况：\n\n\n";
  for(i=0;i<sizeof(wins_list);i++){
  	
  msg+=sprintf("%-10s  获胜次数：%d\n",
  ORG_D->get_board_shili(wins_list[i]),wins[wins_list[i]]);}
  msg+="━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
  ob->start_more(msg);
  return 1;
}
