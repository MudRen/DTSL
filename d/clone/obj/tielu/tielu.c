/*******************************************************************************
 ����¯.
 ���Խ� ��������ʯ�Ž�ȥ�����ɺõĿ�ʯ������Ҫ������������Ѫ��
 ��ʯ���˺����������Ķ��켼���й�
 ��ʯ�ļ�ǿ���������������йء�
*********************************************************************************/
inherit ITEM;
#include <ansi.h>
#define TB this_object()
#define OB this_player()
int do_fire();
int do_put(string arg);
int do_la(string arg);
int do_ximie();
int do_kailu();
void create()
{
   set_name("����¯", ({ "tie lu","lu"}) );
   set_weight(50000000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ�������ĸ�¯���������Ǵ����������ġ�\n�Ա���һ��ʹ��˵��������[pai].\n");
     set("material", "����");
     set("unit", "��");
     set("value",0);
     
   }
   setup();
}
int is_get_of(object pal,object ob)
{
  return notify_fail("����˰��쾢�����ָ���̧�������������¯��\n");
}
void init()
{
  add_action("do_fire","fire");
  add_action("do_put","put");
  add_action("do_la","la");
  add_action("do_ximie","ximie");
  add_action("do_kailu","kailu");
}
int is_owner(object ob)
{
  if(TB->query("owner")==ob)
  return 1;
  return 0;
}
int do_fire()
{
  if(TB->query("fired"))
  return notify_fail("���¯���Ѿ��������ˣ���Ҫ����ʹ����Ϩ��[ximie]���ɣ�\n");
  if(OB->query("vocation")!="����"||OB->query("family/family_name")!="������")
  return notify_fail("ֻ�ж�������������ʹ�����¯�ӣ�\n");
  if(OB->query_skill("bihai-force",1)<200||OB->query_skill("force",1)<200)
  return notify_fail("���书��ô�����ʹ�����¯�ӣ�\n");
 if(time()-OB->query("lianzhi_busy")<1200)
return notify_fail("�㻹����ЪЪ�ɣ�\n");
  TB->set("fired",1);
  message_vision(HIR"$Nֻ��¯�Ӻ��һ�������������ܴ��\n"NOR,OB);
  TB->set("name",HIR"����¯"NOR);
  TB->set("owner",OB);
  return 1;
}

int do_ximie()
{
  if(!TB->query("fired"))
  return notify_fail("���¯��û�е��ţ����ò���Ϩ��\n");
  message_vision("$NС������ش�¯�ӣ�������¯�ҡ�\n",OB);
  TB->delete("fired");
  TB->delete("owner");
  TB->delete("ob");
  TB->set("name","����¯");
  return 1;
}

int do_put(string arg)
{
  string name;object ob;
  if(!arg||
  sscanf(arg,"%s in ����¯",name)!=1)
  return notify_fail("��ʹ�� put xxx in ����¯.\n");
  if(!TB->query("fired"))
  return notify_fail("���¯�ӻ�û���ţ��ȵ����ٷŰɣ�\n");
  if(!is_owner(OB))
  return notify_fail("�����Ѿ�ʹ�����¯���ˣ���Ҫʹ�ã�����Ϩ�����ɣ�\n");
  if(!objectp(ob=present(name,OB)))
  return notify_fail("�������û�����������\n");
  if(!ob->query("skill_type")&&!ob->query("weapon"))
  return notify_fail("���������������������\n");
  if(ob->query("skill_type"))
  ob->unequip();
  message_vision("$N��"+ob->name()+"С������طŵ�������¯�С�\n",OB);
  if(ob->query("skill_type")){
  TB->set("ob/damage",ob->query("weapon_prop/damage"));
  TB->set("ob/strong",ob->query("max_strong"));}
  else{
  TB->set("ob/damage",ob->query("weapon/damage"));
  TB->set("ob/strong",ob->query("weapon/strong"));}  
  destruct(ob);
  return 1;
}

int do_la(string arg)
{
  int damage,strong;
  if(!arg||arg!="����")
  return notify_fail("��ʹ��la ���䡣\n");
  if(OB->is_busy())
  return notify_fail("����æ���أ�\n");
  if(!TB->query("fired"))
  return notify_fail("��û�е��ţ�����ʲô���䰡��\n");
  if(!is_owner(OB))
  return notify_fail("�����Ѿ�ʹ�����¯���ˣ���Ҫʹ�ã�����Ϩ�����ɣ�\n");
  if(!TB->query("ob"))
  return notify_fail("����ʲôҲû�У�����������ʲô�ð���\n");
  damage=TB->query("ob/damage");
  strong=TB->query("ob/strong");
  if(OB->query("force")<damage+strong)
  return notify_fail("��������������������ˣ�\n");
  if(OB->query("kee")<damage*2+strong)
  return notify_fail(HIR"��е���Ѫ�������Ѿ������������ˣ�\n"NOR);
  OB->add("force",-damage-strong);
  OB->receive_damage("kee",damage*2+strong);
  TB->add("ob/damage",OB->query_skill("duanzao-jishu",1)/70);
  TB->add("ob/strong",OB->query_str()/45);
  message_vision(HIR"$N������������һ�·��䣬$N����¯��ӳ��ͨ�죡\n"NOR,OB);
  OB->start_busy(3);
  return 1;
}
int do_kailu()
{
  object ob;
  if(!TB->query("fired"))
  return notify_fail("��û�е��ţ��㿪ʲô¯����\n");
  if(!TB->query("ob"))
  return notify_fail("����ʲôҲû�У��㿪ʲô¯����\n");
  if(!is_owner(OB))
  return notify_fail("���Ǳ������õģ��㲻������¯��\n");
  ob=new(__DIR__"tie");
  ob->set("weapon/strong",TB->query("ob/strong"));
  ob->set("weapon/damage",TB->query("ob/damage"));
  message_vision(HIR"$NС������ش�¯�ӣ�����ǯ�г���һ��ͨ������顣\n"NOR,OB);
  ob->move(environment(OB));
OB->set("lianzhi_busy",time());
  TB->delete("fired");
  TB->delete("owner");
  TB->delete("ob");
  TB->set("name","����¯");
  return 1;
}
