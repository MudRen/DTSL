
inherit "/std/guard.c";

void create()
{
   set_name("�ٱ�",({ "bing" }) );
   set("gender", "����" );
   set("age", 32);
   set("long", "�������������ǵĹٱ��������������������ˡ�\n");
       
   set("combat_exp",800000);
   set("guard","changan");
   set("attitude", "peaceful");
   
   set_this_skills("high");
   set_all_skill(this_object(),180);
   
   setup();
   
}
