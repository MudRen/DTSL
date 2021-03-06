// 大唐双龙传

//傅君瑜


inherit NPC;
#include <ansi.h>

int do_action1();

void create()
{
  set_name("傅君卓", ({"fu junzhuo", "fu", "junzhuo"}));
  set("gender", "女性");
 
  set("per",26);
  set("max_kee",3000);
  set("max_gin",3000);
  set("max_sen",3000);
  set("max_force",3000);
  set("force",4000);
  set("combat_exp",600000);
  set_skill("unarmed", 182);
  set_skill("strike",182);
  set_skill("leg",182);
  set_skill("literate", 182);
  set_skill("sword", 182);
  set_skill("force", 182);
  set_skill("dodge", 182);
  set_skill("parry", 182);
  
  set_skill("jiuxuan-dafa",182);
  set_skill("fengxue-leg",182);
  set_skill("jiuzhuan-jianjue",182);
  set_skill("xingyun-dodge",182);
  
  set("inquiry",([
   "救命":(:do_action1:),
  ]));
 
  setup();
  
  create_family("弈剑派",4, "弟子");

}

int do_action1()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("dtsl_quest_csj_action2")){
    command("heng");
    return 1;
  }
  if(ob->query("age")>20){
    command("say 这么大人了，连自己都不能保护，哼！！");
    return 1;
  }
  if(ob->query("age")<15){
    command("say 小朋友，你年纪这么小，还是快回家吧！");
    return 1;
  }
 
  command("say 原来你被宇文化及那狗贼追杀，看本姑娘高不高兴吧！");
  ob->delete_temp("dtsl_quest_csj_action2");
  ob->set_temp("dtsl_quest_csj_action3",1);
  
  command("guard "+ob->query("id"));
  return 1;
}

void kill_ob(object ob)
{
  if(userp(ob)){
     command("say heng");
     ob->unconcious();
     remove_killer(ob);
     ob->remove_killer(this_object());
     return;
  }
  remove_call_out("check_fight");
  call_out("check_fight",1,ob,1);
  ::kill_ob(ob);
}

void check_fight(object ob,int i)
{
  object target;
  
  if(!ob){
    command("say 好险，好险！");
    return;
  }
  if(!is_fighting(ob)) return;
  
  i++;
  
  if(i>=10){
    message_vision(HIR"$N伤得有些严重了！\n"NOR,this_object());
    command("say 哼，等本姑娘养要伤再来对付你！");
    target=query_temp("guardfor");
    if(!target){
      command("say 好，本姑娘和你同归于尽！！");
      ob->die();
      die();
      return;
    }
    message_vision("\n$N夹起$n，飞身逃走了！\n\n",this_object(),target);
    ob->do_command("say 别让我再看到你们！！！\n");
    target->move("/d/quest/csj/shangu");
    move("/d/quest/csj/shangu");
    set("eff_kee",1);
    set("kee",1);
    set("force",0);
    destruct(ob);
    call_out("do_quest",3,target);
    return;
  }
  call_out("check_fight",1,ob,i);
}

void do_quest(object target)
{
  if(!target) return;
  if(environment(target)!=environment(this_object()))
  return;
  
  command("say 我支持不了多长时间了，你我相见，也是缘分一场，\n"+
          "我就传授给你点武学基础的功夫，希望你能给我报仇！\n");
  target->set("dtsl_quest_csj_ok",1);
  
  die();
  return;
}
