
inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include <job_money.h>
#include "bonze.h"

int do_action2();
int do_action1();
int do_action3();
int do_answer(string arg);

string *dirs=({
"/d/hengshan","/d/taishan","/d/wuyishan","/d/huashan",
});

void create()
{

   set_name("不贪",({ "bu tan","bu","tan"}));
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是净念禅院的四大护法金刚之一。\n");
   set("class","bonze");
   set("combat_exp", 600000);
   set("str", 28);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("cuff",150);
   set_skill("force",150);

   set_skill("tiangang-quan",150);
   set_skill("wuxiang-shengong",150);
   set_skill("bikouchan",150);
   set_skill("chanzong-fofa",160);
   set_skill("literate",160);
   set_skill("lianhua-step",150);

   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("max_force",2000);
   set("force",2000);

   set("inquiry",([
       "考验":(:do_action1:),
       "辈份":(:do_action2:),
       "天罡拳":(:do_action3:),
       ]));
   set("perform_quest/tiangang",1);
   create_family("净念禅院",5,"护法");
   setup();

}


void attempt_apprentice(object ob)
{
	int lev;

	if(ob->query("family")
	   &&ob->query("family/family_name")=="净念禅院"
	   &&ob->query("family/generation",1)<=5){
	    command("say 你可真会开玩笑！");
	    return;
	}

	if(ob->query("gender")=="女性")
	{
	    command("say 唉，施主身为女子之身，不便与男弟子学习佛法。若施主真心希望\n"+
	            "归依佛门大可到慈航静斋。");
	    return;
	}

	if(ob->query("couple")){
	  command("say 身为人夫却不尽夫之责任，我们净念禅院不要如此不仁不义之徒。");
	  return;
	}

	if((int)ob->query("PKS",1)>=5)
	{
		command("say 施主你作孽深重，我如何收你为徒呢！");
		return;
	}

	if(ob->query("bellicosity")>=100){
	  command("say 施主身上杀气重重，如何能专心归依佛门呢！");
	  return;
	}
	if(ob->query_skill("wuxiang-shengong",1)<100){
	  command("say 你的「无相神功」修为太低了，还是去学习一下再拜我为师吧！");
	  return;
	}
	if(ob->query("office_number")<30){
	  command("say 你的功绩太低了，我不喜欢懒惰的弟子！");
	  return;
	}
	if(ob->query("family/generation",1)>7){
	  command("say 你的辈分太低了，如何拜我为师？");
	  return;
	}
	if(!ob->query_temp("try_bai_butan_ok")){
	  command("say 你没经过我的考验，我不会收你为徒的。");
	  return;
	}

	lev=ob->query_skill("cuff",1);
	lev=lev*lev/(lev+100);
	ob->party_reward_skill("cuff",lev);
	tell_object(ob,HIY"\n你对基本拳法有了新的认识！\n\n"NOR);

	command("say 阿弥陀佛！希望你以后能光传佛法，普渡众生！\n");
	command("recruit "+ob->query("id"));
	ob->delete_temp("try_bai_buchi_ok");
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
    ob->set("class", "bonze");
    ob->set("chanyuan_skill","tiangang-quan");
}

int do_action1()
{
   object ob;
   string msg;

   ob=this_player();

        if(ob->query("family")
	   &&ob->query("family/family_name")=="净念禅院"
	   &&ob->query("family/generation",1)<=5){
	    command("say 你可真会开玩笑！");
	    return 1;
	}

        if(ob->query("family/generation")<=6){
          command("say 你已经经过考验，无须再次考验了！");
          return 1;
        }

	if(ob->query("gender")=="女性")
	{
	    command("say 唉，施主身为女子之身，不便与男弟子学习佛法。若施主真心希望\n"+
	            "归依佛门大可到慈航静斋。");
	    return 1;
	}

	if(ob->query("couple")){
	  command("say 身为人夫却不尽夫之责任，我们净念禅院不要如此不仁不义之徒。");
	  return 1;
	}

	if((int)ob->query("PKS",1)>=5)
	{
		command("say 施主你作孽深重，我如何收你为徒呢！");
		return 1;
	}

	if(ob->query("bellicosity")>=100){
	  command("say 施主身上杀气重重，如何能专心归依佛门呢！");
	  return 1;
	}
	if(ob->query_skill("wuxiang-shengong",1)<100){
	  command("say 你的「无相神功」修为太低了，还是去学习一下再拜我为师吧！");
	  return 1;
	}
	if(ob->query("office_number")<30){
	  command("say 你的功绩太低了，我不喜欢懒惰的弟子！");
	  return 1;
	}
	if(ob->query("family/generation",1)>7){
	  command("say 你的辈分太低了，如何拜我为师？");
	  return 1;
	}
	if(ob->query_temp("try_bai_butan_actoin2")){
	  command("say 我可不喜欢贪财的弟子！");
	  return 1;
	}

	msg="$N对$n说道：“你的精神不太好，先去休息一下吧！”\n";
	message_vision(msg,this_object(),ob);
	ob->set_temp("try_bai_butan_actoin1",1);
	return 1;
}

int accept_object(object ob,object obj)
{
   if(!ob->query_temp("try_bai_butan_actoin2"))
   return 0;
   if(!obj->query("bai_butan_quest"))
   return 0;
   command("say 你不贪财宝，正和我的心愿！");
   ob->delete_temp("try_bai_butan_actoin2");
   ob->set_temp("try_bai_butan_ok",1);
   return 1;
}

int do_action3()
{
   object ob,target;

   ob=this_player();

   if(is_fighting())
   return notify_fail("对方正忙着呢！");
   if(is_busy())
   return notify_fail("对方正忙着呢！");

   if(ob->query("perform_quest/tiangang")){
     command("say 你已经掌握了天罡拳的精髓，以后你自己领悟提高吧！");
     return 1;
   }
   if(ob->query("perform_quest/pudu")){
     command("say 你已经掌握了如来神掌的精髓，是无法再掌握这门绝技的！");
     return 1;
   }
   if(ob->query("perform_quest/fumo")){
     command("say 你已经掌握了伏魔杖法的精髓，是无法再掌握这门绝技的！");
     return 1;
   }
   if(ob->query("perform_quest/liudao")){
     command("say 你已经掌握了渡劫指的精髓，是无法再掌握这门绝技的！");
     return 1;
   }

   if(ob->query_skill("tiangang-quan",1)<160){
     command("say 你的天罡拳修为太低了，现在无法掌握其中的精髓！");
     return 1;
   }
   if((int)ob->query("PKS",1)>=5)
	{
		command("say 你作孽深重，我怎么能让你继续害人？");
		return 1;
	}
   if(ob->query("bellicosity")>=100){
	  command("say 你身上杀气重重，如何能掌握此拳法的精髓呢！");
	  return 1;
   }

   command("say 我有个弟子，只练武功，忽略佛法，走火入魔，你去给他讲讲佛法(jiangjing)。");
   target=new(__DIR__"dizi1");
   target->set("target_id",ob->query("id"));
   target->set("last",time());
   if(!random_place(target,dirs)){
     command("say 他最近跑到哪里去了呢？让我想想... ...");
     return 1;
   }
   if(!environment(target)){
     command("say 他最近跑到哪里去了呢？让我想想... ...");
     return 1;
   }
   command("say 据说他最近跑到了"+MISC_D->find_place(environment(target))+"，你去试试看吧！");
   ob->add_temp_array("job_temp_killer",target);
   return 1;
}
