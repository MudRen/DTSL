
#include <dbase.h>
#include <ansi.h>

#include "tiejiang.h"

string result_strong(int i);

string *msg=({
HIY"$N"+HIY+"渐渐流下了汗，炉子的火越来越旺了！\n"NOR,
HIY"$N"+HIY+"渐渐流下了汗，炉子的火越来越旺了！\n"NOR,
HIR"只见火势越来越旺，$N"+HIR+"有些受不了了。\n"NOR,
HIR"只见火势越来越旺，$N"+HIR+"有些受不了了。\n"NOR,
HIB"$N"+HIB+"不停的挥舞着铁锤，乒乒乓乓地敲打着兵器！\n"NOR,
HIB"$N"+HIB+"不停的挥舞着铁锤，乒乒乓乓地敲打着兵器！\n"NOR,
RED"$N"+RED+"有些气喘吁吁，脸被火光映得通红。\n"NOR,
RED"$N"+RED+"有些气喘吁吁，脸被火光映得通红。\n"NOR,
});

int main(object ob,string arg)
{
	object weapon,iron;
	string iron_name,weapon_name;	
	int strong,max_strong;
	string j="";
	
	if(userp(ob)&&ob->query("vocation")!="铁匠")
	return notify_fail("只有铁匠才能修理兵器。\n");
	
	if(userp(ob)&&ob->query_skill("duanzao-jishu",1)<60)
	return notify_fail("你的锻造技术太低了，无法修理兵器。\n");
	
	if(ob->is_fighting())
	 return notify_fail("你还在打仗呢！\n");
	
	if(ob->is_busy())
	 return notify_fail("你正忙着呢！\n");
	
	if(member_array(base_name(environment(ob)),tiejiang_here)==-1)
        return notify_fail("你还是到兵器店去修理兵器吧！\n");
	
	if(!arg)
		return notify_fail("请使用xiuli 兵器 with 矿石。\n");
	if(sscanf(arg,"%s with %s",weapon_name,iron_name)!=2)
	    return notify_fail("请使用xiuli 兵器 with 矿石。\n");
	
	if(!objectp(weapon=present(weapon_name,ob)))
		return notify_fail("你身上并没有这个兵器!\n");
    if(!objectp(iron=present(iron_name,ob)))
		return notify_fail("你身上并没有这种矿石!\n");
	if(!iron->query("weapon"))
		return notify_fail(iron->query("name")+"不是矿石。\n");
	if(!weapon->query("skill_type"))
		return notify_fail("你只能修武器！\n");
    
    strong=(int)weapon->query("strong",1);
	max_strong=(int)weapon->query("max_strong",1);
	 
	 if(!max_strong) max_strong=strong+100;	 

	 if(strong*100/max_strong==100)
	   return notify_fail(weapon->query("name")+"没有损坏，不用修补!\n");
	 j=result_strong(strong*100/max_strong);
	 tell_object(ob,"你的兵器已经"+j+"\n");
     
	 if(userp(ob)&&ob->query("gin")<800)
	 return notify_fail("你发现以你现在的精血无法修理兵器。\n");
        
	message_vision("$N把"+weapon->query("name")+"放到"+environment(ob)->query("short")+"的铁炉上。\n",ob);
	message_vision(RED"\n$N"+RED+"拉动风箱，火“呼”地一声窜了起来！\n"NOR,ob);
	
	if(userp(ob))
	 ob->receive_damage("gin",800);
	
	if(iron->query_amount()&&
	 iron->query_amount()>1)
	 iron->set_amount(iron->query_amount()-1);
	else
        destruct(iron);
        
	ob->start_busy(5);
	
	call_out("do_msg",5,ob,weapon,0);
	
	return 1;
	
	
}

void do_msg(object ob,object weapon,int times)
{
	
	if(!ob||!weapon||environment(weapon)!=ob)
		return;
	
	if(times>=sizeof(msg)){
		message_vision("$N擦了擦汗，终于修好了"+weapon->query("name")+"！\n",ob);
		if(weapon->query("strong",1)<=0)
		weapon->set("name",weapon->query("org_name"));
	        weapon->set("strong",weapon->query("max_strong"));
	        weapon->set("flag",0);
		return;
    }
    message_vision(msg[times]+"\n",ob);
    ob->start_busy(5);
    
    call_out("do_msg",5,ob,weapon,times+1);
    
}

string result_strong(int i)
{
	if(i>=100)
	   return HIG"完好无损"NOR;
	if(i>=90)
		return HIG"轻微损坏"NOR;
	else if(i>=80) return HIG"轻度损坏"NOR;
	else if(i>=70) return GRN"较重损坏"NOR;
	else if(i>=60) return GRN"损伤较大"NOR;
	else if(i>=50) return CYN"半好半坏"NOR;
	else if(i>=40) return CYN"严重损坏"NOR;
	else if(i>=30) return BLU"几乎折断"NOR;
	else if(i>=20) return BLU"残破不堪"NOR;
	else if(i>=10) return RED"破烂不堪"NOR;
	else return RED"破烂之极"NOR;
}
  
