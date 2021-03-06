//九转剑诀jiuzhuan-jianjue
//中级-->终极武功。


inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N剑尖下指，一式「无边落木」，剑尖直点$n的$l！",
    "apply_factor": 2,
    "name" : "无边落木", 
    "damage_type":"刺伤",
  ]),
 ([ "action":"$N踏前数步，避虚就实，右手使一式「星弛电闪」直刺$n的$l！",
    "apply_factor": 3,
    "name" : "星弛电闪",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N一招「雨打飞花」，剑尖抖起五朵剑花，分别刺向$n的左脸和右耳！",
    "apply_factor": 4,
    "name" : "雨打飞花",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N剑身横摆，剑尖指向$n的脸部，一招「万马千军」，横扫$n的$l！",
    "apply_factor": 5,
    "name" : "万马千军",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N双脚离地，使出草上飞，身行直奔$n，一招「紫电穿云」，剑出中宫，平削$n的$l！",
    "apply_factor": 6,
    "name" : "紫电穿云",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N长笑一声，横剑斜削，一招「白虹贯日」，剑风逼向$n的$l！",
    "apply_factor": 7,
    "name" : "白虹贯日",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N使出「彗星袭月」，$w幻一条飞练，带着一股寒气划向$n的$l！",
    "apply_factor": 8,
    "name" : "彗星袭月",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N腾空而起，突然使出一招「无声无色」，悄无声息地疾向$n的背部刺去！",
    "apply_factor": 9,
    "name" : "无声无色",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N侧身前趋，剑诀斜引，一招「百丈飞瀑」，剑锋从半空中直泻下来，罩住$n上方！",
    "apply_factor": 10,
    "name" : "百丈飞瀑",
    "damage_type":"刺伤",
  ]),

});   


string *parry_weapon=({

"$N凝神不动，手中$w虽是后出却好似先发，已经封住了$n的$v！\n",
"$N突然将$w刺在虚空之处，犹如弈棋中的一子，令$n不得不撤回$v！\n",
"$N将手中的$w划了一个圈子，然后反刺在圆心处，非常准确地格开了$n的$v。\n",
"$N将$w举起不动，若$v想打到自己，$n的手腕必定先被$w刺到，$n无奈之下，只好撤回$v！\n"

});

string *parry_hand=({

"$N刷刷刷三剑，已经反攻为守，却有给$n一条活路，$n连忙从唯一活路逃了出去！\n",
"$N微微一笑，手中$w已然凝住不动，好似$n的手腕自动送上来被刺，$n连忙收招后退！\n",
"$N剑光虚点，似乎朝$n的脚下刺去，但招式不老，已经改向$n面门刺去，$n一惊，连忙后退收招。\n",
"$N的剑法入微之至，每一招都是防守严密，令$n不得不收招后退！\n"

});

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}




mapping query_action(object me,object weapon)
{
   return action[random(sizeof(action))];
 

}
mapping *query_all_action(object me)
{
return action;	
}

string query_type()    
{                      
	return "sword";
}
string query_base()  
{
	return "sword";
}

int valid_learn(object me)
{
	object weapon;
	if(!objectp(weapon=me->query_temp("weapon")))
	return notify_fail("手中无剑，如何学习九转剑诀？\n");
	if(weapon->query("skill_type")!="sword")
	return notify_fail("手中无剑，如何学习九转剑诀？\n");
	return 1;
}
int practice_skill(object me)  
{
   object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
 
 return 1;  


}

mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

string *query_perform()
{
   return ({"xingchen","liuxing"});
}


int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/jue"))
  return 200;
  return 100;
}


object offensive_target(object me)
{
	int sz;
	object *enemy,target;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ){
	  target=enemy[random(sz)];
	  return target;
	}
	else return 0;
}

int form_array(object me)
{
   object *t,*m,target;
   int i,flag=0,fight_flag=0;
   string skill_name;
   
   t=me->query_team();
   t=t-({0});
   if(sizeof(t)<2) return notify_fail("要施展「断字诀阵」至少是两个人！\n");
   
   if(time()-me->query_temp("form_busy")<10)
   return notify_fail("你真气不足，无法施展断字诀阵！\n");
   
   for(i=0;i<sizeof(t);i++)
    if(objectp(t[i])){
     if(environment(t[i])!=environment(me))
      return notify_fail("有人不和你站在一起！\n");
     if(t[i]->query_skill("jiuzhuan-jianjue",1)<160)
      return notify_fail(t[i]->name()+"九转剑诀修为太低了！\n");
     skill_name=t[i]->reset_action(t[i]->query_temp("weapon"));
     if(skill_name!="jiuzhuan-jianjue")
     return notify_fail(t[i]->name()+"没有使用九转剑诀！\n");
    }
   target=offensive_target(me);
   if(!target)
   return notify_fail("你没有战斗的目标！\n");
   m=target->query_team();
   if(!arrayp(m)) return notify_fail("对方没有组队，没有必要使用阵法！\n");
   m=m-({0});
   
   message_vision(HIG"$N"+HIG+"一声长啸，只见「断字诀阵」已经施展开来！\n"NOR,me);
   if(me->is_killing(target->query("id")))
    fight_flag=1;
   
   for(i=0;i<sizeof(t);i++){
      if(!t[i]->is_fighting(target)){
        if(fight_flag) {t[i]->kill_ob(target);target->kill_ob(t[i]);}
        else {t[i]->fight_ob(target);target->fight_ob(t[i]);}
      }
      t[i]->set_temp("form_busy",time());
      flag+=COMBAT_D->do_attack(t[i],target,t[i]->query_temp("weapon"),0,2);
   }
   if(flag>=2){
     message_vision("\n在「断字诀阵」的冲击之下，$N的队伍已经散乱！\n",target);
     m=target->query_team();
     m=m-({0});
     for(i=0;i<sizeof(m);i++)
      if(objectp(m[i])){
        m[i]->dismiss_team();
        m[i]->delete_temp("team_mark");
      }
   }
   
   return 1;
}