
inherit NPC;

void create()
{
   set_name("Ǯ����",({ "qian duguan","qian"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����Ǯ����,��˵���������ɵ��ˡ�\n");
       
   set("combat_exp",200000);
   set("attitude", "peaceful");
   set_skill("unarmed",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("strike",100);
   set_skill("cuff",100);
  setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

