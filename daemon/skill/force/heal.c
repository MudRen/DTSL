
#include <ansi.h>

int exert(object me, object target)
{
	int cost;string str;int skill;object ob;
	if(!me->query_skill("bencao-shuli",1))
	 return notify_fail("你必须先学本草术理才能为自己疗伤！\n");
	if(!target)
	    ob=me;
	else ob=target;
	
	if(ob!=me&&me->query("vocation")!="药师")
	return notify_fail("只有药师可以给别人疗伤！\n");
	
	if(me->is_busy())
	 return notify_fail("你正忙着呢！\n");
	
	if(ob!=me&&ob->is_busy())
	 return notify_fail("对方正忙着呢！\n");
	
	if(me->is_fighting()||ob->is_fighting())
	return notify_fail("战斗中不能疗伤！\n");
	if(ob->query("eff_kee")==ob->query("max_kee")&&
	   ob->query("eff_gin")==ob->query("max_gin"))
	if(ob==me)
	return notify_fail(HIW"你一运气，发现气息游走自如，没有必要疗伤。\n"NOR);
	else return notify_fail(HIW"你一运气，发现对方气息游走自如，没有必要疗伤。\n"NOR);
	if(me->query("force")<10)
	return notify_fail("你内力不够！\n");
	cost=me->query_skill("force",1)/2+me->query_skill("bencao-shuli");
	if(cost<20) cost=20;
	str=HIW"$N盘膝坐下，头上冒出阵阵白气。\n"NOR;
	message_vision(str,me);
	str=replace_string(str,"$N",me->name());
	str=replace_string(str,"\n","");
	me->set_temp("apply/short",({str}));
	if(ob!=me){
	str=HIW"$N盘膝坐下，头上冒出阵阵白气。"NOR;
	str=replace_string(str,"$N",ob->name());
	ob->set_temp("apply/short",({str}));
	ob->set_temp("healing",1);}
	if(cost<me->query("force")){
	 me->start_busy((:call_other,this_object(),"heal",me,ob,cost:),
	  (:call_other,this_object(),"halt",me,ob:));
        if(ob!=me)
	  ob->start_busy((:call_other,this_object(),"healed",me,ob:));}
	else{
	  cost=me->query("force");
	  me->start_busy((:call_other,this_object(),"heal",me,ob,cost:),
	  (:call_other,this_object(),"halt",me,ob:));
	  if(ob!=me)
	  ob->start_busy((:call_other,this_object(),"healed",me,ob:));
	  }
	
	return 1;
}

int heal(object me,object ob,int cost)
{
    
    me->add("force",-cost);        
    
    if(!ob){
      me->delete_temp("apply/short");
      message_vision(HIW"$N长长地吐了一口气，站了起来。\n"NOR,me);
      me->delete_temp("apply/short");
      return 0;
   }
   
   if(me->is_fighting()||ob->is_fighting()){     
      message_vision(HIW"$N长长地吐了一口气，站了起来。\n"NOR,me);
      me->delete_temp("apply/short");
      
      ob->delete_temp("healing");
      ob->delete_temp("apply/short");
      
      return 0;
   }
   
    if(ob->query("eff_kee")<ob->query("max_kee"))
    {   ob->receive_heal("kee",cost/2);
    	ob->receive_curing("kee",cost/2);}
   if(ob->query("eff_gin")<ob->query("max_gin"))
    {   ob->receive_heal("gin",cost/2);
    	ob->receive_curing("gin",cost/2);}
   if( (ob->query("eff_kee")==ob->query("max_kee")&&
       ob->query("eff_gin")==ob->query("max_gin"))||!ob)
   { message_vision(HIW"$N长长地吐了一口气，站了起来。\n"NOR,me);
     if(ob!=me){
     message_vision(HIR"$N哇地一声吐了一口鲜血，长长地吐了一口气，站了起来。\n感觉舒服多了。\n"NOR,ob);
     ob->delete_temp("healing");}
     me->delete_temp("apply/short");
     ob->delete_temp("apply/short");
     return 0;
    }
   if((ob->query("eff_kee")<ob->query("max_kee")||ob->query("eff_gin")<ob->query("max_gin"))
     &&me->query("force")<cost)
    { message_vision(HIW"$N感到内力不足，停止了运功疗伤。\n"NOR,me);
      if(ob!=me){
      	ob->delete_temp("healing");}
      me->delete_temp("apply/short");
      return 0;
     }
   
   return 1;
}

int halt(object me,object ob)
{
   message_vision("$N将气息压回丹田，长舒了一口气，站了起来。\n",me);
   if(ob!=me)
   ob->delete_temp("healing");
   me->delete_temp("apply/short");
   ob->delete_temp("apply/short");
   return 1;
}

int healed(object me,object ob)
{
  if(!me){
    ob->delete_temp("apply/short");
    ob->delete_temp("healing");
    return 0;
  }
  
  if(ob->query_temp("healing"))
  return 1;
  ob->delete_temp("apply/short");
  return 0;
}