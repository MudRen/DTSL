// ����˫����
//��ͷ��


inherit NPC;

void create()
{
  set_name("��ͷ", ({"jiao tou", "jiao", "tou"}));
  set("title", "�Ľ����״�����");
  set("gender", "����");
  set("age", 38);
  set("combat_exp",300000);
  set_skill("unarmed", 145);
  set_skill("strike",145);
  set_skill("leg",145);
  set_skill("literate", 145);
  set_skill("sword", 145);
  set_skill("force", 145);
  set_skill("dodge", 145);
  set_skill("parry", 145);
  set_skill("jiuxuan-dafa",100);

  setup();
  
  create_family("�Ľ���", 6, "����");
  carry_object(__DIR__"obj/cloth")->wear();
  carry_object(__DIR__"obj/sword")->wield();
}
