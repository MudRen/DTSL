
inherit NPC;
#include <ansi.h>

void create()
{
   
   set_name("ľ��",({ "mu ren","ren"}) );
   set("gender", "����" );
    set("combat_exp",1000000);
    set_skill("whip",200);
    set_skill("parry",200);
    set_skill("dodge",200);
    set_skill("force",200);
    set_skill("literate",200);
    set_skill("dongming-xinfa",200);
    set_skill("bihai-force",200);
    set_skill("shuiyun-xiufa",200);
    set_skill("nishang-piaoming",200);
    
    set("max_gin",3000);
    set("max_sen",3000);
    set("max_kee",3000);
    set("max_force",3000);
    set("force",3000);
  
   setup();
   
   carry_object(__DIR__"obj/whip")->wield();
  
}

int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_shan")){
     destruct(this_object());
     return 1;
   }
   message("vision",HIG"�������ɡ����������������Х������Ӣ�����ˣ�"+killer->name()+HIG+"�ѳ�Ϊ���ɶ���ս����\n"NOR,users());
   
   tell_object(killer,"ľ�˿���һ���ѳ�����Ƭ��\n");
   tell_object(killer,"ľ�������һ��ֽ������д����������һ�����������ķ��ĵط���\n"+
                      "��˵�ں��ߵ����´�����һֱû�����ҵ��������ܲ����ҵ���������ˣ�\n");
   killer->set("family_lingwu","dongming");
   killer->set("title","����ս��");
   killer->reward_family_point();
   destruct(this_object());
   return 1;
}