
inherit NPC;

void create()
{
   set_name("����",({ "dao ke","ke" }) );
   set("gender", "����" );
   set("age", 30+random(5));
   set("long", "����һ�����ͣ��������糾���͡�\n");
       
   set("combat_exp",500000);
   set("str", 26);
   set_skill("blade",150);
   set_skill("leveltwo-blade",150);
   set_skill("dodge",150);
   set_skill("babu-ganchan",150);
   set_skill("force",150);
   set_skill("parry",150);
   
   set("max_gin",1500);
   set("max_kee",1500);
   set("max_sen",1500);
   set("max_force",2000);
   set("force",2000);
   set("chat_chance",20);
   set("chat_msg",({
     "����һ�ӵ��������ɳ����ʲô���ҵ����������ܱȣ�\n",
     "���ͻ��˻ӵ������̺���������\n",
   }));
   
   set("inquiry",([
     "�ຣ��":"�����Ǹ��õط�������ɳĮ�����˺ܾã����������\n",
     "ɳĮ":"����̫�����ˣ������һ�������ȥһ�Σ�\n",
    ]));
    setup();
   carry_object(__DIR__"obj/blade")->wield();
   add_money("silver",30);
}

