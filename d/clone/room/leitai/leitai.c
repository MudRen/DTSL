
inherit ROOM;
inherit F_SAVE;
#include <ansi.h>
#include <job_money.h>
#include <org.h>
int do_qu(string arg);
int do_list();
int do_biwu(string arg);
int do_clear();
string wiz_refer();
string query_save_file()
{
  return "/data/npc/boss/leitai_save_file";
}

void create()	
{
	set("short", HIR"����̨"NOR);
	set("long", @LONG
���������°��������̨��������ÿһ���¾���һ�Σ�
��̨�����Ϸ�����һ�������ң�����д�ţ���������ĸ����֣�
��̨���߻����ż����������������̨��������Լ�����̸ߣ�
����û�����ӣ�ֻ�й����൱�ߵ��˲ſ�����ȥ���䡣�����б�
���ܡ�jia��������Դ�����ȡ��qu���������Ա߻���һ�鹩��ʦ
�ۿ������ӡ�pai����
LONG);
    
 	set("exits",([
 	  "eastdown":__DIR__"kantai3",
 	  "southdown":__DIR__"kantai2",
 	  "westdown":__DIR__"kantai1",
 	  ]));
 	set("no_death",1);
 set("leitai",1);
 	set("no_sleep",1);
 	set("no_channel","���Ǻúñ���ɣ�\n");
 	set("no_get",1);
 	set("no_quit",1);
 	set("no_fight",1);
 	set("broadcast",1);
 	set("end_fight",1);
 	set("item_desc",([
 	"jia":"����һ�������ܣ������е�(blade)"+
 	      "��(sword)����(hammer)��ذ��(dagger)��\n"+
 	      "ì(fork)������(axe)��ǹ(spear).��(staff)"+
 	      "�����qu xx���ñ�����\n",
 	"pai":(:wiz_refer:),
 	      ]));
      setup();
      restore();
	
}

string wiz_refer()
{
  object ob;
  ob=this_player();
  if(!wizardp(ob))
  return "��������ʦ�������ӣ��㻹��ר�ı���ɣ�\n";
  return "��ʹ�� biwu id1 with id2 ����ʼ���䡣\n";
}

void init()
{
add_action("do_qu","qu");
add_action("do_list","list");
add_action("do_biwu","biwu");
add_action("do_clear","clear");
}	

int broadcast(string str)
{
  object *usr;
  usr=filter_array(users(),"filter_user",this_object());
  message("system",YEL"��������̨�� :"NOR+str,usr);
  return 1;
}

int filter_user(object ob)
{
  if(environment(ob)&&environment(ob)->query("can_receive_fight_msg"))
  return 1;
  else return 0;
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
  message_vision("$N�ӱ�������������һ��"+weapon->name()+"��\n",ob);
  return 1;
}

void end_fight(object killer,object victim)
{
  if(victim->query("kee")<=0)
   victim->set("kee",1);
  if(victim->query("eff_kee")<=0)
   victim->set("eff_kee",1);
  if(victim->query("gin")<=0)
   victim->set("gin",1);
  if(victim->query("eff_gin")<=0)
   victim->set("eff_gin",1);
  
  message("system",HIR"��������̨�� :"NOR+HIG+"�ڱ��α����У�"+killer->name()+HIG+
            "����"+ORG_D->get_shili(killer)+"սʤ��"+victim->name()+HIG+",�����ʤ����\n"NOR,users());
  add_shili(killer,victim->query("max_pot")*2,victim->query("max_pot"));
  add("win_list/"+killer->query("shili/name"),1);
  save();
  return ;
}

int do_list()
{
  int i;
  mapping wins;
  string *wins_list;
  string msg;
  object ob;
  ob=this_player();
  wins=query("win_list");
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

int valid_leave(object ob,string dir)
{
  object *inv;
  int i;
  
  inv=all_inventory(ob);
  if(dir=="eastdown"||dir=="westdown"||dir=="southdown"){
    for(i=0;i<sizeof(inv);i++){
      if(inv[i]->query("leitai_weapon"))
       destruct(inv[i]);}}
  return ::valid_leave(ob,dir);
}

int do_biwu(string arg)
{
  object ob;
  string id1,id2;
  object target1,target2;
  ob=this_player();
  
  if((!arg||sscanf(arg,"%s with %s",id1,id2)!=2)&&
     wizardp(ob))
  return notify_fail("��ʹ�� biwu id1 with id2 ��ʽ��\n");
  if(!wizardp(ob)) return 0;
  if(!objectp(target1=present(id1,environment(ob))))
  return notify_fail("����û��"+id1+"��\n");
  if(!objectp(target2=present(id2,environment(ob))))
  return notify_fail("����û��"+id2+"��\n");
  message("vision",YEL"��������̨����"+target1->name()+NOR+YEL+
                  "��"+target2->name()+NOR+YEL+"����̨���ڿ�ʼ���䣡\n"NOR,
                  users());
  target1->fight_ob(target2);
  target2->fight_ob(target1);
  return 1;
}

int do_clear()
{
  object ob;
  ob=this_player();
  
  if(!wizardp(ob)) return 0;
  if(!query("win_list"))
  return notify_fail("Ŀǰ��û�б���ɼ���\n");
  tell_object(ob,"��ɾ���˱��α���ĳɼ���\n");
  delete("win_list");
  save();
  return 1;
}