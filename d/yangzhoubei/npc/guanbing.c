
inherit NPC;

void create()
{
   set_name("�ٱ�",({ "guan bing","guan","bing" }) );
        set("gender", "����" );
           set("long", "����һ������ϴ���ϰ��յĹٱ���\n");
          set("combat_exp", 5000);
   set("str", 30);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/junfu")->wear();
  carry_object(__DIR__"obj/blade")->wield();
}

