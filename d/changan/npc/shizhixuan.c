
#include <ansi.h>
inherit NPC;

string move_room();
string do_quest();
int do_action1();
int do_action2();
int do_action3();
int do_action4();
int do_action5();

void create()
{
   set_name("石之轩",({ "shi zhixuan","shi"}) );
   set("gender", "男性" );
   set("age", 46);
   set("long", "这是花间派的掌门人。\n");
    set("combat_exp",8000000);
   set("str", 28);
    set_skill("dodge",370);
    set_skill("parry",370);
    set_skill("force",370);
    set_skill("strike",400);
    set_skill("busi-yin",400);
    set_skill("blade",370);
    set_skill("literate",300);
    set_skill("bencao-shuli",300);
    set_skill("tianyi-xuangong",370);
    set_skill("huanmo-shenfa",370);
    set_skill("zhehua-baishi",370);
    set_skill("baihua-zhang",370);

    set("perform_quest/yin",1);
    set("apply_points",2000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: command("execute yin") :),
    }));

    set("max_gin",7000);
    set("max_sen",8000);
    set("max_kee",9000);
    set("max_force",15000);
    set("force",15000);
   set("jiali",10);
   create_family("花间派",3,"掌门");
   
   set("inquiry",([
      "花间护法":(:do_quest:),
      "密室":(:move_room:),
      "花间十二支":(:do_action1:),
      "补天阁":(:do_action2:),
      "不死印":(:do_action3:),
      "考验":(:do_action5:),
      //"遗言":(:do_action4:),
      ]));
    setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/blade")->wield();
}

void init()
{
	add_action("do_lingshang","lingshang");
}


string do_quest()
{
  object ob,obj;
  
  ob=this_player();
  if(ob->query_skill("flower-force",1)<200)
  return "你的功夫太低了，现在还无法超越的！\n";
  if(ob->query("family_lingwu")=="huajian")
  return "成为花间护法就必须严于律己，你不去提高自己到我这里来做什么？\n";
  if(ob->query_temp("quest_fighter"))
  return "你还是快去战胜木人吧！\n";
  ob->set_temp("gage_shi",1);
  
  obj=new(__DIR__"q_shizhixuan");
  obj->set("name",ob->name()+"的木人");
  obj->set("target_id",ob->query("id"));
  obj->set_temp("owner_ob",ob);
  ob->set_temp("quest_fighter",obj);
  ob->add_temp_array("job_temp_killer",obj);
  
  obj->move(environment(ob));
  
  return "哼，你想成为花间护法，必须先打赢这个木头人。\n";
}

/*
int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_shi"))
   return 1;
   message("vision",HIG"【花间派】:石之轩拍了拍"+killer->name()+",纵声狂笑：我花间又多了一位护法！\n"NOR,users());
   message_vision(HIR"$N仰天长笑道：我花间终于后继有人了！\n"NOR,victim);
   message_vision(HIR"$N突然脸色一变，脑羞成怒道：你给我去密室呆一会吧！\n"NOR,victim); 
   killer->set("family_lingwu","huajian");
   killer->set("title","花间护法");
   tell_object(killer,"石之轩双掌一推，一股巨大的内力把你推到一间密室！\n");
   killer->move("/d/clone/room/lingwu/huajian/mishi");
   return 1;
}
int end_fight(object killer,object victim)
{
  if(!victim->query_temp("gage_shi"))
   return 1;
  message_vision("$N朝$n叹了口气，你还是回去再磨练磨练吧！\n",killer,victim);
  return 1;
}
*/
string move_room()
{
  object ob;
  ob=this_player();
  if(ob->query("family_lingwu")!="huajian")
   return "你问我这个想干什么？\n";
  ob->move("/d/clone/room/lingwu/huajian/mishi");
  return "你终于了解了我的一翻苦心！\n";
}

int do_action1()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("perform_quest/zhi_action1")){
     command("say 这么高深的技能岂是你能领会的！");
     return 1;
   }
   command("say 很好！没想到我花间派也有你这样杰出的弟子！\n"+
           "不过，你还没有达到入微的境界！");
   ob->set_temp("perform_quest/zhi_action2",1);
   return 1;
}

int do_action2()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query("execute_quest/busiyin")){
     command("say 你还是安心学花间派的武功吧！");
     return 1;
   }
   ob->set("execute_quest/wanshijue",1);
   command("say 我现在没有教你这些功夫，你去找我的徒弟杨虚彦学吧！");
   
   return 1;
}

int is_apprentice_of(object ob)
{
	return 1;
}

int recognize_apprentice(object ob)
{
	
        return 1;
}

int prevent_learn(object ob,string skill)
{
   if(!ob->query("dtsl_quest_bsy_ok")){
     command("heng");
     return 1;
   }
   if(ob->query_skill("busi-yin",1)>=120){
     command("heng");
     return 1;
   }
   if(skill!="busi-yin"){
    command("heng");
    return 1;
   }
   return 0;
}

int do_action3()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query_skill("busi-yin",1)<190){
   	 ob->add_temp("fail_do_bsy_quest",1);
	 if(ob->query_temp("fail_do_bsy_quest")==1)
     	command("heng");
     else
     if(ob->query_temp("fail_do_bsy_quest")==2)
     	message_vision("$N狠狠地瞪了$n一眼！\n",this_object(),ob);
     else
     if(ob->query_temp("fail_do_bsy_quest")==3){
     	message_vision("$N朝$n喝道：罗罗嗦嗦没完，我看你是活够了！\n",this_object(),ob);	
     	ob->set_temp("fail_do_bsy_quest",0);
     	call_out("do_kill",2,ob);
     }
     return 1;
   }
   
   if(ob->query("execute_quest/busiyin_ok")){
     message_vision("$N狠狠地瞪了$n一眼！\n",this_object(),ob);
     return 1;
   }
   if(ob->query("bsy_quest_fail_age")){
     if(ob->query("age")-ob->query("bsy_quest_fail_age")<5){
     	command("say 不是告诉你五年后再来吗！？");
     	return 1;
     }
   }
   if("/d/quest/busiyin/bsyctrl"->query_flag()){
   		command("say 你等一会吧，正有人接受我的考验！");
   		return 1;
   	}
   if(ob->query_temp("do_bsy_quest2")){
   		command("say 我要的东西你到底拿回来没有？！");
   		return 1;
   	}
   
   ob->set_temp("do_bsy_quest1",1);
   
   message_vision("$N低声沉吟道：想学习不死印的精髓也可以，但是要先通过我的考验。\n",this_object());
   
   return 1;
   
}
int do_action5()
{
	object ob;
   
	ob=this_player();
	
	if(!ob->query_temp("do_bsy_quest1")){
		command("say 你想让我考验你什么？");
		return 1;
	}
	ob->delete_temp("do_bsy_quest1");
	ob->set_temp("do_bsy_quest2",1);
	
	command("say 好！我最近想要一个宝物，你去给我找回来吧！");
	
	tell_object(ob,"\n石之轩抓住你后心，把你带到了一个山洞里！\n\n");
	
	"/d/quest/busiyin/bsyctrl.c"->startquest(ob);
	
	return 1;
	
}

int do_lingshang(string arg)
{
	object ob,obj;
	string str;
	
	ob = this_player();	
	
	if(!arg){
		command("say 你想拿什么来领赏？");
		return 1;
	}
	if(!ob->query_temp("do_bsy_quest2")){
		command("say 你什么都没做，领什么赏？");
		return 1;
	}
	obj = present(arg,ob);
	if(!obj){
		command("say 你身上没有这个东西，领什么赏？");
		return 1;
	}
	if(!obj->query("bsy_quest_obj")){
		command("say 你敢拿假货来冒充？！");
		return 1;
	}
	destruct(obj);
	
	if(ob->query_temp("do_bsyquest_lev")>0)
		str = "石之轩道：不错，你杀了"+ob->query_temp("do_bsyquest_lev")+"个杀手。\n";
	else
		str = "石之轩冷笑道：你连一个杀手都对付不了？\n";
	
	
    if(random(ob->query_kar())<36-ob->query_temp("do_bsyquest_lev")){
		str = str+"石之轩沉吟道：我看你资质还未达到我的要求，你还是五年后再来吧！\n\n";
		ob->set("bsy_quest_fail_age",ob->query("age"));	
		tell_object(ob,str);	
	}
	else{
		message_vision("$N摇头吟道：冰雪佳人貌最奇，常将玉笛向人吹。曲中无限花心动，独许束君第一枝。\n"+
                  "秀心啊，你已抵无忧患的净土，我石之轩仍在人世间的苦海沉浮，是否我必须为自己\n"+
                  "的愚蠢付出代价？\n\n",this_object());
   
   		tell_object(ob,"你在旁边听着，心灵不由一震颤动，终于领会了不死印法的绝学！\n");
      				
   		ob->set("execute_quest/busiyin_ok",1);
   	}	
	
	ob->delete_temp("do_bsyquest_lev");
	ob->delete_temp("do_bsy_quest2");
	
	return 1;
}
/*
int do_action4()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query_skill("busi-yin",1)<190){
     command("heng");
     return 1;
   }
   
   if(ob->query("execute_quest/busiyin_ok")){
     command("say 我一直觉得对不起秀心，唉！");
     return 1;
   }
   
   if(!ob->query_temp("do_bsy_quest1")){
     command("say 难道你要留下什么遗言么？");
     return 1;
   }
   
   ob->set_temp("do_bsy_quest1",0);
   ob->set_temp("do_bsy_quest2",1);
   
   message_vision("$N低头思索一阵，似乎处于极度痛苦之中。\n",this_object());
   message_vision("$N猛地抬起头来，似乎是要杀死$n！\n",this_object(),ob);
   
   call_out("do_kill",2,ob);
   
   return 1;
   
}*/
void do_kill(object ob)
{
   if(!ob) return;
   
   if(environment(ob)!=environment(this_object()))
   return;
   
   command("kill "+ob->query("id"));
   
}

int accept_object(object ob,object obj)
{
   if(!obj->query("hj_bsy_quest_obj"))
    return 0;
   
   if(!ob->query_temp("do_bsy_quest2"))
    return 0;
   
   message_vision("$N摇头吟道：冰雪佳人貌最奇，常将玉笛向人吹。曲中无限花心动，独许束君第一枝。\n"+
                  "秀心啊，你已抵无忧患的净土，我石之轩仍在人世间的苦海沉浮，是否我必须为自己\n"+
                  "的愚蠢付出代价？\n\n",this_object());
   
   tell_object(ob,"你在旁边听着，心灵不由一震颤动，终于领会了不死印法的绝学！\n");
   
   ob->set_temp("do_bsy_quest2",0);
   ob->set("execute_quest/busiyin_ok",1);
   
   return 1;
   
}
