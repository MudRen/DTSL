
inherit "/std/guard.c";

void create()
{
   set_name("����",({ "shi wei","shiwei","wei" }) );
   set("gender", "����" );
   set("age", 32);
   set("long", "���������ʹ���������\n");
       
   set("combat_exp",800000);
   set("attitude", "peaceful");
   set("guard","xucheng");
   
   set_this_skills("high");
   set_all_skill(this_object(),180);
   
   setup();
  
  
}
