
#include <ansi.h>
inherit NPC;

void create()
{
   set_name("ľ��",({ "mu ren","ren"}) );
   set("gender", "����" );
  
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
   message("vision",HIG"�������ɡ�:"+killer->name()+"������Ц����¶���޾��ĵ��⣡\n"NOR,users());
   tell_object(killer,HIR"ֻ����һ����ľ��ը������Ƭ����\n"NOR);
   killer->set("family_lingwu","huajian");
   killer->set("title","���令��");
   killer->reward_family_point();
   tell_object(killer,"һ�ɾ޴�����������Ƶ�һ�����ң�\n");
   killer->move("/d/clone/room/lingwu/huajian/mishi");
   destruct(this_object());
   return 1;
}
