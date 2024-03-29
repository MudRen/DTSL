
//Edit By Subzero

inherit NPC;
#include <ansi.h>

string do_quest();
string move_room();
int do_action1();

void create()
{
   int i;
   object *ob;
   set_name("毕玄",({ "bi xuan","bi" }) );
   set("gender", "男性" );
   set("age", 42);
   set("long", "他就是武尊毕玄，域内外三大宗师之一\n");

   set("combat_exp",8000000);
   set("str", 35);
   set("per", 22);
   set_skill("unarmed",400);
   set_skill("dodge",400);
   set_skill("parry",400);
   set_skill("force",500);
   set_skill("blade",400);
   set_skill("literate",300);
   set_skill("cuff",500);
   set_skill("spear",400);
   set_skill("youlong-shenfa",400);
   set_skill("yanyang-dafa",500);
  //  set_skill("pojun-quan",400);
  //  set_skill("yanyang-quan",400);
  //  set_skill("yuehen-qiang",400);
   set_skill("tianlang-dao",400);
   set_skill("canglang-jue",200);
   set_skill("fuying-spear",400);

   set("gin",6000);
   set("max_gin",6000);
   set("kee",6000);
   set("max_kee",6000);
   set("sen",6000);
   set("max_sen",6000);
   set("force",15000);
   set("max_force",15000);
   set("jiali",150);
   create_family("突厥",2,"武尊");
   set("perform_quest/fengsha",1);
   set("perform_quest/fengyu",1);
   set("perform_quest/kuangsha",1);
   set("chat_chance_combat",100);
   set("chat_msg_combat",({
                (: command("perform fengyu") :),
                (: command("perform fengsha") :),
                (: command("exert riyue") :),
                (: command("perform lengyue") :),
                (: command("execute xiao") :),
        }));
   set("apply_points",2000);
   set("inquiry",([
	   "突厥武神":(:do_quest:),
	   "密室":(:move_room:),
	   "挑战":(:do_action1:),
	   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
ob=children(__DIR__"obj/yinlong-spear");
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
   carry_object(__DIR__"obj/yinlong-spear")->wield();
}

string do_quest()
{
  object ob,obj;

  ob=this_player();
  if(ob->query_skill("yanyang-dafa",1)<200)
  return "你的功夫太低了，现在还无法成为突厥武神！\n";
  if(ob->query("family_lingwu")=="tujue")
  return "你已经得到武神的称号，去继续提高吧。\n";
  if(ob->query_temp("quest_fighter"))
  return "你还是快去战胜木人吧！\n";
  ob->set_temp("gage_bi",1);

  obj=new(__DIR__"q_bi");
  obj->set("name",ob->name()+"的木人");
  obj->set("target_id",ob->query("id"));
  obj->set_temp("owner_ob",ob);
  ob->set_temp("quest_fighter",obj);
  ob->add_temp_array("job_temp_killer",obj);

  obj->move(environment(ob));

  return "无须老夫动手，这个木人便可知道你的实力。\n";
}
/*
int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_bi"))
   return 1;
   message("vision",HIG"【突  厥】：毕玄拍了拍"+killer->name()+",纵声狂笑：我突厥从此又多了一位武神！\n"NOR,users());
   message_vision(HIR"$N仰天长笑道：我突厥终于后继有人了！\n"NOR,victim);
   message_vision(HIR"$N微微一笑，既然能打得过我，你就去我的密室学习吧！\n"NOR,victim);
   killer->set("family_lingwu","tujue");
   killer->set("title","突厥武神");
   killer->move("/d/clone/room/lingwu/tujue/mishi");
   return 1;
}
int end_fight(object killer,object victim)
{
  if(!victim->query_temp("gage_bi"))
   return 1;
  message_vision("$N朝$n叹了口气，你还是回去再磨练磨练吧！\n",killer,victim);
  return 1;
}*/
string move_room()
{
  object ob;
  ob=this_player();
  if(ob->query("pker"))
  return "通缉犯还是老实点吧！\n";
  if(ob->query("family_lingwu")!="tujue")
  return "你还没到这个水平，告诉你也没有用的！\n";

  if(ob->query("super_force_tujue_no_horse"))
  ob->move("/d/clone/room/lingwu/tujue/tujue");
  else
  ob->move("/d/clone/room/lingwu/tujue/mishi");
  return "但愿你能让我们突厥一统中原！\n";
}

int do_action1()
{
  object ob;

  ob=this_player();

  if(ob->query_skill("huanri-dafa",1)||
     present("huanri book",ob)){
    command("say 我看你是可塑之才，快滚远点，你还不是我的对手！");
    return 1;
  }

  if(ob->query_temp("dtsl_quest_huanri_action1")){
    command("say 你是我的手下败将，没有资格向我挑战！");
    return 1;
  }

  if(ob->is_fighting()){
    command("say 等我打完仗再找你算帐！\n");
    return 1;
  }
  if(ob->query("eff_kee")*100/ob->query("max_kee")<90){
    command("say 你已经身负内伤，我可不和你打！\n");
    return 1;
  }

  command("say 哼，天堂有路你不走，地狱无门送上来，拿命来！\n");
  kill_ob(ob);
  remove_call_out("check_fight");
  call_out("check_fight",1,ob);
  return 1;
}

void check_fight(object ob)
{
   if(!ob) return;
   if(!is_fighting(ob)) return;
   if(environment(ob)!=environment(this_object())) return;
   if(!living(ob)) return;

   if(ob->query("eff_kee")*100/ob->query("max_kee")<=20){
     command("say 哼，早说你不是我的对手，这次就留你小命！\n");
     message_vision("\n$N猛地使出惊天动地一招，正好击中$n的要害！\n",
          this_object(),ob);
     ob->set_temp("dtsl_quest_huanri_action1",1);
     remove_killer(ob);
     ob->remove_killer(this_object());
     ob->unconcious();
     return;
   }
   call_out("check_fight",1,ob);
}
