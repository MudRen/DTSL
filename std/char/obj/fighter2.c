
inherit FIGHTER;

void create()
{
   set_name("���޺�",({ "tie luohan","tie","luohan"}) );
   set("gender", "����" );
   set("age", 22);
		
   set("long", "����һ�����޺���������������һģһ����\n");       
   set("combat_exp",5000);
   set("str", 20);
   set("per", 25);
   set_skill("force",20);
   set_skill("dodge",20);
   set_skill("parry",20);
   
   set_skill("strike",20);
   set_skill("tieluohan-skill",20);
   set_skill("lianhua-step",20);
  
   setup();
   
}

