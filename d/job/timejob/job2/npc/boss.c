
inherit NPC;
#include <ansi.h>
#include <job_money.h>
void create()
{
   set_name("��������",({ "ma zei","zei"}) );
        set("gender", "����" );
        set("age",30);
	set("title","��ͨ����");	
   set("long", "�������������죬�������ǳ��׺���\n");
       
   set("combat_exp",500000);
   set("str",30);
   set("cor",30);
   set_skill("force",20);
   set("force",5000);
   set("max_force",5000);
   set_skill("dodge",170);
   set_skill("parry",170);
   set_skill("finger",170);
   set_skill("cuff",170);
   set_skill("strike",170);
   set_skill("dujie-zhi",170);
   set_skill("linglong-yuquan",170);
   set_skill("lingyun-shenfa",170);
   set_skill("tianmo-dafa",170);
   set_skill("chanzong-fofa",200);
   set_skill("bikouchan",200);
   set_skill("force",170);
   set_temp("apply/armor",50+random(50));
   set("chat_chance_combat",30);
   set("jiali",100);
   set("attitude","aggressive");
   setup();
  
}

int chat()
{
  int i;
  if(!environment(this_object())) return 0;
  if(random(100)<60)
  return ::chat();
  i=random(3);
  if(i==0)
  command("perform dujie");
  else
  if(i==1)
  command("perform mie");
  else
  command("perform feiying");
  return ::chat();
}


void die()
{
   object ob,*member;
   int i; 
   object thing;
   int exp,pot;
     
   i=3+random(1);   
       while(i--){
        thing=new("/d/job/killhaidao/obj/thing");
        thing->move(this_object());}
           
   ob=query_temp("last_damage_from");
   if(!ob) return ::die();
    member=ob->query_team();
   for(i=0;i<sizeof(member);i++){
     if(member[i]&&environment(member[i])==environment(ob)){
        exp=270+random(20);
        pot=130+random(10);
        member[i]->add("combat_exp",exp);
        member[i]->add("potential",pot);
        add_shili(member[i],exp/10,100);
        if(member[i]->query("potential")>member[i]->query("max_pot")*2)
	member[i]->set("potential",member[i]->query("max_pot")*2);
        tell_object(member[i],"����ж�����õ���"+HIW+chinese_number(exp)+NOR+"�㾭�飬\n"+
                              "                  "+HIY+chinese_number(pot)+NOR+"��Ǳ�ܡ�\n");}}
   return ::die();
}
        