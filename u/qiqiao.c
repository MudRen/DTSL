
#include <ansi.h>
inherit ITEM;

void create()
{
   set_name(HIY"��"HIM"��"HIC"��"HIG"��"HIW"��"NOR, ({ "qiqiao yu","qiqiao","yu"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "iron");
     set("unit", "��");
     set("value", 10000000);
	 set("weapon",([
         "damage":120,
         "strong":120,
		 ]));
   }
   setup();
}

int is_get_of(object me,object ob)
{
  object dkiller;
  if(query("owner")==me->query("id"))
  return 1;
  dkiller=new(__DIR__"she");
  message_vision(HIR"��Ȼ��ӵ������һ��$N!\n"NOR,dkiller);
  dkiller->move(environment(me));
  set("owner",me->query("id"));
  dkiller->kill_ob(me);
  call_out("move_object",2,ob,dkiller);
  return 1;
}

void move_object(object ob,object dkiller)
{
  if(!dkiller||!ob) return;
  ob->move(dkiller);
  message_vision("$Nβ��һ����"+ob->query("name")+"�������ϣ�\n",dkiller);
  return;
}
