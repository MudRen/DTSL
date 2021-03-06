
#include <ansi.h>
inherit NPC;

void create()
{
   set_name("木人",({ "mu ren","ren"}) );
   set("gender", "男性" );
  
    set("combat_exp",1000000);
    set_skill("dodge",200);
    set_skill("parry",200);
    set_skill("force",200);
    set_skill("strike",200);
    set_skill("busi-yin",200);
    set_skill("blade",200);
    set_skill("literate",200);
    set_skill("bencao-shuli",200);
    set_skill("tianyi-xuangong",200);
    set_skill("huanmo-shenfa",200);
    set_skill("zhehua-baishi",200);
    set_skill("baihua-zhang",200);
    set("apply_points",200);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: command("execute yin") :),
        (: command("perform baihua") :),
    }));

    setup();
   carry_object(__DIR__"obj/cloth")->wear();
}



int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_shi")){
     destruct(this_object());
     return 1;
   }
   message("vision",HIG"【花间派】:"+killer->name()+"纵声狂笑，显露出无尽的得意！\n"NOR,users());
   tell_object(killer,HIR"只听砰一声，木人炸成了碎片！！\n"NOR);
   killer->set("family_lingwu","huajian");
   killer->set("title","花间护法");
   killer->reward_family_point();
   tell_object(killer,"一股巨大的力量把你推到一间密室！\n");
   killer->move("/d/clone/room/lingwu/huajian/mishi");
   destruct(this_object());
   return 1;
}
