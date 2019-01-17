
inherit ITEM;
#include <ansi.h>
int do_paste(string arg);
void create()
{
        set_name(HIY"�����"NOR, ({"mixed"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
    else  {
           set("unit", "��");
           set("yrs","mixed");
           set("long", "����һ����ۺ�ʯ���Ļ���\n");
        }
}

void init()
{
  add_action("do_paste","paste");
}

int do_paste(string arg)
{
  object ob;
  object target;
  string name;
  
  ob=this_player();
  if(!ob->query("dtsl_quest_yrs_ok"))
  return notify_fail("���"+query("name")+"������ȥ�ؿ���������ʲô����.\n");
  if(!arg||sscanf(arg,"on %s",name)!=1)
  return notify_fail("��Ҫ�ѻ����ճ��ʲô���棿\n");
  if(!objectp(target=present(name,ob)))
  return notify_fail("������û�����������\n");
  if(target->query("yrs")!="skin")
  return notify_fail("����ﲻ��ճ��"+target->name()+"����ȥ��\n");
  message_vision(YEL"$NС������ذ�"+query("name")+"ճ����"+target->name()+"��ȥ��\n",ob);
  target->set("step1",1);
  destruct(this_object());
  return 1;
}