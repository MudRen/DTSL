
inherit NPC;

#include <ansi.h>
#include <job_money.h>

string do_job1();
string do_job2();
string do_ok();
void create()
{
   set_name("������",({ "song yuzhi","song","yuzhi" }) );
        set("gender", "Ů��" );
       set("age", 22);
   set("long", "�������μұ��������¡���˵���ǿ�������ϲ�����ˡ�\n");
       
   set("combat_exp", 300000);
   set("str", 28);
   set("per", 27);
   set("attitude", "peaceful");
   set("gin",1000);
   set("max_gin",1000);
   set("kee",1000);
   set("max_kee",1000);
   set("sen",1000);
   set("max_sen",1000);
   set("force",1000);
   set("max_force",1000);
   set_skill("tiandao-bajue",100);
   set_skill("blade",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("unarmed",100);
   set_skill("cuff",100);
   set_skill("anxiang-fuying",100);
   set_skill("force",110);
   set_skill("tiangang-sanjue",100);
   set_skill("poyu-quan",100);
   create_family("�μұ�",5,"����");
 set("chat_chance",60);
set("chat_msg",({ (:random_move:),}));
   set("shili",([
      "name":"songjia_b",
      ]));
   
   set("inquiry",([
        "������":(:do_job1:),
        "��ɱ":(:do_job2:),
        "����":(:do_ok:),
        ]));
   setup();
   carry_object(__DIR__"chouyi")->wear();
   carry_object(__DIR__"duandao")->wield();
  
}

string do_job1()
{
  object ob;
  object *t;
  int i;
  ob=this_player();
  if(ob->query("combat_exp")<500000)
  return "��ľ���̫���ˣ����������̫Σ���ˣ�\n";
   t=ob->query_team();
  if(sizeof(t)>0)
  for(i=0;i<sizeof(t);i++)
       if(objectp(t[i])){
       	
       	 if(t[i]->query("combat_exp")<500000)
       	 return ""+t[i]->name()+"�ľ���̫���ˣ���̫Σ���ˣ�\n";
	 if(ob->query("combat_exp")>=t[i]->query("combat_exp")){
			  if(ob->query("combat_exp")-t[i]->query("combat_exp")>300000)
				  return "���ǵľ������̫�����Σ�գ�\n";}
		  else{ if(t[i]->query("combat_exp")-ob->query("combat_exp")>300000)
			      return "���ǵľ������̫�����Σ�գ�\n";}}
  if(ob->query_temp("dtsl_job_cisha"))
  return "�㻹�ǸϿ�ȥ�Ž��ˣ�������©�˷������޷���ɱ�ˣ�\n";
  if(time()-ob->query("busy_time")<100+random(20))
  return "�������ǳ�Σ�գ��㻹��ЪЪ�ɣ�\n";
  if(ob->query_temp("dtsl_job"))
  return "��������������������æ�����İɣ�\n";
  t=ob->query_team();
  if(sizeof(t)>0)
    for(i=0;i<sizeof(t);i++)
      if(t[i]){
       if(environment(t[i])!=environment(ob)){
       return "�㻹�ǰѶ�Ա�ټ����뵽���������������ɣ�\n";
       break;}
       t[i]->set_temp("dtsl_job_cisha/step1",1);
       t[i]->set_temp("dtsl_job","��ɱ������");}
  ob->set_temp("dtsl_job_cisha/step1",1);
  ob->set_temp("dtsl_job","��ɱ������");
  return "��֪����������������ʿ��ɱ�������������ȫ������\n"+
  "�Ķ��ˣ����߻������ٿ������ֽ�����ɱ�ļƻ���\n";
}

string do_job2()
{
   object ob;
   object *t;
   int i;
   ob=this_player();
   if(!ob->query_temp("dtsl_job_cisha/step1"))
    return "����������Ǵ�ɱ˭�أ�\n";
   t=ob->query_team();
   if(sizeof(t)>0)
    for(i=0;i<sizeof(t);i++)
     if(t[i]){ 
     if(environment(t[i])!=environment(ob)){
       return "�㻹�ǰѶ�Ա�ټ����뵽�����ٿ��Ǵ�ɱ�ļƻ��ɣ�\n";
       break;}
     t[i]->set_temp("dtsl_job_cisha/step2",1);}
   ob->set_temp("dtsl_job_cisha/step2",1);
   if(sizeof(t)<0)
   return "��Ȼ��ִ����ˣ���ô�ͼƻ��þ�ȥ�Ž��ɡ�\n";
   else
   return "��Ȼ����ִ����ˣ���ô�ͼƻ��þ�ȥ�Ž��ɡ�\n";
}

string do_ok()
{
  object ob;
  object *t;
  int i;
  int exp,pot,sil;
  ob=this_player();
  if(!ob->query_temp("dtsl_job_cisha"))
  return "����û������ʲô�£�ƾʲô��Ҫ��������\n";
  if(!ob->query_temp("dtsl_job_cisha/step4"))
  return "��û�ܻ�ɱ������������ô���㽱����\n";
/*  ob->delete_temp("dtsl_job_cisha");
  ob->delete_temp("dtsl_job");
  ob->set("busy_time",time());
  */
  t=ob->query_team();
  if(sizeof(t)>0)
   for(i=0;i<sizeof(t);i++)
   if(t[i]&&environment(t[i])!=environment(ob))
    return "����Ķ�Ա���м�����˵�ɣ�\n";
  if(sizeof(t)>0){
   for(i=0;i<sizeof(t);i++)
   if(t[i]&&environment(t[i])==environment(ob)&&
    t[i]->query_temp("dtsl_job_cisha/step4")&&
    t[i]->query_temp("dtsl_job_cisha/step3")&&
    t[i]->query_temp("dtsl_job_cisha/step2")&&
    t[i]->query_temp("dtsl_job_cisha/step1")){
      exp=230+random(20)-sizeof(t)*10;
      pot=130+random(10)-sizeof(t)*5;
      sil=200+random(100);
      t[i]->add("combat_exp",exp);
      t[i]->add("potential",pot);
      t[i]->add("deposit",sil);
      tell_object(t[i],query("name")+"����Ц����лл�����ˣ�\n");
      tell_object(t[i],"������ж��У���õ���"+HIW+chinese_number(exp)+NOR+"�㾭��\n"+
                       "                      "+HIY+chinese_number(pot)+NOR+"��Ǳ��\n"+
                       "                      "+MONEY_D->money_str(sil)+"\n");
      tell_object(t[i],"���Ǯׯ��������ˣ�\n");
      t[i]->delete_temp("dtsl_job_cisha");
      t[i]->delete_temp("dtsl_job");
      t[i]->set("busy_time",time());
      add_shili(t[i],exp/3,sil/3);}
      return "лл����Ϊ����������ô����£�\n";}
  exp=220+random(20);
      pot=130+random(10);
      sil=200+random(100);
      ob->add("combat_exp",exp);
      ob->add("potential",pot);
      if(ob->query("potential")>ob->query("max_pot"))
	ob->set("potential",ob->query("max_pot"));
      ob->add("deposit",sil);
      tell_object(ob,query("name")+"����Ц����лл���ˣ�\n");
      tell_object(ob,"������ж��У���õ���"+HIW+chinese_number(exp)+NOR+"�㾭��\n"+
                       "                      "+HIY+chinese_number(pot)+NOR+"��Ǳ��\n"+
                       "                      "+MONEY_D->money_str(sil)+"\n");
      tell_object(ob,"���Ǯׯ��������ˣ�\n");
      ob->delete_temp("dtsl_job_cisha");
      ob->delete_temp("dtsl_job");
      ob->set("busy_time",time());
      add_shili(ob,exp/3,sil/3);
      return "лл��Ϊ����������ô����£�\n";
}
