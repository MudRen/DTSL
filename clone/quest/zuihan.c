#include <ansi.h>

inherit NPC;

void create()
{
   set_name("��",({ "zui han","zui","han"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����һ���ȶ��˵���������ɢ����һ�ɾ�����\n");
       
   set("combat_exp",500000);
   
   
   setup();
   
   add_money("gold",10);
  
}

void die()
{
   object ob;
   int pot;
   
   ob=query_temp("last_damage_from");
   if(!ob) return ::die();
   
   pot=200+random(100);
   ob->add("potential",pot);
   
   tell_object(ob,"��õ���"+HIY+chinese_number(pot)+NOR+"��Ǳ�ܣ�\n");
   
   return ::die();
   
}