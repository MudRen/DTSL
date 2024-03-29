// 大唐双龙传

//fucailin.c 傅采林


inherit F_MASTER;
inherit NPC;

#include <ansi.h>
#include <job_money.h>
#include "qipu.h"

string do_quest();
string move_room();
string do_action1();
int do_ok(string arg);
int do_action2();
int do_action3();
int do_action4();
int do_action5();

void create()
{
  int i;
  object *ob;

  set_name("傅采林", ({"fu cailin", "fu", "cailin"}));
  set("title", "弈剑派开山祖师");
  set("gender", "男性");
  set("age", 48);
  set("str", 35);
  set("int", 30);
  set("per", 18);
  set("max_kee",6000);
  set("max_gin",6000);
  set("max_sen",6000);
  set("max_force",15000);
  set("force",15000);
  set("combat_exp",8000000);

  set_skill("literate", 400);
  set_skill("leg", 400);
  set_skill("fengxue-leg", 400);
  set_skill("blade", 400);
  set_skill("wuba-daofa", 400);
  set_skill("sword", 500);
  set_skill("force", 400);
  set_skill("dodge", 400);
  set_skill("parry", 400);
  set_skill("jiuxuan-dafa",400);
  set_skill("yijian-shu",500);
  set_skill("jiuzhuan-jianjue",400);
  set_skill("xingyun-dodge",400);
   set("perform_quest/jue",1);
   set("chat_chance_combat",100);
   set("chat_msg_combat",({
                (: command("perform xingchen") :),
                (: command("execute shu") :),
                (: command("execute yijian") :),
               // (: command("perform nitian") :),
        }));
   set("apply_points",2000);

  set("inquiry",([
    "剑仙":(:do_quest:),
    "棋室":(:move_room:),
    "傅君瑜":(:do_action1:),
    "入微":(:do_action2:),
    "生命何物":(:do_action3:),
    "弈剑术":(:do_action4:),
    "弈棋":(:do_action5:),
    ]));
  set("execute_quest/yijianshu",1);
  setup();

  create_family("弈剑派", 1, "祖师");
  ob=children(__DIR__"obj/jinsijia");
   for(i=0;i<sizeof(ob);i++)
     if(environment(ob[i])&&userp(environment(ob[i]))){
     tell_object(environment(ob[i]),"你手中的"+ob[i]->query("name")+"被它的主人收回去了！\n");
     if(ob[i]->query("worn"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"被一阵风卷走了。\n");
     destruct(ob[i]);}
     else destruct(ob[i]);
   carry_object(__DIR__"obj/jinsijia")->wear();
  carry_object(__DIR__"obj/sword")->wield();
}

void init()
{
   add_action("do_ok","jiaochai");
   add_action("do_play","luozi");
   add_action("do_check","check");
}

void attempt_apprentice(object ob)
{

    if(ob->query_skill("jiuxuan-dafa",1)<160){
       command("say 你的九玄大法修为不够，我可不要这样的徒弟！");
       return;
     }

     if(ob->query("office_number")<60){
       command("say 你的功绩太低了，我可不要这么懒惰的弟子！");
       return;
     }

     if(ob->query_int()<35){
       command("say 你的悟性太低了，我可不要你这样的弟子！");
       return ;
     }

     ob->set("yjp/family3",1);

     command("say 弈剑术虽是我所创，但只可意会不可言传，你在学习中要好好体会！");

     command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yijian3");
}

string do_quest()
{
  object ob,obj;

  ob=this_player();
  if(ob->query_skill("jiuxuan-dafa",1)<200)
  return "你的功夫太低了，如何享有剑仙的称号呢？\n";
  if(ob->query("family_lingwu")=="yjp")
  return "长江后浪推前浪，你已经踏入突破自身障碍踏入新的境界，要靠自己去领悟武道的精髓了！\n";
   if(ob->query_temp("quest_fighter"))
  return "你还是快去战胜木人吧！\n";
  ob->set_temp("gage_fu",1);

  obj=new(__DIR__"q_fucailin");
  obj->set("name",ob->name()+"的木人");
  obj->set("target_id",ob->query("id"));
  obj->set_temp("owner_ob",ob);
  ob->set_temp("quest_fighter",obj);
  ob->add_temp_array("job_temp_killer",obj);

  obj->move(environment(ob));
  return "剑仙不是这么容易就成为的，先突破本体的障碍吧，来试试为师精心制作的木人。\n";
}
/*
int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_fu"))
   return 1;
   message("vision",HIG"【弈剑派】：傅采林纵声长啸：我弈剑派终于又多了一位"+HIW+"剑  仙"+HIG+killer->name()+"\n"NOR,users());
   message_vision(HIR"$N仰天长笑道：我弈剑派终于后继有人了！\n"NOR,victim);
   tell_object(killer,"咱们弈剑派有一个秘密，你自己到本派的棋室参悟吧！\n");
   killer->set("family_lingwu","yjp");
   killer->set("title","剑  仙");
   message_vision("只见$N长袖一挥，$n借着一股内力来到了一个新的地方！\n",victim,killer);
   killer->move("/d/clone/room/lingwu/yjp/qishi");
   return 1;
}
*/
int end_fight(object killer,object victim)
{

  if(victim->query_temp("bai_fu_action6")){
     victim->delete_temp("bai_fu_action6");
     victim->set_temp("bai_fu_action7",1);

     command("say 我毕生都在追寻美好的事物，但只是以旁观者的心态去欣赏品味，\n"+
          "此正是弈剑的精义，能否领会就看你的自己了。");
     return 1;
  }

  if(!victim->query_temp("gage_fu"))
   return 1;
  message_vision("$N朝$n叹了口气，你还是回去再磨练磨练吧！\n",killer,victim);
  return 1;
}

string move_room()
{
  object ob;
  ob=this_player();
  if(ob->query("pker"))
  return "通缉犯还是老实点吧！\n";
  if(ob->query("family_lingwu")!="yjp")
  return "这是个秘密，现在还不能告诉你！\n";
  ob->move("/d/clone/room/lingwu/yjp/qishi");
  return "希望你好好领悟，广大我们弈剑派！\n";
}

string *dirs=({
"/d/huashan","/d/hengshan","/d/taishan",
"/d/emeishan",
});

string do_action1()
{
   object ob,target,guard;

   ob=this_player();

   if(ob->query_skill("dijian-jue",1)<160||
      ob->query("perform_quest/ditian")||
      ob->query("perform_quest/bajue"))
   return "她是我的徒弟，你问这个做什么？\n";

   if(ob->query_temp("perform_quest/ditian_action1"))
   return "她正处于危险之中，快去救他吧！\n";

   target=new(__DIR__"fujunyu");
   guard=new(__DIR__"yingui_killer");

   target->set_status(ob,guard);
   guard->set_status(ob);

   if(!random_place(target,dirs))
   return "她是我的徒弟，你问这个做什么？\n";
   if(!environment(target))
   return "她是我的徒弟，你问这个做什么？\n";

   guard->move(environment(target));
   guard->set_leader(target);

   ob->set_temp("perform_quest/ditian_action1",1);
   ob->add_temp_array("job_temp_killer",target);
   ob->add_temp_array("job_temp_killer",guard);

   return "她是我的徒弟，据说被阴癸弟子抓到"+MISC_D->find_place(environment(target))+
   "了，你去把她解救回来吧！\n";
}

int do_ok(string arg)
{
  object ob,target;
  string name,msg;

  ob=this_player();

  if(!ob->query_temp("perform_quest/ditian_action2"))
  return 0;

  if(!arg||sscanf(arg,"with %s",name)!=1)
  return notify_fail("你拿什么交差(jiaochai with xxx)？\n");

  if(!objectp(target=present(name,environment(ob))))
  return notify_fail("这里没有这个人。\n");

  if(target->query("owner_ob")!=ob){
   command("heng");
   command("say 想来骗我吗？");
   return 1;
  }

  msg="\n$N跪下叩了头：师傅在上，受弟子一拜！\n"+
      "这次弟子蒙难，多亏"+ob->name()+"来解救，才使徒儿脱险。\n\n"+
      "$n微微一笑：好吧，你先进去休息吧！\n\n"+
      "$N行了礼，回自己卧室去了。\n\n";
  message_vision(msg,target,this_object());
  destruct(target);
  call_out("do_ok2",3,ob);
  return 1;
}

void do_ok2(object ob)
{
  string msg;

  if(!ob||
  environment(ob)!=environment(this_object())
  )
  return;
  command("say 原来你是岭南宋家的弟子！让我考验一下你的武功吧！\n");

  msg="\n$N缓慢地一剑朝你刺去，但是$n却在恍惚只间寻不出其中的任何破绽，\n"+
      "而$n自己的任何反击都似乎在$N的预算之中！\n"+
      HIR+"只听哧地一声，$N的长剑在$n的眉心划了一下！\n"NOR+
      "$N微微一笑：宋家的地剑诀长处在于防守，与我派的剑法不同，如果是\n"+
      "宋智在此，必会挡住我的一击。你好好领悟吧！\n\n"+
      "$n似乎若有所悟，长施一礼：多谢大师指点！\n\n";
  message_vision(msg,this_object(),ob);
  ob->delete_temp("perform_quest/ditian_action2");
  ob->set("perform_quest/ditian",1);
  return;
}

int do_action2()
{
  object ob;

  ob=this_player();

  if(!ob->query_temp("perform_quest/zhi_action2")){
     command("say 你现在是无法领会这个境界的！");
     return 1;
  }
  if(ob->query("perform_quest/zhi_fail")){
    command("say 这些道理并不是每个人都能领会的，你不要强求了！");
    return 1;
  }
  ob->delete_temp("perform_quest/zhi_action1");
  ob->delete_temp("perform_quest/zhi_action2");

  command("say 入微的境界在于把握住自己的心理，因为心理的一丝一毫的变化，\n"+
          "都将会影响自己。\n");
  if( ob->query("MKS")!=ob->query("huajian_menpai/huajian_MKS")
    ||ob->query("PKS")!=ob->query("huajian_menpai/huajian_PKS")
    ||ob->query("deadtimes")!=ob->query("huajian_menpai/huajian_deadtimes")
    ||ob->query("age")>=50
    ){
     message_vision("\n$N低头思索一阵，却什么也领悟不出来。\n",ob);
     ob->set("perform_quest/zhi_fail",1);

  }
  else{
    message_vision("\n$N低头思索一阵，似乎略有所悟。\n",ob);
   ob->set("perform_quest/zhi",1);
  }
  return 1;
}

int do_action3()
{
   object ob;

   ob=this_player();

   if(ob->query("execute_quest/yijianshu")){
     command("say 你已经领会了弈剑术的精髓，以后自己去提高吧！\n");
     return 1;
   }

   if(ob->query_skill("jiuxuan-dafa",1)<160){
       command("say 你的九玄大法修为不够，无法领会这个境界！");
       return 1;
   }

   //空出描述
   command("say 生命虽是没有人能解开的谜，却非是无迹可寻。线索隐藏于每一个人的自身，\n"+
           "却因生死间无法逾越的鸿沟而终断。此正为佛道两门中人努力追寻的方向和目标，\n"+
           "只有悟透自身存在的秘密，生命之谜才有机会被解开。");
   command("sigh");
   command("say 沉香的香料来自沉香木中，木质沉重，颜色深暗，且有病害的部份，因饱含树\n"+
           "脂，故香气馥郁。这种由病态形成的芳香木质可呈人形或兽形之状，最罕贵的是作\n"+
           "仙人形的黑沉香。");

   ob->set_temp("bai_fu_action1",1);
   return 1;
}

int accept_object(object ob,object obj)
{

   if(!obj->id("bai_fucailin_quest_obj"))
    return 0;

   if(!ob->query_temp("bai_fu_action4"))
    return 0;

   ob->delete_temp("bai_fu_action4");
   ob->set_temp("bai_fu_action5",1);

   command("say 好，你子时三刻再来找我吧！");

   return 1;
}

int do_action4()
{
  object ob;
  string time;

  ob=this_player();

  if(!ob->query_temp("bai_fu_action5")){
    command("say 这样高深的技能你恐怕无法掌握！");
    return 1;
  }
  time=NATURE_D->game_time();

  if(time[sizeof(time)-8..sizeof(time)]!="子时三刻"){
    command("say 现在是"+time[sizeof(time)-8..sizeof(time)]+" ，你来的时辰不对啊！");
    return 1;
  }

  ob->delete_temp("bai_fu_action5");
  ob->set_temp("bai_fu_action6",1);

  command("say 弈剑术虽是我所创，但只可意会不可言传，寇仲和徐子陵就是很好的例子了。\n"+
          "为了让你对弈剑术有进一步了解，我破例让你亲身感受，看我如何以人弈剑，以剑\n"+
          "弈敌。\n");
  fight_ob(ob);
  command("execute yijian "+ob->query("id"));
  return 1;
}

int do_action5()
{
   object ob;
   mapping *old_maps,*myold_maps=({}),give_maps;
   string *old_numbers;
   int i;

   ob=this_player();

   if(ob->query("perform_quest/sanfen")){
      command("say 你已经掌握了五霸刀法的精髓，无法再领会弈剑派的绝学！");
      return 1;
   }
   if(ob->query("perform_quest/xingchen")){
      command("say 你已经掌握了九转剑诀的精髓，以后自己去提高吧！");
      return 1;
   }

   if(ob->query_skill("jiuxuan-dafa",1)<160){
       command("say 你的九玄大法修为不够，看不懂我的棋谱的！");
       return 1;
   }


   if(ob->query_int()<40){
       command("say 你的悟性太低了，看不懂我的棋谱的！");
       return 1;
   }
   if(sizeof(ob->query_temp("bai_xiaqi_log"))>=9){
      command("say 我只考你九个棋谱，你好好看看吧！");
      return 1;
   }
   if(sizeof(ob->query_temp("bai_xiaqi"))>=1){
      command("say 你先做完那几个棋谱再问新的棋谱吧！");
      return 1;
   }

   old_maps=weiqi_maps;
   if(!ob->query_temp("start_bai_xiaqi")){
      for(i=0;i<sizeof(old_maps);i++)
      ob->add_temp_array("bai_xiaqi_numbers",i);
      ob->set_temp("start_bai_xiaqi",1);
   }

   old_numbers=ob->query_temp("bai_xiaqi_numbers");
   if(arrayp(ob->query_temp("bai_xiaqi_log"))){
   	myold_maps=ob->query_temp("bai_xiaqi_log");
   	for(i=0;i<sizeof(myold_maps);i++)
   	old_numbers=old_numbers-({myold_maps[i]});
   }
   if(old_numbers==({})){
     command("say 不好意思，巫师的题库不够了，等着吧！");
     return 1;
   }
   i=(int)(old_numbers[random(sizeof(old_numbers))]);
   ob->set_temp("bai_xiaqi",({old_maps[i]}));
   ob->add_temp_array("bai_xiaqi_log",i);
   tell_object(ob,old_maps[i]["maps"]);
   command("say 看看这个棋谱，你会选择哪个星点作为第一落子处呢？");
   return 1;
}

int do_play(string arg)
{
   object ob;
   mapping *mymaps,map;

   ob=this_player();

   if(!arrayp(ob->query_temp("bai_xiaqi")))
   return 0;

   if(!arg||arg=="maps") return notify_fail("你要落子在哪里？\n");

   mymaps=ob->query_temp("bai_xiaqi");
   if(!mymaps) return 0;
   map=mymaps[0];

   if(!map[arg])
   return notify_fail("看好星点！\n");

   ob->add_temp("bai_xiaqi_score",map[arg]);
   ob->add_temp("bai_xiaqi_times",1);
   tell_object(ob,"你落了一子，此子能得"+map[arg]+"分。\n");

   mymaps=mymaps-({map});
   if(mymaps==({})) ob->delete_temp("bai_xiaqi");
   else ob->set_temp("bai_xiaqi",mymaps);

   if(ob->query_temp("bai_xiaqi_times")>=9){
     if(ob->query_temp("bai_xiaqi_score")>=80){
       command("say 好！真是可塑之才！我就传你九转剑诀的精髓！");
       message_vision("$N俯到$n耳边，低声说了几句话。$n似乎若有所悟。\n",this_object(),ob);
       ob->set("perform_quest/xingchen",1);
     }
     else command("say 你的下棋水平这么差劲，如何领会我弈剑派的精髓！");
     ob->delete_temp("bai_xiaqi_score");
     ob->delete_temp("bai_xiaqi_times");
     ob->delete_temp("bai_xiaqi");
     ob->delete_temp("bai_xiaqi_log");
     ob->delete_temp("bai_xiaqi_numbers");
     ob->delete_temp("start_bai_xiaqi");
  }

   return 1;
}

int do_check()
{
  object ob;
  mapping *mymaps;
  int i;
  string msg;

  ob=this_player();

  if(ob->query_temp("bai_xiaqi_score"))
   tell_object(ob,"你目前的得分："+ob->query_temp("bai_xiaqi_score")+"\n");
  if(!arrayp(ob->query_temp("bai_xiaqi")))
  return 1;

  mymaps=ob->query_temp("bai_xiaqi");
  msg="你目前还没有解答的棋谱：\n";
  for(i=0;i<sizeof(mymaps);i++)
    msg+=mymaps[i]["maps"]+"\n";

  ob->start_more(msg);

  return 1;
}
