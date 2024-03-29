// Combatd.c
//Written by Yanyan.
//For DaTangShuangLong
//Copyrights DaTangShuangLong.wiz
// #pragma optimize

inherit F_DBASE;

#include <ansi.h>
#include <skill.h>
#include <org.h>
#include <weapon.h>
#include <combat.h>
#include <globals.h>


void fight(object me, object victim);
void end_fight(object killer,object victim);
void do_parry(object me,object victim,object weapon);

void create()
{
	seteuid(getuid());
	set("channel_id", "战斗精灵");

}


string *guard_msg = ({
	CYN "$N"+CYN+"注视着$n"+CYN+"的行动，企图寻找机会出手。\n" NOR,
	CYN "$N"+CYN+"正盯着$n"+CYN+"的一举一动，随时准备发动攻势。\n" NOR,
	CYN "$N"+CYN+"缓缓地移动着，想要找出$n"+CYN+"的破绽。\n" NOR,
  CYN "$N"+CYN+"聚精会神地盯着$n"+CYN+"，寻找最佳出招机会。\n" NOR,
	CYN "$N"+CYN+"目不转睛地盯着$n"+CYN+"的动作，寻找进攻的最佳时机。\n" NOR,
	CYN "$N"+CYN+"慢慢地移动着，伺机出手。\n" NOR,
});

string *beat_parry=({
	"$n连忙蹦开，躲开了攻击!\n",
	"$n迅速的跑开，准备着寻找机会!\n",
	"$n飞快的躲开，准备再次进攻!\n",
});

string *beat_guard=({
	CYN"$N"+CYN+"连忙蹦开，躲开了攻击!\n"NOR,
	CYN"$N"+CYN+"一动不动，准备着寻找机会!\n"NOR,
	CYN"$N"+CYN+"一动不动，准备再次进攻!\n"NOR,
});

string *catch_hunt_human_msg = ({
	HIW "$N"+HIW+"和$n"+HIW+"仇人相见分外眼红，立刻打了起来！\n" NOR,
	HIW "$N"+HIW+"对着$n"+HIW+"大喝：「可恶，又是你！」\n" NOR,
	HIW "$N"+HIW+"和$n"+HIW+"一碰面，二话不说就打了起来！\n" NOR,
	HIW "$N"+HIW+"一眼瞥见$n"+HIW+"，「哼」的一声冲了过来！\n" NOR,
	HIW "$N"+HIW+"一见到$n"+HIW+"，愣了一愣，大叫：「我宰了你！」\n" NOR,
	HIW "$N"+HIW+"喝道：「$n"+HIW+"，我们的帐还没算完，看招！」\n" NOR,
	HIW "$N"+HIW+"喝道：「$n"+HIW+"，看招！」\n" NOR,
});

string *catch_hunt_beast_msg = ({
	HIW "$N怒吼一声，扑了过来攻击$n！\n" NOR,
	HIW "$N对着$n大吼，想杀死$n！\n" NOR,
	HIW "$N发出连串低吼，突然暴起攻击$n！\n" NOR,
});

string *catch_hunt_bird_msg = ({
	HIW "$N对着$n一声怒鸣，飞冲了过来！\n" NOR,
	HIW "$N怒鸣几声，突然暴起攻击$n！\n" NOR,
	HIW "$N一声锐鸣，猛然向$n发起攻击！\n" NOR,
});

string *winner_msg = ({
	CYN "\n$N"+CYN+"微微一笑，说道：承让了！\n\n" NOR,
	CYN "\n$N"+CYN+"双手一拱，笑着说道：承让！\n\n" NOR,
    CYN "\n$N"+CYN+"笑道：青山不改，绿水常流，就此罢手如何?\n\n" NOR,
	CYN "\n$N"+CYN+"胜了这招，向后跃开三尺，笑道：承让！\n\n" NOR,

});
string *winner_animal_msg = ({
	CYN "\n$N退在一旁，警戒地向$n盯视！\n\n" NOR,
	CYN "\n$N退守开来，但仍然毫不放松地盯着$n！\n\n" NOR,
	CYN "\n$N退了几步，但随时可能再冲过来！\n\n" NOR
});
string damage_msg(int damage, string type)
{
	string str;
	if( damage <= 0 ) return "结果对$n没有造成任何伤害。\n";

	switch( type ) {
		case "擦伤":
		case "刮伤":
		case "割伤":
			if( damage < 10 ) return "$N结果只是轻轻地划破$n的$l处的皮肉。\n";
			if( damage < 50 ) return "$N结果在$n的身上划出一道细长的血痕。\n";
			if( damage < 100 ) return "结果「嗤」地一声，$N在$n身上划出一道伤口！\n";
			if( damage < 200 ) return "结果「嗤」地一声，$N在$n身上划出一道血淋淋的伤口！\n";
			if( damage < 320 ) return "结果「嗤」地一声，$N在$n身上划出一道又长又深的伤口，溅得$N满脸鲜血！\n";
			return "结果只听见$n一声惨嚎，已在$n$l上划出一道深及见骨的可怕伤口！！\n";
		case "刺伤":
			if( damage < 10 ) return "结果只是轻轻地刺破$n$l处的皮肉。\n";
			if( damage < 50 ) return "结果在$n的$l刺出一个创口。\n";
			if( damage < 100 ) return "结果「噗」地一声刺入了$n$l寸许！\n";
			if( damage < 200 ) return "结果「噗」地一声刺进$n的$l，使$n不由自主地退了几步！\n";
			if( damage < 320 ) return "结果「噗嗤」地一声，刺进了$n的$l，殷红的鲜血随即喷了出来！\n";
			return "结果只听见$n一声惨嚎，已在$n的$l对穿而出，鲜血溅得满地！！\n";
		case "瘀伤":
			if( damage < 20 ) return "结果只是轻轻地碰到$n的$l，比拍苍蝇稍微重了点。\n";
			if( damage < 40 ) return "结果在$n的$l造成一处瘀青。\n";
			if( damage < 80 ) return "结果一击命中，$n的$l登时肿了一块老高！\n";
			if( damage < 100 ) return "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n";
			if( damage < 170 ) return "结果「砰」地一声，$n退了两步！\n";
			if( damage < 240 ) return "结果这一下「砰」地一声打得$n连退了好几步，差一点摔倒！\n";
			if( damage < 320 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
			if( damage < 450 ) return "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！\n";
			return "只听见$n一声惨叫，整个身体象断了线的风筝一样飞了出去！！\n";
		case "内伤":
			if( damage < 20 ) return "结果只是把$n打得退了半步，毫发无损。\n";
			if( damage < 60 ) return "结果$n痛哼一声，在$p的$l造成一处瘀伤。\n";
			if( damage < 100 ) return "结果一击命中，把$n打得痛得弯下腰去！\n";
			if( damage < 170 ) return "结果$n闷哼了一声，脸上一阵青一阵白，显然受了点内伤！\n";
			if( damage < 240 ) return "结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n";
			if( damage < 320 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
			if( damage < 450 ) return "结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n";
			return "结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n";
		case "震伤":
			if( damage < 100 ) return "结果$n受到$N的劲力一震，闷哼一声。\n";
			if( damage < 150 ) return "结果$n被$N以劲力一震，「嘿」地一声退了两步。\n";
			if( damage < 230 ) return "结果$n被$N以劲力一震，$l有如受到一记重锤，连退了五六步！\n";
			if( damage < 340 ) return "结果$N的劲力一下震得$n连退了好几步，差一点摔倒！\n";
			if( damage < 450 ) return "结果$n被$N的劲力震得全身气血倒流，口中鲜血狂喷而出！\n";
			return "结果$n被$N的劲力震得眼前一黑，内脏碎裂，身子凭空飞了出去！！\n";
		case "拉伤":
			if( damage < 15 ) return "结果只是轻轻地划过了$n的$l。\n";
			if( damage < 50 ) return "结果在$n的$l抽出一道细长的血印。\n";
			if( damage < 150 ) return "结果「啪」地一声将$n的$l的皮肤扯开，形成一道尺许长的伤口！\n";
			if( damage < 250 ) return "只听$n「啊」地一声吐出一口鲜血，原来$n$l的骨头已经被的劲力抽裂！\n";
			if( damage < 350 ) return "结果随着「咔」地一声，已将$n$l处的骨头硬生生地抽断，断骨从肉里冒了出来！\n";
			return "结果$n一声惨嚎，已从$n的$l处撕下了一大片血淋淋的皮肉，鲜血溅得满地！！\n";
		case "砸伤":
		case "挫伤":
			if( damage < 20 ) return "结果只是轻轻地碰撞到了$n一下，没有造成什么伤害。\n";
			if( damage < 80 ) return "结果只将$n的$l砸出一块瘀红。\n";
			if( damage < 160 ) return "结果「啪」地一声，打中$n的$l，登时肿了一块老高！\n";
			if( damage < 320 ) return "结果重重得击中$n的$l，打得$n倒退数步，「哇」地吐出一大口鲜血！\n";
			if( damage < 450 ) return "结果只听见「硼」地一声巨响，打在$n$l，将$n像一捆稻草般击飞出去！\n";
			return "结果一下打在$n的$l，几声骨碎声中，$n象散了架似的瘫了下去！！\n";
		case "抓伤":
			if( damage < 20 ) return "结果只是在$n$l处轻轻刮过，没有什么伤害。\n";
			if( damage < 40 ) return "结果$n皱了皱眉，$l的下部已经被拉出了一道浅浅的血痕。\n";
			if( damage < 80 ) return "结果拉下来$n$l的一点皮肉，疼得$n「哇哇」怪叫了起来！\n";
			if( damage < 120 ) return "结果「唰」地一声，$n的$l上顿时被抓出五道血痕，鲜血流了出来！\n";
			if( damage < 220 ) return "结果$n疼得大叫一声，$l上被抓出了几道深深的血沟，鲜血直流！\n";
			if( damage < 330 ) return "结果只听见$n一声惨嚎，$N的手爪已在$n$l处刺出了五个血肉模糊的窟窿！\n";
			if( damage < 440 ) return "结果「啊」地一声惨叫，$n的$l被$N抓下了一大片皮肉，鲜血横飞满地！！\n";
			return "结果$n一声凄惨的嘶叫，$l处被连皮带肉扯下一大块，露出了白森森的骨头！！\n";
               case "摔伤":
			if( damage < 20 ) return "结果$n脚下不稳，在地上擦破了点儿皮。\n";
			if( damage < 80 ) return "结果「啪」地一声，$n在地上摔了个屁礅。\n";
			if( damage < 160 ) return "结果$n一不小心，被$N重重摔倒在地！\n";
			if( damage < 300 ) return "结果$n被一下摔倒在地，「噗地」一声喷出了一大口鲜血！\n";
            if( damage < 420 ) return "结果被$N这一下摔在地上，$l处的骨头「卡嚓」一声断了！\n";
			return "结果只听见$n一声惨嚎，被$N摔得血肉横飞，惨不忍睹！！\n";
		case "砍伤":
			if(damage<20) return "$N只是刮破了$n$l处的一点皮。\n";
			if(damage<40) return "只听嗤的一声，$n的$l处已经是鲜血直流！\n";
			if(damage<80) return "只听$n一声惨叫，$N已经已经砍在了$n$l处，露出了白森森的骨头！\n";
			if(damage<160) return "$N正砍在$n的$l处，$n惨叫一声，几乎昏死过去！\n";
			if(damage<300) return "$n的$l处立刻血流如注，好象成了血人一般！\n";
			if(damage<420) return "$n的$l处发出「卡嚓」一声，已经被$N砍断了！\n";
			return "只听$n一声惨叫，身子如掉了线的风筝，浑身都是鲜血，朝远处跌去！\n";
		default:
			if( !type ) type = "伤害";
			str =  "结果对$n造成非常可怕的严重";
			if( damage < 270 ) str = "结果对$n造成极其严重的";
			if( damage < 210 ) str = "结果对$n造成十分严重的";
			if( damage < 160 ) str = "结果对$n造成相当严重的";
			if( damage < 120 ) str = "结果对$n造成颇为严重的";
			if( damage < 80 ) str = "结果对$n造成一处严重";
			if( damage < 50 ) str = "结果对$n造成一处";
			if( damage < 30 ) str = "结果对$n造成轻微的";
			if( damage < 10 ) str =  "结果对$n只是勉强造成一处轻微";
			return str + type + "！\n";
	}
}

string report_status(object ob,int damage)
{
	if(ob->query_temp("no_report"))
		return "";

	if(damage>=80)
    	return "($n"+HIY+"看起来受了几处伤，不过似乎并不碍事。"+NOR+")\n";
	else
	if(damage>=60)
		return "($n"+HIY+"受伤不轻，看起来状况并不太好。"+NOR+")\n";
	else
	if(damage>=40)
		return "($n"+HIR+"气息粗重，动作开始散乱，看来所受的伤着实不轻。"+NOR+")\n";
	else
	if(damage>=30)
		return "($n"+HIR+"已经伤痕累累，正在勉力支撑着不倒下去。"+NOR+")\n";
	else
	if(damage>=20)
		return "($n"+HIR+"看起来受伤过重，只怕会有生命危险。"+NOR+")\n";
	else
	if(damage>=10)
		return "($n"+RED+"伤重之下已经难以支撑，眼看就要倒在地上！"+NOR+")\n";
	else
    	return "($n"+RED+"受伤过重，已经有如风中残烛，随时都可能断气！"+NOR+")\n";
}
void report_sen(object ob,int sen)
{
	if(ob->query_temp("no_report"))
    	return;

	if(sen>=50){
		message_vision("\n($N"+CYN+"已经气喘嘘嘘，看起来状况并不太好。"NOR")\n",ob);
		return;
	}
	else if(sen>=40){
		message_vision("\n($N"+CYN+"看起来已经似乎十分疲惫，应该休息一下了。"+NOR+")\n",ob);
		return;
	}
	else if(sen>=30){
		message_vision("\n($N"+CYN+"已经累的头昏眼花，有点摇摇晃晃了！"+NOR+")\n",ob);
		return;
	}
	else if(sen>=20){
		message_vision("\n($N"+CYN+"已经没有什么力气了，马上就要昏倒了！"NOR")\n",ob);
		return;
	}
	else{
		message_vision("\n($N"+CYN+"已经手脚发软，就要倒在地上了！"+NOR+")\n",ob);
		return;
	}
}

int status(object ob,int wound)
{

	if(wound)
		return (int)ob->query("eff_kee",1)*100/(int)ob->query("max_kee",1);
	else
		return ob->query("kee")*100/ob->query("max_kee",1);

}
int sen_status(object ob)
{

	if(((int)ob->query("sen",1)*100)/(int)ob->query("max_sen",1)>100)
		return 100;
	return ((int)ob->query("sen",1)*100)/(int)ob->query("max_sen",1);
}

void announce(object ob, string event)
{
	switch(event) {
		case "dead":
			message_vision("\n$N「啪」的一声倒在地上，挣扎着抽动了几下就死了。\n\n", ob);
			break;
		case "unconcious":
			message_vision("\n$N神志迷糊，脚下一个不稳，倒在地上昏了过去。\n\n", ob);
			break;
		case "revive":
		        if(ob->query("blind") || ob->query("race") != "人类")
			     message_vision("\n$N身子一颤，扭动了几下，清醒了过来。\n\n", ob);
			else if(ob->query("mute"))
			     message_vision("\n$N慢慢清醒了过来，睁开眼睛站起来摇了摇头。\n\n", ob);
			else message_vision("\n$N身子动了动，口中呻吟了几声，清醒过来。\n\n", ob);
			break;
	}
}

string eff_status_msg(int ratio)
{
   if( ratio==100 ) return HIG "看起来气血充盈，并没有受伤。" NOR;
   if( ratio > 95 ) return HIG "似乎受了点轻伤，不过光从外表看不大出来。" NOR;
   if( ratio > 90 ) return HIY "看起来可能受了点轻伤。" NOR;
   if( ratio > 80 ) return HIY "受了几处伤，不过似乎并不碍事。" NOR;
   if( ratio > 60 ) return HIY "受伤不轻，看起来状况并不太好。" NOR;
   if( ratio > 40 ) return HIR "气息粗重，动作开始散乱，看来所受的伤着实不轻。" NOR;
   if( ratio > 30 ) return HIR "已经伤痕累累，正在勉力支撑着不倒下去。" NOR;
   if( ratio > 20 ) return HIR "受了相当重的伤，只怕会有生命危险。" NOR;
   if( ratio > 10 ) return RED "伤重之下已经难以支撑，眼看就要倒在地上。" NOR;
   if( ratio > 5  ) return RED "受伤过重，已经奄奄一息，命在旦夕了。" NOR;
   return RED "受伤过重，已经有如风中残烛，随时都可能断气。" NOR;
}

varargs int skill_power(object ob, string skill, int usage)
{
	return 1;
}

int get_exp_inflict(object attack,object defense)
{
	return (attack->query("combat_exp")-defense->query("combat_exp"))*5/30000;
}

//计算攻击者将会造成的伤害：
int get_damage(object me,object victim,object weapon,mapping action,mapping apply_action,string skill_name)
{
	int damage,skill_level,base_skill_level;
	int damage_factor;
	string base_skill;
	int w_damage,w_min_damage,w_max_damage;
	int w_strong;
	int str_factor;

	damage=0;
	skill_level=0;
	base_skill_level=0;

   //有兵器或没有兵器时的附加伤害：

	if(weapon&&weapon->query("max_strong")){
		w_strong=weapon->query("strong");
		if(w_strong<0) w_strong=0;
		w_min_damage=me->query_temp("apply/min_damage")+me->query_temp("apply/enhance_min_damage")+
                me->query_temp("apply/double_damage");
		w_max_damage=me->query_temp("apply/damage")+me->query_temp("apply/enhance_max_damage")+
                me->query_temp("apply/double_damage");
		if(w_min_damage>w_max_damage)
			w_min_damage=w_max_damage;

		if(weapon->query("save_flag")&&userp(me))
			damage=w_min_damage+random(w_max_damage-w_min_damage);
		else
			damage=w_max_damage;

		damage=damage-damage*(weapon->query("max_strong")-w_strong)/weapon->query("max_strong");

		if(userp(me)&&weapon->query("save_flag")&&
				weapon->query("user")!=me->query("id"))
			damage=damage/5;
		else
			damage +=weapon->query("user_skill")/10;
	}
	else
		damage=me->query_temp("apply/damage");
   //the end {有兵器或没有兵器时的附加伤害}

   //加力(jiali)造成的伤害，空手时效果比有兵器时效果好，
   //因为兵器有附加伤害。
	if(me->query("jiali",1)&&me->query("force",1)>me->query("jiali",1)){
		me->add("force",-(int)me->query("jiali",1));
		if(!weapon)
			damage +=(int)me->query("jiali",1)*5/3;
		else
			damage +=me->query("jiali")/2;
	}
   //the end {加力(jiali)造成的伤害}

  // the end {招数造成的伤害}
	if(stringp(skill_name)
			&&intp(SKILL_D(skill_name)->skill_damage(me,victim)))
		damage +=SKILL_D(skill_name)->skill_damage(me,victim);


   //将技能的等级加入到 伤害中。
   // 这样计算，虽然使伤害的数值加大，但相对的
   //防守一方的 parry 技能也是如此计算，所以不会相差很大。
   // 技能伤害=特殊技能+基本技能/2
	if(stringp(skill_name)){
		if(weapon)
			skill_level=(int)me->query_skill(skill_name,1);
		else
			skill_level=(int)me->query_skill(skill_name,1)*3/2;

		if(stringp(base_skill=SKILL_D(skill_name)->query_base())){
			if(base_skill!="base"){
				base_skill_level=(int)me->query_skill(base_skill,1);
				damage +=(skill_level+base_skill_level/2);
			}
		}
    	else
    		damage +=(skill_level);
	}

   str_factor = me->query_str();
   damage = damage+(damage/4)*str_factor/20;

   return damage+damage*damage_factor/40;
}

//计算攻击者的攻击力，也就是敏捷度，用来和防守者的
//躲闪相比较，看是否能击中对方。
int get_attack(object me,object victim,mapping action,mapping apply_action)
{
	int me_attack;
	int dex_factor;
	string *me_dodges,me_dodge;

   //看是否有附加敏捷。如靴子或特殊武功作用。
	if(me->query_temp("apply/dodge"))
		me_attack=me->query_temp("apply/dodge");
	else
		me_attack=0;

   //将轻功等级加入到敏捷中：
   //有效等级：特殊+基本/2。如果学了两个或两个以上轻功，
   //则随机选一个。
	me_dodges=me->query("dodge");
	if(sizeof(me_dodges)>0){
		me_dodge=me_dodges[random(sizeof(me_dodges))];
		me_attack=me_attack+(int)me->query_skill(me_dodge,1);
		me_attack = me_attack+SKILL_D(me_dodge)->query_dodge(me);
	}
	me_attack=me_attack+(int)me->query_skill("dodge",1)/2;

	if(me_attack>=0){
		//如果以上敏捷>0，则按照身法来增加。
		dex_factor=me->query_dex();
		me_attack=me_attack+(me_attack/4)*dex_factor/15;
	}
	else
		me_attack=random(me->query_dex());

	if(me->is_busy())
		me_attack = me_attack-me_attack/3;

	if(me_attack<0)
		me_attack=0;
	return me_attack;
}

int get_parry(object victim)
{
	int victim_parry,defence_factor,armor;

	victim_parry=0;

	//防御中附加部分。如盔甲或特殊内功。
	armor=victim->query_temp("apply/armor")+victim->query_temp("apply/parry");
//	if(armor>1000) armor=1000;

	victim_parry=victim_parry+armor;

	//防御按照根骨来增加。
	defence_factor=victim->query_con();


	//防御加上基本招架的等级。
	victim_parry +=victim->query_skill("parry",1)*3/2;
	if(!victim->query_temp("weapon"))
		victim_parry=victim_parry+victim_parry/3;
	else
		victim_parry=victim_parry+victim_parry/5;

	//如果处于忙的状态，防御减少！
	victim_parry=victim_parry+(victim_parry/4)*defence_factor/10;

	if(victim->is_busy()) victim_parry=victim_parry-victim_parry/3;

	if(victim_parry>0)
		return victim_parry;
	else
		return 1;
}

varargs int do_perform_attack(int damage,int reduce_dex,string msg,
						object me,object target,object weapon,mapping apply_action,int quick,
            			string damage_type)
{
	int flag;

	me->add_temp("apply/damage",damage);
	me->add_temp("apply/dodge",reduce_dex);
	if(msg!="")
    	me->set_temp("action_msg",msg);
    flag = COMBAT_D->do_attack(me,target,weapon,apply_action,2,damage_type);
    me->add_temp("apply/damage",-damage);
    me->add_temp("apply/dodge",-reduce_dex);
    me->delete_temp("action_msg");

    return flag;

}

varargs int do_attack(object me,object victim,object weapon,mapping apply_action,int quick,
            string damage_type)
{
	mapping action,dodge_action;
	string skill_name;
	int em,wound;
	int ap,me_status,me_sen;
	int pp,vp,victim_sen,victim_status;
	string report_damage,get_damage_type;
	string *limb,l,combat_msg;
	string *dodges,victim_dodge;
	int damage;int exp_inflict;
	int hit_victim,parry_flag;
	int reward_p=90;

	int skill_damage;
	int me_exp,victim_exp;

	if(!me||!victim)
		return 0;

	me_exp = me->query("combat_exp");
	victim_exp = victim->query("combat_exp");
	wound=0;
	hit_victim=0;//此变量用于判断是否击中敌人，作为返回数值。
	parry_flag=0;//此变量用于判断是否招架。
	combat_msg="";
	victim_sen=-1;
	victim_status=-1;
	limb=victim->query("limbs");
	l=limb[random(sizeof(limb))];

	if(me->query_temp("apply_pause_fight")>0){
		message_vision(CYN"\n$N"+CYN+"施展完绝技，觉得气息紊乱，连忙守住门户！\n"NOR, me);
		return 0;
	}

	if (userp(victim) && living(victim)&&victim->query("age")>12
	&& 3*me_exp >= 2*victim_exp){
    	victim->receive_damage("sen", 2+random(2));
		if (victim->query("sen") * 100 / victim->query("eff_sen") < 20)
			tell_object(victim, HIR "\n你的体力快消耗完了！\n" NOR);
    }

	if(me->query("force_quest/csj_ok")){
    	if(me->query("force_quest/csj1")&&victim->query("apply_points")>0&&
              !present("huolong neidan",victim)){
        	skill_damage=me->query_skill("changsheng-jue",1)/8;

            if(present("bingpo shenzhu",victim))
            	skill_damage/=2;
            if(victim->query_skill("huanri-dafa",1)>=me->query_skill("changsheng-jue",1))
            	skill_damage/=2;

			if(skill_damage>0){
            	victim->add("apply_points",-skill_damage);
            	if(victim->query("apply_points")<0)
            	victim->set("apply_points",0);
			}
		}
		if(me->query("force_quest/csj2")&&victim->query("force")>0
             &&!present("bingpo shenzhu",victim)){
            skill_damage=me->query_skill("changsheng-jue",1)/8;

            if(present("huolong neidan",victim))
            	skill_damage/=2;
            if(victim->query_skill("huanri-dafa",1)>=me->query_skill("changsheng-jue",1))
            	skill_damage/=2;

			if(skill_damage>0){
				victim->add("force",-skill_damage);
            	if(victim->query("force")<0)
            	victim->set("force",0);
			}
		}
	}
	//choose actions.

	if(!me->query("actionp")){//if you have perform or exert action.
		skill_name=me->reset_action(weapon);//new reset_action() at /feature/attack.c by yanyan.
		action=me->query("actions");
	}
	else{
		action=me->query("actionp");
		skill_name=action["skill_name"];
	}
	if(me->query_temp("action_msg"))
		combat_msg=me->query_temp("action_msg");//如果有action_msg变量，则战斗描述为此变量。
	else
		combat_msg=action["action"];
	if(weapon)
		combat_msg = replace_string(combat_msg, "$w", weapon->query("name"));

	combat_msg = replace_string(combat_msg, "$l", l);

	combat_msg ="\n"+combat_msg+"\n";
	//me_attack now.
	ap=get_attack(me,victim,action,apply_action);
	//vdodge now.
	vp=get_attack(victim,me,0,0);
	dodges=victim->query("dodge");
	if(sizeof(dodges)>0)
		victim_dodge=dodges[random(sizeof(dodges))];

	//if(me_attack>vdodge)   //hit victim or not!
	if(!living(victim)||random(ap+vp)>vp*2/3||vp*3<ap){
		//only attack-dodge>10 you can must hit the victim!
		// damage now.or since your attack is high,the victim maybe dodge.
		damage=get_damage(me,victim,weapon,action,apply_action,skill_name);
		//parry now.
		pp=get_parry(victim);

		exp_inflict=get_exp_inflict(me,victim);
		damage = damage+(exp_inflict);

		if(damage<0)
			damage = 0;
		//if victim can parry:
		if((damage>pp&&(damage-pp)>(random(20)))
      			||!living(victim)||random(damage+pp)>pp||damage>2*pp){

			hit_victim=1;//击中敌人。

			if(damage<pp){
				if(!damage_type)
					victim->receive_damage("kee",damage/4,me);
				else
					victim->receive_damage(damage_type,damage/4,me);
			}
			else{
				if(!damage_type)
					victim->receive_damage("kee",(damage-pp*2/3),me);
				else
					victim->receive_damage(damage_type,(damage-pp*2/3),me);
			}
			//击中对方，奖励经验。
			if(victim->query("reward_p"))
				reward_p=victim->query("reward_p");
			if(me_exp>=victim_exp){
				if(me_exp-victim_exp>100000){
					if(random(100)>reward_p+20){ //如果和比自己低 100K的人 fight ,得到的少。
						me->add("combat_exp",victim->query("reward_exp")/3+random(1));
						if(stringp(victim->query("reward_skill")))
							me->improve_skill(victim->query("reward_skill"),victim->query("reward_exp")/3+random(1));
						//me->add("potential",victim->query("reward_pot")+random(3));
					}
				}
				else{
					if(random(100)>reward_p){//如果比对方高不多，则得到的几率大些
						me->add("combat_exp",victim->query("reward_exp")/2+random(1));
						if(stringp(victim->query("reward_skill")))
							me->improve_skill(victim->query("reward_skill"),victim->query("reward_exp")/2+random(1));
					//me->add("potential",victim->query("reward_pot")+random(3));
					}
				}
			}
			else{
				if(victim_exp-me_exp>100000){
					if(random(100)>reward_p+20){
						me->add("combat_exp",victim->query("reward_exp")+random(3));
						if(stringp(victim->query("reward_skill")))
							me->improve_skill(victim->query("reward_skill"),victim->query("reward_exp")+random(1));
						//me->add("potential",victim->query("reward_pot")+random(8));
					}
				}
                else{
					if(random(100)>reward_p){
						me->add("combat_exp",victim->query("reward_exp")+random(3));
						if(stringp(victim->query("reward_skill")))
							me->improve_skill(victim->query("reward_skill"),victim->query("reward_exp")/3+random(1));
						//me->add("potential",victim->query("reward_pot")+random(10));
					}
				}
			}

			//被击中，得到潜能
			if(random(100)>reward_p){
				victim->add("potential",me->query("reward_pot")+random(2));
				if(victim->query("potential")>victim->query("max_pot")*5)
					victim->set("potential",victim->query("max_pot")*5);
			}

			//伤害上限的条件：
			//1) 伤害+招架 的随机数>招架+护甲的随机数
			//2) 伤害的随机数>护甲
			//3) 符合命中条件。
			if(random(damage+pp)>pp+random(victim->query_temp("apply/armor"))
						&&random(damage)>victim->query_temp("apply/armor")
						&&random(ap+vp)>vp){

				damage = damage-pp;

				//如果 ap 比 vp 小很多，则属于碰运气击中对方，
				//所以此时对方受上限伤害应该降低，为原来的 1/3
				if((ap-vp)<random(100))
					damage=damage/3;
				if(damage<0){
					if(!damage_type)
						victim->receive_wound("kee",10,me);
					else
						victim->receive_wound(damage_type,10,me);
				}
				else{
					if(!damage_type)
						victim->receive_wound("kee",damage,me);
					else
						victim->receive_wound(damage_type,damage,me);
				}

				wound=1;//report status.
			}

			if(apply_action)
				get_damage_type=apply_action["damage_type"];
			else
				get_damage_type=action["damage_type"];
			if(victim->query_temp("back_damage")||victim->query_temp("back_wound")){
				combat_msg+="$n真气护体，$N反受自己的攻击所害！\n\n";
				message_vision(combat_msg,me,victim);
				combat_msg=damage_msg(damage,get_damage_type);
				combat_msg=replace_string(combat_msg, "$l", l);
				victim_status=status(me,wound);
				combat_msg +=report_status(me,victim_status);
				message_vision(combat_msg,victim,me);
			}
			else{
				combat_msg+=damage_msg(damage,get_damage_type);
				combat_msg=replace_string(combat_msg, "$l", l);
				victim_status=status(victim,wound);
				combat_msg +=report_status(victim,victim_status);
				message_vision(combat_msg,me,victim);
			}
			if(random(50)>25)
				victim->add("potential",random(3));

			if(random(me->query("max_pot"))>100&&random(50)>25)
				me->improve_skill(skill_name,random(10));

			if(weapon){
				//1)只有 me 和 victim 经验相差不多时才会使兵器增加伤害。
				//2)me 的杀意比 victim 的杀意大很多。
				if(random(10)>7
						&&me_exp-victim_exp<300000
						&&me_exp-victim_exp>-300000
						&&random(me->query("apply_points"))>random(victim->query("apply_points")))
					weapon->improve(1+random(1));
				if(weapon->query("poison"))
					if(!victim->query_condition("quest_poison"))
						victim->apply_condition("quest_poison",weapon->query("poison"));
			}
			if(!apply_action)
				if(functionp(action["post_action"]))
					evaluate(action["post_action"],me,victim,weapon,damage);

			if(me&&victim)// hit_ob
				SKILL_D(skill_name)->hit_ob(me,victim);

			if(me&&victim&&weapon)//weapon hit_ob.
				weapon->hit_ob(me,victim);
			if(me&&victim)
				me->hit_ob(me,victim);

		}//the end of{ if victim can parry}.
		else{
			//victim 受到少量的伤害，并进行招架：
			if(!damage_type)
				victim->receive_damage("kee",random(5),me);
			else
				victim->receive_damage(damage_type,random(5),me);
			message_vision(combat_msg,me,victim);
			do_parry(me,victim,weapon);
	   		parry_flag=1;
	  	}
	}//the end of {if victim can dodge}.
	else{
		if(victim_dodge){
			//如果有特殊轻功，而且 vp 比 ap 大很多，则出现轻功描述
			//否则，则招架。
			if(random(ap)<random(vp)&&living(victim)){
				dodge_action=SKILL_D(victim_dodge)->query_action(victim);
				combat_msg +=dodge_action["action"]+"\n";
				message_vision(combat_msg,me,victim);
				if(functionp(dodge_action["skill_dodge"]))
				evaluate(dodge_action["skill_dodge"],me,victim);
			}
			else{
				//如果是动物，只出现描述。
				if((string)victim->query("race")!="人类"&&living(victim)){
					combat_msg +=beat_parry[random(sizeof(beat_parry))];
					message_vision(combat_msg,me,victim);
				}
				else{
					message_vision(combat_msg,me,victim);
					do_parry(me,victim,weapon);
					parry_flag=1;
				}
			}
		}
		else//如果 vp 比 ap 大很多，则使用普通轻功的描述，否则招架。
		if(random(ap)<random(vp)&&living(victim)){
			dodge_action=SKILL_D("dodge")->query_action(victim);
			combat_msg +=dodge_action["action"]+"\n";
			message_vision(combat_msg,me,victim);
		}
		else{
			if((string)victim->query("race")!="人类"&&living(victim)){
				combat_msg +=beat_parry[random(sizeof(beat_parry))];
				message_vision(combat_msg,me,victim);
			}
			else{
				message_vision(combat_msg,me,victim);
				do_parry(me,victim,weapon);
				parry_flag=1;
			}

		}
	}//the end of{victim can dodge or parry}
	victim_sen=sen_status(victim);

	if(!victim->query("env/wimpy")){
		if(((victim_sen>=0&&victim_sen<=50)
				||(victim_status>=0&&victim_status<=50))
				&&!me->is_killing(victim->query("id"))
				&&!victim->is_killing(me->query("id"))){
			end_fight(me,victim);
			return hit_victim;
		}
	}
	else{
		if(((victim_sen>=0&&victim_sen<=victim->query("env/wimpy"))
				||(victim_status>=0&&victim_status<=victim->query("env/wimpy")))
				&&!me->is_killing(victim->query("id"))
				&&!victim->is_killing(me->query("id"))){
			end_fight(me,victim);
			return hit_victim;
		}
	}

	if((victim->query_temp("guarding"))
			&&parry_flag&&!victim->is_busy()
			&&!victim->query_temp("apply_pause_fight")){
		victim->delete_temp("guarding");
		if( random(me->query("dex")) < 5 ) {
			message_vision("$N一击不中，大惊失色，不觉露出了破绽！\n", me);
			do_attack(victim, me, victim->query_temp("weapon"),0, TYPE_QUICK);
		}
		else{
			message_vision("$N一见$n攻击失误，顿时趁机发动攻击！\n", victim, me);
			do_attack(victim, me, victim->query_temp("weapon"),0, TYPE_QUICK);
		}
	}

    return hit_victim;//返回值：是否击中敌人。
}

void do_parry(object me,object victim,object weapon)
{
	object vweapon;
	vweapon=victim->query_temp("weapon");
	"/adm/daemons/parryd.c"->do_parry(me,victim,weapon,vweapon);
}

void fight(object me, object victim)
{
	object weapon = me->query_temp("weapon");

	me->set_temp("last_damage_from",victim);
	victim->set_temp("last_damage_from",me);

	if( !living(me) || me->query("env/yield")||
		me->query_temp("no_eff_combat")) return;

	if (!me->is_killing(victim->query("id"))
			&& member_array(me, victim->query_enemy()) > 4)
	return;

	if(userp(me)
			&&userp(victim)
			&&(me->query("apply_points")-victim->query("apply_points"))/100>0
			&&random(10)>5){
		victim->start_busy((me->query("apply_points")-victim->query("apply_points"))/100);
		message_vision(CYN"\n$n"+CYN+"受$N"+CYN+"气势所迫，身形变得迟缓了！\n"NOR,me,victim);
	}

// If victim is busy or unconcious, me start to attack!
	if( victim->is_busy() || !living(victim)||victim->query_temp("apply_pause_fight") ) {
		me->delete_temp("guarding", 0);
		if( !victim->is_fighting(me) )
			victim->fight_ob(me);

	    if(objectp(weapon=me->query_temp("weapon")))
	    	do_attack(me,victim,weapon,0,TYPE_QUICK);
		else
			do_attack(me,victim,0,0,TYPE_QUICK);

        // Else, see if we are brave enough to make an aggressive action.
	}
	else
	if( me->query_temp("guarding")||me->query_temp("combat")
			|| random( (int)victim->query_dex()*2) < (int)me->query_dex()) {
		me->delete_temp("guarding");
		if( !victim->is_fighting(me) )
			victim->fight_ob(me);

		if(objectp(weapon=me->query_temp("weapon")))
			do_attack(me,victim,weapon,0,TYPE_QUICK);
		else
			do_attack(me,victim,0,0,TYPE_QUICK);
		// Else, we just start guarding.
	}
	else{
		me->set_temp("guarding", 1);
		if(me->query("race")=="人类")
			message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
		else
			message_vision( beat_guard[random(sizeof(beat_guard))], me, victim);

	}

}
void auto_fight(object me, object obj, string type)
{
	// Don't let NPC autofight NPC.
	if( !userp(me) && !userp(obj) ) return;

	// Because most of the cases that we cannot start a fight cannot be checked
	// before we really call the kill_ob(), so we just make sure we have no
	// aggressive callout wating here.
	if( me->query_temp("looking_for_trouble") ) return;
	me->set_temp("looking_for_trouble", 1);

	// This call_out gives victim a chance to slip trough the fierce guys.
	call_out( "start_" + type, 1, me, obj);
}

void start_berserk(object me, object obj)
{
	int shen;

	if( !me || !obj ) return;                               // Are we still exist( not becoming a corpse )?

	me->delete_temp("looking_for_trouble");

	if(     me->is_fighting(obj)                            // Are we busy fighting?
	||      !living(me)                                     // Are we capable for a fight?
	||      environment(me)!=environment(obj)       // Are we still in the same room?
	||      environment(me)->query("no_fight")      // Are we in a peace room?
	) return;

	shen = -me->query("shen");
	message_vision("$N用一种异样的眼神扫视着在场的每一个人。\n", me);

	if( wizardp(me) || !userp(me) || (int)me->query("neili") > (random(shen) + shen)/20 ) return;

	if( shen/2 > random((int)me->query("combat_exp"))
	&&      !wizardp(obj) ) {
		message_vision("$N对着$n喝道：" + RANK_D->query_self_rude(me)
			+ "看你实在很不顺眼，去死吧！\n", me, obj);
		me->kill_ob(obj);
	} else {
		message_vision("$N对着$n喝道：喂！" + RANK_D->query_rude(obj)
			+ "，" + RANK_D->query_self_rude(me) + "正想找人打架，陪我玩两手吧！\n",
			me, obj);
		me->fight_ob(obj);
	}
}

void start_hatred(object me, object obj)
{
	if( !me || !obj ) return;                               // Are we still exist( not becoming a corpse )?

	me->delete_temp("looking_for_trouble");

	if( (me->is_killing(obj->query("id")) && me->is_fighting(obj))	// Are we busy fighting?
	||      !living(me)                                                     // Are we capable for a fight?
	||      environment(me)->query("no_fight")      // Are we in a peace room?
	) return;

	// We found our hatred! Charge!
	if (environment(me)==environment(obj)) {
		switch(me->query("race")) {
			case "家畜":
			case "野兽":
				message_vision( catch_hunt_beast_msg[random(sizeof(catch_hunt_beast_msg))], me, obj);
				break;
			case "飞禽":
				message_vision( catch_hunt_bird_msg[random(sizeof(catch_hunt_bird_msg))], me, obj);
				break;
			default:
				message_vision( catch_hunt_human_msg[random(sizeof(catch_hunt_human_msg))], me, obj);
		}
		me->kill_ob(obj);
	} else if (me->query("race")=="人类" && random(4) == 2) {
		tell_object(me, HIW "你冲着远处"+obj->name()+"的背影叫到：下次别让我看到你！\n" NOR);
		tell_room(environment(me), HIW+me->name()+"冲着远处"+obj->name()+"的背影叫到：下次别让我看到你！\n" NOR, ({me}));
		tell_object(obj, HIW+me->name()+"在远处对你叫到：下次别让我看到你！\n" NOR);
		tell_room(environment(obj), HIW+me->name()+"在远处对"+obj->name()+"叫到：下次别让我看到你！\n" NOR, ({obj}));
	}
}

void start_vendetta(object me, object obj)
{
	if( !me || !obj ) return;                               // Are we still exist( not becoming a corpse )?

	me->delete_temp("looking_for_trouble");

	if( (me->is_killing(obj->query("id")) && me->is_fighting(obj))	// Are we busy fighting?
	||      !living(me)                                                     // Are we capable for a fight?
	||      environment(me)!=environment(obj)       // Are we still in the same room?
	||      environment(me)->query("no_fight")      // Are we in a peace room?
	) return;

	// We found our vendetta opponent! Charge!
	message_vision(HIW "$N对$n喝道："+RANK_D->query_rude(obj)+"，竟敢对本门弟子下毒手，受死吧！\n" NOR, me, obj);
	me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
	if( !me || !obj ) return;                               // Are we still exist( not becoming a corpse )?

	me->delete_temp("looking_for_trouble");

	if( (me->is_killing(obj->query("id")) && me->is_fighting(obj))	// Are we busy fighting?
	||      !living(me)                                                     // Are we capable for a fight?
	||      environment(me)!=environment(obj)       // Are we still in the same room?
	||      environment(me)->query("no_fight")      // Are we in a peace room?
	) return;

	// We got a nice victim! Kill him/her/it!!!
	me->kill_ob(obj);
}

void pause_fight(object killer,object victim,string type)
{
    message_vision(HIY"\n$N"+HIY+"一时手软，放弃了对$n"+HIY+"的攻击！\n"NOR,killer,victim);
    victim->set("eff_" + type,0);
    victim->set(type,-10);
    killer->remove_killer(victim);
    victim->remove_killer(killer);
}


void end_fight(object killer,object victim)  //Fight over!
{
	string shili;

	if((string)killer->query("race")=="人类"||!killer->query("race"))
		message_vision(winner_msg[random(sizeof(winner_msg))],killer);
	else
	if((string)killer->query("race")!="人类")
		message_vision(winner_animal_msg[random(sizeof(winner_animal_msg))],killer,victim);
	killer->delete_temp("last_damage_from");
	victim->delete_temp("last_damage_from");

	if(victim->is_end_fight(killer)||
			killer->is_end_fight(victim))
		killer->remove_enemy(victim);
	else
		killer->remove_all_enemy();

	if(!killer||!victim) return;

	if(victim->is_end_fight(killer)||
			killer->is_end_fight(victim))
		victim->remove_enemy(killer);
	else
		victim->remove_all_enemy();

	if(!killer||!victim) return;

	if(killer->query_temp("gage")==victim&&
			victim->query_temp("gage")==killer&&
			victim->query("shili/leader")){
		killer->set("shili/leader",victim->query("shili/leader"));
		victim->delete("shili/leader");
		shili=killer->query("shili/leader");
		if(shili=="lifa_b")
			CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s夺得李阀阀主之位！", killer->name()));
		else
		if(shili=="songjia_b")
			CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s夺得宋家堡堡主之位！", killer->name()));
		else
		if(shili=="duzun_b")
			CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s夺得独尊堡堡主之位！", killer->name()));
		else
		if(shili=="dajiang_b")
			CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s夺得大江联盟主之位！", killer->name()));
		else
		if(shili=="haisha_b")
			CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s夺得海杀帮帮主之位！", killer->name()));
		else
		if(shili=="feima_b")
			CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s夺得飞马场主之位！", killer->name()));
        if(!userp(victim))
			ORG_D->del_leader(victim->query("shili_id"));
        ORG_D->set_leader_log(killer,victim);
        killer->delete_temp("gage");
        victim->delete_temp("gage");
		victim->save();
	}
	if(environment(killer)->query("end_fight"))
		environment(killer)->end_fight(killer,victim);
	killer->end_fight(killer,victim);
	victim->surrender(killer,victim);

	return;

}

void killer_reward(object killer, object victim)
{

	if(userp(killer)){//如果杀人者是玩家
		if(!environment(killer)->query("no_death")&&
				killer->is_killing(victim->query("id"))){
			if(userp(victim))
				killer->add("PKS",1);
			else
				killer->add("MKS",1);
		}
		if(victim->query("guard")){//如果杀了官兵
			killer->set("killer",victim->query("guard"));
			killer->set("killer_time",time());
		}
		if(killer->query("vocation")=="杀手"){
			if(userp(victim)){
				killer->add("bellicosity",10);
				killer->add("vocation_score",(victim->query("famous")+100)/1000);
			}
			else
				killer->add("bellicosity",2);
		}
		else{
			if(userp(victim))
				killer->add("bellicosity",5);
			else
				killer->add("bellicosity",1);
		}
		//判断是否将变成通缉犯：
		if(userp(killer)
	           &&userp(victim)
	           &&killer->is_killing(victim->query("id"))
	           &&!environment(killer)->query("no_death")
	           &&!environment(killer)->is_city_war_room()
	           &&victim->query("age")>12
	           &&!victim->query("pker")){
	         //通缉犯设定：
	         //killer->set("pk_target_id",victim->query("id"));
                 //killer->set("pk_target_id_time",time());
                 //killer->add("TIME_PKS",1);
                 //killer->set("TIME_PKS_TIME",time());
		 	killer->add("pker",1);
		 	killer->set("pker_time",time());
		 	//if(!killer->query_condition("pker_msg"))
		 	//	killer->apply_condition("pker_msg",1);
            ORG_D->org_lose(victim);//帮会的储备受到损失。
            //如果是宋家堡弟子：
			if(killer->query("family/family_name")=="宋家堡"){
				if(victim->query("family/family_name")=="宋家堡"){
					killer->add("kill_same_party_flags/times",1);
					killer->add("kill_same_party_flags/killers",10);
					if(!killer->query_condition("kill_same_party"))
						killer->apply_condition("kill_same_party",10);
				}
				if(victim->query("family/family_name")=="净念禅院"||
                       victim->query("family/family_name")=="东溟派"||
                       victim->query("family/family_name")=="慈航静斋"||
                       victim->query("family/family_name")=="弈剑派")
					victim->add("kill_good_party_flags",1);

			}
		}
	}//the end of {if the killer is player}

    //如果被杀者是玩家：
	if(userp(victim)){
		if(killer->query("race")=="人类"){
			if(!killer->is_killing(victim->query("id"))
					&&!victim->is_killing(killer->query("id")))
				CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s被%s失手杀死了。", victim->name(), killer->name()));
			else
			if(!killer->is_killing(victim->query("id"))
					&&victim->is_killing(killer->query("id")))
				CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s被%s正当防卫杀死了。", victim->name(), killer->name()));
			else
			if((int)victim->query("beipan",1)>=3)
				CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("叛徒%s被%s杀死了。", victim->name(), killer->name()));
			else
			if(victim->query("vocation")=="杀手")
				CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("职业杀手%s被%s杀死了。", victim->name(), killer->name()));
			else
				CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s被%s杀死了。", victim->name(), killer->name()));
		}//the end of {if the killer is human}
		else{
			if(killer->query("race")=="飞禽")
				CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s被%s啄死了。", victim->name(), killer->name()));
			else
				CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s被%s杀害了。", victim->name(), killer->name()));
		}

		//通缉犯被杀后：
		if(userp(victim)&&victim->query("pker")
				&&!environment(victim)->query("no_death")){
			CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("通缉犯%s被%s就地正法了。", victim->name(), killer->name()));
	    	if(userp(killer)||killer->is_defence_guard()){
				if(killer->is_defence_guard()){
					victim->set("pker_lose",victim->query("pker")-1);
					victim->set("zuolao",victim->query("pker"));
					victim->set("zuolao_time",time());
				}
				else{
					victim->set("pker_lose",victim->query("pker"));
					killer->set_temp("rank/class","替天行道");
				}
				victim->delete("pker");
			}

		}

		//如果是有效死亡地点，则降低杀气：
		if(!environment(victim)->query("no_death")){
			victim->set("bellicosity",0);
			//victim->add("office_number",-victim->query("office_number")/100);
			victim->save();//保存档案
		}


	}//the end of {if the victim is player}

	victim->delete_temp("last_damage_from");
	killer->delete_temp("last_damage_from");
	killer->remove_killer(victim);
	victim->remove_all_killer(killer);

	if(environment(killer)->query("killer_reward"))
		environment(killer)->killer_reward(killer,victim);
  	killer->kill_object(killer,victim);
	if(killer&&userp(killer))
		killer->save();
	if(victim&&userp(victim))
		victim->save();//保存档案
   //the end of function { killer_reward}
}
