//written by yanyan.
/*type 为 armor:盔甲
          head :头盔
          neck :护颈
          waist:护腰
          wrists:护腕
          shield:盾牌
          finger:板指
          hands :护掌
          boots :靴子
防御度为 armor>shield>head>boots>waist>neck>hands>wrists>finger

*/

#include <ansi.h>


inherit F_CLEAN_UP;
#include "tiejiang.h"
#include "vocation.h"

int get_type_par(string type);

string *armor_type=({"armor","shield","head","boots",
"waist","neck","hands","wrists","finger","yaoding"});

string *dazao_msg=({
HIY"$N"+HIY+"渐渐流下了汗，炉子的火越来越旺了！\n"NOR,
HIY"$N"+HIY+"渐渐流下了汗，炉子的火越来越旺了！\n"NOR,
HIY"$N"+HIY+"渐渐流下了汗，炉子的火越来越旺了！\n"NOR,
HIR"只见火势越来越旺，$N"+HIR+"有些受不了了。\n"NOR,
HIR"只见火势越来越旺，$N"+HIR+"有些受不了了。\n"NOR,
HIR"只见火势越来越旺，$N"+HIR+"有些受不了了。\n"NOR,
HIB"$N"+HIB+"不停的挥舞着铁锤，乒乒乓乓地敲打着！\n"NOR,
HIB"$N"+HIB+"不停的挥舞着铁锤，乒乒乓乓地敲打着！\n"NOR,
HIB"$N"+HIB+"不停的挥舞着铁锤，乒乒乓乓地敲打着！\n"NOR,
RED"$N"+RED+"有些气喘吁吁，脸被火光映得通红。\n"NOR,
RED"$N"+RED+"有些气喘吁吁，脸被火光映得通红。\n"NOR,
RED"$N"+RED+"有些气喘吁吁，脸被火光映得通红。\n"NOR,
});

int main(object me,string arg)
{
    
	object ob,armor,metirial;
	string m_name,armor_name,type;
	mapping mweapon;
	int lev,wstrong;
	
	if(!arg||sscanf(arg,"%s %s %s",m_name,armor_name,type)!=3)
		return notify_fail("请使用 duanzao 原料名称 盔甲名称 盔甲类型。 \n");
	
	if(!is_leagel_name(armor_name))
	 return 1;
        	
    if(member_array(type,armor_type)==-1)
      return notify_fail("没有这种盔甲类型！\n");
    if(me->query("vocation")!="铁匠")
      return notify_fail("你不是铁匠，不能锻造兵器!\n");
        
    if(member_array(base_name(environment(me)),tiejiang_here)==-1)
        return notify_fail("你还是到兵器店去锻造盔甲吧！\n");
    
    if(time()>me->query("duanzao_busy")&&time()-me->query("duanzao_busy")<30+random(10))
	  return notify_fail("你歇会再锻造吧！\n");
       
	if(!objectp(metirial=present(m_name,me)))
		return notify_fail("你身上没有这种东西!\n");
	if(me->is_busy())
		return notify_fail("你现在很忙，歇歇吧!\n");
	if(me->is_fighting())
		return notify_fail("你还是先打完仗再说吧！\n");
	mweapon=metirial->query("weapon");
	if(!mweapon)
		return notify_fail("这种"+metirial->name()+"不能锻造盔甲！\n");
   
	lev=(int)me->query_skill("duanzao-jishu",1);
	if(lev<60)
	return notify_fail("你的锻造技术太差劲，无法打造兵器！\n");
	if(me->query_str()<30)
	return notify_fail("你的膂力太低了，无法锻造盔甲！\n");
	
	if(me->query("gin")<me->query("max_gin")/2)
	 return notify_fail("你的精血太低了，无法锻造盔甲。\n");
	if(me->query("kee")<me->query("max_kee")/2)
	 return notify_fail("你的气血太低了，无法锻造盔甲。\n");
	if(me->query("sen")<me->query("max_sen")/2)
	 return notify_fail("你的精神太差了，无法锻造盔甲。\n");
	 
	message_vision("$N打开"+environment(me)->query("short")+"的小铁炉，将"+metirial->name()+"放了进去。\n",me);
    message_vision(RED"\n$N"+RED+"拉动风箱，火“呼”地一声窜了起来！\n"NOR,me);
    
    me->start_busy(5);
    call_out("do_msg",5,me,metirial,mweapon,armor_name,type,lev,0);
    
    return 1;
}

void do_msg(object me,object metirial,mapping mweapon,string armor_name,
            string type,int lev,int times)
{
	          
      if(!me||!metirial||environment(metirial)!=me)
        return;
      
      if(times>=sizeof(dazao_msg)){
      	call_out("do_msg2",5,me,metirial,mweapon,armor_name,type,lev);
      	me->start_busy(5);
      	return;
      }
      message_vision(dazao_msg[times]+"\n",me);
      
     if(lev>=1000) 
      	call_out("do_msg",5,me,metirial,mweapon,armor_name,type,lev,times+1);
      else
      	call_out("do_msg",5,me,metirial,mweapon,armor_name,type,lev,times+3);
      me->start_busy(5);
      return;
}
 
void do_msg2(object me,object metirial,mapping mweapon,string armor_name,
            string type,int lev)
{
	object obj;
	
	int armor=0,parry=0,dodge=0,damage=0;
    int str=0,intl=0,con=0,dex=0;
    int per=0,kar=0;
    int w_str=0,w_con=0,w_int=0,w_dex=0,w_force=0,w_maxforce=0;
    int no_need_force=0,no_need_maxforce=0,no_need_sx=0,reduce_force=0,
        reduce_maxforce=0,reduce_sx=0;
    int enhance_min_damage=0,enhance_max_damage=0,double_damage=0;
    
    int fenzhi_flag=0;
    int score=0;
    
    if(!me||!metirial||environment(metirial)!=me)
        return;
    
    message_vision(RED"\n$N"+RED+"抽出随身携带的匕首，朝自己胳膊上扎去！\n"NOR,me);
   tell_object(environment(me),WHT"\n只听“滋”的一声，鲜血飞溅上去，一阵白烟冒了出来！\n\n"NOR);
	
	if(me->query("vocation_fenzhi")=="armor")//如果是盔甲分支，则盔甲要好的多。
	 fenzhi_flag=1;
	
	 if(type=="armor")	
	  armor=80+random(lev*mweapon["strong"]/150);
	 else
	 if(type=="head")
	  armor=20+random(lev*mweapon["strong"]/300);
	 else
	 if(type=="waist")
	  armor=15+random(lev*mweapon["strong"]/300);
	 else
	 if(type=="shield")
	  armor=50+random(lev*mweapon["strong"]/150);
	 else
	 if(type=="boots")
	  armor=10+random(lev*mweapon["strong"]/300);
	 else
	 if(type=="hands")
	  armor=10+random(lev*mweapon["strong"]/300);
	 else
	 if(type=="neck")
	  armor=10+random(lev*mweapon["strong"]/300);
	 else
	 if(type=="finger")
	  armor=5+random(lev*mweapon["strong"]/300);
	 else
	 if(type=="wrists")
	  armor=10+random(lev*mweapon["strong"]/300);
	
	if(!fenzhi_flag) armor=armor/3;
	
	score=armor/10;
	
	if(lev>=200&&fenzhi_flag){
		if(random(armor)<20){
		 parry=random(get_type_par(type))+random(lev/50);
		 score++;
		}
		
		if(random(armor)<6&&type=="boots"){
		 dodge=random(get_type_par(type))+random(lev/50);
		 score++;
		}
	    
            if(random(1000)==me->query_kar()){
	     enhance_min_damage=random(get_type_par(type));
	     score++;
	    }
	    
            if(random(1000)==me->query_kar()){
	     enhance_max_damage=random(get_type_par(type));
	     score++;
	    }
	    
            if(random(1000)==me->query_kar()){
     	  double_damage=random(get_type_par(type));
     	  score+=2;
     	}
     	
     	if(random(400)==me->query_kar()){
     	  intl=random(get_type_par(type)/10);
     	  score+=1;
     	}
     	if(random(400)==me->query_kar()){
     	  con=random(get_type_par(type)/10);
     	  score+=1;
     	}
     	if(random(400)==me->query_kar()){
     	  dex=random(get_type_par(type)/10);
     	  score+=1;
     	}
     	if(random(400)==me->query_kar()){
     	  str=random(get_type_par(type)/10);
     	  score+=1;
     	}
	    
	    if(random(400)==me->query_kar()){
     	  kar=random(lev/60);
     	  score+=1;
     	}
     	if(random(400)==me->query_kar())
     	  per=random(lev/60);
     	
     	if(random(100)==me->query_kar()){
     	  no_need_force=1;
     	  score+=1;
     	}
     	if(random(100)==me->query_kar()){
     	  no_need_maxforce=1;
     	  score+=1;
     	}
     	if(random(400)==me->query_kar()){
     	  no_need_sx=1;
     	  score+=1;
     	}
     	if(random(armor)<90){
     	  reduce_force=lev/2+random(lev);
     	  score+=1;
     	}
     	if(random(armor)<96){
     	  reduce_maxforce=lev/2+random(lev);
     	  score+=1;
     	}
     	if(random(armor)<95){
     	  reduce_sx=random(lev/60);
     	  score+=1;
     	}
    }	
      
	obj=new("/obj/armorclass/"+type);
	armor_name=replace_string(armor_name,"$HIR$",""HIR"");
	armor_name=replace_string(armor_name,"$HIG$",""HIG"");
	armor_name=replace_string(armor_name,"$HIY$",""HIY"");
	armor_name=replace_string(armor_name,"$HIW$",""HIW"");
	armor_name=replace_string(armor_name,"$HIB$",""HIB"");
	armor_name=replace_string(armor_name,"$HIM$",""HIM"");
	armor_name=replace_string(armor_name,"$HIC$",""HIC"");
	armor_name=replace_string(armor_name,"$GRN$",""GRN"");
	armor_name=replace_string(armor_name,"$RED$",""RED"");
	armor_name=replace_string(armor_name,"$BLK$",""BLK"");
	armor_name=replace_string(armor_name,"$YEL$",""YEL"");
	armor_name=replace_string(armor_name,"$BLU$",""BLU"");
	armor_name=replace_string(armor_name,"$MAG$",""MAG"");
	armor_name=replace_string(armor_name,"$CYN$",""CYN"");
	armor_name=replace_string(armor_name,"$WHT$",""WHT"");
	armor_name=armor_name+NOR;
	obj->set("name",armor_name);
	
	obj->set("long","这是"+me->name()+"用"+metirial->name()+"锻造的【"+armor_name+"】\n"NOR);
        
    if(type=="yaoding")
      obj->set("dlev",random(lev));
    
    if(type!="yaoding"){ 
     switch(random(4)){
	   case 0: 
	           obj->set("wear_str",score-score/5);
	           break;
	   case 1: 
	           obj->set("wear_con",score-score/5);
	           break;	  	  
	   case 2: 
	           obj->set("wear_dex",score-score/5);
	           break;
	   case 3: 
	           obj->set("wear_int",score-score/5);
	           break;
     }
    
        obj->set("wear_force",score*16);	           	   
	obj->set("wear_maxforce",score*90);  
	
	obj->set("armor_prop/armor",armor);
	obj->set("armor_prop/parry",parry);
	obj->set("armor_prop/dodge",dodge);
	obj->set("armor_prop/damage",damage);
	    
	obj->set("armor_prop/strength",str);
	obj->set("armor_prop/intelligence",intl);
	obj->set("armor_prop/constitution",con);
	obj->set("armor_prop/dodgeaction",dex);
	    
	obj->set("armor_prop/personality",per);
	obj->set("armor_prop/karma",kar);	    	
	    
	obj->set("no_need_force",no_need_force);
	obj->set("no_need_maxforce",no_need_maxforce);
	obj->set("no_need_sx",no_need_sx);
	obj->set("reduce_force",reduce_force);
	obj->set("reduce_maxforce",reduce_maxforce);
	obj->set("reduce_sx",reduce_sx);
	    
	obj->set("armor_prop/enhance_min_damage",enhance_min_damage);
	obj->set("armor_prop/enhance_max_damage",enhance_max_damage);
	obj->set("armor_prop/double_damage",double_damage);  
    }	
	obj->set("save_flag",1);  	
	
	obj->setup();
	
	message_vision("\n"+obj->name()+"锻造好了!\n"NOR,me);
	
	if(metirial->query_amount()&&
	metirial->query_amount()>1)
	 metirial->set_amount(metirial->query_amount()-1);
	else
        destruct(metirial);
        
  	if(!obj->move(me)){
	  tell_object(me,"你的负重不够了！\n");
	  obj->move(environment(me));
	}
	
	me->receive_damage("kee",me->query("max_kee")/2);
	me->receive_damage("gin",me->query("max_gin")/2);
	me->receive_damage("sen",me->query("max_sen")/2);
	
	me->add("vocation_score",armor/2);
	
	if(me->query_skill("duanzao-jishu",1)>=100)
       me->improve_skill("duanzao-jishu",(me->query_int())+me->query("max_pot"));
	else me->improve_skill("duanzao-jishu",random(10));
	
	me->set("duanzao_busy",time());

    return;
}

int get_type_par(string type)
{
	if(type=="armor") return 50;
	else
	if(type="shield") return 50;
	else
	if(type="head") return 30;
	else
	if(type="boots") return 10;
	else
	if(type="waist") return 5;
	else
	if(type="neck") return 10;
	else
	if(type="hands") return 10;
	else
	if(type="wrists") return 10;
	else
	if(type="finger") return 3;
	else
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : duanzao 原料名称 盔甲名称 盔甲类型
           盔甲名称支持颜色字符。
此命令为铁匠的专用命令，可以用来锻造盔甲。
可以锻造的类型为：
          armor  :盔甲
          head   :头盔
          neck   :护颈
          waist  :护腰
          wrists :护腕
          shield :盾牌
          finger :板指
          hands  :护掌
          boots  :靴子
          yaoding:药鼎，用于给药师炼制药物。
HELP
    );
    return 1;
}
