
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("Ů����",({ "nv dizi","nv","dizi" }) );
        set("gender", "Ů��" );
	  set("age", 20);
   set("long", "���Ƕ����ɵ�ѧ�յ��ӡ�\n");
       
   set("combat_exp",80000);
   set("str", 23);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",70);
   set_skill("dodge",70);
   set_skill("parry",70);
   set_skill("force",70);
   set_skill("sword",70);
   set_skill("strike",70);
   set_skill("dongming-xinfa",70);
  
   set_skill("shuiyun-xiufa",70);

   set_skill("nishang-piaoming",70);
  
   set("max_gin",500);
   set("max_sen",500);
   set("max_kee",500);
   set("force",500);
   set("max_force",500);
   create_family("������",7,"����");
   setup();
   carry_object(__DIR__"obj/caiyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
}
