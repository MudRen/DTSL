
inherit NPC;
#include <ansi.h>
#include <job_money.h>

#define CTRL_D __DIR__"jctrl.c"

string give_job();
int cancel_job();
int do_ok(string arg);
int do_action1();

string *dir=({
"/d/suiye","/d/dingxiang","/d/mayi",
"/d/tuyuhun"});

void create()
{
   set_name("����",({ "ma zei","ma","zei" }) );
   set("gender", "����" );
   set("age",35);
   set("long", "����һ���������������������Ŀ��̡�\n");
       
   set("combat_exp",80000);
  
   set("force",200);
   set("max_force",200);
   set_skill("force",30);
  
   set("inquiry",([
	   "���":(:give_job:),
	   "����":(:cancel_job:),
	   "����":(:do_action1:),
	   ]));
   
   set("chat_chance",30);
   set("chat_msg",({
    (:do_command,"thief":),
    (:do_command,"envy":),
   }));
   
   setup();
  
}

void init()
{
	add_action("do_ok","jiaochai");
}

string give_job()
{
	object me;
	object target;
	int flag;
	
	
	me=this_player();
	
	if(!CTRL_D->if_join(me))
	return "�㲻����������ΰ��Ҵ�٣���\n";
		
	if(me->query_temp("mazei_job"))
	return "���ȥ��ٰɣ���Ȼһ���˶����ˣ�\n";
	
	if(me->query("combat_exp")<100000)
	 return "��ı���̫���ˣ�Ъ��ȥ�ɣ�\n";
	
  	if(time()-me->query("busy_time")<=30+random(5))
		return "����ЪЪ�ɣ�\n";
	if(me->query_temp("dtsl_job"))
        return "������������������æ�����İɣ�\n";
        if(!valid_do_job(me,"dajie"))
	return "����书�ܸ��ˣ���������С�����Ǵ��С���ˣ�\n";
                
	target=new(__DIR__"target");
	target->set("last",time());
	
	flag=target->set_status(me);
	
	if(!random_place(target,dir))
	 return "����������Դ���أ���������... ...\n";	
	
	if(!(environment(target)))
          return "����������Դ���أ���������... ...\n";
               
	me->set_temp("dtsl_job","�����������");
	me->set_temp("mazei_job",1);
	me->add_temp_array("job_temp_killer",target);
	
	if(flag==1)	
	return "�ðɣ���Ȼ"+RANK_D->query_respect(me)+"Ը�⣬���ȥ"+MISC_D->find_place(environment(target))+"\n"+
	"���"+target->name()+"�����ţ�һ��Ҫ�ѶԷ�ɱ����\n";
	else
	return "�ðɣ���Ȼ"+RANK_D->query_respect(me)+"Ը�⣬���ȥ"+MISC_D->find_place(environment(target))+"\n"+
	"���"+target->name()+"�����ţ��Ҳ���������ִ󣬲�Ҫɱ���Է���\n";
	
}

int cancel_job()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("mazei_job")){
	command("heng "+ob->query("id"));
	command("say ����˵ʲô��");
	return 1;}
   
   JOBSYS_D->do_cancel_job("mazeijob",ob,this_object());
   	
     command("sigh "+ob->query("id"));
     command("say ��Ȼ����ôû�ã���Ҳû�а취�ˣ�\n");
     return 1;
}

int accept_fight(object who)
{
   return 0;
}


int do_action1()
{
   object ob;
   
   ob=this_player();
   
   if(CTRL_D->is_full()){
     command("say л�ˣ��ҵ��ֵ��Ѿ������ˣ�");
     return 1;
   }
   if(CTRL_D->if_join(ob)){
     command("say ���Ȼ�Ѿ����͸Ͽ��ٰɣ�");
     return 1;
   }
   
   CTRL_D->add_member(ob);
      
   command("say �ã����㵨����С���Ҿ�������");   
   return 1;
}

void die()
{
   object ob,book;
   
   ob=query_temp("last_damage_from");
   
   if(!ob) return ::die();
   
   if(ob->query("family/family_name")=="ͻ��"
    &&ob->query("combat_exp")>=1000000
    &&!ob->query("dtsl_quest_help_toutianjf")){
      book=new(__DIR__"obj/book");
      book->move(this_object());
      ob->set("dtsl_quest_help_toutianjf",1);
      ob->set_temp("cannot_get_jianpu",1);
   }
   
   return ::die();
   
}