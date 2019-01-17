
inherit NPC;
#include <ansi.h>
#include <job_money.h>
string give_job();
int cancel_job();
int do_ok(string arg);
int do_action1();

string *dir=({
"/d/hangzhou","/d/yangzhou","/d/pengliang",
"/d/taishan"});

void create()
{
   set_name("����ɽ",({ "xiang yushan","xiang","yushan" }) );
   set("gender", "����" );
   set("age", 25);
   set("long", "����[�����]������ɽ��\n");
       
   set("combat_exp",80000);
   set("str", 10);
   set("per", 25);
   set_skill("parry",30);
   set_skill("unarmed",30);
   set_skill("dodge",30);
   set("force",200);
   set("max_force",200);
   set_skill("force",30);
   set("attitude", "peaceful");
   set("inquiry",([
	   "�����˿�":(:give_job:),
	   "����":(:cancel_job:),
	   "����":(:do_action1:),
	   ]));
   
   set("target_id","####");//��ֹ������ ansha ������ɱ����
   
   setup();
   carry_object(__DIR__"chouyi")->wear();
  
}

void init()
{
	add_action("do_ok","jiaochai");
}

string give_job()
{
	object me;
	object target,guard,mixiang;
	
	
	me=this_player();
	
	if(me->query_temp("fanmai_job"))
	return "�㻹�ǿ�ȥ�ɣ�\n";
	
	if(me->query("combat_exp")<100000)
	 return "��ı���̫���ˣ�Ъ��ȥ�ɣ�\n";
	
  	if(time()-me->query("busy_time")<=40+random(5))
		return "����ЪЪ�ɣ�\n";
	if(me->query_temp("dtsl_job"))
   return "������������������æ�����İɣ�\n";
   if(!valid_do_job(me,"qiangjie"))
	return "����书�ܸ��ˣ���������С�����Ǵ��С���ˣ�\n";
                
	target=new(__DIR__"girl");
	target->set("last",time());
	mixiang=new(__DIR__"mixiang");
	target->set("target",me);
	me->set_temp("target",target);
	target->set("target_id",me->query("id"));
	mixiang->set("target",target);
	mixiang->move(me);
	
	if(!random_place(target,dir))
	 return "���������Ů�˱Ƚ��ܻ�ӭ�أ���������... ...\n";
	
	target->set("long",query("long")+"��˵����ɽ����Ѿ��������ŵ��˷���"+me->name()+"���������ˡ�\n");
		
	tell_object(me,"����ɽ������һ�����㡣\n");
	tell_object(me,"����ɽ��Ц���� ���Ǽ�Ժ�����Ҫ�������\n");
	
	if(!(environment(target)))
          return "���������Ů�˱Ƚ��ܻ�ӭ�أ���������... ...\n";
        
        guard=new(__DIR__"guard");
        guard->set_status(me);
        guard->move(environment(target));
        guard->set_leader(target);
        
	me->set_temp("dtsl_job","����ɽ�����˿�����");
	me->set_temp("fanmai_job",1);
	me->add_temp_array("job_temp_killer",target);
	me->add_temp_array("job_temp_killer",guard);
	return "�ð�,��Ȼ"+RANK_D->query_respect(me)+"Ը�⣬���ȥ"+MISC_D->find_place(environment(target))+"\n��"+target->name()+"�����ң��Ҳ��������ģ�\n";
}

int do_ok(string arg)
{
	object me,ob,mixiang;
	
	
	me=this_player();
	
	if(!arg){
	command("grin");
	command("say û��Ů�ˣ���ʲô�������");
	return 1;}
	
	if(!me->query_temp("fanmai_job")){
	command("?");
	command("say ����˵ʲô��");
	return 1;}
	
	
		
	if(
	!objectp(ob=present(arg,me))&&
	!objectp(ob=present(arg,environment(me)))){
		command("?");
	command("say û������˰���");
	return 1;}
	
	if(ob==me){
	
	 if(me->query("gender")=="Ů��"){
		command("grin");
	        command("say ���ۣ����������ҵ���... ...");
	        }
	 else{
	     command("pei");
	        command("say �ҿɲ��������");
	       }
	return 1;}
	
	if(ob->query("gender")=="����"){
		command("shake");
	command("say �����ҿɲ�Ҫ��");
	return 1;}
        if(ob->query("target")!=me){
        command("kok "+me->query("id"));
	command("say ��ץ�����ˣ�");
	return 1;}
	
        if(objectp(mixiang=present("mixiang",me)))
        destruct(mixiang);
        
        tell_object(environment(me),"����ɽ��ͷ�������ˣ�����λ�������ȥ��\n");
	tell_object(environment(me),"���̳���һ���ˣ���"+ob->name()+"���ȥ�ˡ�\n");
	destruct(ob);
	
	me->delete_temp("fanmai_job");
	me->delete_temp("come_guard");
	me->delete_temp("dtsl_job");
	me->delete_temp("target");
		
	me->set("busy_time",time());
	if(me->query("gender")=="Ů��")
	tell_object(me,"û�뵽����Ů�˶���ô���ˣ���... ...\n");
	
	JOBSYS_D->give_reward_xiangfanmai(me);	
	return 1;
}

int cancel_job()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("fanmai_job")){
	command("pei "+ob->query("id"));
	command("say ����˵ʲô��");
	return 1;}
   
   JOBSYS_D->do_cancel_job("fanmaijob",ob,this_object());
   

	
	if(objectp(present("mixiang",ob)))
        destruct(present("mixiang",ob));
        
        if(objectp(ob->query_temp("target")))
          destruct(ob->query_temp("target"));
	
     command("sigh "+ob->query("id"));
     command("say ��Ȼ����ôû�ã���Ҳû�а취�ˣ�\n");
     return 1;
}

int accept_fight(object who)
{
   return 0;
}

void kill_ob(object ob)
{
  ob->remove_killer(this_object());
  command("bi "+ob->query("id"));
  return;
}

int accept_object(object ob,object obj)
{
   object target,killer;
   
   if(obj->query("daughter")!="lianrou")
   return 0;
   
   if(ob->query("dtsl_quest_ysdodge_help_ok"))
   return 0;
   
   command("grin");
   command("say ������а���������ôƯ����Ů�ˣ�\n");
   message_vision("$Nһ���֣�����һ�����£�����������ˣ�\n",this_object());
   target=new("/d/quest/yunshuai-dodge/lianrou");
   killer=new(__DIR__"killer");
   copy_object(target,obj);
   target->move("/d/quest/yunshuai-dodge/migong8");
   killer->set_status(ob);
   killer->move("/d/quest/yunshuai-dodge/migong8");
   ob->set("dtsl_quest_ysdodge_help_ok",1);
   return 1;
}

int do_action1()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query_skill("jiuying-dodge",1)){
     command("say ����������������ˣ�\n");
     return 1;
   }
      
   command("say �ã�������������ˣ��е���������������ȥ�޻أ�");
   ob->move("/d/quest/yunshuai-dodge/migong1");
   
   return 1;
}