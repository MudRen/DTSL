
inherit NPC;

void create()
{
   set_name("��å",({ "liu mang","liu","mang"}) );
        set("gender", "����" );
        set("age", 22);
		
   set("long", "���������������������µ���å��\n");
       
   set("combat_exp", 5000);
   set("str", 20);
   set("per", 25);
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
  set("attitude", "peaceful");
  set("chat_chance",30);
  set("chat_msg",({
	  "��å�ߵ��������첻�£��ز��£�˭�ܹܵ����ң�\n",
	  "��å����������ι��������������ǲ������鷳?\n",
	  "��å�ٺ�Ц������û��Ư����椰�������һ����\n",
	  "��å����ؿ��˿���Χ.\n",
  }));

   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

