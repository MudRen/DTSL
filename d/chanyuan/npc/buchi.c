
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
   int i;
   object *ob;

   set_name("不痴",({ "bu chi","bu","chi"}));
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是净念禅院的四大护法金刚之一。\n");
   set("class","bonze");
   set("combat_exp", 600000);
   set("str", 28);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("staff",150);
   set_skill("force",150);

   set_skill("fumo-zhangfa",150);
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
       "伏魔杖法":(:do_action3:),
       ]));
   set("perform_quest/fumo",1);
   create_family("净念禅院",5,"护法");
   setup();

   ob=children(__DIR__"obj/xiangmo-zhang");
   for(i=0;i<sizeof(ob);i++)
     if(environment(ob[i])&&userp(environment(ob[i]))){
     tell_object(environment(ob[i]),"你手中的"+ob[i]->query("name")+"被它的主人收回去了！\n");
     if(ob[i]->query("equipped"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"被一阵风卷走了。\n");
     destruct(ob[i]);}
     else destruct(ob[i]);

   carry_object(__DIR__"obj/xiangmo-zhang")->wield();

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
	if(!ob->query_temp("try_bai_buchi_ok")){
	  command("say 你没经过我的考验，我不会收你为徒的。");
	  return;
	}

	lev=ob->query_skill("cuff",1);
	lev=lev*lev/(lev+100);
	ob->party_reward_skill("staff",lev);
	tell_object(ob,HIY"\n你从基本拳法中逐渐领会了一些基本杖法！\n\n"NOR);

	command("say 阿弥陀佛！希望你以后能光传佛法，普渡众生！\n");
	command("recruit "+ob->query("id"));
	ob->delete_temp("try_bai_butan_ok");
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "bonze");
     ob->set("chanyuan_skill","fumo-zhangfa");
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
	if(time()-ob->query("mud_flags/try_bai_buchi_time")<300){
	  command("say 你还是过一段时间再来找我吧！");
	  return 1;
	}

	msg="$N对$n说道：“我可要考验你一下！\n"+
	"你觉得身处乱世，是战斗经验（exp）重要啊，是战斗技能（skills）重要啊，\n"+
	"还是金钱（gold）重要啊？”\n";
	message_vision(msg,this_object(),ob);
	ob->set_temp("try_bai_buchi_actoin1",1);
	ob->delete("mud_flags/try_bai_buchi_time");
	return 1;
}

int do_answer(string arg)
{
  object ob;
  string msg;

  ob=this_player();

  if(!ob->query_temp("try_bai_buchi_actoin1")&&
     !ob->query_temp("try_bai_buchi_actoin2"))
  return 0;
  if(!arg||
      (arg!="exp"&&
       arg!="skill"&&
       arg!="gold"&&
       arg!="agree"&&
       arg!="disagree"
       )
     )
  return notify_fail("请正确回答问题。\n");

 if(ob->query_temp("try_bai_buchi_actoin1")){
   if(arg!="exp"&&arg!="skill"&&arg!="gold")
   return notify_fail("请正确回答问题。\n");
  if(arg=="exp")
    msg="$N对$n说道：“好，但你重视经验只会固步自封难以成长，我现在废你经验，你愿意吗？”\n";
  if(arg=="skill")
    msg="$N对$n说道：“你的功夫都已过时，是时候破旧立新了，拜入我门下就该废去武功，你愿意吗？”\n";
  if(arg=="gold")
    msg="N对$n说道：“我们寺院也该修葺一下了，你把全部财富捐献给禅院怎样？”\n";
  ob->delete_temp("try_bai_buchi_actoin1");
  ob->set_temp("try_bai_buchi_actoin2",arg);
  message_vision(msg,this_object(),ob);
  return 1;
 }

 if(arg!="agree"&&arg!="disagree")
 return notify_fail("请正确回答问题。\n");

 if(arg=="disagree"){
   ob->delete_temp("try_bai_buchi_actoin2");
   ob->set("mud_flags/try_bai_buchi_time",time());
   msg="$N朝$n叹道：看来你和我还是无缘啊！\n";
   message_vision(msg,this_object(),ob);
   return 1;
 }

 msg=ob->query_temp("try_bai_buchi_actoin2");
 switch(msg){

  case "exp":
     msg="$N伸出手指向$n太阳穴刺去，刹那间$n脑内一片空白，也许没有战斗经验就是\n"+
         "这样的吧。$N说道：“你不迷恋事物，正合为师不痴的性格，以后就跟着为师\n"+
         "学习吧。”\n";
     break;
  case "skill":
     msg="$N一掌拍在$n头顶上，$n全身一震，手脚麻痹，似乎再也不能施展以前所学的武功了。\n"+
     "$N说道：“你不迷恋事物，正合为师不痴的性格，以后就跟着为师学习吧。”\n";
     break;
  case "gold":
     msg="$N伸手到$n口袋，把$n全部现金和存款拿走。\n"+
     "$N说道：“你不迷恋事物，正合为师不痴的性格，以后就跟着为师学习吧。”\n";
 }

 message_vision(msg,this_object(),ob);
 ob->delete_temp("try_bai_buchi_actoin2");
 ob->set_temp("try_bai_buchi_ok",1);
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

   if(ob->query("perform_quest/fumo")){
     command("say 你已经掌握了伏魔杖法的精髓，以后你自己领悟提高吧！");
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
   if(ob->query("perform_quest/pudu")){
     command("say 你已经掌握了如来神掌的精髓，是无法再掌握这门绝技的！");
     return 1;
   }

   if(ob->query_skill("fumo-zhangfa",1)<160){
     command("say 你的伏魔杖法修为太低了，现在无法掌握其中的精髓！");
     return 1;
   }
   if((int)ob->query("PKS",1)>=5)
	{
		command("say 你作孽深重，我怎么能让你继续害人？");
		return 1;
	}
   if(ob->query("bellicosity")>=100){
	  command("say 你身上杀气重重，如何能掌握此杖法的精髓呢！");
	  return 1;
   }

   command("say 伏魔杖的绝学是还有一招，但只能意会，不可言传！\n"+
           "你到本寺的一些佛像那里去领会一下吧！");
   ob->set_temp("perform_quest/fumo_action1",1);
   return 1;
}
