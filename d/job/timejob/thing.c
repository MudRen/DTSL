#include <ansi.h>
#include <job_money.h>
inherit ITEM;
mapping name=([
HIY"��ת����"NOR:"jiuzhuan lingzhu",HIW"ҹ����"NOR:"yeming zhu",HIG"�������"NOR:"necklace",HIW"����׻�"NOR:"tigger",
HIY"������"NOR:"jin wawa",HIC"��ˮ��"NOR:"bishui zhu",HIG"���ɺ��"NOR:"shan hu",HIW"��������"NOR:"baiyu meiren",
HIC"ҹ������"NOR:"shou zhuo",HIY"��ש"NOR:"jin zhuan",HIW"������"NOR:"xiao",HIG"è��"NOR:"mao yan",HIG"���"NOR:"ma nao",
HIG"����"NOR:"qin pu",HIY"����Ȧ"NOR:"xiang quan",HIY"��ʯ"NOR:"zuan shi",HIW"��ɽѩ��"NOR:"xue lian",HIW"ǧ���˲�"NOR:"ren shen",
]);

//#include "want_owner.h"

void create()
{
   string *n;int i;
   string *w;
   
   n=keys(name);
   i=random(sizeof(n));
   set_name(n[i],({name[n[i]]}));
   set_weight(5000);
   
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("no_sell",1);
     set("unit", "��");
     set("value", 0);
     set("baowu",1);
     
   }
   setup();
   
}

/*

string *part=({"left","right","up","down","center"});
string to_part(string arg)
{
   switch(arg){
   case "left":return "���";
   case "right":return "�ұ�";
   case "up":return "�ϱ�";
   case "down":return "�±�";
   case "center":return "�м�";}
}
string long()
{
  
  string *w;
  int i;
  if(query("long")) return query("long");
  if(random(100)>60){
    w=keys(want_owner);
    i=random(sizeof(w));
    set("want_owner",want_owner[w[i]]);
    set("long","��˵����"+w[i]+"һֱ��Ҫ�ı��\n");}
  else 
  if(random(100)==38){
  	set_name(YEL"��Ƥ"NOR,({"yang pi","pi"}));
  	i=random(sizeof(part));
  	set("part",part[i]);
  	set("quest",1);
  	set("long","����������һ����Ƥ����ͼ��"+to_part(part[i])+"���֡�\n");}
  else
  set("long","���һ�������ı��\n");
  return query("long");
}


void init()
{
  if(!query("last_time"))
   set("last_time",time());
  add_action("do_give","xianbao");
  add_action("do_name","want");
  add_action("do_hecheng","hecheng");
}

int clean_up()
{
  if(time()-query("last_time")<300)
   return 0;
  return 1;
}


int do_give(string arg)
{
   object ob;
   object target;
   object q_ob;
   int exp,pot;
   string name,target_name;
  
   ob=this_player();
   if(!query("want_owner")) return 0;
   if(!arg||sscanf(arg,"%s %s",target_name,name)!=2)
   return notify_fail("��Ҫ�׸�˭ʲô���\n");
   if(!objectp(target=present(target_name,environment(ob))))
   return notify_fail("����û������ˣ�\n");
   if(!present(name,ob))
   return notify_fail("������û�����������\n");
   if(present(name,ob)->query("want_owner")!=base_name(target))
   return notify_fail(target->name()+"һҡͷ����������ҿɲ���Ҫ��\n");
   if(present(name,ob)->query("give_weapon")==base_name(target))
   return notify_fail(target->name()+"˵�����㵽����Ҫʲô���ֵı�����\n");
   message_vision("$N��$nЦ����лл�����ҵ���ô���Ķ�����\n",target,ob);
   
   
   if(ob->query("combat_exp")>=3000000){
   	q_ob=new("/d/job/questjob/quest"+(random(TOTAL_Q_JOB)+1));
   	q_ob->move(ob);
   	tell_object(ob,target->name()+"������һ�����\n");}
   	
   if(ob->query_temp("dm_job_find")){
   ob->delete_temp("dm_job_find");
   ob->delete_temp("dm_job_find_where");
   ob->delete_temp("have_killer");
   ob->delete_temp("dtsl_job");}
     
   exp=230+random(40);
   pot=110+random(10);
   ob->add("combat_exp",exp);
   ob->add("potential",pot);
   if(ob->query("potential")>ob->query("max_pot"))
     ob->set("potential",ob->query("max_pot"));
   tell_object(ob,target->name()+"��������"+HIW+chinese_number(exp)+NOR+"�㾭�顣\n");
   tell_object(ob,"��������"+HIY+chinese_number(pot)+NOR+"��Ǳ�ܡ�\n");
   add_shili(ob,exp/10,1);
   
   destruct(present(name,ob));
   return 1;
}


int do_hecheng(string arg)
{
   object ob;
   object part1,part2,part3,part4,part5;
   string p1,p2,p3,p4,p5;
   string *content;
   int i;
   object baowu;
   
   ob=this_player();
   if(!arg||sscanf(arg,"%s and %s and %s and %s and %s",
    p1,p2,p3,p4,p5)!=5)
   return notify_fail("��Ҫ�ϳ�ʲô��\n");
   if(!objectp(part1=present(p1,ob)))
   return notify_fail("������û��"+p1+"��\n");
   if(!objectp(part2=present(p2,ob)))
   return notify_fail("������û��"+p2+"��\n");
   if(!objectp(part3=present(p3,ob)))
   return notify_fail("������û��"+p3+"��\n");
   if(!objectp(part4=present(p4,ob)))
   return notify_fail("������û��"+p4+"��\n");
   if(!objectp(part5=present(p5,ob)))
   return notify_fail("������û��"+p5+"��\n");
   if(!part1->query("quest")||!part2->query("quest")||
   !part3->query("quest")||!part4->query("quest")||
   !part5->query("quest")||!query("quest"))
   return notify_fail("��Щ�������ܺϳ���һ��\n");
   content=({"left","right","up","down","center"});

     if(member_array(part1->query("part"),content)==-1)
      return notify_fail("��Щ�������ܺϳ���һ��\n");
      content=content-({part1->query("part")});
     if(member_array(part2->query("part"),content)==-1)
      return notify_fail("��Щ�������ܺϳ���һ��\n");
      content=content-({part2->query("part")});
     if(member_array(part3->query("part"),content)==-1)
      return notify_fail("��Щ�������ܺϳ���һ��\n");
      content=content-({part3->query("part")});
     if(member_array(part4->query("part"),content)==-1)
      return notify_fail("��Щ�������ܺϳ���һ��\n");
      content=content-({part4->query("part")});
     if(member_array(part5->query("part"),content)==-1)
      return notify_fail("��Щ�������ܺϳ���һ��\n");
      content=content-({part5->query("part")});
   tell_object(ob,"�㽫�⼸����ƤС�ĵ�ƴ����������\n");
   baowu=new(__DIR__"map");
   baowu->move(ob);
   if(part1!=this_object())
   destruct(part1);
   if(part2!=this_object())
   destruct(part2);
   if(part3!=this_object())
   destruct(part3);
   if(part4!=this_object())
   destruct(part4);
   if(part5!=this_object())
   destruct(part5);
   destruct(this_object());
   return 1;
}

*/