
inherit ITEM;
int do_linghui(string arg);
void create()
{
   set_name("��ɽ�־�", ({ "shou juan"}));
   set_weight(600);
   set("unit", "��");
   set("long","����һ����ɽ�־�\n");
set("no_give",1);
set("no_get",1);  
}

void init()
{
  add_action("do_linghui","linghui");
}

int do_linghui(string arg)
{
  object ob;
  
  ob=this_player();
  if(!arg||arg!="shou juan")
  return notify_fail("��Ҫ���ʲô��\n");
  if(ob->query_skill("huanri-dafa",1)<100)
  return notify_fail("�������ʲôҲ��᲻������\n");
  if(ob->query("eff_kee")*100/ob->query("max_kee")>20)
  return notify_fail("���մ󷨽������ƶ��������ܶ���ɡ�����ķ����ƺ����ԡ�\n");
  if(ob->query("gin")<100)
  return notify_fail("���ͷ����Щ����������޷���ỻ�մ󷨡�\n");
  if(ob->query("potential")<30)
  return notify_fail("���Ǳ�ܲ�������ỻ�մ󷨣�\n");
  if(ob->is_busy()||ob->is_fighting())
  return notify_fail("����æ���أ�\n");
  if(ob->query_skill("huanri-dafa",1)>=400)
  return notify_fail("��Ļ��մ��Ѿ��Ƿ��켫���޷�������ˣ�\n");
  ob->receive_damage("gin",100);
  ob->add("potential",-30);
  tell_object(ob,"�㿴����ɽ�־���Ϣ��������������������,���û��մ���Щ�����ˡ�\n");
  ob->start_busy(random(2));
  ob->improve_skill("huanri-dafa",ob->query("potential")*ob->query_int()/2);
  return 1;
}