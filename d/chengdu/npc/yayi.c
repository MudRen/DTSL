//��ͨ��npc
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("����", ({ "ya yi","ya","yi"}) );
       set("gender", "����" );
       set("age", 28);
       set("long",
               "�������ŵ����ۡ�\n");
       set("combat_exp", 52500);
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
			say( "����˵������λ" + RANK_D->query_respect(ob)
          + "�㻹���ȹ�����˵��!\n");
			break;
		case 1:
			say( "���ۺȵ�:��~~~~~~~~�䡣\n");
			break;
	}

}
