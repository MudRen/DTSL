
inherit "/std/guard.c";

void create()
{
   set_name("�ٱ�",({ "bing" }) );
   set("gender", "����" );
   set("age", 32);
   set("long", "����һ���������ٵĹٱ���\n");
       
   set("combat_exp",800000);  
   set("attitude", "peaceful");
   set("chat_chance",50);
   set("guard","pengliang");
   set("chat_msg",({
   	(:random_move:),
      "���ٺȵ����������̵ĸ�������������\n",
   }));
   
   set_this_skills("high");
   set_all_skill(this_object(),160);
   
   setup();
  
  
}

