
#include <ansi.h>
inherit ITEM;

int do_find();

void create()
{
        set_name("�ر�ͼ", ({ "paper" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ųر�ͼ�������ʹ��[soucha]�����ұ��");
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
                set("value", 300);
                set("material", "wood");
        }

        setup();
}

void init()
{
  add_action("do_find","soucha");
}
int do_find()
{
  object ob;string here;
  object baowu;
  
  ob=this_player();
  if(!ob->query_temp("liyuan_job/step"))
  return notify_fail("�㿴�˿����ܣ����ֱ�������������\n");
  here=base_name(environment(ob));
  if(here!=query("target_where"))
  return notify_fail("�㿴�˿����ܣ����ֱ�������������\n");
  baowu=new(__DIR__"baowu");
  baowu->set("target",ob);
  baowu->move(environment(ob));
  message_vision("$N�ҵ���һ�����\n",ob);
  destruct(this_object());
  return 1;
}
