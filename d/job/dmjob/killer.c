
inherit NPC;
#include <job_money.h>
#include <ansi.h>
mapping name1=([
"周":"zhou","吴":"wu","郑":"zheng","王":"wang",
"赵":"zhao","钱":"qian","孙":"sun","李":"li",
]);
string *name2=({"一","二","三","四","五","六","七","八","九","十"});
void create()
{
   string *myname;
   int i;

   myname=keys(name1);
   i=random(sizeof(myname));
   set_name(myname[i]+name2[random(sizeof(name2))],({name1[myname[i]]}) );
        set("gender", "男性" );
        set("age",42);
        set("long","这是一个到东溟盗宝的盗贼。\n");
    set("combat_exp",10000);
     set_skill("sword",70);
     set_skill("dodge",70);
  set_skill("strike",70);
     set_skill("parry",70);
     set_skill("piaomeng-jianfa",70);
   //   set_skill("bihai-jianfa",70);
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
