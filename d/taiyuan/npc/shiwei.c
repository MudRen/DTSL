inherit "/std/guard.c";

void create()
{
   set_name("����",({ "shiwei" }) );
   set("gender", "����" );
   set("age", 35);
   set("long", "���������ʹ����������������������ݡ�\n");
   set("guard","taiyuan");  
   set("combat_exp",800000);
   set("attitude", "peaceful");

   set_this_skills("high");
   set_all_skill(this_object(),180);

   setup();
}
