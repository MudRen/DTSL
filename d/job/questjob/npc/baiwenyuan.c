
inherit NPC;

void create()
{
   set_name("����ԭ",({ "bai wenyuan","bai"}) );
        set("gender", "����" );
        set("age", 22);
		
   set("long", "���Ǿ�������ð�����ĸ��֣�Ҳ�����ĵ�����\n"+
               "���ף����Ĵ�����������\n");
       
   set("combat_exp", 30000);
   set("str", 30);
   set("per", 26);
   
   set_skill("force",140);
   set_skill("parry",140);
   set_skill("dodge",140);
   set_skill("sword",140);
   
   set_skill("babu-ganchan",140);
   set_skill("leveltwo-sword",140);
   
   setup();
   carry_object(__DIR__"obj/changjian")->wield();
  
}

