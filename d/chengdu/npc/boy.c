//��ͨ��npc
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("С��", ({ "boy"}) );
       set("gender", "����" );
       set("age", 10);
       set("long",
               "����һ��С�к���\n");
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
			say( "С��˵������λ" + RANK_D->query_respect(ob)
          + "�ҳ�����Ҫ��Ϊһ�����ָ���!\n");
			break;
		case 1:
			say( "С�к�������Ц��Ц��\n");
			break;
	}

}
