

inherit NPC;

#include <ansi.h>

void create()
{
  
  set_name("ľ��",({ "mu ren","ren"}) );
   set("gender", "����" );
   
  set("max_kee",3000);
  set("max_gin",3000);
  set("max_sen",3000);
  set("max_force",3000);
  set("force",3000);
  set("combat_exp",1000000);
 
  set_skill("literate", 200);
  set_skill("sword", 200);
  set_skill("force", 200);
  set_skill("dodge", 200);
  set_skill("parry", 200);
  set_skill("jiuxuan-dafa",200);
  set_skill("yijian-shu",200);
  set_skill("jiuzhuan-jianjue",200);
  set_skill("xingyun-dodge",200);
  
  setup();
 
  carry_object(__DIR__"obj/sword")->wield();
}

int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_fu")){
   	destruct(this_object());
        return 1;
   }
   message("vision",HIG"���Ľ��ɡ���������������Х�����Ľ��������ֶ���һλ"+HIW+"��  ��"+HIG+killer->name()+HIG+"��\n"NOR,users());
   tell_object(killer,"ľ�˿���һ���ѳ���Ƭ��\n");
   tell_object(killer,"ľ����ͻȻ����һ��ǿ���������\n");
   killer->set("family_lingwu","yjp");
   killer->set("title","��  ��");
   killer->reward_family_point();
   message_vision("������������������һ���µĵط���\n",victim,killer);
   killer->move("/d/clone/room/lingwu/yjp/qishi");
   
   destruct(this_object());
   return 1;
}