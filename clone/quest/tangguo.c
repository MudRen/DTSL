#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name(HIY"�¹�"HIR"�ǹ�"NOR, ({"tang guo","tang"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "������¹��ǹ�������Ѹ�ٻָ�һ���˾���������\n");
     set("unit", "��");
     set("no_decay",1);
     set("value", 400000);
     
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
  
  ob->set("eff_gin",ob->query("max_gin"));
  ob->set("gin",ob->query("max_gin"));
  ob->set("eff_sen",ob->query("max_sen"));
  ob->set("sen",ob->query("max_sen"));
  ob->set("eff_kee",ob->query("max_kee"));
  ob->set("kee",ob->query("max_kee"));
  
  destruct(this_object());
  
  return 1;
  
}

