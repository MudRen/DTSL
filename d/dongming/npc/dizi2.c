
inherit NPC;
#include <ansi.h>

int do_action1();

void create()
{
   set_name("�е���",({ "nan dizi","nan","dizi" }) );
        set("gender", "����" );
	  set("age", 20);
   set("long", "���Ƕ����ɵ�ѧ�յ��ӡ�\n");
       
   set("combat_exp",100000);
   set("str", 23);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",80);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("force",80);
   set_skill("sword",80);
   set_skill("strike",80);
   set_skill("dongming-xinfa",80);
  
   set_skill("shuiyun-xiufa",80);

   set_skill("nishang-piaoming",80);
   
   set("max_gin",500);
   set("max_sen",500);
   set("max_kee",500);
   set("force",500);
   set("max_force",500);
   set("target_id","###");
   set("inquiry",([
      "���":(:do_action1:),
      ]));
   create_family("������",7,"����");
   setup();
   carry_object(__DIR__"obj/caiyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
}

int do_action1()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("bai_dongming/action1")){
     command("?");
     return 1;
   }
   command("say ����ģ����Ƕ����ɲ����ö����۸���ģ�");
   ob->set_temp("guard_npc",this_object());
   return 1;
}