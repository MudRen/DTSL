
#include <dbase.h>
#include <ansi.h>

string result_strong(int i);
int get_value(object weapon);

string *msg=({
HIY"$N"+HIY+"渐渐流下了汗，炉子的火越来越旺了！\n"NOR,
HIR"只见火势越来越旺，$N"+HIR+"有些受不了了。\n"NOR,
HIB"$N"+HIB+"不停的挥舞着铁锤，乒乒乓乓地敲打着兵器！\n"NOR,
RED"$N"+RED+"有些气喘吁吁，脸被火光映得通红。\n"NOR,
});

int do_repair(string arg)
{
	object ob,weapon;
	int strong,max_strong,value,i;
	string weapon_name;
	string j="";
	
	ob=this_player();
	
	if(this_object()->is_busy()){
		return notify_fail(query("name")+"说道：我正忙着，请稍等。\n");
	}
	
	if(ob->is_busy())
	 return notify_fail("你正忙着呢！\n");
	
	if(!arg)
		return notify_fail(query("name")+"说道：请使用 xiu 兵器。\n");
	
	weapon_name=arg;
	
	if(!objectp(weapon=present(weapon_name,ob)))
		return notify_fail(query("name")+"说道：你身上并没有这个东西!\n");
	
	if(!weapon->query("skill_type"))
		return notify_fail(query("name")+"说道：我只能修武器！\n");
     
         strong=(int)weapon->query("strong",1);
	 max_strong=(int)weapon->query("max_strong",1);
	 if(!max_strong)
	  max_strong=strong+100;
	 i=strong*100/max_strong;

	 if(i==100)
		 return notify_fail(query("name")+"说道：你的兵器没有损坏，不用修补!\n");
	 j=result_strong(i);
	 tell_object(ob,query("name")+"说道：你的兵器已经"+j+"。\n");
     value=get_value(weapon);
	 
	 tell_object(ob,query("name")+"说道：您的兵器修理需要"+MONEY_D->money_str(value)+"。\n");
	 
	 switch( MONEY_D->player_pay(this_player(), value) ){
	 	case 0:
		 return notify_fail(query("name")+"说道：你身上带的钱不够啊!\n");break;
	    case 2:
		 return notify_fail(query("name")+"说道：您的零钱不够了，银票又没人找得开。\n");
	 }
	if(!weapon->move(this_object()))
		return notify_fail(query("name")+"说道：你的兵器太重了，我拿不动！\n");
	
	weapon->set("no_steal",1);
	weapon->set("no_get",1);
	
	message_vision(HIG"$N"+HIG+"拿出一块矿石叮叮当当的砸了起来。\n"NOR,this_object());

		
	this_object()->start_busy(3);	
	ob->start_busy(3);
		
	call_out("do_msg",3,this_object(),ob,weapon,0);		
	
	return 1;
	
	
}

void do_msg(object tiejiang,object ob,object weapon,int times)
{
	
	if(!tiejiang||!ob||!weapon||environment(weapon)!=tiejiang)
		return;
	
	if(times>=sizeof(msg)){
		message_vision("$N擦了擦汗，终于修好了"+weapon->query("name")+"!\n",tiejiang);
		if(weapon->query("strong",1)<=0)
		weapon->set("name",weapon->query("org_name"));
	    weapon->set("strong",weapon->query("max_strong"));
	    weapon->set("flag",0);
	    
	    weapon->set("no_steal",0);
	    weapon->set("no_get",0);
	    
	    if(environment(ob)!=environment(tiejiang)){
	     weapon->move(environment(tiejiang));
	    }
	    else
	    if(!weapon->move(ob)){
		 tell_object(ob,query("name")+"说道：你身上东西太多了，拿不动兵器，我给你放到地上了。\n");
		 weapon->move(environment(ob));
	    }
		return;
    }
    message_vision(msg[times]+"\n",tiejiang);
    tiejiang->start_busy(3);
    ob->start_busy(3);
    
    call_out("do_msg",3,tiejiang,ob,weapon,times+1);
    
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

int get_value(object weapon)
{
	int value;
	
	value=weapon->query("weapon_prop/damage");
    value+=weapon->query("weapon_prop/min_damage");
    value+=weapon->query("weapon_prop/enhance_min_damage")*5;
    value+=weapon->query("weapon_prop/intelligence")*5;
    value+=weapon->query("weapon_prop/dodge")*5;
    value+=weapon->query("weapon_prop/karma")*5;
    value+=weapon->query("weapon_prop/dodgeaction")*5;
    value+=weapon->query("weapon_prop/constitution")*5;
    value+=weapon->query("weapon_prop/personality")*5;
    value+=weapon->query("weapon_prop/armor")*5;
    value+=weapon->query("weapon_prop/strength")*5;
   
    value=value*10;
    
    return value;
}

   
