
inherit NPC;
inherit F_MASTER;

#include <ansi.h>

int do_action1();
int do_action2();

void create()
{
   set_name("虚尘",({ "xu chen","xu","chen"}));
        set("gender", "男性" );
        set("age",26);
   set("long", "这是净念禅院的高僧之一。\n");
   set("class","bonze"); 
   set("combat_exp", 100000);
   set("str", 28);
   set("per", 22);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("cuff",100);
   set_skill("force",100);
   
   set_skill("wuxiang-shengong",100);
   set_skill("luohan-quan",100);
   set_skill("lianhua-step",100);
   set_skill("bikouchan",100);
   set_skill("chanzong-fofa",110);
   set_skill("literate",110);
   
   set("gin",1000);
   set("max_gin",1000);
   set("kee",800);
   set("max_kee",800);
   set("sen",800);
   set("max_sen",800);
   set("force",1000);
   set("max_force",1000);
   
   set("inquiry",([
     "剃度":(:do_action1:),
     "辈分":(:do_action2:),
     ]));
     
   create_family("净念禅院",7,"僧人");
   setup();
  
}

void attempt_apprentice(object ob)
{   
	
	if(ob->query("family")
	   &&ob->query("family/family_name")=="净念禅院"
	   &&ob->query("family/generation",1)<=7){
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
	
	tell_object(ob,HIY"\n你成为了净念禅院的俗家弟子！\n\n"NOR);
	command("say 阿弥陀佛！施主请先当本派俗家弟子，等主持同意再正式收你为本派弟子！\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "chanyuan1");
}

int do_action1()
{
   object ob;
   string msg;
   
   ob=this_player();
   
   if(ob->query("family/family_name")!="净念禅院"){
     command("say 你不是本派弟子，我无法给你剃度。");
     return 1;
   }
   if(ob->query("class")=="bonze"){
     command("say 你已经出家剃度了。");
     return 1;
   }
   if(ob->query_skill("chanzong-fofa",1)<100){
     command("say 你的佛法修为太低了，还是先不要剃度的好！");
     return 1;
   }
   if(ob->query("PKS")>=5){
     command("say 你罪孽深重，佛祖不会要这样的弟子！");
     return 1;
   }
   if(ob->query("bellicosity")>=100){
     command("say 你杀气深重，怎么会静下心来出家？");
     return 1;
   }
   command("say 好。你学习佛法也有一段时间了，虽未大彻大悟，但已种下佛缘，\n"+
           "也该行出家礼了。");
   msg="$N缓缓的跪下，只见$n右手一挥，$N的头发悉数落下。\n\n"+
       "$N正式出家了。\n";
   message_vision(msg,ob,this_object());
   ob->set("class","bonze");
   return 1;
}

int do_action2()
{
   object ob;
   string msg;
   
   ob=this_player();
   
   if(ob->query("family/family_name")!="净念禅院"){
     command("say 你不是本派弟子，问我这个问题做什么？");
     return 1;
   }
   if(ob->query("class")!="bonze"){
     command("say 你还是先出家再说吧。");
     return 1;
   }
   
   if(ob->query("PKS")>=5){
     command("say 你罪孽深重，还敢问我这个问题？");
     return 1;
   }
   if(ob->query("bellicosity")>=100){
     command("say 你杀气深重，还敢问我这个问题？");
     return 1;
   }
   if(ob->query("family/generation")<=7){
     command("say 你可真会说笑。");
     return 1;
   }
   if(time()-ob->query("mud_flags/try_beifen_time")<300){
     command("say 早和你说过出家人不可浮躁，怎么这么快就忘记了？");
     return 1;
   }
   
   ob->delete("mud_flags/try_beifen_time");
   msg="$N朝$n一笑：好，就让我看看你的功夫如何了！\n";
   message_vision(msg,this_object(),ob);
   
   ob->set_temp("try_beifen",1);
   fight_ob(ob);
   return 1;
}

string no_color(string arg)
{
        arg = replace_string(arg,  BLK, "");
	arg = replace_string(arg,  RED, "");
	arg = replace_string(arg,  GRN, "");
	arg = replace_string(arg,  YEL, "");
	arg = replace_string(arg,  BLU, "");
	arg = replace_string(arg,  MAG, "");
	arg = replace_string(arg,  CYN, "");
	arg = replace_string(arg,  WHT, "");
	arg = replace_string(arg,  HIR, "");
	arg = replace_string(arg,  HIG, "");
	arg = replace_string(arg,  HIY, "");
	arg = replace_string(arg,  HIB, "");
	arg = replace_string(arg,  HIM, "");
	arg = replace_string(arg,  HIC, "");
	arg = replace_string(arg,  HIW, "");
	arg = replace_string(arg,  NOR, "");
	arg = replace_string(arg,  BLINK, "");
	return arg;
}

int surrender(object killer,object victim)
{
   string msg,newname;
   
   if(killer->query_temp("try_beifen")){
      msg="\n$N朝$n一合十，诵了声佛号：阿弥陀佛！看来你的确是进行了一番苦练！\n"+
          "以后你就是本派「虚」字辈弟子了！\n\n";
      message_vision(msg,victim,killer);
      newname=killer->query("name");
      newname=no_color(newname);
      newname="虚"+newname[0..1];
      killer->set("name",newname);
      tell_object(killer,HIY"以后你的名字是「"+newname+"」\n你成为了净念禅院第七代弟子。\n\n"NOR);
      killer->set("family/generation",7);
      killer->delete_temp("try_beifen");
   }
   return 1;
}

int end_fight(object killer,object victim)
{
     string msg;
   
   if(killer->query_temp("try_beifen")){
      msg="\n$N朝$n唉了一声，说道：“出家人切记不可轻浮，更不可当一天和尚敲一天钟。\n"+
      "继续努力吧！”\n\n";
      message_vision(msg,killer,victim);     
      killer->delete_temp("try_beifen");
      killer->set("mud_flags/try_beifen_time",time());
   }
   return 1;
}	
