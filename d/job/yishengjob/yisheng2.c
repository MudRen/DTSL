
inherit NPC;

#include <ansi.h>
#include <job_money.h>

int item_player();
int cancel_me();
mapping yaoname=([
RED"红花"NOR:"honghua",
YEL"陈皮"NOR:"chenpi",
HIY"人参"NOR:"renshen",
GRN"当归"NOR:"danggui",
HIC"雪莲"NOR:"xuelian",
BLU"生地"NOR:"shengdi",
MAG"何首乌"NOR:"heshouwu",
]);

mapping itemname=([
"活血丸":"气血",
"回神丸":"精神",
"养精丹":"精血",
]);
void create()
{
  set_name("药师", ({ "yao shi", "shi" }));
  set("age", 60);
  set("gender", "男性");
  set("long", "一个药师。\n");
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
        "job":   (: item_player:),
        "放弃":   (: cancel_me:),
      ]));
  setup();

}

int item_player()
{
  string *strs = ({
    "$N对$n说道：  你的技术够高了，应该可以炼制",
    "$N想想说：我看现在的技术起码可以炼制",
  });  
  string str;
  object me = this_object();
  object who = this_player();
  string *itemn,*itemid1;int itemz;
  string *n,*id1;int z;

 if(who->query("combat_exp")<100000){
	   	
		command("hehe");
		command(
 		  "say 你还是先去帮一帮采药人找采药吧！\n");
		return 1;
	    }

 if (who->query_temp("quest/yaoitem"))
  {
    message_vision ("$N对$n说道：你不是答应帮我炼制"+who->query_temp("quest/yaoitem/name")+"吗？怎么还没来？\n",me,who);
    return 1;
 } 
if(time()-who->query("busy_time")<30){
	   	
		command("hehe");
		command(
 		  "say 我们这里暂时不缺东西，等会吧！\n");
		return 1;
	    }

 
   n=keys(yaoname);
  z=random(sizeof(n));  
//  if(z%2!=0) z++;
//   if(z==sizeof(yaoname)-1)
//    z=z-2;  
   id1=yaoname[n[z]];
   itemn=keys(itemname);
  itemz=random(sizeof(itemn));  
//  if(itemz%2!=0) itemz++;
//   if(itemz==sizeof(itemname))
//    itemz=itemz-2;  
   itemid1=itemname[itemn[itemz]];
  who->set_temp("quest/yaoitem/name", itemn[itemz]);
  who->set_temp("quest/yaoitem/id", itemid1);
  who->set_temp("quest/yaoitem/med", n[z]);
  who->set("busy_time",time()-20);
  str = strs[random(sizeof(strs))]+itemn[itemz]+
        "了，\n这位"+RANK_D->query_respect(who)+
        "，你去帮我炼一个！记住，要用"+n[z]+"炼制\n";

  message_vision (str,me,who);
  return 1;
}


int cancel_me()
{	
	
	object target,me=this_player();

           if(!me->query_temp("quest/yaoitem"))
	   
	{
	   command("bite");
	   command("say 我又没叫你帮我炼制东西，你放什么弃啊？！\n");
	   return 1;
       }
	
	JOBSYS_D->do_cancel_job("yishengjob2",me,this_object());
	command("say 没用的东西！！\n");
        return 1;
}

string no_color(string arg)
{
        arg = replace_string(arg,BLK, "");
	arg = replace_string(arg,RED, "");
	arg = replace_string(arg,GRN, "");
	arg = replace_string(arg,YEL, "");
	arg = replace_string(arg,BLU, "");
	arg = replace_string(arg,MAG, "");
	arg = replace_string(arg,CYN, "");
	arg = replace_string(arg,WHT, "");
	arg = replace_string(arg,HIR, "");
	arg = replace_string(arg,HIG, "");
	arg = replace_string(arg,HIY, "");
	arg = replace_string(arg,HIB, "");
	arg = replace_string(arg,HIM, "");
	arg = replace_string(arg,HIC, "");
	arg = replace_string(arg,HIW, "");
	arg = replace_string(arg,NOR, "");
	arg = replace_string(arg,BLINK, "");
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
  string name,jname,*mname,jmname,*heal_types,heal_type;
  int t,heal_num;
  string reason;
  
  if (who->query_temp("yaojobkiller_come"))
  {
    return notify_fail(query("name")+"对"+who->name()+"说道：东西给人抢了就拿另一个顶替，太那个啦吧？。\n");
   
  }

  if (! who->query_temp("quest/yaoitem")||ob->query("id")!="medicine")
  {
    return notify_fail(query("name")+"对"+who->name()+"说道：我现在不缺这个，你给我也没用。\n");
   
  }

  if(ob->is_character()) return notify_fail("\n");
  
  /*
  name=no_color(ob->query("name"));
  jname=no_color(who->query_temp("quest/yaoitem/name"));
  jmname=no_color(who->query_temp("quest/yaoitem/med"));
  mname=no_color(ob->query("makeby"));
  */
  name=(ob->query("name"));
  jname=(who->query_temp("quest/yaoitem/name"));
  jmname=(who->query_temp("quest/yaoitem/med"));
  mname=(ob->query("makeby"));
  
  if (jname !=name)
  {
    return notify_fail(query("name")+"对"+who->name()+"说道：我叫你帮我炼"+
		    who->query_temp("quest/yaoitem/name")+
                    "，您却给我炼出个"+ob->query("name")+"，这是什么意思？\n");
   
  }

  if (member_array(jmname,mname)==-1)
  {
    return notify_fail(query("name")+"对"+who->name()+"说道：我叫你帮我炼的丹药是用"+
		    who->query_temp("quest/yaoitem/med")+
                    "炼制的，您却给我的药中却没有这个原料，这是什么意思？\n");   
  }

  if (member_array(who->query_temp("quest/yaoitem/id"),keys(ob->query("heal_up")))==-1)
  {
    
    heal_types=keys(ob->query("heal_up"));
    heal_type="";
    for(heal_num=0;heal_num<sizeof(heal_types);heal_num++)
     heal_type+=heal_types[heal_num]+" ";
    
    return notify_fail(query("name")+"对"+who->name()+"说道：我等着您的"+who->query_temp("quest/yaoitem/name")+
                    "，东西倒挺象，但不是同一个货；\n我要的是能治疗("+who->query_temp("quest/yaoitem/id")+")的，您给的是治疗("+
                    heal_type+")方面的！\n");
  }

  if (who->query("combat_exp") >=800000)
  {
  if (!who->query_temp("yaojobkiller"))
  {
        cob=new("/obj/medicine/medicine");	
	cob->set("name",ob->query("name"));
	cob->set("type",ob->query("type"));
	cob->set("makeby",ob->query("makeby"));
	cob->set("value",ob->query("value"));
	cob->set("long",ob->query("long"));
	cob->set("heal_up",ob->query("heal_up"));
	cob->set("medicine_type/type",ob->query("medicine_type/type"));
	cob->set("medicine_type/heals",ob->query("medicine_type/heals"));
     killer = new("/d/job/yishengjob/killer");    
     lvl=who->query_temp("yaojob/level");     
     where=killer->invocation(who,lvl);
     message_vision ("忽然间，一个蒙面人冲了出来，一把抢过$n手中的"+ob->query("name")+"，然后夺门而出，\n",me,who);
     message_vision ("$n拼命地追了出去！！\n",me,who);
     who->set_temp("yaojobkiller_come",1);
     who->add_temp_array("job_temp_killer",killer);
     who->move(environment(killer));     
     cob->move(killer);
     
   return 1;
  }
}
  
  reason = "帮我炼制"+ob->query("name")+"，";
  message_vision ("$N对$n说道：你"+reason+"我真的要好好奖励你！\n",me,who);    
  JOBSYS_D->give_reward_yishengjob2(who);
  who->delete_temp("quest/yaoitem");
  who->delete_temp("yaojobkiller");
  who->set("busy_time",time());  
  return 1;
}


