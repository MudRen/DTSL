//��ͨ��npc
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("��ʿ", ({ "wu shi","wu","shi"}) );
       set("gender", "����" );
       set("age", 20);
       set("long",
               "�������м����е���ʿ��\n");
       set("combat_exp", 72500);
       set("attitude", "friendly");
       
       setup();
 carry_object(__DIR__"obj/cloth")->wear();
 carry_object("/clone/weapon/changjian")->wield();

}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
	 

	if (!ob || !present(ob, environment())) return;
	switch( random(2) ) {
		case 0:
			say( "��ʿ˵������λ" + RANK_D->query_respect(ob)
          + "�ҵ��书�ɲ��Ǵ����!\n");
			break;
		case 1:
			say( "��ʿ�����������㡣\n");
			break;
	}

}
