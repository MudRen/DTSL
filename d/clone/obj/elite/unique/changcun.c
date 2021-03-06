
#include <armor.h>
#include <ansi.h>

inherit HEAD;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIW"长存"NOR, ({ "chang cun","head"}) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "布");
     set("unit", "顶");
     set("value",400);
     set("long","这是武林的至宝之物，名为「苍龙之长存」。\n");
     set("armor_prop/armor",100);
     set("armor_prop/parry",20);
     set("armor_prop/canglong",1);
   }
   setup();
}

int wear()
{
   object owner;
   
   if(!(owner = environment())->is_character()) return 0;
   
   if(!::wear()) return ::wear();
   
   if(owner->query("combat_exp")<1000000)
    return notify_fail("你目前无法装备这件物品。\n");
   
   if(owner->query_temp("apply/canglong")==5){
    	message_vision(HIB"$N"+HIB+"的身上隐隐发出雷鸣的声音，四周的空气产生一股震动。\n"NOR,owner);
    	owner->add_temp("apply/damage",100);
    	owner->add("max_kee",500);
    	owner->add("max_force",500);}
    	
   return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
   
    if(owner->query_temp("apply/canglong")==4){
    	owner->add_temp("apply/damage",-100);
    	owner->add("max_kee",-500);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
    	owner->add("max_force",-500);
    	if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));}
    
    return 1;
}