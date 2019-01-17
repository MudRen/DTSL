inherit ROOM;

#include <org.h>
#include <ansi.h>

#define OB this_player()

string *skills=({"dodge","unarmed","parry","finger","strike",
"leg","cuff","force","sword","blade","staff","fork","axe","whip",
"hammer","spear","stick","dagger"});

void init()
{
  add_action("do_lingwu","lingwu");
  
}

int do_lingwu(string arg)
{
  string str;
  if(!arg)
  return notify_fail("��Ҫ����ʲô��\n");
  if(member_array(arg,skills)==-1)
  return notify_fail("������ܲ�������������ߡ�\n");
  if(OB->query_skill(arg,1)<200)
  return notify_fail("��ļ���̫�ͣ�����������\n");
  if(OB->query("gin")<=15)
  return notify_fail("��ľ����㣬�޷�����\n");
  if(OB->query("potential")<=0)
  return notify_fail("���Ǳ�ܲ��㣬�޷�����\n");
  if(OB->is_busy())
  return notify_fail("����æ���أ�\n");
    
  if(OB->query_temp("mark/lingwu"))
  return notify_fail("���Ѿ���ʼ�����ˣ�\n");
  message_vision("$N������������ʼڤ˼������ѧ��\n",OB);
  str=YEL+OB->name()+"���������������ڤ˼����"NOR;
  OB->set_temp("apply/short",({str}));
  OB->set_temp("mark/lingwu",1);
  OB->start_busy((:call_other,this_object(),"doing_lingwu",OB,arg:),
                 (:call_other,this_object(),"halt",OB:));
   return 1;
}

int doing_lingwu(object ob,string arg)
{
   int i;
   if(ob->query("potential")>=30)
   i=30;
   else i=ob->query("potential");
   
   ob->improve_skill(arg,(ob->query_int()/6+random(10))*i
                          );
   if(ob->query("gin")>15)
   ob->receive_damage("gin",15);
   if(ob->query("potential")>30)
   ob->add("potential",-30);
   else ob->set("potential",0);
   if(ob->query("gin")<15||ob->query("potential")<=0){
   message_vision(HIY"$N����ͷ��һ��ѣ�Σ���æվ��������\n"NOR,ob);
   ob->delete_temp("apply/short");
   ob->delete_temp("mark/lingwu");
   return 0;}
   else return 1;
}

int halt(object ob)
{
  message_vision("$N���������˿�����������վ��������\n",ob);
  ob->delete_temp("apply/short");
  ob->delete_temp("mark/lingwu");
  return 1;
}
