//清玄剑法.
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N身行晃动,身走九宫八卦之式,一招[心清身静]刺向$n！",
    "apply_factor": 5,
    "name" : "招数", 
    "damage_type":"刺伤",
  ]),
 ([ "action":"$N身行猛地向前一冲,脚下虚晃一扫,一招[风清月明]举剑向$n的额头刺去！",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N腾空越起,挥剑凌空刺下,正是一招[清风邀月]！",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N气定神闲,长剑画了一个圆弧,一招[玄虚无实]刺向$n的周身大穴！",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"刺伤",
  ])});   






mapping query_action(object me,object weapon)
{
   return action[random(sizeof(action))];
 

}


string query_type()    
{                      
	return "sword";
}
string query_base()  
{
	return "sword";
}

