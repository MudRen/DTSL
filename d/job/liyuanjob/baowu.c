#include <ansi.h>
#include <job_money.h>
inherit ITEM;
mapping name=([
HIY"��ת����"NOR:"jiuzhuan lingzhu",HIW"ҹ����"NOR:"yeming zhu",HIG"�������"NOR:"necklace",HIW"����׻�"NOR:"tigger",
HIY"������"NOR:"jin wawa",HIC"��ˮ��"NOR:"bishui zhu",HIG"���ɺ��"NOR:"shan hu",HIW"��������"NOR:"baiyu meiren",
HIC"ҹ������"NOR:"shou zhuo",HIY"��ש"NOR:"jin zhuan",HIW"������"NOR:"xiao",HIG"è��"NOR:"mao yan",HIG"���"NOR:"ma nao",
HIG"����"NOR:"qin pu",HIY"����Ȧ"NOR:"xiang quan",HIY"��ʯ"NOR:"zuan shi",HIW"��ɽѩ��"NOR:"xue lian",HIW"ǧ���˲�"NOR:"ren shen",
]);
void create()
{
   string *n;int i;
   n=keys(name);
   i=random(sizeof(n));
   set_name(n[i],({name[n[i]]}));
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("no_sell",1);
     set("no_give",1);
     set("no_drop",1);
     set("unit", "��");
     set("value", 0);
   }
   setup();
}
int is_get_of(object pal,object ob)
{
  object killer,killer2;
  if(query("owner")==pal->query("id"))
  return 1;
  if(query("target")!=pal)
 return notify_fail("�������������\n");
  killer=new(__DIR__"killer4");
  killer2=new(__DIR__"killer4");
  killer->set("combat_exp",pal->query("combat_exp"));
 if("/cmds/usr/hp.c"->get_pot(killer));
 copy_hp_item(pal,killer,"gin");
 copy_hp_item(pal,killer,"kee");
 copy_hp_item(pal,killer,"sen");
  set_all_skill(killer,pal->query("max_pot")-90);
  copy_object(killer2,killer);
  set_all_skill(killer2,pal->query("max_pot")-100);
  killer->move(environment(pal));
  killer2->move(environment(pal));
  message_vision("$N�����������������ӳ���͵���Ķ�������Ҳ���������ǲ�Ҫ���ˣ�\n",killer);
  killer->kill_ob(pal);
  killer->set_leader(pal);
  pal->kill_ob(killer);
  killer2->kill_ob(pal);
  killer2->set_leader(pal);
  pal->kill_ob(killer2);
  set("owner",pal->query("id"));
  call_out("move_baowu",2,killer,killer2);
  return 1;
}

void init()
{
  if(!query("last_time"))
   set("last_time",time());
}

int clean_up()
{
  if(time()-query("last_time")<1800)
   return 0;
  return 1;
}

void move_baowu(object killer,object killer2)
{
  if(random(2)==1)
   if(!killer) return;
   else{
   this_object()->move(killer);
   message_vision(HIC"$N�ۼ��ֿ죬���һ��������"+query("name")+"\n"NOR,killer);
   return;}
  else{
  if(!killer2) return;
   else{
   this_object()->move(killer2);
   message_vision(HIC"$N�ۼ��ֿ죬���һ��������"+query("name")+"\n!"NOR,killer2);
   return;}}
}