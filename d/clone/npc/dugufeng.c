
inherit NPC;

void create()
{
   set_name("���·�",({ "dugu feng","dugu","feng" }) );
        set("gender", "Ů��" );
        set("age", 22);
   set("long", "���Ƕ��·��ĸ��ֶ��·\n");
   set("shili","dugu");
   set("combat_exp",600000);
   set("str", 28);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",200);
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("sword",200);
   set_skill("cuff",200);
   set_skill("dugu-jianfa",200);
   set_skill("youming-zhang",200);
   set("max_gin",1500);
   set("max_sen",1500);
   set("max_kee",2000);
   set("force",3000);
   set("max_force",3000);
   setup();
   carry_object(__DIR__"obj/cloth-f")->wear();
   carry_object(__DIR__"obj/xiuhuaxie")->wear();
   carry_object(__DIR__"obj/sword")->wield();
  
}

