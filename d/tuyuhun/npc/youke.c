
inherit NPC;

void create()
{
   set_name("�ο�",({ "you ke","you","ke" }) );
   set("gender", "����" );
   set("age", 32);
   set("long", "����һ���ο͡�\n");
       
   set("combat_exp", 5000);
   set("chat_chance",20);
   set("chat_msg",({
     "�ο��޵�������ķ羰����������\n",
     "�οͶ��������������ס����������������\n",
   }));
   setup();
 //  carry_object(__DIR__"obj/cloth")->wear();
  
}

