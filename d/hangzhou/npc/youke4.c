
inherit NPC;

void create()
{
   set_name("�ο�",({ "you ke","you","ke"}) );
        set("gender", "����" );
        set("age",80);
   set("long", "����һ�������ݹ۹���οͣ�������\n"+
               "�������硣\n");
       
   set("combat_exp",100000);
   set("str", 30);
   set("attitude", "peaceful");
   set("chat_chance",30);
   set("chat_msg",({
	   "�ο�˵������������ݣ�һ��Ҫ�úõ���һ�ˣ�\n",
	   "�ο�̾��������������ϣ��������ң���֪��ʲôʱ�������������ˡ�\n",
	   "�ο�˵�����������Ů���������ף���Ҳ����ȥ���԰���\n",
   }));
   setup();
   carry_object(__DIR__"obj/guaigun")->wield();
  
}

