
inherit NPC;

#include <ansi.h>
#include <job_money.h>

void create()
{
   set_name("ϯӦ",({ "xi ying","xi"}) );
        set("gender", "����" );
        set("age",40);
        set("nickname","���");
		
   set("long", "�����˳������ϯӦ�������ط���ԭ��\n"+
               "��һ�����£�����ʿ��磬˶�����ݣ�\n"+
               "���濴ȥһ�����ʱ�򣬾�ֹ���ţ���\n"+
               "�����ݵ����Ϲ���΢Ц����ֻҪ�����\n"+
               "��Ũ�ܵ�üë���ǶԷ�������עĿ����\n"+
               "������ɷ�������͸��а��Ͳ��̡�\n");
       
   set("combat_exp", 30000);
   set("str", 20);
   set("per", 10);
   
   set_skill("strike",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   
   set_skill("ziqi-tianluo",100);
   set_skill("niaozong-shu",100);
   
   set("max_kee",2000);
   set("max_gin",2000);
   set("max_sen",2000);
   set("force",2000);
   set("max_force",2000);
   setup();
  
}



#include "job_npc.c"