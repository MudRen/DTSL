
inherit NPC;

void create()
{
   set_name("����ҿ�������",({ "npc"}) );
        set("gender", "����" );
        set("age", 32);
    setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

