
inherit NPC;
void create()
{
   set_name("���Ա",({ "li" }) );
        set("gender", "����" );
        set("age", 42);
   set("long", "����������ĵ������֣�ר�Ű���������ļ�в�֮ʿ��\n");
       
   set("combat_exp", 500000);
   set("shili","wang");
   set("str", 10);
   set("per", 22);
   set("attitude", "peaceful");
   
   setup();
   carry_object(__DIR__"obj/guanfu")->wear();
  
}

void init()
{
}


