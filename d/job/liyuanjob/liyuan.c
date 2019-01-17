
inherit NPC;

#include <ansi.h>
#include "dx_map.h"
#include "hill_map.h"
#include "npc_list.h"
#include "weapon_list.h"
#include <job_money.h>

string do_job1();
string do_job2();
string do_job3();
string do_job4();
string do_job5();
string do_job6();
string do_job7();
string do_abandon();
int do_lingshang(string arg);
#define THIS_JOB "liyuan_job"

string *target_name=({"л��","����","���","����"});
string *killer_name2=({"ŷ��","���","�Ϲ�","����"});
string *killer_id2=({"��","����","��","һЦ","��"});
string *killer_name=({"��","Ǯ","��","��","��","��","֣","��"});
string *killer_id=({"һ","��","��","��","��","��","��","��"});
void create()
{
   set_name("��Ԩ",({ "li yuan","li","yuan" }) );
        set("gender", "����" );
        set("age", 55);
   set("long", "����ǳ�����ķ�����Ԩ��\n");
   set("combat_exp", 500000);
   set("str", 28);
   set("per", 24);
   set("attitude", "peaceful");
   set_skill("unarmed",150);
   set_skill("parry",150);
   set_skill("dodge",150);
   set_skill("force",150);
   set("max_gin",1000);
   set("max_sen",1000);
   set("max_kee",1000);
   set("force",1500);
   set("max_force",1500);
   set("shili",([
      "name":"lifa_b",
      ]));
   set("inquiry",([
    "�а�":(:do_job1:),
    "����":(:do_job2:),
    "��ɱ":(:do_job3:),
    "�ȼ�":(:do_job4:),
    "ƽ��":(:do_job5:),
    "Ѱ��":(:do_job6:),
    "����":(:do_job7:),
    "����":(:do_abandon:),
    ]));
   setup();
   carry_object(__DIR__"obj/guanfu")->wear();
  
}

void init()
{
  add_action("do_lingshang","lingshang");
}

string do_job1()
{
  object ob;
  object paper;
  string place;
  string name;
  
  ob=this_player();
  if(ob->query("combat_exp")<1000000)
  return "ƾ�������������������ô����£�\n";
  if(ob->query_temp("liyuan_job/step")>=2)
  return "���Ѿ�����а��ˣ����ǿ����������°ɣ�\n";
  if(ob->query_temp("dtsl_job")==THIS_JOB)
  return "�㻹�ǸϿ�ȥ������ɣ�\n";
  
  if(time()-ob->query("busy_time")<40+random(20))
  return "��ԨЦ������ô��޵������㻹��ЪЪ�����ɣ�\n";
  
  ob->set_temp("dtsl_job",THIS_JOB);
  ob->add_temp("liyuan_job/step",1);
  
  place=dx_map[random(sizeof(dx_map))];
  name=target_name[random(sizeof(target_name))];
 
  paper=new(__DIR__"paper1");
  paper->set("target_name",name);
  paper->set("target_place","����");
  paper->set("target_where",place);
  paper->move(ob);
  tell_object(ob,"��Ԩ������һ���а��\n");
  return "��˵"+name+
         "�书�˵ã�Ӧ�ö�����ȡ���������ã�����ȥ"+HIW+"����"+NOR+CYN+"�����н���\n";
}

string do_job2()
{
  object ob;
  object office;
  object paper;
  string *place;
  string name;
  int i;   
  
  ob=this_player();
  if(ob->query("combat_exp")<1000000)
  return "ƾ�������������������ô����£�\n";
  if(ob->query_temp("liyuan_job/step")>=4)
  return "���Ѿ���ɼ����ˣ����ǿ����������°ɣ�\n";
  if(ob->query_temp("liyuan_job/step")<2)
  return "�㻹���ȴ�ͷ����ɣ�\n";
  if(ob->query_temp("liyuan_job/step")==3)
  return "�㻹�ǸϿ�ȥ������ɣ�\n";
  
  ob->add_temp("liyuan_job/step",1);
  
  ob->add("combat_exp",100);
  ob->add("potential",50);
  tell_object(ob,"��Ԩ����Ц������л������˵�һ������\n"+
                 "��Ԩ��������"+HIW+chinese_number(100)+NOR+"���飬"+
                 HIY+chinese_number(50)+NOR+"��Ǳ�ܡ�\n");
  
  place=keys(hill_map);
  i=random(sizeof(place));
 
  name=killer_name[random(sizeof(killer_name))]+
       killer_id[random(sizeof(killer_id))];
    
  paper=new(__DIR__"paper");
  paper->set("target_name",name);
  paper->set("target_where",place[i]);
  paper->set("target_place",hill_map[place[i]]);
  paper->move(ob);
  
  office=new(__DIR__"office");
  office->set("owner",ob);
  office->move(environment(ob));
  office->set_leader(ob);
  tell_object(ob,"һ���������˳�����\n");
  message_vision("$N����$nһ��"+paper->name()+"��\n",this_object(),ob);
  return "��˵"+name+"���������������������ȥ"+HIW+hill_map[place[i]]+NOR+CYN+"\n"+
         "�������ã�Ȼ�󽻸�����ٲ�Ϳ����ˣ�\n";
}

string do_job3()
{
  object ob;
  object paper;
  string *place;
  string name;
  int i;   
  
  ob=this_player();
  if(ob->query("combat_exp")<1000000)
  return "ƾ�������������������ô����£�\n";
  if(ob->query_temp("liyuan_job/step")>=6)
  return "���Ѿ���ɼ����ˣ����ǿ����������°ɣ�\n";
  if(ob->query_temp("liyuan_job/step")<4)
  return "�㻹���ȴ�ͷ����ɣ�\n";
  if(ob->query_temp("liyuan_job/step")==5)
  return "�㻹�ǸϿ�ȥ������ɣ�\n";
  
  ob->add_temp("liyuan_job/step",1);
  
  ob->add("combat_exp",110);
  ob->add("potential",50);
  tell_object(ob,"��Ԩ����Ц������л������˵ڶ�������\n"+
                 "��Ԩ��������"+HIW+chinese_number(110)+NOR+"���飬"+
                 HIY+chinese_number(50)+NOR+"��Ǳ�ܡ�\n");
  
  place=keys(hill_map);
  i=random(sizeof(place));
  name=killer_name2[random(sizeof(killer_name2))]+
       killer_id2[random(sizeof(killer_id2))];
  
  paper=new(__DIR__"paper3");
  paper->set("target_name",name);
  paper->set("target_place",hill_map[place[i]]);
  paper->set("target_where",place[i]);
  paper->move(ob);
  
  message_vision("$N����$nһ��"+paper->name()+"��\n",this_object(),ob);
  return "��˵"+name+"������Ѿã���˵�����ӵ�"+HIW+hill_map[place[i]]+NOR+CYN+"\n"+
         "������ȥ�����͵�������\n";
}

string do_job4()
{
  object ob;
  object track;
  string msg;
  
  ob=this_player();
  if(ob->query("combat_exp")<1000000)
  return "ƾ�������������������ô����£�\n";
  if(ob->query_temp("liyuan_job/step")>=8)
  return "���Ѿ���ɾȼ��ˣ����ǿ����������°ɣ�\n";
  if(ob->query_temp("liyuan_job/step")<6)
  return "�㻹���ȴ�ͷ����ɣ�\n";
  if(ob->query_temp("liyuan_job/step")==7)
  return "�㻹�ǸϿ�ȥ������ɣ�\n";
  
  ob->add_temp("liyuan_job/step",1);
  
  ob->add("combat_exp",120);
  ob->add("potential",50);
  tell_object(ob,"��Ԩ����Ц������л������˵���������\n"+
                 "��Ԩ��������"+HIW+chinese_number(120)+NOR+"���飬"+
                 HIY+chinese_number(50)+NOR+"��Ǳ�ܡ�\n");
  
  track=new(__DIR__"track");
  track->set("owner",ob);
  ob->set_temp("track_target",track);
  track->move(environment(ob));
  switch(random(3)){
  
  case 0:
  track->set("target_place",1);
  msg= "��������ֺ��֣�����Ѻ����������ǰȥ�ȼ���\n";
  track->set("long","����һ����"+ob->name()+"�����������ݵ����ݳ���\n");
  break;
  case 1:
  track->set("target_place",2);
  msg= "����Ž��ֺ��֣�����Ѻ����������ǰȥ�ȼ���\n";
  track->set("long","����һ����"+ob->name()+"���������Ž������ݳ���\n");
  break;
  case 2:
  track->set("target_place",3);
  msg= "��������ֺ��֣�����Ѻ����������ǰȥ�ȼ���\n";
  track->set("long","����һ����"+ob->name()+"����������������ݳ���\n");
  break;}
  msg+="���⳵���ݽ������ص����˾��پͿ����ˣ�\n"+
       "·��ҪС��ǿ������\n";
  ob->apply_condition("liyuan_job_killer1",1);
  return msg;
}

string do_job5()
{
  object ob;
  object target;
  string *list;
  object paper;
  int i;
  
  ob=this_player();
  if(ob->query("combat_exp")<1000000)
  return "ƾ�������������������ô����£�\n";
  if(ob->query_temp("liyuan_job/step")>=10)
  return "���Ѿ���ɾȼ��ˣ����ǿ����������°ɣ�\n";
  if(ob->query_temp("liyuan_job/step")<8)
  return "�㻹���ȴ�ͷ����ɣ�\n";
  if(ob->query_temp("liyuan_job/step")==9)
  return "�㻹�ǸϿ�ȥ������ɣ�\n";
  
  ob->add_temp("liyuan_job/step",1);
  
  ob->add("combat_exp",130);
  ob->add("potential",50);
  tell_object(ob,"��Ԩ����Ц������л������˵��ĸ�����\n"+
                 "��Ԩ��������"+HIW+chinese_number(130)+NOR+"���飬"+
                 HIY+chinese_number(50)+NOR+"��Ǳ�ܡ�\n");
  
  list=keys(npc_list);
  i=random(sizeof(list));
  
  paper=new(__DIR__"paper2");
  paper->set("target_place",list[i]);
  paper->set("target_name",npc_list[list[i]]);
  paper->move(ob);
  message_vision("$N����$nһ��"+paper->query("name")+"��\n",
                 this_object(),ob);
  return "��˵���"+npc_list[list[i]]+"���ھ��ڷ��������ȥ����һ�°ɣ�\n";
}

string do_job6()
{
    object ob;
    object paper;
    string *place;
    int i;
    
    ob=this_player();
  if(ob->query("combat_exp")<1000000)
  return "ƾ�������������������ô����£�\n";
  if(ob->query_temp("liyuan_job/step")>=12)
  return "���Ѿ����Ѱ���ˣ����ǿ����������°ɣ�\n";
  if(ob->query_temp("liyuan_job/step")<10)
  return "�㻹���ȴ�ͷ����ɣ�\n";
  if(ob->query_temp("liyuan_job/step")==11)
  return "�㻹�ǸϿ�ȥ������ɣ�\n";
  
  ob->add_temp("liyuan_job/step",1);
  
  ob->add("combat_exp",140);
  ob->add("potential",50);
  tell_object(ob,"��Ԩ����Ц������л������˵��������\n"+
                 "��Ԩ��������"+HIW+chinese_number(140)+NOR+"���飬"+
                 HIY+chinese_number(50)+NOR+"��Ǳ�ܡ�\n");
                 
  place=keys(weapon_list);
  i=random(sizeof(place));
  
  paper=new(__DIR__"paper4"); 
  paper->set("target_where",place[i]);
  paper->move(ob);
  tell_object(ob,"��Ԩ������һ�Ųر�ͼ��\n");
  return "�������ʧ��һ������,��˵��"+weapon_list[place[i]]+",��ȥ�����һ����ɣ�\n";
}

int do_lingshang(string arg)
{
    object ob;
    object baowu;
    
    ob=this_player();
    
    if(!arg)
    return notify_fail("��Ҫ��ʲô�����ͣ�\n");
    if(!objectp(baowu=present(arg,ob)))
    return notify_fail("������û�����������\n");
    
    if(ob->query_temp("liyuan_job/step")!=11||
       baowu->query("target")!=ob)
    return 0;
    destruct(baowu);
    ob->add_temp("liyuan_job/step",1);
    
    tell_object(ob,query("name")+"����һЦ������̫лл���ˣ�\n");
    return 1;
}

string do_job7()
{
   object ob;
  object track;
  
  ob=this_player();
  if(ob->query("combat_exp")<1000000)
  return "ƾ�������������������ô����£�\n";
  if(ob->query_temp("liyuan_job/step")>=14)
  return "���Ѿ������ȫ�������񣬿�ȥ������ͤ�����Ͱɣ�\n";
  if(ob->query_temp("liyuan_job/step")<12)
  return "�㻹���ȴ�ͷ����ɣ�\n";
  if(ob->query_temp("liyuan_job/step")==13)
  return "�㻹�ǸϿ�ȥ������ɣ�\n";
  
  ob->add_temp("liyuan_job/step",1);
  
  ob->add("combat_exp",150);
  ob->add("potential",50);
  tell_object(ob,"��Ԩ����Ц������л������˵���������\n"+
                 "��Ԩ��������"+HIW+chinese_number(150)+NOR+"���飬"+
                 HIY+chinese_number(50)+NOR+"��Ǳ�ܡ�\n");
  
  track=new(__DIR__"track2");
  track->set("owner",ob);
  ob->set_temp("track_target",track);
  track->move(environment(ob));
  track->set("long","������"+ob->name()+"�����͵Ĵ󳵡�\n");
  tell_room(environment(ob),"һ���ٱ�������ϳ���һ���󳵡�\n");
  tell_room(environment(ob),"һ�������󳼴��������˳���������˴��С�\n");
  ob->apply_condition("liyuan_job_killer2",1);
  return "��λ������Ҫȥ���ݵ��ܹܸ����㸺��·�ϵı����ɣ�\n";
}

string do_abandon()
{
   object ob;
   
   ob=this_player();
   ob->delete_temp("liyuan_job");
   ob->delete_temp("track_target");
   ob->delete_temp("dtsl_job");
   ob->delete_temp("killer_comes");
   ob->set("busy_time",0);
   return "������ôû�������������Ǹ������������\n";
}