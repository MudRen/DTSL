

void apply_poison(object me,object ob)
{
   
    if(!me||!ob)
    return;
    if(ob->query("poison"))
   	if(!me->query_condition("quest_poison")&&
   	   ob->query("poison/times")>0){   	  
   	   ob->add("poison/times",-1);
   	me->apply_condition("quest_poison",ob->query("poison"));}
    return;
}