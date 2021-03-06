
#include <armor.h>
#include <ansi.h>

inherit HANDS;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIB"密印"NOR, ({ "mi yin","hands"}) );
   set_weight(200);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "铁");
     set("unit", "双");
     set("value",400);
     set("long","这是武林的至宝之物，名为「莫邪之密印」。\n");
     set("armor_prop/armor",80);
     set("armor_prop/moye",1);
   }
   setup();
}

int wear()
{
   object owner;
   
   if(!(owner = environment())->is_character()) return 0;
   
   if(!::wear()) return ::wear();
   
   if(owner->query("combat_exp")<800000)
    return notify_fail("你目前无法装备这件物品。\n");
    
   owner->add("max_kee",200);
  
  if(owner->query_temp("apply/moye")==4){
    	message_vision(HIR"$N"+HIR+"的身上冒出阵阵红晕，久久不见消散。\n"NOR,owner);
    	owner->add_temp("apply/damage",100);
    	owner->add_temp("apply/dodge",100);
    	owner->add("max_kee",500);
    	owner->add("max_force",1000);}
    	
   return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
    
    owner->add("max_kee",-200);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
  
    if(owner->query_temp("apply/moye")==3){
    	owner->add_temp("apply/damage",-100);
    	owner->add_temp("apply/dodge",-100);
    	owner->add("max_kee",-500);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
    	owner->add("max_force",-1000);
    	if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));}
    
    return 1;
}