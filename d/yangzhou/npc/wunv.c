
inherit NPC;

void create()
{
   set_name("���",({ "ge ji","ge","ji"}) );
   set("gender", "Ů��" );
   set("age", 22);
		
   set("long", "���ǻ����ϵ��������˵ĸ�ˡ�\n");
       
   set("combat_exp", 30000);
   set("str", 20);
   set("per", 30);
   set_skill("unarmed",50);
   set_skill("dodge",50);
   set_skill("parry",50);
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
 
}

