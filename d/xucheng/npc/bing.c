
inherit "/std/guard.c";

void create()
{
   set_name("�ٱ�",({ "bing" }) );
   set("gender", "����" );
   set("age", 32);
   set("long", "����������ǵ�κ���ٱ���\n");
   set("guard","xucheng");
   set("combat_exp",800000);  
   set("attitude", "peaceful");
   
   set_this_skills("high");
   set_all_skill(this_object(),180);
   
   setup();
  
}
