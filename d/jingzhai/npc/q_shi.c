
#include <ansi.h>

inherit NPC;

void create()
{
  
   set_name("ľ��",({ "mu ren","ren" }) );
   set("gender", "����" );
       
    set("combat_exp",1000000);
    set("max_gin",3000);
    set("max_sen",3000);
    set("max_kee",3000);
    set("max_force",3000);
    set("force",3000);
    set_skill("sword",200);
    set_skill("parry",200);
    set_skill("dodge",200);
    set_skill("finger",200);
    set_skill("literate",200);
    set_skill("force",200);
    set_skill("sekong-jianfa",200);
    set_skill("xiuluo-zhi",200);
    set_skill("wuwang-jing",200);
    set_skill("qingxin-force",200);
    set_skill("lingyun-shenfa",200);

   setup();
  
   carry_object(__DIR__"obj/changjian")->wield();
  
}

int surrender(object killer,object victim)
{
   if(killer->query_temp("dtsl_fquest_jz/step2")){
    killer->delete_temp("dtsl_fquest_jz/step2");
    killer->set_temp("dtsl_fquest_jz/step3",1);
    tell_object(killer,"ľ�˿���һ���ѳ���Ƭ��\n");
    tell_object(killer,"��ľ���������һ��ֽ������д�ţ�\n��˵�����˼��ڳ�������������ƶ����У���ȥ���ҿ��ɣ�\n");
    destruct(this_object());
    return 1;}
    destruct(this_object());
    return 1;
}
