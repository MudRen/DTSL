inherit NPC;
#include <ansi.h>
void create()
{
   set_name("��ˬ",({ "song shuang","song","shuang" }) );
        set("gender", "����" );
set("age", 42);
   set("long", "�������μұ�����ˬ������ȱ�ı��ң����ĵ���Ҳ�ǲ��ס�\n");
set("combat_exp", 300000);
   set("str", 28);
   set("per", 24);
   set("attitude", "peaceful");
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
   set_skill("literate",100);
   set_skill("anxiang-fuying",100);
   set_skill("force",110);
   set_skill("tiangang-sanjue",100);
   set_skill("poyu-quan",100);
   // set_skill("yinlong-guaifa",150);
   set_skill("staff",200);
   create_family("�μұ�",3,"����");
set("shili",([
      "name":"songjia_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth2")->wear();
   carry_object(__DIR__"obj/blade")->wield();

}
