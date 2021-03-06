//散手八扑
//八扑。

#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -50

int perform(object me,object target)
{ 
   object weapon;
   string msg;
   int damage,flag=0;
   int str,inte;
   int add;
   
    weapon=me->query_temp("weapon");
   
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
   if(!me->is_fighting())
   return notify_fail("「八扑」只能在战斗中使用!\n");
   if(weapon)
    return notify_fail("拿着武器，如何使用「八扑」？\n");
    if(!me->query_skill("sanshou-strike",1))
    return notify_fail("不学「散手八扑」如何使用「八扑」？\n");
    if((int)me->query("max_force")<1500)
    return notify_fail("你的内力修为太低了!\n");
    if((int)me->query_skill("strike",1)<120)
    return notify_fail("你的基本掌法太差了！\n");
    if((int)me->query_skill("sanshou-strike",1)<120)
    return notify_fail("你的「散手八扑」还不到家！\n");
    
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展「八扑」！\n");
    if(me->query("perform_quest/bapu")
      &&time()-me->query_temp("perform_busy")<10)
      return notify_fail("连续施展「八扑」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    if(!me->query("perform_quest/bapu")
      &&time()-me->query_temp("perform_busy")<5)
      return notify_fail("连续施展「八扑」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/bapu"))
    	damage=damage/2;
    else{
   		str = me->query("str");
		inte = me->query("int"); 
    	if(str>=38&&inte>=38){  			
  			add = str-38;
  			if(inte-38>add)
  				add = inte-38;
  			damage = damage+damage*(add/2)*20/100;
  			
  		}
  		else
  		if(str>=35&&inte>=35)
  			damage = damage*2/3;
  		else
  			damage = damage/2;
    
    
   	}
    me->set("apply_points",0);
    
    msg=HIY"$N"+HIY+"双手合什，双目异光大盛，目注$n"+HIY+"，就在$n"+HIY+"加速的同一刹那，$N"+HIY+"合拢的两手分开，\n"+
        "似预知来$n"+HIY+"动作的变化。$N"+HIY+"往前冲出，似扑非扑，若缓若快，只是其速度上的玄奥难\n"+
        "测，可教人看得头痛欲裂，偏又是潇洒好看。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「八扑」只能在战斗中使用!\n");
   
    msg=HIG"$N"+HIG+"倏地背对背的立在$n"+HIG+"后方丈许处。右手虚按胸前，左手往后拂出，手从袍袖探出，\n"+
        "掌变抓，抓变指，左手往后拂出，手从袍袖探出，掌变抓，抓变指，最后以拇指按正\n"+
        "绞击而来的$n"+HIG+"的攻击，其变化之精妙，纯凭感觉判断刀势位置，令人叹为观止！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「八扑」只能在战斗中使用!\n");
   
    msg=HIR"$N"+HIR+"头下脚上的来到$n"+HIR+"上方，钉子般下挫，撞入$n"+HIR+"攻势之内，竟是以头盖硬憧$n"+HIR+"头盖，\n"+
        "一派与敌偕亡的招数。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「八扑」只能在战斗中使用!\n");
    
    msg=WHT"$N"+WHT+"两手箕张，手如鸟啄，倏地振衣瞩行，两千化成似两头嘻玩的小鸟，在前方闹斗追\n"+
        "逐，你扑我啄，斗个不亦乐乎，往$n"+WHT+"迫去。脸上现出似孩童弄雀的天真神色，左顾右\n"+
        "盼的瞧着两手虚拟的小鸟儿腾上跃下，追逐空中嘻玩的奇异情况。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    
    if(!me->query("perform_quest/bapu")){
    	me->set_temp("perform_busy",time());
        return 1;
    }
    
    call_out("perform2",3,me,target,damage);
    me->set_temp("perform_busy",time());
    return 1;   
  
}  

int perform2(object me,object target,int damage)
{
    string msg;
    int flag=0;
    
    if(!me||!target)
    return 1;
    if(!me->is_fighting(target))
    return 1;
    
    if(me->query_temp("weapon"))
    return 1;
    
    if(me->is_busy())
    return 1;
    
    msg=HIG"$N"+HIG+"仍保持两手负后的姿态，双目异芒电闪，募地挺直身骨，全身袍袖无风自动，须眉\n"+
        "瞩张，形态变得威猛无涛，与$n"+HIG+"相比毫不逊色，一拳击出，连续作出玄奥精奇至超乎\n"+
        "任何形容的玄妙变化，却又是毫无伪借的一拳轰向$n"+HIG+"的$l！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「八扑」只能在战斗中使用!\n");
  
    msg=HIY"$N"+HIY+"以千变万化的动作，似进似退、欲上欲下，双手施出玄奥莫测的手法，以炉火纯青、\n"+
        "出神人化的先天气功，先一步隔远击中$n"+HIY+"，织出无形而有实的气网，如蚕吐丝，而这\n"+
        "真气的茧恰在与$n"+HIY+"正面有实的气网，如蚕吐丝，而这真气的茧恰在与$n"+HIY+"正面交锋的一\n"+
        "刻积聚至爆发的巅峰，抵着$n"+HIY+"必杀的一招。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「八扑」只能在战斗中使用!\n");
   
    msg=WHT"$n"+WHT+"攻至$N"+WHT+"面门华尺许的当儿，教人不敢相信的情况在毫无先兆下发生，$N像变成一片\n"+
        "羽毛般，不堪$n"+WHT+"带起的狂飑被刮得抛起飞退，以毫厘之差遗过攻击，真个神奇至教人\n"+
        "不敢相信，但确为事实。其退妙绝天下，颇有乘云御气飞龙的逍迟妙况。\n"NOR;
    
    flag = COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「八扑」只能在战斗中使用!\n");
    
    msg=HIC"$N"+HIC+"突发一声长啸，在空中忽然凝定，钉子般疾落锥下，钉往地面，面对$n"+HIC+"能使风云色\n"+
        "变的一招，$N"+HIC+"仍是神态闲雅，快速吟道：“人有畏影恶迹而去之走者，举足愈数而迹\n"+
        "愈多，走愈疾而影不离身。不知处阴以休影，处静以息迹，愚亦甚矣。”$N"+HIC+"整个人弹\n"+
        "上半空，给予$n"+HIC+"强力的一击！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(flag){
      message_vision("\n$n被$N击中，身形不由得一滞！\n\n",me,target);
      target->start_busy(3);
    }
    
    me->set_temp("perform_busy",time());
    return 1;
}
