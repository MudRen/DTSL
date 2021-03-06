
inherit NPC;

#include <ansi.h>
#include "dx_map.h"
#include "hill_map.h"
#include "npc_list.h"
#include "weapon_list.h"
#include <job_money.h>

string do_job1();
string do_job2();
string do_job3();
string do_job4();
string do_job5();
string do_job6();
string do_job7();
string do_abandon();
int do_lingshang(string arg);
#define THIS_JOB "liyuan_job"

string *target_name=({"谢龙","王汉","李贵","周新"});
string *killer_name2=({"欧阳","诸葛","上官","东方"});
string *killer_id2=({"青","飞云","剑","一笑","昭"});
string *killer_name=({"赵","钱","孙","李","周","吴","郑","王"});
string *killer_id=({"一","二","三","四","五","六","七","八"});
void create()
{
   set_name("李渊",({ "li yuan","li","yuan" }) );
        set("gender", "男性" );
        set("age", 55);
   set("long", "这就是长安李阀的阀主李渊。\n");
   set("combat_exp", 500000);
   set("str", 28);
   set("per", 24);
   set("attitude", "peaceful");
   set_skill("unarmed",150);
   set_skill("parry",150);
   set_skill("dodge",150);
   set_skill("force",150);
   set("max_gin",1000);
   set("max_sen",1000);
   set("max_kee",1000);
   set("force",1500);
   set("max_force",1500);
   set("shili",([
      "name":"lifa_b",
      ]));
   set("inquiry",([
    "招安":(:do_job1:),
    "缉拿":(:do_job2:),
    "刺杀":(:do_job3:),
    "救急":(:do_job4:),
    "平乱":(:do_job5:),
    "寻宝":(:do_job6:),
    "护送":(:do_job7:),
    "放弃":(:do_abandon:),
    ]));
   setup();
   carry_object(__DIR__"obj/guanfu")->wear();
  
}

void init()
{
  add_action("do_lingshang","lingshang");
}

string do_job1()
{
  object ob;
  object paper;
  string place;
  string name;
  
  ob=this_player();
  if(ob->query("combat_exp")<1000000)
  return "凭你的能力还不足以做这么大的事！\n";
  if(ob->query_temp("liyuan_job/step")>=2)
  return "你已经完成招安了，还是快点做下面的事吧！\n";
  if(ob->query_temp("dtsl_job")==THIS_JOB)
  return "你还是赶快去做事情吧！\n";
  
  if(time()-ob->query("busy_time")<40+random(20))
  return "李渊笑道：这么艰巨的任务，你还是歇歇再做吧！\n";
  
  ob->set_temp("dtsl_job",THIS_JOB);
  ob->add_temp("liyuan_job/step",1);
  
  place=dx_map[random(sizeof(dx_map))];
  name=target_name[random(sizeof(target_name))];
 
  paper=new(__DIR__"paper1");
  paper->set("target_name",name);
  paper->set("target_place","定襄");
  paper->set("target_where",place);
  paper->move(ob);
  tell_object(ob,"李渊给了你一个招安令。\n");
  return "据说"+name+
         "武功了得，应该对我们取得天下有用，你速去"+HIW+"定襄"+NOR+CYN+"将他招降！\n";
}

string do_job2()
{
  object ob;
  object office;
  object paper;
  string *place;
  string name;
  int i;   
  
  ob=this_player();
  if(ob->query("combat_exp")<1000000)
  return "凭你的能力还不足以做这么大的事！\n";
  if(ob->query_temp("liyuan_job/step")>=4)
  return "你已经完成缉拿了，还是快点做下面的事吧！\n";
  if(ob->query_temp("liyuan_job/step")<2)
  return "你还是先从头做起吧！\n";
  if(ob->query_temp("liyuan_job/step")==3)
  return "你还是赶快去做事情吧！\n";
  
  ob->add_temp("liyuan_job/step",1);
  
  ob->add("combat_exp",100);
  ob->add("potential",50);
  tell_object(ob,"李渊朝你笑道：多谢你完成了第一个任务！\n"+
                 "李渊奖励了你"+HIW+chinese_number(100)+NOR+"经验，"+
                 HIY+chinese_number(50)+NOR+"点潜能。\n");
  
  place=keys(hill_map);
  i=random(sizeof(place));
 
  name=killer_name[random(sizeof(killer_name))]+
       killer_id[random(sizeof(killer_id))];
    
  paper=new(__DIR__"paper");
  paper->set("target_name",name);
  paper->set("target_where",place[i]);
  paper->set("target_place",hill_map[place[i]]);
  paper->move(ob);
  
  office=new(__DIR__"office");
  office->set("owner",ob);
  office->move(environment(ob));
  office->set_leader(ob);
  tell_object(ob,"一个军官走了出来。\n");
  message_vision("$N给了$n一个"+paper->name()+"。\n",this_object(),ob);
  return "据说"+name+"意欲对我们李阀做害，请你去"+HIW+hill_map[place[i]]+NOR+CYN+"\n"+
         "将他缉拿，然后交给这个官差就可以了！\n";
}

string do_job3()
{
  object ob;
  object paper;
  string *place;
  string name;
  int i;   
  
  ob=this_player();
  if(ob->query("combat_exp")<1000000)
  return "凭你的能力还不足以做这么大的事！\n";
  if(ob->query_temp("liyuan_job/step")>=6)
  return "你已经完成缉拿了，还是快点做下面的事吧！\n";
  if(ob->query_temp("liyuan_job/step")<4)
  return "你还是先从头做起吧！\n";
  if(ob->query_temp("liyuan_job/step")==5)
  return "你还是赶快去做事情吧！\n";
  
  ob->add_temp("liyuan_job/step",1);
  
  ob->add("combat_exp",110);
  ob->add("potential",50);
  tell_object(ob,"李渊朝你笑道：多谢你完成了第二个任务！\n"+
                 "李渊奖励了你"+HIW+chinese_number(110)+NOR+"经验，"+
                 HIY+chinese_number(50)+NOR+"点潜能。\n");
  
  place=keys(hill_map);
  i=random(sizeof(place));
  name=killer_name2[random(sizeof(killer_name2))]+
       killer_id2[random(sizeof(killer_id2))];
  
  paper=new(__DIR__"paper3");
  paper->set("target_name",name);
  paper->set("target_place",hill_map[place[i]]);
  paper->set("target_where",place[i]);
  paper->move(ob);
  
  message_vision("$N给了$n一个"+paper->name()+"。\n",this_object(),ob);
  return "据说"+name+"反对李阀已久，据说他已逃到"+HIW+hill_map[place[i]]+NOR+CYN+"\n"+
         "，你速去将他就地正法！\n";
}

string do_job4()
{
  object ob;
  object track;
  string msg;
  
  ob=this_player();
  if(ob->query("combat_exp")<1000000)
  return "凭你的能力还不足以做这么大的事！\n";
  if(ob->query_temp("liyuan_job/step")>=8)
  return "你已经完成救急了，还是快点做下面的事吧！\n";
  if(ob->query_temp("liyuan_job/step")<6)
  return "你还是先从头做起吧！\n";
  if(ob->query_temp("liyuan_job/step")==7)
  return "你还是赶快去做事情吧！\n";
  
  ob->add_temp("liyuan_job/step",1);
  
  ob->add("combat_exp",120);
  ob->add("potential",50);
  tell_object(ob,"李渊朝你笑道：多谢你完成了第三个任务！\n"+
                 "李渊奖励了你"+HIW+chinese_number(120)+NOR+"经验，"+
                 HIY+chinese_number(50)+NOR+"点潜能。\n");
  
  track=new(__DIR__"track");
  track->set("owner",ob);
  ob->set_temp("track_target",track);
  track->move(environment(ob));
  switch(random(3)){
  
  case 0:
  track->set("target_place",1);
  msg= "最近扬州闹旱灾，你速押解粮草银两前去救急！\n";
  track->set("long","这是一辆由"+ob->name()+"护送送往扬州的粮草车。\n");
  break;
  case 1:
  track->set("target_place",2);
  msg= "最近九江闹旱灾，你速押解粮草银两前去救急！\n";
  track->set("long","这是一辆由"+ob->name()+"护送送往九江的粮草车。\n");
  break;
  case 2:
  track->set("target_place",3);
  msg= "最近巴陵闹旱灾，你速押解粮草银两前去救急！\n";
  track->set("long","这是一辆由"+ob->name()+"护送送往巴陵的粮草车。\n");
  break;}
  msg+="把这车粮草交给当地的粮运军官就可以了！\n"+
       "路上要小心强盗！！\n";
  ob->apply_condition("liyuan_job_killer1",1);
  return msg;
}

string do_job5()
{
  object ob;
  object target;
  string *list;
  object paper;
  int i;
  
  ob=this_player();
  if(ob->query("combat_exp")<1000000)
  return "凭你的能力还不足以做这么大的事！\n";
  if(ob->query_temp("liyuan_job/step")>=10)
  return "你已经完成救急了，还是快点做下面的事吧！\n";
  if(ob->query_temp("liyuan_job/step")<8)
  return "你还是先从头做起吧！\n";
  if(ob->query_temp("liyuan_job/step")==9)
  return "你还是赶快去做事情吧！\n";
  
  ob->add_temp("liyuan_job/step",1);
  
  ob->add("combat_exp",130);
  ob->add("potential",50);
  tell_object(ob,"李渊朝你笑道：多谢你完成了第四个任务！\n"+
                 "李渊奖励了你"+HIW+chinese_number(130)+NOR+"经验，"+
                 HIY+chinese_number(50)+NOR+"点潜能。\n");
  
  list=keys(npc_list);
  i=random(sizeof(list));
  
  paper=new(__DIR__"paper2");
  paper->set("target_place",list[i]);
  paper->set("target_name",npc_list[list[i]]);
  paper->move(ob);
  message_vision("$N给了$n一个"+paper->query("name")+"。\n",
                 this_object(),ob);
  return "据说最近"+npc_list[list[i]]+"正在聚众反对李阀，你去安抚一下吧！\n";
}

string do_job6()
{
    object ob;
    object paper;
    string *place;
    int i;
    
    ob=this_player();
  if(ob->query("combat_exp")<1000000)
  return "凭你的能力还不足以做这么大的事！\n";
  if(ob->query_temp("liyuan_job/step")>=12)
  return "你已经完成寻宝了，还是快点做下面的事吧！\n";
  if(ob->query_temp("liyuan_job/step")<10)
  return "你还是先从头做起吧！\n";
  if(ob->query_temp("liyuan_job/step")==11)
  return "你还是赶快去做事情吧！\n";
  
  ob->add_temp("liyuan_job/step",1);
  
  ob->add("combat_exp",140);
  ob->add("potential",50);
  tell_object(ob,"李渊朝你笑道：多谢你完成了第五个任务！\n"+
                 "李渊奖励了你"+HIW+chinese_number(140)+NOR+"经验，"+
                 HIY+chinese_number(50)+NOR+"点潜能。\n");
                 
  place=keys(weapon_list);
  i=random(sizeof(place));
  
  paper=new(__DIR__"paper4"); 
  paper->set("target_where",place[i]);
  paper->move(ob);
  tell_object(ob,"李渊给了你一张藏宝图。\n");
  return "我最近丢失了一件宝物,据说在"+weapon_list[place[i]]+",你去帮我找回来吧！\n";
}

int do_lingshang(string arg)
{
    object ob;
    object baowu;
    
    ob=this_player();
    
    if(!arg)
    return notify_fail("你要拿什么来领赏？\n");
    if(!objectp(baowu=present(arg,ob)))
    return notify_fail("你身上没有这个东西！\n");
    
    if(ob->query_temp("liyuan_job/step")!=11||
       baowu->query("target")!=ob)
    return 0;
    destruct(baowu);
    ob->add_temp("liyuan_job/step",1);
    
    tell_object(ob,query("name")+"朝你一笑：真是太谢谢你了！\n");
    return 1;
}

string do_job7()
{
   object ob;
  object track;
  
  ob=this_player();
  if(ob->query("combat_exp")<1000000)
  return "凭你的能力还不足以做这么大的事！\n";
  if(ob->query_temp("liyuan_job/step")>=14)
  return "你已经完成了全部的任务，快去「观雨亭」领赏吧！\n";
  if(ob->query_temp("liyuan_job/step")<12)
  return "你还是先从头做起吧！\n";
  if(ob->query_temp("liyuan_job/step")==13)
  return "你还是赶快去做事情吧！\n";
  
  ob->add_temp("liyuan_job/step",1);
  
  ob->add("combat_exp",150);
  ob->add("potential",50);
  tell_object(ob,"李渊朝你笑道：多谢你完成了第六个任务！\n"+
                 "李渊奖励了你"+HIW+chinese_number(150)+NOR+"经验，"+
                 HIY+chinese_number(50)+NOR+"点潜能。\n");
  
  track=new(__DIR__"track2");
  track->set("owner",ob);
  ob->set_temp("track_target",track);
  track->move(environment(ob));
  track->set("long","这是由"+ob->name()+"负责护送的大车。\n");
  tell_room(environment(ob),"一个官兵从里面赶出了一辆大车。\n");
  tell_room(environment(ob),"一个军机大臣从里面走了出来，钻进了大车中。\n");
  ob->apply_condition("liyuan_job_killer2",1);
  return "这位军机大臣要去扬州的总管府，你负责路上的保护吧！\n";
}

string do_abandon()
{
   object ob;
   
   ob=this_player();
   ob->delete_temp("liyuan_job");
   ob->delete_temp("track_target");
   ob->delete_temp("dtsl_job");
   ob->delete_temp("killer_comes");
   ob->set("busy_time",0);
   return "象你这么没有能力的人真是给我们李阀丢脸！\n";
}