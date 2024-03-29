
inherit NPC;
inherit F_MASTER;
string do_quest1();
string do_quest2();
string do_jzzy_quest1();
string do_jzzy_quest2();
string do_jzzy_quest3();
void create()
{
   set_name("师妃喧",({ "shi feixuan","shi" }) );
        set("gender", "女性" );
        set("age", 22);
   set("long", "这是慈航静斋的师妃喧。\n");

   set("combat_exp",4000000);
   set("str", 25);
   set("per", 30);
   set("max_gin",6000);
   set("max_kee",6000);
   set("max_sen",6000);
   set("max_force",6000);
   set("force",6000);
   set("attitude", "peaceful");
   set_skill("sword",300);
   set_skill("cuff",300);
   set_skill("parry",300);
   set_skill("strike",300);
   set_skill("dodge",300);
   set_skill("finger",300);
   set_skill("literate",300);
   set_skill("force",300);
   set_skill("sekong-jianfa",300);
  //  set_skill("piaokong-zhang",300);
  //  set_skill("jingxin-quan",300);
   set_skill("xiuluo-zhi",300);
   set_skill("wuwang-jing",300);
   set_skill("qingxin-force",300);
   set_skill("lingyun-shenfa",300);
   set("hand",({"piaokong-zhang","jingxin-quan","xiuluo-zhi"}));
   set("sword",({"sekong-jianfa"}));
   set("dodge",({"lingyun-shenfa"}));
   create_family("慈航静斋",6,"弟子");
   set("inquiry",([
      "徐子陵":"他乃是人中之龙，你又怎能找的到他？\n",
      "寇仲":"他的刀法的确高明，如今谁又敢和他比试武艺呢？\n",
      "梵清惠":(:do_quest1:),
      "玄女":(:do_quest2:),
      "大石寺":(:do_jzzy_quest1:),
      "罗汉":(:do_jzzy_quest2:),
      "鸠摩罗":(:do_jzzy_quest3:),
      ]));
   setup();
   carry_object(__DIR__"obj/baiyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();

}

void attempt_apprentice(object ob)
{

	if(ob->query("gender")=="男性")
	{
	  command("say 我们慈航静斋不收男弟子的。\n");
	  return;
	}

	if(ob->query("family_lingwu")=="jingzhai"){
	  command("say 你是本门玄女，我可不敢收你为徒！\n");
	  return;}

	if(ob->query("family")&&ob->query("family/family_name")!="慈航静斋")
	{
	  command("say 我们慈航静斋不收其他门派的叛徒的。\n");
	  return;
	}
	if(ob->query("kar")<24)
	{
	  command("say 唉，看你面象于佛无缘，你还是投靠其他门派吧！\n");
	  return;
	 }
	if(ob->query_int()<31)
	{
	  command("say 你的头脑不够聪明啊，好好学学再来吧！\n");
	  return;
	 }
	if(ob->query("int")<27)
	{
	  command("say 你的先天悟性太低了，看来你与我们慈航静斋是没有这个缘分了！\n");
	  return;
	 }
       if(ob->query_skill("qingxin-force",1)<150)
       {
       	 command("say 你的[清心普善诀]修炼还不够，继续去修炼吧！\n");
       	 return;
       	}
	command("say 好,既然能拜到我的门下，说明你真的能够忍受修炼的艰苦!\n");
	command("say 希望你以后能普善济世，为武林造福！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "jingzhai2");
}

string do_quest1()
{
  object ob;
  ob=this_player();
  if(ob->query("family_lingwu")=="jingzhai")
  return "你已经是本门玄女了，还是直接去找师傅她老人家吧！\n";
  if(ob->query_skill("qingxin-force",1)<300)
  return "你的武功这么低，师傅她老人家是不会见你的。\n";
  ob->set_temp("dtsl_fquest_jz/step1",1);
  return "师傅他老人家喜欢清净，你还是别打扰他了。\n";
}

string do_quest2()
{
  object ob;
  ob=this_player();
  if(!ob->query_temp("dtsl_fquest_jz/step1"))
  return "是否能成为本门的玄女，是师傅她老人家决定的，我可不敢做主！\n";
  ob->delete_temp("dtsl_fquest_jz/step1");
  ob->set_temp("dtsl_fquest_jz/step2",1);
  return "如果想成为本门的玄女，必须要先战胜我才可以。\n";
}

int surrender(object killer,object victim)
{
   if(killer->query_temp("dtsl_fquest_jz/step2")){
    killer->delete_temp("dtsl_fquest_jz/step2");
    killer->set_temp("dtsl_fquest_jz/step3",1);
    message_vision("$N长叹一生：没想到本门中还有你这么出色的弟子！\n",this_object());
    tell_object(killer,"师妃喧朝你招招手：到我这里来，我告诉梵师傅她老人家的主处。\n");
    tell_object(killer,"师妃喧悄声说道：据说她老人家在长白上卧龙岭白云洞修行，你去找找看吧！\n");
    return 1;}
    return 1;
}

string do_jzzy_quest1()
{
   object ob;
   ob=this_player();
   if(!ob->query_temp("dtsl_quest_jzzy/step5"))
   return "你说的事我可是一点都没听说过。\n";
   ob->set_temp("dtsl_quest_jzzy/step6",1);
   ob->delete_temp("dtsl_quest_jzzy/step5");
   return "我也是入川后方由川帮帮主范卓告知此事，此人\n"+
          "名列邪道八大高手榜上，一向非常低调，行藏诡秘，与大石寺\n"+
          "的上代主持大德圣僧乃死敌，最近不知是否魔功大成，从西域\n"+
          "赶回来挑战大德，岂知大德刚於十天前圆寂火化。他竟把怨恨\n"+
          "发泄在他不懂武功的徒子徒孙身上，说若有人逗留寺内，他将\n"+
          "尽杀方圆十里内所有生人，寺僧为免祸及附近无辜乡民，只好\n"+
          "弃寺离开。\n";
}
string do_jzzy_quest2()
{
   object ob;
   ob=this_player();
   if(!ob->query_temp("dtsl_quest_jzzy/step6"))
   return "你说的事我可是一点都没听说过。\n";
   ob->set_temp("dtsl_quest_jzzy/step7",1);
   ob->delete_temp("dtsl_quest_jzzy/step6");
   return "这些罗汉均是依后秦圣僧鸠摩罗什亲绘的手本敬制。\n";
}

string do_jzzy_quest3()
{
object ob;
   ob=this_player();
   if(!ob->query_temp("dtsl_quest_jzzy/step7"))
   return "你说的事我可是一点都没听说过。\n";
   ob->set_temp("dtsl_quest_jzzy/step8",1);
   ob->delete_temp("dtsl_quest_jzzy/step7");
   return "鸠摩罗什乃天竺来中士传法有大德大智的高僧，广\n"+
          "究大乘佛法而尤精於般若性空的精义，武技更是超凡入圣，却从\n"+
          "不以武学传人，只论佛法。来中土后在长安的逍遥园从事翻译佛\n"+
          "经的工作。\n";
}
