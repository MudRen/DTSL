
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("�п�̩",({ "shang kuitai","shang","kuitai" }) );
   set("gender", "����" );
   set("nickname","����ս��");
   set("age", 22);
   set("long", "���Ƕ����ɵĻ����Ľ�֮һ��\n");
       
   set("combat_exp",100000);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("strike",100);
   
   set_skill("dongming-xinfa",100);
   set_skill("bihai-force",100);
   set_skill("youyue-zhangfa",100);
   set_skill("nishang-piaoming",100);
   set_skill("literate",100);
  
   set("max_gin",1000);
   set("max_sen",1000);
   set("max_kee",1000);
   set("force",1000);
   set("max_force",1000);
   create_family("������",7,"����");
   setup();
  
}
