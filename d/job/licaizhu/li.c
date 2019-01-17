#include <ansi.h>
#include <job_money.h>
inherit NPC;
string give_job();
string abandon_job();
int do_ok(string arg);
void create()
{
   set_name("�����",({ "li caizhu","li","caizhu" }) );
        set("gender", "����" );
        set("age", 52);
   set("long", "���Ǻ��ݵĴ������������������ΪŮ���ٰ�������ס�\n");
       
   set("combat_exp", 50000);
   set("str", 10);
   set("per", 22);
   set("attitude", "friendly");
/*   set("inquiry",([
	   "��������":(:give_job:),
	   "����":(:abandon_job:),
	   ]));*/
   set("chat_chance",30);
   set("chat_msg",({
	   (:random_move:),
   }));
   setup();
 //  carry_object(__DIR__"obj/chouyi")->wear();
  
}

void init()
{
	add_action("do_ok","task");
}

string give_job()
{
	object me,ob,letter;
	object *usr;
	int i,j;
	me=this_player();ob=this_object();
	if(me->query("combat_exp")<100000)
	return "��ı�����ô�ͣ���ô���Ұ���\n";
	
	if(me->query_temp("li_job"))
		return "�㻹����������ͷ���°ɣ�\n";
	if(me->query_temp("li_song_job"))
      	return "�㻹����������ͷ���°ɣ�\n";
	if(time()-me->query("busy_time")<=30+random(10))
		return "�㻹����ЪЪ�ɣ�\n";
	if(me->query_temp("dtsl_job"))
   return "������������������æ�����İɣ�\n";
      //  if(!valid_do_job(me,"licaizhu"))
      //  return "����书��ô�ߣ��ҿ�û��ô���Ǯ��Ӷ�㡣\n";
      if(me->query("combat_exp")<500000){
      	
      	usr=users();
      	for(j=0;j<sizeof(usr);j++){
      	 i=random(sizeof(usr));
      	 if(!interactive(usr[i])) continue;
      	 if(!living(usr[i])) continue;
      	 if(wizardp(usr[i])) continue;
      	 if(query_ip_name(usr[i])==
      	    query_ip_name(me)) continue;
      	 if(usr[i]==me) continue;
      	 break;}
      	 if(j==sizeof(usr))
      	 return "��˭������أ��������뿴��\n";
       me->set_temp("li_song_job",1);
      	me->set_temp("dtsl_job","�������������");
      	letter=new(__DIR__"letter");
       letter->set("target_id",usr[i]->query("id"));
       letter->move(me);
       return "�ðɣ���������������(song)��"+usr[i]->name()+"�ɣ�\n";}
   me->set_temp("dtsl_job","�������������");
	me->set_temp("li_job",1);
       
   return "�ҼҺ�Ժ�и��������׵���̨�������������Ѿ���\n"+
          "�Լ����������μӱ������ף��������ҵ�Ů������ȥ\n"+
          "���Ұ��Ǽ����ٱ���ܰɣ���һ�������س�л��ģ���\n";
	
}
string abandon_job()
{
  object ob;
  ob=this_player();
  if(!ob->query_temp("li_job"))
  return "����˵ʲô����һ��Ҳ��������\n";
  ob->delete_temp("li_job");
  ob->delete_temp("dtsl_job");
  ob->delete_temp("target_come");
  ob->delete("busy_time");
  return "�������ֺ�������Խ��Խ���ˣ���... ...\n";
}
  
int do_ok(string arg)
{
	object me,ob,money;
	int exp,i,sil,pot,famous,score;
	me=this_player();i=0;
	if(!me->query_temp("li_job"))
		return notify_fail("ʲô��\n");
	if(!arg||arg!="ok")
		return notify_fail("�������������task ok.\n");
	if(!me->query_temp("defence_ok"))
		return notify_fail("�㲻������ɱ���Ĺٱ����Ҳ����л��ģ�\n");
	exp=5+random(5);
	sil=500+me->query("max_pot");
	pot=3+random(2);	
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->add("deposit",sil);
	add_shili(me,exp/2,20+random(2));
	me->delete_temp("defence_ok");
	me->delete_temp("li_job");
	me->delete_temp("dtsl_job");
	me->delete_temp("target_come");
	me->set("busy_time",time());
  	tell_object(me,"�����������Ц��лл"+RANK_D->query_respect(me)+"�ˣ�\n"+
  	               "�����������"+MONEY_D->money_str(sil)+"��Ϊ���ꡣ\n");
  	tell_object(me,"���Ǯׯ��������ˣ�\n");
	return 1;
}
