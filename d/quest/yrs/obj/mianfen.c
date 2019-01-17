
inherit ITEM;
#include <ansi.h>
int do_mix(string arg);
void create()
{
        set_name(HIW"���"NOR, ({"mianfen"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
    else  {
           set("unit", "��");
           set("yrs","mianfen");
           set("long", "����һ�����̵���ۣ�\n");
        }
}

void init()
{
  add_action("do_mix","mix");
}

int do_mix(string arg)
{
  object ob;
  object target;
  object result;
  string name;
  ob=this_player();
  if(!ob->query("dtsl_quest_yrs_ok"))
  return notify_fail("�����۷�����ȥ�ؿ���������ʲô����.\n");
  if(!arg||sscanf(arg,"with %s",name)!=1)
  return notify_fail("��Ҫ�����ͬʲô�����һ��\n");
  if(!objectp(target=present(name,ob)))
  return notify_fail("������û�����������\n");
  if(target->query("yrs")!="shila")
  return notify_fail("��۲���ͬ"+target->name()+"�����һ��\n");
  message_vision(YEL"$N��"+query("name")+"��"+target->name()+"���������\n"NOR,ob);
  result=new(__DIR__"mixed");
  result->move(ob);
  destruct(target);
  destruct(this_object());
  return 1;
}