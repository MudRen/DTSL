int do_lingwu(string arg)
{
  object ob;
  ob=this_player();
  if(!arg)
  return notify_fail("��Ҫ����ʲô�ڹ���\n");
  if(arg!=environment(ob)->query("force"))
  return notify_fail("���ﲻ�����������ڹ���\n");
  if(ob->query_skill(arg,1)>=300)
  return notify_fail("����ڹ����Ѿ����������ˣ��޷���������ˣ�\n");
  if(ob->query("potential")<=0)
  return notify_fail("���Ǳ��̫���ˣ��޷���������\n");
  if(ob->query("gin")<300)
  return notify_fail("��ľ�Ѫ���㣬�޷���������\n");
  ob->improve_skill(arg,ob->query("potential")*30);
  ob->set("potential",0);
  ob->set("gin",1);
  tell_object(ob,"��������"+to_chinese(arg)+"������������Щ�ջ�\n");
  return 1;
}