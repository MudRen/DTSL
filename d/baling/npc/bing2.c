
inherit "/std/guard.c";

void create()
{
   set_name("�ٱ�",({ "bing" }) );
   set("gender", "����" );
   set("age", 32);
   set("long", "����һ���ڰ������Ѳ�ߵĹٱ���\n");
       
   set("combat_exp",800000);
   set("guard","baling");
   set("attitude", "friendly");
   
   set_this_skills("high");
   set_all_skill(this_object(),180);
   
   setup();
 
}
