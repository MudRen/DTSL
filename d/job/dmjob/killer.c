
inherit NPC;
#include <job_money.h>
#include <ansi.h>
mapping name1=([
"��":"zhou","��":"wu","֣":"zheng","��":"wang",
"��":"zhao","Ǯ":"qian","��":"sun","��":"li",
]);
string *name2=({"һ","��","��","��","��","��","��","��","��","ʮ"});
void create()
{
   string *myname;
   int i;
   
   myname=keys(name1);
   i=random(sizeof(myname));
   set_name(myname[i]+name2[random(sizeof(name2))],({name1[myname[i]]}) );
        set("gender", "����" );
        set("age",42);
        set("long","����һ������������ĵ�����\n"); 
    set("combat_exp",10000);
     set_skill("sword",70);
     set_skill("dodge",70);  
  set_skill("strike",70);
     set_skill("parry",70);
     set_skill("piaomeng-jianfa",70);
     set_skill("bihai-jianfa",70);
set_skill("youyue-zhangfa",70);
  set_skill("shuiyun-xiufa",70);
  set_skill("nishang-piaoming",70);
     set_skill("force",70);
     set_skill("dongming-xinfa",70);
  setup();
   carry_object(__DIR__"obj/changjian")->wield();
  
}

 void improve_level()
{
  add_temp("apply/damage",random(100));
  add_temp("apply/dodge",random(100));
}
