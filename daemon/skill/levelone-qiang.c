inherit SKILL;
#include <ansi.h>
mapping *action=({
 ([ "action":"$N手中$w一颤，连续刺向$n面门，哽嗓，前心",
    "apply_factor": 5,
    "name" : "枪法",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N一个跨步，$w上下分飞，重重枪影先将敌人身形罩住，",
    "apply_factor": 5,
    "name" : "枪法",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N一按枪把，啪！地一声抖出五朵枪花。上下左右，虚虚实实刺向$n全身要害",
    "apply_factor": 5,
    "name" : "枪法",
    "damage_type":"刺伤",
  ]),([ "action":"$N狂喝一声，$w己化成一道亮光，人枪如流星似的划过空间，冲向$n",
    "apply_factor": 5,
    "name" : "枪法",
    "damage_type":"刺伤",
  ]),
});   

mapping query_action(object me,object weapon)
{
   return action[random(sizeof(action))];
 

}
string query_type()    
{                      
	return "spear";
}
string query_base()  
{
	return "spear";
}


mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}
