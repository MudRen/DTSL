
int do_action(string arg)
{
   object ob;
   string *work_msg;
   
   ob=this_player();
   
   if(ob->query("combat_exp")>20000)
   return notify_fail("����书��ô���ˣ����ǵ����洳�������ɣ�\n");
   
   if(ob->is_busy())
    return notify_fail("����æ���أ�\n");
   
   if(!arg)
   return notify_fail("��Ҫ��ϰʲô���գ�\n");
   
   if(arg!=query("lianwu"))
   return notify_fail("���ﲻ����ϰ�������ա�\n");
   
   if(ob->query_temp("slwg_job")!=query("lianwu"))
   return notify_fail("û�н�ͷ����ɣ��㲻����������ϰ���գ�\n");
   
   if(ob->query("kee")<15)
    return notify_fail("��ľ���״̬̫���ˣ��޷���ϰ���գ�\n");
   if(ob->query("sen")<15)
    return notify_fail("��ľ���״̬̫���ˣ��޷���ϰ���գ�\n");
     
   if(ob->query_temp("slwg_job_ok"))
    return notify_fail(query("over_work"));
   
   if(ob->query_temp("slwg_job_times")>=5+random(5)){
     tell_object(ob,query("over_work"));
     ob->set_temp("slwg_job_ok",1);
     return 1;
    }
    
     ob->add_temp("slwg_job_times",1);
   ob->receive_damage("kee",10+random(5));
   ob->receive_damage("sen",10+random(5));
   
    if(arrayp(query("work_msg"))){
    	work_msg=query("work_msg");
    	tell_object(ob,work_msg[random(sizeof(work_msg))]);
    	}
    else tell_object(ob,query("work_msg"));
    
    ob->start_busy(1+random(1));
    
   return 1;
}