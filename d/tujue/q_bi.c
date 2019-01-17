

inherit NPC;
#include <ansi.h>

void create()
{
   
   set_name("ľ��",({ "mu ren","ren" }) );
   set("gender", "����" );		
      
   set("combat_exp",1000000);
   
   set_skill("unarmed",200);
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("blade",200);
   set_skill("literate",200);
   set_skill("cuff",200);
   set_skill("spear",200);
   set_skill("youlong-shenfa",200);
   set_skill("yanyang-dafa",200);
   set_skill("pojun-quan",200);
   set_skill("yanyang-quan",200);
   set_skill("yuehen-qiang",200);
   set_skill("tianlang-dao",200);
   set_skill("canglang-jue",200);
   set_skill("fuying-spear",200);

   set("apply_points",200);
   set("chat_chance_combat",100);
   set("chat_msg_combat",({
                (: command("perform fengyu") :),
                (: command("perform fengsha") :),
                (: command("exert riyue") :),
                (: command("perform lengyue") :),
                (: command("execute xiao") :),
        }));
   
   set("gin",3000);
   set("max_gin",3000);
   set("kee",3000);
   set("max_kee",3000);
   set("sen",3000);
   set("max_sen",3000);
   set("force",3000);
   set("max_force",3000);
   
   setup();
   
   carry_object(__DIR__"obj/spear")->wield(); 
}

int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_bi")){
     destruct(this_object());
     return 1;
   }
   message("vision",HIG"��ͻ  �ʡ���"+killer->name()+"������Ц���Ӵ�ͻ���ֶ���һλ����\n"NOR,users());
   
   tell_object(killer,"ľ�˿���һ���ѳ���Ƭ��\n");
   tell_object(killer,"һ�ɾ޴��������������������͵�����һ���ط���\n");
   killer->set("family_lingwu","tujue");
   killer->set("title","ͻ������");
   killer->reward_family_point();
   killer->move("/d/clone/room/lingwu/tujue/mishi");
   
   destruct(this_object());
   return 1;
}
