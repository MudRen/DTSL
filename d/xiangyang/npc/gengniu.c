
inherit NPC;

void create()
{
   set_name("��ţ",({ "geng niu","niu"}) );
        set("race", "Ұ��" );
        set("combat_exp",50000);
     set("long", "����һֻ���ţ��\n");
	 set("verbs",({"bite","hoof"}));
     set("limbs",({"ͷ","β��","����","����"}));
     set("chat_chance",20);
     set("chat_msg",({
     	"��ţ���衱�ؽ���һ����\n",
     	"��ţ˦��˦β�ͣ����˼���Ұ�ݡ�\n",
     	}));
  setup();

}


