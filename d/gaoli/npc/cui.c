// ����˫����
//cui.c 
 
inherit NPC;

void create()
{
        set_name("������", ({ "cui minggui", "cui" }));
        set("age", 48);
        set("gender", "����");
        set("long","���ǽ��̺ŵĴ��ƹ�,�ǽ�����˵������֡�/n");
        set("attitude", "peaceful");
   set("str", 20);
        set("combat_exp", 500000);
   set("max_kee", 2400);
   set("max_mana", 2200);
   set("max_sen", 2400);
   set("max_force", 2200);
   set("force", 2200);
   set("force_factor", 100);
        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("force", 150);
        setup();
        carry_object("/d/gaoli/obj/pao3")->wear();
}
