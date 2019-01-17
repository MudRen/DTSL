
inherit ITEM;
#include <ansi.h>
int do_draw(string arg);
void create()
{
        set_name(YEL"����"NOR, ({"pencil"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
    else  {
           set("unit", "��");
           set("yrs","pencil");
           set("long", "����һ��С���ʣ�\n");
        }
}

void init()
{
  add_action("do_draw","draw");
}

int do_draw(string arg)
{
  object ob;
  object target,source;
  string tname,sname;
  
  ob=this_player();
  if(!ob->query("dtsl_quest_yrs_ok"))
  return notify_fail("���"+query("name")+"������ȥ�ؿ���������ʲô����.\n");
  
  if(!arg||sscanf(arg,"%s by %s",tname,sname)!=2)
  return notify_fail("��ʹ�� draw ��Ƥ by Ŀ��\n");
  if(!objectp(target=present(tname,ob)))
  return notify_fail("������û�����������\n");
  if(target->query("yrs")!="skin")
  return notify_fail("�����治�ܻ��κζ�����\n");
  if(!target->query("step1"))
   return notify_fail("�����治�ܻ��κζ�����\n");
  if(!objectp(source=present(sname,environment(ob))))
  return notify_fail("����Χû�����������\n");
  if(!source->is_character())
  return notify_fail("�ǲ��ǻ��ˣ���\n");
  if(target->query("weared"))
  return notify_fail("����������Ƥ��ߡ�\n");
  if(ob->query_skill("yirong-shu",1)<50)
  return notify_fail("���������̫���ˣ��޷�������ߡ�\n");
  message_vision("$N����$n����.\n",ob,source);
  target->set("mask/name",source->query("name"));
  target->set("mask/id",source->query("id"));
  target->set("mask/short",source->short());
  target->set("mask/long",source->long());
  target->set("mask/continue",(ob->query_skill("yirong-shu",1)+30)/10);
  tell_object(ob,"��Ƥ��߻����ˣ�����Դ��ˣ�\n");
  return 1;
}