
inherit NPC;

void create()
{
   set_name("��ʿ��",({ "lin shihong","lin"}) );
        set("gender", "����" );
        set("age", 32);
		
   set("long", "����۶����Ķ���ͷ��\n");
       
   set("combat_exp", 300000);
   set("str", 20);
   set("per", 15);
   
   set_skill("force",130);
   set_skill("parry",130);
   set_skill("dodge",130);
   
  
   setup();
  
}

