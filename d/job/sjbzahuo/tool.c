
#include <weapon.h>

inherit STAFF;

int do_action();

void create()
{
        set_name("ɨ��", ({ "sao zhou","sao","zhou" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_save",1);
                set("long","��������ɨ����ɨ�㡣\n");
		set("material", "wood");
        }
        init_staff(10,20,20);

       set("wield_msg", "$N��$n�������������С�\n");
        set("unwield_msg", "$N�ɿ������е�$n��\n");

        setup();
}

void init()
{
   add_action("do_action","dasao");
}

int do_action()
{
   object ob;
   string here;
   
   ob=this_player();
   
   if(!ob->query_temp("sjb_saochu"))
  return notify_fail("��������Ϲæ��ʲô�أ�\n");
  if(query("owner")!=ob)
  return notify_fail("�ⲻ�����ɨ�㡣\n");
  if(ob->query_temp("weapon")!=this_object())
  return notify_fail("������ɨ���������вſ��Ըɻ\n");
  here=base_name(environment(ob));
  if(here!=query("place"))
  return notify_fail("���ߴ�ط��ˡ�\n");
  if(query("ok")){
  return notify_fail("�����Ѿ���ɨ���ˣ����Ի�ȥ�����ˡ�\n");}
  
  if(ob->query("sen")<20)
   return notify_fail("��ľ���״̬̫���ˣ��޷��ٴ�ɨ��ȥ�ˣ�\n");
   
  if(ob->is_busy())
  return notify_fail("����æ���أ�\n");
  
  ob->add_temp("sjb_saochu_times",1);
  ob->receive_damage("sen",19+random(5));
  
  message_vision("$N���������е�ɨ�㣬��ϸ�ش�ɨ������\n",ob);
  if(ob->query_temp("sjb_saochu_times")>=15+random(5)){
  set("ok",1);
  tell_object(ob,"�����Ѿ���ɨ��ϣ����Ի�ȥ�����ˡ�\n");}
  ob->start_busy(random(2));
  
  return 1;
}