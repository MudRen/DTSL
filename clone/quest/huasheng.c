#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name(HIY"��"HIR"��"NOR, ({"hua sheng","sheng"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "����һ�����������滹Ʈɢ���ɿ�������ζ��\n");
     set("unit", "��");
     set("no_decay",1);
     set("value", 200000);
     
   }

}

void init()
{
  add_action("do_eat","eat");
  
}

int do_eat(string arg)
{
  object ob;
  
  ob=this_player();
  
  if(!arg) return 0;
  
  if(!id(arg)) return 0;
  
  message_vision(HIY"$N"HIY"һ�ڳ�����"+query("name")+HIY+"���е�������̫ˬ���ˣ���\n"NOR,ob);
  
  ob->add("food",1000);
  ob->add("water",1000);  
  
  destruct(this_object());
  
  return 1;
  
}

