inherit "/std/guard.c";

void create()
{
   set_name("������",({ "jinyi wei","wei" }) );
   set("gender", "����" );
   set("age", 30);
   set("long", "���ǻʳ��еĽ�������������ȥ������Ѳ�ߡ�\n");

   set("combat_exp",800000);
   set("guard","changan");
   set("attitude", "peaceful");

   set_this_skills("high");
   set_all_skill(this_object(),180);

   setup();
    carry_object(__DIR__"obj/jinyi")->wear();
}
