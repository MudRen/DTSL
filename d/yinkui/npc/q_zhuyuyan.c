
inherit NPC;
#include <ansi.h>

void create()
{
   
   set_name("ľ��",({ "mu ren","ren"}) );
   set("gender", "����" );
    set("combat_exp",1000000);
 
    set_skill("whip",200);
    set_skill("dodge",200);
    set_skill("parry",200);
    set_skill("force",200);
    set_skill("literate",200);
    set_skill("tianmo-jue",200);
    set_skill("tianmo-dafa",200);
    set_skill("tianmo-huanzong",200);
    set_skill("tianmo-dai",200);

    set("max_gin",3000);
    set("max_sen",3000);
    set("max_kee",3000);
    set("max_force",3000);
    set("force",3000);
 
   setup();
  
   carry_object("/d/yinkui/obj/whip")->wield();
  
  
}


int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_zhu")){
    destruct(this_object());
    return 1;
   }
   tell_object(killer,HIR"ֻ������һ����ľ�˱�ը������\n"NOR);
   tell_object(killer,"һ�ɾ޴���������ը����һ�������ڣ�\n"); 
   message("vision",HIR"�������ɡ�:"+killer->name()+HIR+"��Ϊ���������ߣ������������ٲ����ȷ�Ѫ���ˣ�\n"NOR,users());
   killer->set("family_lingwu","yingui");
   killer->set("title","��������");
   killer->reward_family_point();
   killer->move("/d/clone/room/lingwu/yingui/mishi");
   destruct(this_object());
   return 1;
}
