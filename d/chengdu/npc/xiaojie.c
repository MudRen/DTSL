//��ͨ��npc
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("С��", ({ "lady"}) );
       set("gender", "Ů��" );
       set("age", 20);
       set("long",
               "���ǳɶ�������ҵĴ�С�㡣\n");
       set("combat_exp", 22500);
       set("attitude", "friendly");
       
       setup();
 carry_object(__DIR__"obj/cloth")->wear();
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
			say( "С��˵������λ" + RANK_D->query_respect(ob)
          + "�����ҿ�����ȥ��������ѽ!\n");
			break;
		case 1:
			say( "С�㿴�˿��㡣\n");
			break;
	}

}
