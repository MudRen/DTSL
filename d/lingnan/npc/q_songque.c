
inherit NPC;
#include <ansi.h>

void create()
{
   
   set_name("ľ��",({ "mu ren","ren"}) );
   set("gender", "����" );
   
   set("combat_exp",1000000);
  
    set_skill("blade",200);
    set_skill("dodge",200);
    set_skill("parry",200);
    set_skill("force",200);
    set_skill("tiandao-bajue",200);
    set_skill("anxiang-fuying",200);
    set_skill("tiangang-sanjue",200);
    set_skill("wangdao-jue",200);
    set_skill("literate",200);

    set("max_gin",3000);
    set("max_kee",3000);
    set("max_sen",3000);
    set("max_force",3000);
    set("force",3000);
   
   setup();
 
   carry_object(__DIR__"obj/blade")->wield();
   
  
}

int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_song")){
   	destruct(this_object());   	
        return 1;
   }
   message("vision",HIG"���μұ���:��ȱ���쳤Ц����"+killer->name()+HIG+"սʤ���ң��μұ����ں�������ˣ�\n"NOR,users());
   tell_object(killer,"ľ�˿���һ���ѳ���Ƭ��\n");
   tell_object(killer,"ľ�������һ�����������μұ��İ׻��ã��������������ɵ�һ�����ܣ�\n"+
                      "�ܲ������򣬾Ϳ����Լ����컯�ˣ�\n");
   killer->set("family_lingwu","songjia");
   killer->set("title","����һ��");
   killer->reward_family_point();
   destruct(this_object());   
   return 1;
}