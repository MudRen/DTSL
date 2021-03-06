
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_action1();

void create()
{
   set_name("慕铁雄",({ "mu tiexiong","mu","tiexiong" }) );
   set("gender", "男性" );		
   set("age",30);
   set("nickname","悍狮");
   set("long", "他就是突厥人称「悍狮」的慕铁雄。\n");       
   set("combat_exp",100000);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("finger",100);
   set_skill("literate",100);
  
   set_skill("yanyang-dafa",100);
   set_skill("canglang-jue",100);
   set_skill("youlong-shenfa",100);  
   set_skill("tianlang-zhi",100);
  
   set("max_gin",1000);
   set("max_kee",1000);
   set("max_sen",1000);
   set("force",1000);
   set("max_force",1000);
   create_family("突厥",7,"武士");
   set("inquiry",([
     "考验":(:do_action1:),
    ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   
  
}
void attempt_apprentice(object ob)
{   
	if(ob->query("family"))
	if(ob->query("family/family_name")=="突厥")
	if((int)ob->query("family/generation",1)<=7)
	{   
	  command("say 此话从何说起？");
	  return;
	}
	if(!ob->query_temp("bai_mutiexiong_ok")){
            command("say 你没经过考验，我可不要你！");
            return;
        }
        
	ob->delete_temp("bai_mutiexiong_ok");
	command("say 好！在突厥好好学习武功，将来一统中原！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "tujue1");
}

int do_action1()
{
  object ob;
  string msg;
  
  ob=this_player();
  
  if(ob->query("family")
  &&ob->query("family/family_name")!="突厥"
    ){
    command("say 你真是说笑了！");
    return 1;
  }
  if(ob->query("family")
  &&ob->query("family/family_name")=="突厥"
    ){
    command("say 既然已是我突厥派弟子，无须再考验了！");
    return 1;
  }
  
  if(ob->query_temp("bai_mutiexiong_ok")){
    command("say 你经过考验，可以拜师了！");
    return 1;
  }
  msg="$N朝$n道：好，要成为突厥弟子先考验你一下吧！突厥弟子要求勇敢，\n"+
      "看你能不能挨过我的考验了！\n\n";
  msg+=HIR"$N抽出一把尖刀，朝$n的肩膀扎去！\n\n"NOR;
  msg+="$n疼的几欲昏死过去！\n"+
       "$N微微一笑：不错，胆量已经足够了！\n";
  ob->set("kee",10);
  ob->set_temp("bai_mutiexiong_ok",1);
  message_vision(msg,this_object(),ob);
  
  return 1;
}