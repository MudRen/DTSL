
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("����", ({ "dizi","di","zi"}) );
       set("gender", "����" );
	   set("title","�������");
       set("age", 25);
       set("long",
               "�����Ĵ���һ��ﴨ������ŵ��ӡ�\n");
       set("combat_exp",40000);
       set("attitude", "peaceful");
	   
	   set("force",300);
	   set("max_force",300);
	   set_skill("force",40);
	   set_skill("fork",40);
	   setup();
 carry_object(__DIR__"obj/cloth")->wear();
 carry_object(__DIR__"obj/fork")->wield();

}










