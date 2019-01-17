
#include <ansi.h>

inherit ITEM;

int do_pingluan(string arg);

void create()
{
        set_name("������", ({ "paper" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "");
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
                set("value", 300);
                set("material", "wood");
        }

        setup();
}

string long()
{
  return "\n"+
  "������������������������������������\n"+
  "����һ�Źٸ����İ������飬����д��:  \n"+
  "��˵���"+query("target_name")+"��������,\n"+
  "����������ʹȥ����ƽ�ҡ�          \n"+
  "������������������������������������\n";
}

void init()
{
  add_action("do_pingluan","pingluan");
}

int do_pingluan(string arg)
{
  object ob;
  object target;
  int cost;
  
  ob=this_player();
  if(!arg)
  return notify_fail("��Ҫƽ��˭�����ң�\n");
  if(!objectp(target=present(arg,environment(ob))))
  return notify_fail("����û������ˣ�\n");
  if(query("target_place")!=base_name(target))
  return notify_fail(target->name()+"һЦ����û����ʲô�£���ʲô������ƽ�ң�\n");
  if(ob->query_temp("liyuan_job/step")!=9)
  return notify_fail("��û��Ȩ����ƽ�ң�\n");
  
  cost=1500+random(500);
  
  switch(MONEY_D->player_pay(ob,cost)){
    case 0:
    case 2:
    return notify_fail("�����ϵ�Ǯ����������ƽ�����ң�\n");
    break;
    default:break;}
  ob->add_temp("liyuan_job/step",1);
  message_vision("$NЦ������Ȼ�����Ϊ���ս��ң��ǰ��ջ����в�ӵ��֮��\n",
                  target);
  tell_object(ob,"��ɹ���ƽ���˷��ң�\n");
  destruct(this_object());
  return 1;
}
  