
inherit NPC;

void create()
{
   set_name("����ʢ",({ "tao shusheng","tao"}) );
        set("gender", "����" );
        set("age", 40);
   set("long", "�����Ƿ����������Ĵ�ִ��֮����\n"); 
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

