
inherit NPC;
#include <ansi.h>
#include <job_money.h>
#include "pass.h"
string give_job();
int cancel_job();
int do_ok(string arg);

string *dirs1=({
"/d/changan",
});

string *dirs2=({
"/d/taishan","/d/mangshan","/d/pengliang",
});

string *dirs3=({
"/d/emeishan","/d/hengshan"
});



void create()
{
   set_name("�ž���",({ "zhang junguan","zhang","junguan" }) );
        set("gender", "����" );
        set("age", 35);
   set("long", "����ͻ�ʵ�һ�����٣�ר�Ÿ���ͻ�ʵ��鱨������\n");
       
   set("combat_exp",200000);
   set("str", 30);
   set("per",10+random(20));
   set_skill("parry",30);
   set_skill("unarmed",30);
   set_skill("dodge",30);
   set("force",200);
   set("max_force",200);
   set_skill("force",30);
   set("inquiry",([
	   "job":(:give_job:),
	   "����":(:cancel_job:),
	   ]));
   
   set("target_id","####");//��ֹ������ ansha ������ɱ����
   
   setup();
   
}

void init()
{
	add_action("do_ok","jiaochai");
}

string give_job()
{
	object me;
	object target,paper;
	string *dirs,password;
	
	
	me=this_player();
	
	if(me->query_temp("tujue_jieying_job"))
	return "�㻹�ǿ�ȥ�ɣ�\n";
	
	if(me->query("combat_exp")<100000)
	 return "��ı���̫���ˣ�Ъ��ȥ�ɣ�\n";
	
  	if(time()-me->query("busy_time")<=40+random(5))
		return "����ЪЪ�ɣ�\n";
	if(me->query_temp("dtsl_job"))
   return "������������������æ�����İɣ�\n";
                
	target=new(__DIR__"mitan");
	target->set("last",time());	
	target->set("target",me);
	
	me->set_temp("target",target);
	target->add_array("target_id",me->query("id"));
	
	if(me->query("combat_exp")<300000)
	 dirs=dirs1;
	else
	if(me->query("combat_exp")<800000)
	 dirs=dirs1+dirs2;
	else
	 dirs=dirs1+dirs2+dirs3;
	
	if(!random_place(target,dirs))
	 return "ͻ����̽�����������أ���������... ...\n";
	
	target->set("long",query("long")+"��˵ͻ���Ѿ���"+me->name()+"����Ӧ���ˡ�\n");
		
	tell_object(me,query("name")+"������һ�����ᡣ\n");
	
	if(!(environment(target)))
          return "ͻ����̽�����������أ���������... ...\n";
        
        password=pass[random(sizeof(pass))]+" "+
        pass[random(sizeof(pass))];
        
        paper=new(__DIR__"paper");
	paper->set("target",target);
	paper->set("pass",password);
	paper->move(me);
	
        
	me->set_temp("dtsl_job","ͻ�ʽ�Ӧ��̽����");
	me->set_temp("tujue_jieying_job",1);
	me->add_temp_array("job_temp_killer",target);
	return "�ð�,��Ȼ"+RANK_D->query_respect(me)+"Ը�⣬���ȥ"+MISC_D->find_place(environment(target))+"\nȥ��Ӧ���ǵ�"+target->name()+"�ɣ�\n"+
	"���ν�Ӧ�İ����ǣ�"+HIY+password+NOR+CYN+"����ǧ��Ҫ�����ˣ�\n";
}

int do_ok(string arg)
{
	object me,ob,paper;
	
	
	me=this_player();
	
	if(!arg){
	command("heng");
	command("say ���ҽ�������ɲ��������ģ�");
	return 1;}
	
	if(!me->query_temp("tujue_jieying_job")){
	command("?");
	command("say ����˵ʲô��");
	return 1;}
	
	
		
	if(!objectp(ob=present(arg,environment(me)))){
		command("?");
	command("say ����û������˰���");
	return 1;}
	
	if(ob==me){
	
	 	command("kok "+me->query("id"));
	        command("say ����������ﵷ�ң���");
	 
	return 1;}
		
        if(ob->query("target")!=me){
        command("papaya "+me->query("id"));
	command("say ���Ӧ���ˣ�����");
	return 1;}
	
	if(!ob->query("pass_ok")){
        command("sigh "+me->query("id"));
	command("say ��û�����԰��ţ�����ô֪�����ǲ��������̽��");
	return 1;}
	
        if(objectp(paper=present("juan zhou",me)))
        destruct(paper);
                
        tell_object(environment(me),query("name")+"��ͷ�������ˣ���"+ob->name()+"���쵽��������\n");
	tell_object(environment(me),"���̳���һ���ˣ���"+ob->name()+"�����ˡ�\n");
	destruct(ob);
	
	JOBSYS_D->give_reward_tujuejy(me);
	
	me->delete_temp("tujue_jieying_job");
	me->delete_temp("come_killer");
	me->delete_temp("dtsl_job");
	me->delete_temp("target");	
	me->set("busy_time",time());	
	
	return 1;
}

int cancel_job()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("tujue_jieying_job")){
	command("? "+ob->query("id"));
	command("say ����˵ʲô��");
	return 1;}
   
   JOBSYS_D->do_cancel_job("tujuejy",ob,this_object());
        
	if(objectp(present("juan zhou",ob)))
        destruct(present("juan zhou",ob));
        
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