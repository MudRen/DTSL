
inherit NPC;

void create()
{
   set_name("����",({ "xing ren","xing","ren"}) );
   set("gender", "����" );
   set("age", 30);
		
   set("long", "����һλҪȥ���ݵ����ˡ�\n");
       
   set("combat_exp", 100000);
   set("str", 26);
   
   set_skill("unarmed",50);
   set_skill("dodge",50);
   set_skill("parry",50);
  
   set("chat_chance",10);
   set("chat_msg",({
     "����˵������˵����ʮ�ַ���������Ҫȥ������\n",
     "������ǰ���������ڿ������ݵĳ����ˣ�\n",
    }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

