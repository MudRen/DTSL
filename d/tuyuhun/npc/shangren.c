
inherit NPC;

void create()
{
   set_name("����",({ "shang lv","shang","lv" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����һ�������ķ������á�\n");
       
   set("combat_exp", 5000);
   set("attitude", "friendly");
   setup();
 //  carry_object(__DIR__"obj/cloth")->wear();
  
}

