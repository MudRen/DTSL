
inherit NPC;

#include <ansi.h>
void create()
{
   set_name("������",({ "song yuzhi","song","yuzhi" }) );
   set("gender", "Ů��" );
   set("age", 22);
   set("long", "�������μұ��������¡�\n");
       
   set("combat_exp", 300000);
   set("per", 27);
   set("gin",1000);
   set("max_gin",1000);
   set("kee",1000);
   set("max_kee",1000);
   set("sen",1000);
   set("max_sen",1000);
   set("force",1000);
   set("max_force",1000);
   set_skill("tiandao-bajue",100);
   set_skill("blade",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("unarmed",100);
   set_skill("cuff",100);
   set_skill("anxiang-fuying",100);
   set_skill("force",110);
   set_skill("tiangang-sanjue",100);
   set_skill("poyu-quan",100);  
   create_family("�μұ�",5,"����");
   set("shili",([
      "name":"songjia_b",
      ]));
   
   set("inquiry",([
    "����":"��һ�ĳư����£��͵�������˼��ı���ͣ��Ҹ���ô���أ�\n",
    "������":"���������ѣ�����ȥ�ɶ���ʯ����˰ɣ�\n",
    "��ȱ":"���ǼҸ��������ſ��ٳư����£�����\n"
    ]));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
   carry_object(__DIR__"obj/blade")->wield();
  
}


