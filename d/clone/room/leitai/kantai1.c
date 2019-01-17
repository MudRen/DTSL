
inherit ROOM;
#include <ansi.h>
#include <org.h>
void create()	
{
	set("short", HIR"���俴̨"NOR);
	set("long", @LONG
���������°�����ĵĿ�̨���Ա߻���������̨����̨��
��ȥ��ֻ���������ָ�����������֣��Աߵ���Ⱥ��ʱ��������
�õ������������������У��ǳ����֡���̨����ȥ��ֻ��������
�ָ�������������׼�����׼����һ��ȥһ�������ˡ�
LONG);
        set("exits",([
          "east":__DIR__"kantai2",
   "west":"/d/yangzhou/beidajie1",
          ]));
        
        set("no_fight",1);
 	set("no_death",1);
 	set("no_sleep",1);
 	set("no_channel","���Ǻúÿ�����ɣ�\n");
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
  return notify_fail("��û�н����κα�����\n");
  wins_list=keys(wins);
  msg="������������������������������������������������������\n";
  msg+=HIR"                   ����Ӣ�۱�����                   \n"NOR;
  msg+="������Ŀǰʤ�������\n\n\n";
  for(i=0;i<sizeof(wins_list);i++){
  	
  msg+=sprintf("%-10s  ��ʤ������%d\n",
  ORG_D->get_board_shili(wins_list[i]),wins[wins_list[i]]);}
  msg+="������������������������������������������������������\n";
  ob->start_more(msg);
  return 1;
}
