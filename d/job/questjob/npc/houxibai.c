
inherit NPC;
#include <ansi.h>
#include <job_money.h>
void create()
{
  
   set_name("��ϣ��",({ "hou xi bai","hou"}) );
        set("gender", "����" );
        set("age", 26);
   set("long", "���ǻ����ɵĸ��֣�Ҳ�ǻ����ɵ�Ψһ���ˡ�\n");
   set("combat_exp",2000000);
   set("str", 28);
   set("per", 26);
   set("attitude", "peaceful");
   set_skill("unarmed",260);
   set_skill("cuff",260);
   set_skill("finger",260);
   set_skill("dodge",260);
   set_skill("parry",260);
   set_skill("force",260);
   set_skill("strike",270);
   set_skill("blade",270);
   set_skill("sword",270);
   set_skill("literate",270);
   set_skill("tianyi-xuangong",270);
   set_skill("huanmo-shenfa",270);
   set_skill("zhehua-baishi",270);
   set_skill("sanhua-zhi",270);
   set_skill("baihua-zhang",270);
   
   set("max_gin",4000);
   set("max_sen",4000);
   set("max_kee",4000);
   set("max_force",4000);
   set("force",4000);
   set("jiali",200);
   create_family("������",6,"����");
  
    setup();
 
   carry_object(__DIR__"obj/tieshan")->wield();
}


   
#include "job_npc.c"