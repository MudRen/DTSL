
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("��",({ "horse"}) );
        set("race", "Ұ��" );
     set("long", "����һƥ���������ǳ��á�\n");
     set("verbs",({"hoof"}));
	 set("limbs",({"ͷ","��","����"}));
     set("chat_chance",50);
     set("chat_msg",({
     "���ͷ���˼��ڲݡ�\n",
     "������ͷ��������˻���˼�����\n",
     }));
  setup();

}
