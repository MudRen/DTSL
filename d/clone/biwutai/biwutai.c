
inherit ROOM;
#include <ansi.h>
#include <job_money.h>
int filter_user(object ob);
mapping d_member=([
 "yingui":"������","chanyuan":"������Ժ","songjia":"�μұ�","dongming":"������","yijian":"�Ľ���",
 "huajian":"������","jingzhai":"�Ⱥ���ի","feima":"��������","haisha":"��ɳ��","tujue":"ͻ��",
 "duzun":"����","lifa":"��  ��","dajiang":"����",]);
void create()	
{
	set("short", HIR"����̨"NOR);
	set("long", @LONG
����ĵĽ�����ˣ���ֻ��������ˡ������Ǳ���̨������
����԰�ȫ�Ľ���������������Ƿ���Ч���������������
�������ֳ�ֱ���ġ������б�����(jia)������Դ�����ȡ
(qu)������
LONG);
    set("exits", ([
	        "east" : __DIR__"meeting_room",
 	]));
 	set("no_death",1);
 	set("no_sleep",1);
 	set("no_channel","���Ǻúñ���ɣ�\n");
 	set("no_get",1);
 	set("no_quit",1);
 	set("broadcast",1);
 	set("end_fight",1);
 	set("item_desc",([
 	"jia":"����һ�������ܣ������е�(blade)\n"+
 	      "��(sword)����(hammer)��ذ��(dagger)��"+
 	      "ǹ(fork)������(axe).�����qu xx���ñ�����\n",
 	      ]));
      setup();
	
}

void init()
{
add_action("do_qu","qu");
}	

int broadcast(string str)
{
  tell_room("/d/yangzhou/kantai",HIR"��������̨�� :"NOR+str);
  return 1;
}

int do_qu(string arg)
{
  object ob,weapon;
  ob=this_player();
  if(ob->is_busy())
  return notify_fail("����æ���أ�\n");
  if(!arg)
  return notify_fail("��Ҫ��ʲô��\n");
  if(ob->is_fighting())
  ob->receive_damage("sen",-20);
  weapon=new(__DIR__+arg);
  if(!weapon)
  return notify_fail("û�����ֱ�����\n");
  weapon->move(ob);
  message_vision("$N�ӱ�������������һ��"+weapon->name()+"\n",ob);
  return 1;
}

void end_fight(object killer,object victim)
{
  object *usr,*ob,here;int i;
  usr=filter_array(users(),"filter_user",this_object());
  message("system",HIR"��������̨�� :"NOR+HIG+"�ڱ��α����У�"+killer->name()+
            "սʤ��"+victim->name()+",�����ʤ����\n",usr);
  add_shili(killer,victim->query("max_pot")*2,victim->query("max_pot"));
  this_object()->add("win_count/"+killer->query("clean/register_leitai"),1);
  victim->set("clean/fail",1);
  if(this_object()->query("win_count/"+killer->query("clean/register_leitai"))>=3){
   message("system",HIR"��������̨�� :"NOR+HIG+"�ڱ��α����У�"+d_member[killer->query("clean/register_leitai")]+
        "սʤ��"+d_member[victim->query("clean/register_leitai")]+"!\n"NOR,users());
   __DIR__"meeting_room"->delete("dengji");
   __DIR__"meeting_room"->delete("zhuce");
   killer->delete("clean");
   victim->delete("clean");
   this_object()->delete("win_count");
   here=load_object(__DIR__"meeting_room");
   ob=all_inventory(here);
   for(i=0;i<sizeof(ob);i++)
   if(interactive(ob[i]))
     ob[i]->delete("clean");
   }
   
  return ;
}

int valid_leave(object ob,string dir)
{
  __DIR__"meeting_room"->add("member_count",-1);
  return ::valid_leave(ob,dir);
}