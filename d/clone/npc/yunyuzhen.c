
inherit NPC;

void create()
{
   set_name("������",({ "yun yuzhen","yun"}) );
        set("gender", "Ů��" );
        set("age",22);
        set("per",25);
        set("nickname","��۰���");
        set("long","����Ǿ��������ΰ���������������\n"+
                   "�����ƹ��걻�˴�ɱ�󣬰��ε�Ů����\n"+
                   "������Ѿ��������������ɫ������\n"+
                   "��տ����ʤ�˸�������Ϊ�������ֵĵ�\n"+
                   "һӢ�ơ�\n");
               
        set("combat_exp",400000);
        set_skill("parry",150);
        set_skill("dodge",150);
        set_skill("force",150);
        set_skill("sword",150);
        set_skill("leveltwo-sword",150);
        set_skill("niaozong-shu",150);
        set("shili/name","junkun_b");
        set("chat_chance_combat",30);
        set("chat_msg_combat",({
        	(:apply_action,"leveltwo-sword",4,"damage":),
             }));
             
        set("inquiry",([
          "�����":"��Ҳ���󱾰�����������ֲ��࣬���Ѻͺ�ɱ��Ⱦ����ġ�\n",
          "������":"�ܾ�û�п������ˣ������е�������\n",
          "����":"�����ʵ�ˣ���... ... �������Ѿ��ܾ�û�����ˡ�\n",
          ]));
    setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/tongxiao")->wield();
  
}

