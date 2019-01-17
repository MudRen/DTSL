#include <ansi.h>
#include <job_money.h>
inherit ITEM;
mapping name=([
HIY"��ת����"NOR:"jiuzhuan lingzhu",HIW"ҹ����"NOR:"yeming zhu",HIG"�������"NOR:"necklace",HIW"����׻�"NOR:"tigger",
HIY"������"NOR:"jin wawa",HIC"��ˮ��"NOR:"bishui zhu",HIG"���ɺ��"NOR:"shan hu",HIW"��������"NOR:"baiyu meiren",
HIC"ҹ������"NOR:"shou zhuo",HIY"��ש"NOR:"jin zhuan",HIW"������"NOR:"xiao",HIG"è��"NOR:"mao yan",HIG"���"NOR:"ma nao",
HIG"����"NOR:"qin pu",HIY"����Ȧ"NOR:"xiang quan",HIY"��ʯ"NOR:"zuan shi",HIW"��ɽѩ��"NOR:"xue lian",HIW"ǧ���˲�"NOR:"ren shen",
]);
#include "want_owner.h"

int do_give(string arg);
int do_name(string arg);
int do_hecheng(string arg);
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
     set("no_give",1);
     set("no_drop",1);
     set("unit", "��");
     set("value", 0);
     set("baowu",1);
     
   }
   setup();
   
}
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
  if(userp(environment(this_object())))
  	set("no_get",1);
  
}

int clean_up()
{
  if(time()-query("last_time")<300)
   return 0;
  return 1;
}


string *weaponclass=({
"blade","sword","spear","fork","staff","hammer","axe","dagger","whip"});
string to_weapon(string arg)
{
  switch(arg){
  
  case "blade":return "����";
  case "sword":return "����";
  case "spear":return "ǹ��";
  case "fork":return "����";
  case "staff":return "����";
  case "hammer":return "����";
  case "axe":return "����";
  case "dagger":return "ذ����";
  case "whip":return "����";}
}
//maybe give money or exp or pot or weapon.
int do_give(string arg)
{
   object ob;
   object target;
   int money,pot,exp;
   string name,target_name;
   string weapon;
  
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
   
   if(ob->query_temp("dm_job_find")){
   ob->delete_temp("dm_job_find");
   ob->delete_temp("dm_job_find_where");
   ob->delete_temp("have_killer");
   ob->delete_temp("dtsl_job");}
  
   switch(random(4)){
   case 0:
   money=ob->query("max_pot")*2*100;
   ob->add("deposit",money);
   tell_object(ob,target->name()+"������"+MONEY_D->money_str(money)+"��\n");
   add_shili(ob,1,money/500);
   break;
   case 1:
   pot=150+random(50);
   ob->add("potential",pot);
   tell_object(ob,target->name()+"��������"+HIY+chinese_number(pot)+"��Ǳ�ܡ�\n");
   break;
   case 2:
   exp=260+random(40);
   ob->add("combat_exp",exp);
   tell_object(ob,target->name()+"��������"+HIY+chinese_number(exp)+"�㾭�顣\n");
   add_shili(ob,exp/10,1);
   break;
   case 3:
   weapon=weaponclass[random(sizeof(weaponclass))];
   ob->set_temp("will_get_weapon/owner",base_name(target));
   ob->set_temp("will_get_weapon/weapon",weapon);
   present(name,ob)->set("give_weapon",base_name(target));
   tell_object(ob,target->name()+"��������һ��"+to_weapon(weapon)+"�ı�������ʹ��\n"+
               "want id �������� with �������� ����ȡ��������������֧����ɫ�ַ�����\n");
   return 1;
   break;}
   destruct(present(name,ob));
   return 1;
}

int do_name(string arg)
{
   object ob;
   object target;
   string wp,target_name,name;
   object new_weapon;
   
   ob=this_player();
   if(!ob->query_temp("will_get_weapon"))
   return 0;
   if(!arg||sscanf(arg,"%s %s with %s",target_name,wp,name)!=3)
   return notify_fail("��ʹ��want id �������� with �������� ��Ҫ������\n");
   if(!objectp(target=present(target_name,environment(ob))))
   return notify_fail("����û������ˣ�\n");
   if(!present(name,ob))
   return notify_fail("������û�����������\n");
   if(present(name,ob)->query("want_owner")!=base_name(target))
   return notify_fail("������ô����ˡ�\n");
   if(ob->query_temp("will_get_weapon/owner")!=base_name(target))
   return notify_fail("������ϴ����˰ɣ���\n");
        wp=replace_string(wp,"$HIR$",""HIR"");
	wp=replace_string(wp,"$HIG$",""HIG"");
	wp=replace_string(wp,"$HIY$",""HIY"");
	wp=replace_string(wp,"$HIW$",""HIW"");
	wp=replace_string(wp,"$HIB$",""HIB"");
	wp=replace_string(wp,"$HIM$",""HIM"");
	wp=replace_string(wp,"$HIC$",""HIC"");
	wp=replace_string(wp,"$GRN$",""GRN"");
	wp=replace_string(wp,"$RED$",""RED"");
	wp=replace_string(wp,"$BLK$",""BLK"");
	wp=replace_string(wp,"$YEL$",""YEL"");
	wp=replace_string(wp,"$BLU$",""BLU"");
	wp=replace_string(wp,"$MAG$",""MAG"");
	wp=replace_string(wp,"$CYN$",""CYN"");
	wp=replace_string(wp,"$WHT$",""WHT"");
	wp=wp+NOR;
   
   new_weapon=new(__DIR__"weapon/"+ob->query_temp("will_get_weapon/weapon"));
   new_weapon->set("name",wp);
   new_weapon->set("weapon_prop/damage",random(ob->query("max_pot")));
   new_weapon->set("max_strong",random(ob->query("max_pot")));
   new_weapon->set("strong",new_weapon->query("max_strong"));
   new_weapon->move(ob);
   tell_object(ob,target->name()+"������һ"+new_weapon->query("unit")+
               new_weapon->query("name")+"��\n");
   ob->delete_temp("will_get_weapon");
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