
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("ŷ��ٻ",({ "ouyang qian","ouyang","qian" }) );
        set("gender", "Ů��" );
	set("age", 30);
        set("title","���º��");
   set("long", "��������������ٵ˧֮һ��������ȱ�ĵ������֡�\n");
       
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
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("unarmed",100);
   set_skill("cuff",100);
   set_skill("literate",100);
   set_skill("anxiang-fuying",100);
   set_skill("force",110);
   set_skill("tiangang-sanjue",100);
   set_skill("poyu-quan",100);
   set("shili",([
      "name":"songjia_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth2")->wear();
  
}

