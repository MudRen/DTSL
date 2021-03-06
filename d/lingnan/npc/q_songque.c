
inherit NPC;
#include <ansi.h>

void create()
{
   
   set_name("木人",({ "mu ren","ren"}) );
   set("gender", "男性" );
   
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
   message("vision",HIG"【宋家堡】:宋缺仰天长笑道："+killer->name()+HIG+"战胜了我，宋家堡终于后继有人了！\n"NOR,users());
   tell_object(killer,"木人喀嚓一声裂成碎片！\n");
   tell_object(killer,"木人里落出一张字条：我宋家堡的白虎堂，那里有我们门派的一个秘密！\n"+
                      "能不能领悟，就看你自己的造化了！\n");
   killer->set("family_lingwu","songjia");
   killer->set("title","岭南一刀");
   killer->reward_family_point();
   destruct(this_object());   
   return 1;
}