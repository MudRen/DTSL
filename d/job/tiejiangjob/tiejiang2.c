
inherit NPC;

#include <job_money.h>
#include <ansi.h>

int item_player();
int cancel_me();
mapping tiename=([
RED"红铁矿"NOR:"hongtie",
YEL"橙铁矿"NOR:"chengtie",
HIY"黄铁矿"NOR:"huangtie",
GRN"绿铁矿"NOR:"lvtie",
HIC"青铁矿"NOR:"qingtie",
BLU"蓝铁矿"NOR:"lantie",
MAG"紫铁矿"NOR:"zitie",
//"红铁矿":"hongtie",
//"橙铁矿":"chengtie",
//"黄铁矿":"huangtie",
//"绿铁矿":"lvtie",
//"青铁矿":"qingtie",
//"蓝铁矿":"lantie",
//"紫铁矿":"zitie",
]);

mapping itemname=([
"铁刀":"blade",
"铁剑":"sword",
"铁枪":"spear",
"铁叉":"fork",
"铁鞭":"whip",
"铁杖":"staff",
"铁匕首":"dagger",
]);
void create()
{
  set_name("打铁工", ({ "datie gong", "gong" }));
  set("age", 60);
  set("gender", "男性");
  set("long", "一个打铁工。\n");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 10);
  set("combat_exp", 1200000);
  set("max_kee", 1500);
  set("max_sen", 1500);
  set("max_force", 1500);
  set("force", 1500);
  set("force_factor", 150);
  set_skill("unarmed", 90);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("force", 80);
  set("target_id","###");
  set("inquiry", ([
        "打造":   (: item_player:),
        "放弃":   (: cancel_me:),
      ]));
  setup();

}

int item_player()
{
  string *strs = ({
    "$N对$n说道：  你的技术够高了，应该可以打造",
    "$N想想说：我看现在的技术起码可以打造",
  });  
  string str;
  object me = this_object();
  object who = this_player();
  string *itemn,*itemid1;int itemz;
  string *n,*id1;int z;

 if(who->query("combat_exp")<100000){
	   	
		command("hehe");
		command(
 		  "say 你还是先去帮一帮铁匠找铁矿吧！\n");
		return 1;
	    }

 if (who->query_temp("quest/item"))
  {
    message_vision ("$N对$n说道：你不是答应帮我打造"+who->query_temp("quest/item/name")+"吗？怎么还没来？\n",me,who);
    return 1;
 } 
if(time()-who->query("busy_time")<5){
	   	
		command("hehe");
		command(
 		  "say 我们这里暂时不缺东西，等会吧！\n");
		return 1;
	    }

 
   n=keys(tiename);
  z=random(sizeof(n));  

   id1=tiename[n[z]];
   itemn=keys(itemname);
  itemz=random(sizeof(itemn));  

   itemid1=itemname[itemn[itemz]];
  who->set_temp("quest/item/name", itemn[itemz]);
  who->set_temp("quest/item/id", itemid1);
  who->set_temp("quest/item/med", n[z]);
  who->set("busy_time",time()-20);
  str = strs[random(sizeof(strs))]+itemn[itemz]+
        "，\n这位"+RANK_D->query_respect(who)+
        "了，你去帮我打造一把！记住，要用"+n[z]+"打造\n";

  message_vision (str,me,who);
  return 1;
}


int cancel_me()
{	
	
	object target,me=this_player();

           if(!me->query_temp("quest/item"))
	   
	{
	   command("bite");
	   command("say 我又没叫你帮我打造东西，你放什么弃啊？！\n");
	   return 1;
       }
        JOBSYS_D->do_cancel_job("tiejiangjob2",me,this_object());
	
	command("say 没用的东西！！\n");
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


int accept_object(object who, object ob)
{
	string where;
	string type;
	int lvl;
	object killer;
	object cob;
  object me = this_object();
  string name,jname,mname,jmname;
  int t;
  string reason;
  
  if (who->query_temp("tiejobkiller_come"))
  {
    return notify_fail(query("name")+"对"+who->name()+"说道：东西给人抢了就拿另一个顶替，太那个啦吧？。\n");
   
  }

  if (! who->query_temp("quest/item")||!ob->query("metirial"))
  {
    return notify_fail(query("name")+"对"+who->name()+"说道：我现在不缺这个，你给我也没用。\n");
   
  }

  if(ob->is_character()) return notify_fail("\n");
  
  name=no_color(ob->query("name"));
  jname=no_color(who->query_temp("quest/item/name"));
  jmname=no_color(who->query_temp("quest/item/med"));
  mname=no_color(ob->query("metirial"));
  
  if (jname !=name)
  {
    return notify_fail(query("name")+"对"+who->name()+"说道：我叫你帮我打"+
		    who->query_temp("quest/item/name")+
                    "，您却给我打个"+ob->query("name")+"，这是什么意思？\n");
   
  }

  if (mname !=jmname)
  {
    return notify_fail(query("name")+"对"+who->name()+"说道：我叫你帮我打的东西是用"+
		    who->query_temp("quest/item/med")+
                    "打造的，您却给我用"+ob->query("metirial")+"来打，这是什么意思？\n");   
  }

  if (who->query_temp("quest/item/id") != ob->query("id"))
  {
    return notify_fail(query("name")+"对"+who->name()+"说道：我等着您的"+who->query_temp("quest/item/name")+
                    "，东西倒挺象，但不是同一个货；我要的是("+who->query_temp("quest/item/id")+")，您给的是("+
                    ob->query("id")+")！\n");
  }
  if (who->query("combat_exp") >=800000)
  {
  if (!who->query_temp("tiejobkiller"))
  {
      type=ob->query("skill_type");
      cob=new("/obj/weaponclass/"+type);	
      cob->set("name",ob->query("name"));
	cob->set("long",ob->query("long"));
      cob->set("weapon_prop/damage",ob->query("weapon_prop/damage"));
      cob->set("max_strong",ob->query("max_strong"));
	cob->set("metirial",ob->query("metirial"));
	cob->set("strong",ob->query("strong"));
	cob->set("flag",0);     
     killer = new("/d/job/tiejiangjob/killer");    
     lvl=who->query_temp("tiejob/level");     
     where=killer->invocation(who,lvl);
     message_vision ("忽然间，一个蒙面人冲了出来，一把抢过$n手中的"+ob->query("name")+"，然后夺门而出，\n",me,who);
     message_vision ("$n拼命地追了出去！！\n",me,who);
     who->set_temp("tiejobkiller_come",1);
     who->add_temp_array("job_temp_killer",killer);
     who->move(environment(killer));     
     cob->move(killer);
     
   return 1;
  }
}
  
  reason = "帮我打造"+ob->query("name")+"，";
  message_vision ("$N对$n说道：你"+reason+"我真的要好好奖励你！\n",me,who); 
  
  JOBSYS_D->give_reward_tiejiangjob2(who);
  who->delete_temp("quest");
  who->delete_temp("tiejobkiller");
  who->set("busy_time",time());  
  return 1;
}

