
inherit ITEM;
#include <ansi.h>
#include <job_money.h>
mapping name=(["������":"yu zhuo","����":"letter","����":"tie",
"����":"book","���":"yu chi","�ײı��۵�":"dan","��ӡ":"yin",
]);
int do_give(string arg);
void create()
{
   string *na;int i;
   na=keys(name);
   i=random(sizeof(na));
   set_name(na[i], ({name[na[i]]}));
   set_weight(600);
   if( clonep() )
     set_default_object(__FILE__);
   else {
   set("unit","��");
    set("owner",1);
   }
   setup();
}
void init()
{
  add_action("do_give","song");
}

int do_give(string arg)
{
  object ob,target;
  int exp,coin,pot;
  ob=this_player();
  if(!arg) return notify_fail("��Ҫ��"+this_object()->name()+"��˭��\n");
  if(!objectp(target=present(arg,environment(ob))))
  return notify_fail("����û������ˣ�\n");
  if(this_object()->query("owner")!=
     base_name(target)||!ob->query_temp("job/rong_job"))
  return notify_fail("�Է����������������\n");
  ob->delete_temp("job/rong_job");
  ob->delete_temp("dtsl_job");
  ob->set("busy_time",time());
  if(ob->query("combat_exp")<150000)
  exp=ob->query("max_pot")/3;
  else exp=200+random(30);
  if(ob->query("combat_exp")<1000000)
  pot=ob->query("max_pot")/4;
  else pot=120+random(10);
  coin=1000;
  ob->add("combat_exp",exp);
  ob->add("potential",pot);
  ob->add("deposit",coin);
  add_shili(ob,exp/3,coin/2);
  tell_object(ob,"����˰Ѻ���������ж�����õ���"+HIW+chinese_number(exp)+NOR+"�㾭��ֵ.\n"+
                 HIY+chinese_number(pot)+NOR+"��Ǳ��"+chinese_number(coin)+"��ͭǮ\n");
  tell_object(ob,target->name()+"Ц����лл�ˣ�\n");
  tell_object(ob,"���Ǯׯ��������ˣ�\n");
  destruct(this_object());
  return 1;
}
