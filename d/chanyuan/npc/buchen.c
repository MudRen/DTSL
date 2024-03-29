
inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "bonze.h"

#define TIME_TICK1 time()*60

int do_action2();
int do_action1();
int do_action3();
int do_answer(string arg);

void create()
{

   set_name("不嗔",({ "bu chen","bu","chen"}));
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是净念禅院的四大护法金刚之首。\n");
   set("class","bonze");
   set("combat_exp", 600000);
   set("str", 28);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("strike",150);
   set_skill("force",150);

   set_skill("rulai-shenzhang",150);
   set_skill("bikouchan",150);
   set_skill("chanzong-fofa",160);
   set_skill("literate",160);
   set_skill("lianhua-step",150);
   set_skill("wuxiang-shengong",150);

   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("max_force",2000);
   set("force",2000);

   set("inquiry",([
       "考验":(:do_action1:),
       "辈份":(:do_action2:),
       "如来神掌":(:do_action3:),
       ]));
   set("perform_quest/pudu",1);
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

	if(!ob->query_temp("try_bai_buchen_ok")){
	  command("say 你没经过我的考验，我不会收你为徒的。");
	  return;
	}
	command("say 贫僧叫你去做的都是异常简单的事，你都不动怒，完成的很好，正合贫僧不嗔之意。");
	lev=ob->query_skill("cuff",1);
	lev=lev*lev/(lev+100);
	ob->party_reward_skill("strike",lev);
	tell_object(ob,HIY"\n你从基本拳法中逐渐领会了一些基本掌法！\n\n"NOR);

	command("say 阿弥陀佛！希望你以后能光传佛法，普渡众生！\n");
	command("recruit "+ob->query("id"));
	ob->delete_temp("try_bai_buchen_ok");
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "bonze");
     ob->set("chanyuan_skill","rulai-shenzhang");
}

int do_action1()
{
   object ob,obj;
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

	msg="$N对$n说道：“我这里有几棵树种，你去到华山的巨灵足、无上洞、玉女峰、\n"+
	    "朝阳峰、迎阳洞、全真崖、金天宫、落雁峰、莲花峰、莲花坪 去把它们种下吧！\n";
	message_vision(msg,this_object(),ob);
	obj=new(__DIR__"obj/shuzhong");
	obj->move(ob);
	tell_object(ob,query("name")+"给了你一"+obj->query("unit")+obj->query("name")+"。\n");
	ob->set_temp("try_bai_buchen_actoin1",1);
	return 1;
}


int do_action3()
{
   object ob;
   string str1,str2,msg;

   ob=this_player();

   if(is_fighting())
   return notify_fail("对方正忙着呢！");
   if(is_busy())
   return notify_fail("对方正忙着呢！");

   if(ob->query("perform_quest/pudu")){
     command("say 你已经掌握了如来神掌的精髓，以后你自己领悟提高吧！");
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
   if(ob->query("perform_quest/tiangang")){
     command("say 你已经掌握了天罡拳的精髓，是无法再掌握这门绝技的！");
     return 1;
   }

   if(ob->query_skill("rulai-shenzhang",1)<160){
     command("say 你的如来神掌修为太低了，现在无法掌握其中的精髓！");
     return 1;
   }
   if((int)ob->query("PKS",1)>=5)
	{
		command("say 你作孽深重，我怎么能让你继续害人？");
		return 1;
	}
   if(ob->query("bellicosity")>=100){
	  command("say 你身上杀气重重，如何能掌握此掌法的精髓呢！");
	  return 1;
   }

   if(!ob->query_temp("perform_quest_pudu")){
   	command("say 想学习如来神掌的精髓也可以，不过现在还不是时机啊！");
   	ob->set_temp("perform_quest_pudu",1);
   	return 1;
   }
  str1=CHINESE_D->chinese_date(TIME_TICK1);
  str2=CHINESE_D->chinese_date((ob->query("birthday") -14*365*24*60)*60);
  if(str1[sizeof(str1)-8..sizeof(str1)]!=str2[sizeof(str2)-8..sizeof(str2)]){
  	command("say 想学习如来神掌的精髓也可以，不过现在还不是时机啊！");
  	return 1;
  }
  ob->delete_temp("perform_quest_pudu");
  ob->set("perform_quest/pudu",1);
  command("say 很好，你能不急不燥，看来可以学习如来神掌的精髓了！");

  msg="\n$N在$n的耳边低语了几句。\n"+
      "$n低头沉思了一会，突然一笑，跪地磕了头：谢谢师傅指点！\n\n";
  message_vision(msg,this_object(),ob);
  return 1;
}
