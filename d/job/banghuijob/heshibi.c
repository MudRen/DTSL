#include <job_money.h>
#include <ansi.h>
inherit ITEM;

void create()
{
   set_name(HIW"�����"NOR, ({ "heshibi"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��ʯ");
     set("unit", "��");
     set("value", 0);
   }
   setup();
}

int is_get_of(object me,object ob)
{
  object killer;
  if(ob->query("job/p_id")!=me->query("id"))
  return notify_fail("�����������ò�������\n");
  message_vision(HIW"$Nֻ��ž��һ���������ը������Ƭ��\n",me);
  killer=new(__DIR__"killer");
  copy_object(killer,me);
  killer->set("job/p_id",me->query("id"));
  killer->set_name("������",({"man"}));
  killer->delete("family");
  killer->delete("nickname");
  killer->delete("title");
  killer->move(environment(me));
  message_vision(HIR"$N��Ц�����Ҿ��Ƿ��˸��ٺ�������������μұ������Ϲ���û�뵽�������ˣ�\n"NOR,killer);
  killer->kill_ob(me);
  ob->set("name","����ĺ����");
  return 1;
}
  
