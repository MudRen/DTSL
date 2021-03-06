
inherit NPC;
#define TIME_TICK1 time()*60
#include "ansi.h"
string do_quest1();
string do_quest2();
string do_quest3();
int do_answer(string arg);
string do_find1();
string do_find2();
string do_find3();
string do_find4();
#include "target.c"
void create()
{
   set_name("诸葛德威",({ "zhuge dewei","zhuge"}) );
        set("gender","男性");
        set("title","铁扇子");
        set("age", 32);
        set("max_kee",1000);
        set("max_gin",1000);
        set("max_sen",1000);
        set("max_force",1500);
        set("force",1500);
        set("combat_exp",300000);
        set_skill("dodge",140);
        set_skill("parry",140);
        set_skill("force",140);
        set_skill("tieshan-gong",140);
        set_skill("blade",140);
        set_skill("yirong-shu",200);
        set("inquiry",([
           "铁扇子":(:do_quest1:),
           "易容术":(:do_quest2:),
           "杨广":(:do_quest3:),
           "刘黑闼":"他是我的好兄弟，可是已经很久不见了。\n",
           "崔冬":"他是我的好兄弟，可惜死的太可惜了！\n",
           "十大罪状":"我当然知道了，可是懒得告诉你！\n",
           "人皮":(:do_find1:),
           "画笔":(:do_find2:),
           "石蜡":(:do_find3:),
           "面粉":(:do_find4:),
           ]));
    setup();
   carry_object(__DIR__"obj/tieshan")->wield();
  
}
int is_apprentice_of(object ob)
{
	return 1;
}

int recognize_apprentice(object ob)
{
       
        if(!ob->query("dtsl_quest_yrs_ok"))
         return 0;
        if(ob->query("combat_exp")<500000)
        return notify_fail("你功夫这么低，我可不能传授你易容术。\n");
        ob->set("dtsl_quest_yrs_all_ok",1);
        return 1;
}

int prevent_learn(object ob,string skill)
{
	if(skill!="yirong-shu")
		return 1;
	return 0;	
}

void init()
{
  add_action("do_answer","answer");
}
string do_quest1()
{
  object ob;
  ob=this_player();
  ob->set_temp("dtsl_quest_yrs/step1",1);
  return "我很喜欢铁扇子，你能不能再给我弄一把呢？\n";
}
string do_quest2()
{
  object ob;
  ob=this_player();
  if(!ob->query_temp("dtsl_quest_yrs/step2"))
  return "我的易容术可是轻易不传人的。\n";
  ob->delete_temp("dtsl_quest_yrs/step2");
  ob->set_temp("dtsl_quest_yrs/step3",1);
  return "如今世事混乱，国君无道，你学了这项技术又有什么用呢？\n";
}
string do_quest3()
{
  object ob;
  ob=this_player();
  if(!ob->query_temp("dtsl_quest_yrs/step3"))
  return "象他这样的皇上，早晚会被起义军杀死的！\n";
  ob->delete_temp("dtsl_quest_yrs/step3");
  ob->set_temp("dtsl_quest_yrs/step4",1);
  return "这么说你也赞同我的观点了！你知道杨广的十大罪状吗？\n";
}

int do_answer(string arg)
{
   object ob;
   string str1,str2;
   
   ob=this_player();
   if(!ob->query_temp("dtsl_quest_yrs/step4"))
   return 0;
   if(!arg)
   return notify_fail("诸葛德威看看你：你到底能不能说出来啊？\n");
   if(arg!=
   "一弒父，二乱伦，三荒湎酒色，四建宫殿楼台，奢侈浪费，五苛捐杂税，"+
   "压榨百姓，六巡游天下，建造长城，七征伐高丽，穷兵黩武，八拒直谏，"+
   "杀直士，九贿赂成风，君子在野，小人在位，十言而无信。")
   return notify_fail("诸葛德威摇摇头：你说的不对啊！\n");
   str1=CHINESE_D->chinese_date(TIME_TICK1);
  str2=CHINESE_D->chinese_date((ob->query("birthday") -14*365*24*60)*60);
  if(str1[sizeof(str1)-8..sizeof(str1)]!=str2[sizeof(str2)-8..sizeof(str2)])
  return notify_fail(query("name")+"叹了口气：你虽然说得不错，但终究是难以成为我的知己啊！\n");
   ob->delete_temp("dtsl_quest_yrs/step4");
   ob->set("dtsl_quest_yrs_ok",1);
   message_vision("$N哈哈一笑：你说的太好了，看来你可真是我的知己了！\n",this_object());
   return 1;
}

string do_find1()
{
  object ob;
  ob=this_player();
  if(!ob->query("dtsl_quest_yrs_ok"))
  return "奇怪，你要人皮有什么用呢？\n";
  ob->set_temp("yrs_find/skin",1);
  return "据说九江南城外有家黑店，你去哪里搜搜看吧！\n";
}

string do_find2()
{
  object ob;
  
  ob=this_player();
  if(!ob->query("dtsl_quest_yrs_ok"))
  return "奇怪，你要画笔有什么用呢？\n";
  ob->set_temp("yrs_find/pencil",1);
  return "据说长安的凌烟阁有位画师，你去那里看看吧！\n";
}

string do_find3()
{
  object ob;
  ob=this_player();
  if(!ob->query("dtsl_quest_yrs_ok"))
  return "奇怪，你要石蜡有什么用呢？\n";
  return "石蜡我现在也没有，你去随便买一个吧！\n";
}

string do_find4()
{
  object ob;
  ob=this_player();
   if(!ob->query("dtsl_quest_yrs_ok"))
  return "奇怪，你要面粉有什么用呢？\n";
  ob->set_temp("yrs_find/mianfen",1);
  return "据说九江有家杂货铺藏有这种面粉，你去找找吧！\n";
}

int accept_object(object who,object ob)
{
  
  string name;
  
  if(!who->query_temp("dtsl_quest_yrs/step1"))
  return 0;
  
  name=ob->query("name");
  name=replace_string(name,NOR,"");
  if(name!="铁扇")
  return 0;
  if(ob->query("skill_type")!="blade")
  return 0;
  tell_object(who,YEL"诸葛德威呵呵一笑：好，真是谢谢你了！\n"NOR);
  who->delete_temp("dtsl_quest_yrs/step1");
  who->set_temp("dtsl_quest_yrs/step2",1);
  return 1;
}