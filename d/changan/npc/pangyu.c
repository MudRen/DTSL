
inherit NPC;

void create()
{
   set_name("����",({ "pang yu","pang","yu" }) );
        set("gender", "����" );
        set("age", 25);
   set("long", "����ǳ�������������������\n");
   set("shili","li");
   set("combat_exp", 500000);
   set("str", 28);
   set("per", 24);
   set("attitude", "peaceful");
   set_skill("strike",150);
   set_skill("parry",150);
   set_skill("dodge",150);
   set_skill("force",150);
   set_skill("taixu-cuoshou",160);
   set("hand",({"taixu-cuoshou"}));
   set("max_gin",1000);
   set("max_sen",1000);
   set("max_kee",1000);
   set("force",1500);
   set("max_force",1500);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

