//��ͨ��npc
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("Ů��", ({ "girl"}) );
       set("gender", "Ů��" );
       set("age", 10);
       set("long",
               "����һ��СŮ����\n");
       set("combat_exp", 12500);
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
			say( "СŮ��˵������λ" + RANK_D->query_respect(ob)
          + "���ܸ����������?\n");
			break;
		case 1:
			say( "СŮ��������Ц��Ц��\n");
			break;
	}

}
