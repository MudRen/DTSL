
inherit NPC;

void create()
{
   set_name("��å",({ "liu mang","liu","mang"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����һλ�ڳ����ǹ�����å��\n");
       
   set("combat_exp", 10000);
   
   
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

