
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
  set_name( GRN "��ת���굤" NOR , ({"dan"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�Ž��ɫ�ĵ��裬��΢���ŵ�Щ��������\n");
    set("value", 30000);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="dan")	return 0;
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("force", (int)me->query("max_force"));
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  message_vision(HIG "$N��������һ�ŵ�ҩ�������У�һʱ���������硣
ֻ��$N���������������Σ��������о�����ˣ�\n" NOR, me);
  destruct(this_object());
  return 1;
}

