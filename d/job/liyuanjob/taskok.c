void init()
{
   add_action("do_task","task");
}

int do_task(string arg)
{
  object ob;
  object track;
  
  ob=this_player();
  if(!arg||arg!="ok")
  return notify_fail("��ʹ�� task ok ��������\n");
  if(ob->query_temp("liyuan_job/step")!=7)
  return notify_fail("�����۾�һ�ɣ���֪���񣬵�������˵ʲô����\n");
  if(!ob->query_temp("track_target")||
  !objectp(track=ob->query_temp("track_target")))
  return notify_fail("����һ��ü�������ĳ������ˣ���̫û���ˣ�\n");
 
  if(environment(track)!=environment(ob))
  return notify_fail("����Ҳ�������ﰡ���Ͽ��˹����ɣ�\n");
  if(this_object()->query("task_ok")!=track->query("target_place"))
  return notify_fail("������ݳ��ʹ��˵ط�����\n");
  ob->add_temp("liyuan_job/step",1);
  destruct(track);
  ob->delete_temp("track_target");
  tell_object(environment(ob),"���ϳ���һ��С�������γ����˽�ȥ��\n");
  tell_object(ob,this_object()->query("name")+"����Ц����лл���ˣ�\n");
  return 1;
}

  
