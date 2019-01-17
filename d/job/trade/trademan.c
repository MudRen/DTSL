inherit NPC;

#include <job_money.h>
#include <ansi.h>

string give_job();
string abandon_job();

string *dir1=({
"/d/luoyang","/d/yangzhou",
});
string *dir2=({
"/d/xiangyang","/d/jiujiang","/d/baling",
});
string *dir3=({
"/d/gaoli","/d/changan","/d/hefei"
});

void create()
{
   set_name("������",({ "maimai wang","maimai","wang"}) );
   set("gender", "����" );
   set("age", 40);
   set("long", "����һ�����ˣ��˳�[������]������������һ�ס�\n");
   set("combat_exp",300000);
   set("str",26);
   set("per", 22);
   set("force",500);
   set("max_force",500);
   set("kee",800);
   set("max_kee",800);
   set("sen",500);
   set("max_sen",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("force",80);
   set_skill("trade",200);
   set("attitude", "peaceful");
   set("target_id","####");
   set("vocation","����");
   set("vocation_skill","trade");
   set("inquiry",([
	   "����":(:give_job:),
           "����":(:abandon_job:),
	   ]));
   setup();
   carry_object("/obj/armor/cloth")->wear();
  
}

string give_job()
{
	object me,order;
        object owner;
        string *dirs,str;
	me=this_player();
        
        if(me->query("vocation")!="����")
	        return "��ֻ�������ˡ�\n";
        if(me->query_skill("trade",1)>me->query("int")*8)
                return "�������Ƕ���һ��������ˣ�������Щ����̫ί�����ˡ�\n";
	if(me->query_temp("order_job"))
		return "�㻹�ǰ����еĶ������ͳ�ȥ�ɡ�\n";
	if(time()-me->query("busy_time")<=50)
		return "���ڲ��������㻹��ЪЪ�ɣ�\n";
	if(me->query_temp("dtsl_job"))
                return "������������������æ�����İɣ�\n";
        if(me->query("combat_exp")<500000)
	 dirs=dir1;
	else
	 if(me->query("combat_exp")<1000000)
	 dirs=dir1+dir2;
	else
	 dirs=dir1+dir2+dir3;
       
        owner=new(__DIR__"owner");
        
        owner->set_status(me);
  
        if(!random_place(owner,dirs))
        return "�ջ����������أ���������... ... ... ...\n";
        
        if(!environment(owner))
        return "�ջ����������أ���������... ...\n"; 
       
        order=new(__DIR__"order");
	order->set("target",owner);
	order->set("long","����һ���͸�"+HIC+owner->name()+NOR+"�Ķ�������\n");
	order->set("owner",me);
	order->move(me);
	me->set_temp("dtsl_job","������������������");
	
	me->set_temp("order_job",1);

         if(me->query("combat_exp",1)>=1000000)
	  me->set_temp("need_killer",2);
        else
         if(me->query("combat_exp",1)>=500000)
	  me->set_temp("need_killer",1);
	else
	  me->set_temp("need_killer",0);
	 if((int)me->query("combat_exp",1)>=500000)
	   {   
	   	call_out("killer_come",20+random(10),me);
            str="��ȥ�ٻأ���Ҫ�����̻���\n";
	}
        else str="";
	tell_object(me,query("name")+"����һ��"+order->query("name")+"��\n");
	return "�ðɣ��鷳����Ұ�����"+order->query("name")+CYN+"�͸���"+MISC_D->find_place(environment(owner))+
	 "��"+owner->name()+"��ʮ��𼱣���ȥ��ȥ��\n"+
	       str;
	
	 
}

string abandon_job()
{
   object ob;
   object order;
   
   ob=this_player();
   
   if(!ob->query_temp("order_job")){
   command("heng "+ob->query("id"));
   return "���߿����һ�æ���أ�\n";
   }
   
   JOBSYS_D->do_cancel_job("tradejob",ob,this_object());
   
   return "������������ô�ܵ����ˡ�\n";
}

void killer_come(object me)
{
  object killer;
   object killer2;
   object order;
   
   if(!me)
    return;
   if(me->is_ghost())
    return;
   
   if(!me->query_temp("order_job"))
    return;
    
   tell_object(me,HIB"\n�ƺ����˴���ı���Ϯ����\n\n"NOR);
   	killer=new("/d/job/trade/killer");
   	
   	killer->set_status(me);	
	
	killer->move(environment(me));
	message_vision("\n$N������:������Ʋ���!\n",killer);
	me->add_temp_array("job_temp_killer",killer);
	killer->kill_ob(me);
	
        if(me->query("combat_exp")>=500000){
          killer2=new("/d/job/trade/killer");
          killer2->set_status(me);	
          killer2->move(environment(me));
          me->add_temp_array("job_temp_killer",killer2);
          killer2->kill_ob(me);}
     return;
}	

int is_apprentice_of(object ob)
{
        return 1;
}

int recognize_apprentice(object ob)
{
   return 1;
}

int prevent_learn(object me,string skill)
{
   if(me->query("vocation")!=query("vocation")){
     command("say ���ֲ���"+query("vocation")+"���ҿɲ������㼼�ܣ�");
     return 1;
   }
   if(skill!=query("vocation_skill")){
    command("say ��ֻ����"+to_chinese(query("vocation_skill"))+
             "��"+query("vocation_skill")+"����");
    return 1;
   }
   return 0;
}
    

