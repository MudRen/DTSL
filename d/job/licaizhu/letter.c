
 
inherit ITEM;
#include <ansi.h>

int do_give(string arg);
void create()
{
   set_name(HIY"���"NOR, ({"qing jian","qing","jian"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��������\n");
                set("unit", "��");
                set("no_sell",1);
                set("no_drop",1);
                set("no_give",1);
               
        }
}

void init()
{
  add_action("do_give","song");
}

int do_give(string arg)
{
  object ob,target;
  int sil;
  
  ob=this_player();
  if(!arg)
  return notify_fail("��Ҫ������͸�˭��\n");
  if(!ob->query_temp("li_song_job"))
  return 0;
  if(!objectp(target=present(arg,environment(ob))))
  return notify_fail("����û������ˣ�\n");
  if(!userp(target))
  return notify_fail("�������ֻ�ܸ���ң�\n");
  if(query("target_id")!=target->query("id"))
  return notify_fail("���ʹ�����ˣ�\n");
  
  sil=100+ob->query("max_pot")-random(5);
  ob->add("deposit",sil);
  ob->delete_temp("li_song_job");
  ob->delete_temp("dtsl_job");
  ob->set("busy_time",time());
  tell_object(ob,"�����������ó�"+MONEY_D->money_str(sil)+",�������С�\n");
  tell_object(ob,"���Ǯׯ��������ˣ�\n");
  destruct(this_object());
  return 1;
}