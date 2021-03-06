// 散手八扑。

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N的劲气如附骨之蛆，无论$n如何腾挪闪跃，始终不即不离的威胁着$n的$l，令$n无可奈何！",
        "apply_factor": 2,
        "name" : "附骨之蛆",
       "damage_type": "瘀伤"
]),

([  "action": "$N的劲气像一把枷锁般硬附于$n身上，只要$n防守稍差，保证可袭得$n吐血倒地，绝无幸理！",
        "apply_factor": 5,
        "name" : "篓中之鱼",
        "damage_type": "瘀伤"
]),

([      "action": "$N脸上露出凝重的神色，身体忽然生出非任何笔墨能形容的微妙玄奇变化，似是两袖\n"+
                  "扬起，倏地晶莹如玉的手从左袖探出，漫不经意的指尖合拢，扫往$n的$l。",
        "apply_factor": 10,
        "name" : "昙花一现",
        "damage_type": "瘀伤"
]),

([  "action": "只见$N简单的一步，竟能把整个对峙的气场转移重心，偏又能令$n欲攻无从，且陷进劣境。\n"+
              "就像两人角力，硬被对手突然扭得身子歪往一方，有力难施。",
        "apply_factor": 7,
        "name" : "风雨欲来",
        "damage_type": "瘀伤"
]),

([  "action": "衣袖在$n眼前扩大，竟看不到$N的身形步法，本是袍袖飘拂，忽然又化为修长晶莹的仙手，\n"+
              "其神妙处怎都形容不出来。",
        "apply_factor": 4,
        "name" : "飞幻千仙",
        "damage_type": "瘀伤"
]),

([  "action": "$N倏又欺近，左掌横切$n的$l，明明是平实无奇，毫无花巧的招式，但却有变化无\n"+
              "方，令人无法捉摸的迷幻感觉。",
        "apply_factor": 6,
        "name" : "变换其中",
        "damage_type": "瘀伤"
]),

([  "action": "$N一手负后，一手探前，合指撮掌打出问讯般的手势，站得稳如山岳，使人生出难\n"+
              "以动摇其分毫的感觉！",
        "apply_factor": 3,
        "name" : "镇海之山",
        "damage_type": "瘀伤"
]),

([  "action": "$N出招随意，潇洒随意的拨、扫、挥、劈，没有丝毫花巧，却守得$n难越雷池半步。",
        "apply_factor": 8,
        "name" : "百尺风屏",
        "damage_type": "瘀伤"
]),

});

string *parry_weapon=({

"$N出招随意，潇洒随意的拨、扫、挥、劈，没有丝毫花巧，已经格开了$n的$v！\n",
"$N掌往后收，在胸前似动非动，迫得$n收回$v后退开来！\n",
"$N神态从容的自天而降，状如仙人，只听砰地一声，一股惊人气劲震开了$n的$v！\n",
"$N脸上露出凝重的神色，漫不经意的指尖合拢，扫在$n的$v处！\n"

});

string *parry_hand=({

"$N出招随意，潇洒随意的拨、扫、挥、劈，没有丝毫花巧，已经格开了$n的进攻！\n",
"$N掌往后收，在胸前似动非动，迫得$n收回招式后退开来！\n",
"$N神态从容的自天而降，状如仙人，只听砰地一声，一股惊人气劲震开了$n的手臂！\n",
"$N脸上露出凝重的神色，漫不经意的指尖合拢，扫在$n的手腕处！\n"

});

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}

mapping query_action(object me)  
{
        return action[random(sizeof(action))];
}
mapping *query_all_action(object me)
{
return action;	
}

int valid_learn(object me)
{
     return 1;  
        
       
}

int practice_skill(object me)
{
   return 1;
}



string query_type() 
{
	return "hand";
}

string query_base()
{
	return "strike";
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

string *query_perform()
{
  return ({"bapu"});
}



int skill_damage(object me,object victim)
{
	int str,inte;
	int damage;
	int add;
	
	str = me->query("str");
	inte = me->query("int");
	
  	if(me->query("perform_quest/bapu")){
  		if(str>=38&&inte>=38){  		
  			damage = 250;
  			add = str-38;
  			if(inte-38>add)
  				add = inte-38;
  			damage = damage+damage*(add/2)*20/100;
  			
  		}
  		else
  		if(str>=35&&inte>=35)
  			damage = 150;
  		else
  			damage = 100;
  	}
  	else
  		damage = 80;
  		
  	return damage;
}
