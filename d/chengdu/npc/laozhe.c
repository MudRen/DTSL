//��ͨ��npc
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("����", ({ "old man","man","oldman"}) );
       set("gender", "����" );
       set("age", 60);
       set("long",
               "��λ�Ǿþ����е����ߡ�\n");
       set("combat_exp", 32500);
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
			say( "����˵������λ" + RANK_D->query_respect(ob)
          + "��ס������60���꣬��ʲô���������!\n");
			break;
		case 1:
			say( "���߳���Ц��Ц��\n");
			break;
	}

}
