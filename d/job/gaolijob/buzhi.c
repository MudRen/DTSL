
inherit NPC;

#include <ansi.h>
#include <job_money.h>

string give_job();
int do_ok(string arg);

string *dir1=({
"/d/huashan","/d/changan"
});

string *dir2=({
"/d/emeishan","/d/wuyishan"
});

string *dir3=({
"/d/taishan","/d/hengshan"
});	

void create()
{
   set_name("����",({ "bu zhi","bu","zhi"}));
        set("gender", "����" );
        set("age", 32);
   set("long", "���Ǿ�����Ժ�ĵõ���ɮ�����ķ�ˮƽ�����൱�ߵġ�\n");
   set("class","bonze"); 
   set("combat_exp", 400000);
   set("str", 28);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("dodge",80);
   set_skill("parry",90);
   set_skill("staff",90);
   set_skill("force",150);
   set_skill("blade",150);
   set_skill("chanzong-fofa",150);
   set_skill("chanzong-fofa",100);
   set_skill("jinguang-daofa",150);
   set_skill("wuxiang-zhangfa",90);
   set_skill("liuyun",150);
   
   set("target_id","####");//��ֹ������ ansha ������ɱ����
   
    create_family("������Ժ",5,"ɮ��");
	set("inquiry",([
		"����":(:give_job:),
		"���᱾����,�������̨":"������һ��,�δ��ǳ���",
		"��������":"�ڼ����Բ�������Ϊ��",
		"��������":"�����ڶ�����Ϊ����",
		]));
   setup();
   carry_object("/d/chanyuan/npc/obj/sengyi")->wear();
   carry_object("/d/chanyuan/npc/obj/staff")->wield();
  
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

void init()
{
	object ob,ob2;
	
	add_action("do_ok","jiaochai");
	
	ob=this_player();
	ob2=this_object();
	::init();
	if(!ob||!present(ob,environment())) return;
	remove_call_out("welcome");
	call_out("welcome",1,ob,ob2);
	
}

void welcome(object ob,object ob2)
{
   if(!ob||!present(ob,environment())) return;
	switch(random(2))
	{
	case 0: message_vision("$N�����е��������ӷ�!\n",ob2);break;
	case 1: message_vision("$N��$n���������Ե�ˡ�\n",ob2,ob);
	}
	
	return;
}

string give_job()
{
	object ob,me;
	string str,*dirs;
	
	me=this_player();
	
	if(me->query("class")!="bonze") 
	return "���������黹�����Ƿ��ŵ����Լ�����ɣ�\n";
	
	if(me->query("combat_exp")<100000)
	return "������������㹻���ؾ��飡\n";
	
	if(me->query_temp("buzhi_jiangjing"))
		return "�㻹�����������е��°�!������,��ô����?\n";
		
	
	      if(time()-me->query("busy_time")<40+random(5))
	          return "�㻹��ЪЪ�ɣ�\n";
	          
	if(me->query_temp("dtsl_job"))
        return "������������������æ�����İɣ�\n";
        
        if(!valid_do_job(me,"jiangjing"))
	return "������������������̫ί���ˣ�\n";
	
	if(me->query("combat_exp")<400000)
	  dirs=dir1;
	else
	  if(me->query("combat_exp")<800000)
	  dirs=dir1+dir2;
	else
	  dirs=dir1+dir2+dir3;
	
	ob=new(__DIR__"killer");
	
	if(!ob->set_status(me))
	return "���ᾭ����˳������⣬��ȥ������ʦ�ɣ�\n";
	
	if(!random_place(ob,dirs))
	return "���ᾭ������������أ���������... ...\n";
	
	if(!environment(ob))
	return "���ᾭ������������أ���������... ...\n";
	
	me->set_temp("dtsl_job","������Ժ��������");
	me->set_temp("buzhi_jiangjing",1);
	
	return "ǰ�����и���"+ob->name()+CYN+"����͵�������еľ��飬\n"+
	"��˵�����ڶ����"+MISC_D->find_place(environment(ob))+CYN+"������ȥ�Ѿ������������\n";
	
}

int do_ok(string arg)
{
   object ob,book;
   string name;
   
   
   ob=this_player();
   
   
   if(!ob->query_temp("buzhi_jiangjing")){
    command("?");
    command("say ������ʲô��");
    return 1;}
   
   if(!arg||sscanf(arg,"with %s",name)!=1){
   	command("hehe");
   return notify_fail("��ʹ�� jiaochai with xxx ���������\n");
   }
    
   if(!objectp(book=present(name,ob))){
   	command("kok "+ob->query("id"));
   	command("say ��������ô��˵�ѻ���");
   	return 1;
    }
   
    
        ob->delete_temp("dtsl_job");
        ob->delete_temp("buzhi_jiangjing");
        ob->set("busy_time",time());
       command("say "+RANK_D->query_respect(ob)+"��Ȼ�¸ң��Ҵ���ؾ���лл���ˣ�");
       destruct(book);
       
       JOBSYS_D->give_reward_jj(ob);
     
     return 1;
}