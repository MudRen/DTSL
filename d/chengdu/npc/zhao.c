//��ͨ��npc
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("����Զ", ({ "zhao tianyuan","zhao","tian","yuan"}) );
       set("gender", "����" );
       set("age", 48);
       set("long",
               "�����ǳɶ���֪������Զ��\n");
       set("combat_exp", 52500);
       set("attitude", "friendly");
       
       setup();
 carry_object(__DIR__"obj/guanfu")->wear();


}
