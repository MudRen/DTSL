
inherit ITEM;
#include <ansi.h>
int do_absorb();
void create()
{
   set_name(HIW"�����"NOR, ({ "heshibi"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����ǽ�������������ĺ���赡�\n");
     set("material", "��ʯ");
     set("unit", "��");
     set("value", 40000000000000);
     set("no_sell",1);
   }
   setup();
}

void init()
{
  add_action("do_absorb","absorb");
}

int do_absorb()
{
  object ob;
  ob=this_player();
  if(ob->query("max_force")<800){
  message_vision(HIR"$Nֻ�������������������һ�㣡\n"NOR,ob);
  ob->unconcious();
  destruct(this_object());
  return 1;}
  message_vision(HIR"$Nֻ�������������������һ�㣡\n"NOR,ob);
  tell_object(ob,HIC"��æ������Ϣ��ֻ��һ������ֱ�����������\n"NOR);
  ob->add("max_force",5);
  ob->unconcious();
  destruct(this_object());
  return 1;
}