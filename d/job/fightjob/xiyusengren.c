
inherit F_FIGHT_OWNER;


void create()
{
       set_name("����ɮ��", ({ "seng ren","seng","ren"}) );
       set("gender", "����" );
       set("age", 30);
       set("long","����һ������ɮ�ˣ���˵���ж��ص��������š�\n");
       set("combat_exp", 12500);
       set("target_id","###");
       set("attitude", "peaceful");
       set("class","bonze");
       set("inquiry",([
	   "ľͷ��":(:do_action1:),
	   "���޺�":(:do_action2:),
	   "Ƥ����":(:do_action3:),
       ]));
       
       set("chat_chance",70);
       set("chat_msg",({
       	"����ɮ�˸ߺ����������������ˣ�ľͷ�ˡ����޺���Ƥ����ඣ�\n",
       	(:random_move:),
       	}));
              
       setup();

}

