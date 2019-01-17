
inherit ITEM;

#include <ansi.h>
#include <job_money.h>


int do_xianbao(string arg);

void create()
{
   set_name("�ر�ͼ", ({ "map"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
     set("duobao_job",1);
     set("rumor",1);
     set("no_drop",1);
     set("no_give",1);
     set("no_get",1);
     set("unit", "��");
     set("value", 4000000);
     set("long","����һ���ر�ͼ��\n");
   }
   setup();
}

void init()
{
    add_action("do_xianbao","xianbao");
}

int do_xianbao(string arg)
{
   object ob,target;
   int exp,money,pot;
   
   ob=this_player();
   if(!arg)
   return notify_fail("��Ҫ��˭�ױ���\n");
   if(!objectp(target=present(arg,environment(ob))))
   return notify_fail("����û������ˡ�\n");
if(base_name(environment(target))!="/d/haisha/fenzangpeng")
   return notify_fail("����ͼ����BUG��Ұ�ı���ʦ�����ˣ�\n");
   if(!query("duobao_job"))
   return notify_fail("��ô���ı���ɲ�Ҫ�״����ˣ�\n");
   
   ob->delete("job");
  ob->delete_temp("dtsl_job");
  
  ob->set("busy_time",time());
  exp=300+random(50);
  pot=ob->query("max_pot")*2/3;
  money=ob->query("max_pot")+random(30);
  
  ob->add("combat_exp",exp);
  ob->add("potential",pot);
  if(ob->query("potential")>ob->query("max_pot")*3/2)
  ob->set("potential",ob->query("max_pot")*3/2);
  ob->add("deposit",money);
 add_shili(ob,exp,money);
 
 tell_object(ob,"��ʤ����һЦ���ã�"+RANK_D->query_respect(ob)+",�����ģ�\n");
  tell_object(ob,"����ж���õ���"+HIW+chinese_number(exp)+NOR+"�㾭�顣\n");
  tell_object(ob,"����ж���õ���"+HIY+chinese_number(pot)+NOR+"��Ǳ�ܡ�\n");
  tell_object(ob,"                "+HIW+chinese_number(money/100)+NOR+"��������\n");
  tell_object(ob,"���Ǯׯ��������ˣ�\n");
  destruct(this_object());
  return 1;
}
  
