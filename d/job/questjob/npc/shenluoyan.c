
inherit NPC;

void create()
{
   set_name("������",({ "shen luoyan","shen"}) );
        set("gender", "Ů��" );
        set("age", 26);
		
   set("long", "���������㣬�����������µ�һıʿ��\n");
       
   set("combat_exp",600000);
   set_skill("sword",182);
   set_skill("dodge",182);
   set_skill("force",182);
   set_skill("parry",182);
   set_skill("leveltwo-sword",182);
   set_skill("niaozong-shu",182);
   
   set("max_kee",1000);
   set("max_sen",1000);
   set("max_force",1000);
   set("force",1000);
   
   set("str", 20);
   set("per", 26);
   set("inquiry",([
      "����":"�Һ����ǵ������ѣ������������ҿ�����\n",
      "������":"���Ļ��ǲ����ڿ��٣���������������ͷ���ˡ�\n",
      "����":"�����ҵ����ӣ���ʲô��Ҫ��ת����\n",
      ]));
   setup();
  carry_object(__DIR__"obj/changjian")->wield();
}

