
inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "bonze.h"
int do_action2();
int do_action1();
int do_action3();
int do_answer(string arg);

void create()
{

   set_name("不惧",({ "bu ju","bu","ju"}));
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是净念禅院的四大护法金刚之一。\n");
   set("class","bonze");
   set("combat_exp", 600000);
   set("str", 28);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("finger",150);
   set_skill("force",150);

   set_skill("dujie-zhi",150);
   set_skill("bikouchan",150);
   set_skill("chanzong-fofa",160);
   set_skill("literate",160);
   set_skill("wuxiang-shengong",150);
   set_skill("lianhua-step",150);

   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("max_force",2000);
   set("force",2000);

   set("inquiry",([
       "考验":(:do_action1:),
       "辈份":(:do_action2:),
       "渡劫指":(:do_action3:),
       ]));
   set("perform_quest/liudao",1);
   create_family("净念禅院",5,"护法");
   setup();

}

void init()
{
   add_action("do_answer","answer");
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
	if(ob->query_temp("try_bai_buju_fail")){
	  command("say 连件僧衣你也能当做鬼，今后如何除魔卫道？这样的徒弟我不要！");
	  return;
	}
	if(!ob->query_temp("try_bai_buju_ok")){
	  command("say 你没经过我的考验，我不会收你为徒的。");
	  return;
	}

	lev=ob->query_skill("cuff",1);
	lev=lev*lev/(lev+100);
	ob->party_reward_skill("finger",lev);
	tell_object(ob,HIY"\n你从基本拳法中逐渐领会了一些基本指法！\n\n"NOR);


	command("say 阿弥陀佛！希望你以后能光传佛法，普渡众生！\n");
	command("recruit "+ob->query("id"));
	ob->delete_temp("try_bai_buju_ok");
	ob->delete_temp("try_bai_buju_fail");
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "bonze");
     ob->set("chanyuan_skill","dujie-zhi");
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

	if(time()-ob->query("mud_flags/try_bai_buju_time")<300){
	  command("say 象你这样的胆小鬼，我暂时不想见到你！");
	  return 1;
	}

	msg="$N对$n说道：“你帮我到暗房里拿件僧衣过来吧！”\n";
	message_vision(msg,this_object(),ob);
	ob->delete("mud_flags/try_bai_buju_time");
	ob->set_temp("try_bai_buju_actoin1",1);
	return 1;
}

int accept_object(object ob,object obj)
{
   if(obj->query("owner_id")!=ob->query("id"))
   return 0;
   ob->set_temp("try_bai_buju_ok",1);
   ob->delete_temp("try_bai_buju_fail");
   ob->delete_temp("try_bai_buju_actoin1");
   command("say 你临危不惧，日后定是除魔卫道的最佳人选啊。");
   return 1;
}

int do_action3()
{
   object ob;

   ob=this_player();

   if(is_fighting())
   return notify_fail("对方正忙着呢！");
   if(is_busy())
   return notify_fail("对方正忙着呢！");

   if(ob->query("perform_quest/liudao")){
     command("say 你已经掌握了渡劫指的精髓，以后你自己领悟提高吧！");
     return 1;
   }
   if(ob->query("perform_quest/tiangang")){
     command("say 你已经掌握了天罡拳的精髓，是无法再掌握这门绝技的！");
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
   if(ob->query_skill("dujie-zhi",1)<160){
     command("say 你的渡劫指修为太低了，现在无法掌握其中的精髓！");
     return 1;
   }
   if((int)ob->query("PKS",1)>=5)
	{
		command("say 你作孽深重，我怎么能让你继续害人？");
		return 1;
	}
   if(ob->query("bellicosity")>=100){
	  command("say 你身上杀气重重，如何能掌握此指法的精髓呢！");
	  return 1;
   }

   command("say 好吧，我现在就告诉你渡劫指的真正精髓！");
   fight_ob(ob);
   remove_call_out("do_fight");
   call_out("do_fight",5,ob);
   return 1;
}

int do_fight(object ob)
{
  if(!ob) return 1;
  if(!living(ob)) return 1;
  if(!is_fighting(ob)){
     command("say 你的功夫不行啊，再回去练习一下吧！");
     return 1;
  }
  command("say 小心看仔细了！！\n\n");
  set("max_pot",282);
  command("execute wuyu");
  command("perform liudao");
  call_out("do_fight2",6,ob);
  return 1;
}

int do_fight2(object ob)
{
  string msg;

  if(!ob) return 1;
  if(!living(ob)) return 1;
  if(!is_fighting(ob)){
     command("say 你的功夫不行啊，再回去练习一下吧！");
     return 1;
  }
  remove_enemy(ob);
  ob->remove_enemy(this_object());
  msg="\n\n$N微微一笑：你领会到什么了吗？\n"+
      "$n沉思一会，突然一笑，跪地磕了头：谢谢师傅！！\n\n";
  ob->set("perform_quest/liudao",1);
  message_vision(msg,this_object(),ob);
  return 1;
}
