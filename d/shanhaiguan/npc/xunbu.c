
inherit NPC;

void create()
{
   set_name("Ѳ��",({ "xun bu","xun","bu" }) );
        set("gender", "����" );
        set("age", 12);
   set("long", "����һ����ɽ������Ѳ�ߵ�Ѳ����\n");   
   set("combat_exp", 5000+random(5000));
   set("attitude", "peaceful");
   set("chat_chance",50);
   set("chat_msg",({
   	(:random_move:),
   	"Ѳ������������С�ĵ�����\n",
   	"Ѳ���������������´�����һ����\n",
   	}));
   setup();
   //carry_object("/d/gaoli/obj/cloth")->wear();
  
}

