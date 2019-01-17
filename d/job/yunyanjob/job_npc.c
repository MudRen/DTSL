
inherit NPC;

#include <job_money.h>
#include <ansi.h>

#define JOBCTRL __DIR__"jobctrl.c"


string give_job()
{
   object ob,obj,jobctrl;
   int i;
   mapping line;
   
   ob=this_player();
   jobctrl=load_object(JOBCTRL);
   jobctrl->start_job();
   i=jobctrl->give_job(environment(ob)->query("job_name"));
   if(!i)
   return "��������û���γ���ҪѺ�ͣ��㻹��ȥ�������п����ɣ�\n";
   
   if(ob->query_temp("yunyan_job"))
   return "��Ͽ�ȥ���ΰɣ�\n";
   
   if(time()-ob->query("busy_time")<40+random(10))
   return "��Ъ���ټ����ɻ�ɣ�\n";
   
   if(ob->query_temp("dtsl_job"))
   return "������������������æ�����İɣ�\n";
   
   jobctrl->reset_job(i);
   
   obj=new(__DIR__"yanche");
   line=jobctrl->get_this_line(i);
   obj->set("line",line);
   obj->set("owner",ob);
   obj->set("last_time",time());
   obj->move(environment(ob));
   ob->set_temp("track",obj);
   obj->set("long","������"+ob->name()+"����Ѻ�͵Ĵ�"+line["from"]+"��"+
    line["to"]+"��"+obj->query("name")+"��\n");
   ob->add_temp_array("job_temp_killer",obj);
   ob->set_temp("yunyan_job",1);
   ob->set_temp("dtsl_job","��������");
   
   if(ob->query("combat_exp")>=200000){
   
   if(ob->query("combat_exp")<500000)
    ob->set_temp("need_killer",1);
   else
    ob->set_temp("need_killer",2);
   
   call_out("killer_come",30+random(5),ob);
   }
   
   return "�ðɣ�����Ͱ����"+obj->query("name")+"���͵�"+
   line["to"]+"�ɣ�\n";
}
   
   

int do_ok(string arg)
{
	object track,me,ob;
	object *killers;
	int i;
	
	me=this_player();
	ob=this_object();
	
	if(!arg||arg!="ok") return notify_fail("��ʹ��task ok������!\n");
	if(!me->query_temp("yunyan_job"))
		return notify_fail("��û����ٸ��������ѵ�����ð����?\n");
	if(!objectp(track=present("yan che",environment(me))))
		return notify_fail("����γ�Ū���ˣ�����ʲô������\n");
	if(track->query("owner")!=me)
		return notify_fail("�ⲻ������γ�!\n");
	if(track->query("line/to")!=environment(ob)->query("job_name"))
	return notify_fail("����γ��ʹ�ط��ˣ�\n");
	message_vision("$N�����溰�������γ�����ȥ��\n���ϳ���һ���ٱ������γ�����ȥ��!\n",ob);
	JOBSYS_D->give_reward_yunyanjob(me,track->query("line/dif"));
	if(objectp(track))
	destruct(track);		
	me->delete_temp("yunyan_killer");
	me->delete_temp("yunyan_job");
	me->delete_temp("dtsl_job");			
	me->delete_temp("need_killer");
	me->delete_temp("need_killer_flags");
	me->set("busy_time",time());
	
	return 1;
}

string give_line()
{
	object me,jobctrl;
	string str;
	
	me=this_player();
	str="";
	
	jobctrl=load_object(JOBCTRL);
	jobctrl->start_job();
	str=jobctrl->get_line();
	
	me->start_more(str);
	
	return "·;Զ����ͬ���ٸ�����Ľ�����Ȼ��ͬ������ϸѡ��ɣ�\n";
}
string abandon_job()
{
  object me;
  object track;
  me=this_player();
  if(!me->query_temp("yunyan_job"))
  return "��˵ʲô�أ�ϷŪ������\n";
  
  JOBSYS_D->do_cancel("yunyan",me,this_object());
  
  	me->delete_temp("yunyan_killer");
	me->delete_temp("yunyan_job");
	me->delete_temp("dtsl_job");			
	me->delete_temp("need_killer");
	me->delete_temp("need_killer_flags");
  
  if(objectp(track=me->query_temp("track"))){
   track->delete("last_time");
   destruct(track);}
  
  return "��������Ϊ�ٸ����µ�����Խ��Խ���ˣ�\n";
}


void killer_come(object me)
{
   object killer;
   object killer2;
   
   if(!me) return;
   if(!me->query_temp("yunyan_job"))
    return;
   if(!objectp(me->query_temp("track")))
    return;
    
    tell_object(me,HIB"\nͻȻһ����紵�˹�����\n\n"NOR);
   	killer=new("/d/job/yunyanjob/killer");   	
   	
   	killer->set_status(me);
   	me->add_temp_array("job_temp_killer",killer);
   	killer->move(environment(me));
   	
   	message_vision("\n$N��$n��������ɽ���ҿ������������ԣ���������γ��ɣ���\n\n",
   				killer,me);
   	killer->kill_ob(me);
   	   	
    if(me->query("combat_exp")>=500000){
        killer2=new("/d/job/yunyanjob/killer");
        
        killer2->set_status(me);
        me->add_temp_array("job_temp_killer",killer2);
        killer2->move(environment(me));
        
        message_vision("\n$N�����������书��ǿ���ֵ��ǲ������ϰ�����\n\n",
   				killer);
   			killer2->kill_ob(me);
        
    }
              
      return;
}	           