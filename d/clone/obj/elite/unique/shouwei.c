
#include <armor.h>
#include <ansi.h>

inherit ARMOR;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIY"守卫"NOR, ({ "shou wei","armor"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "铁");
     set("unit", "件");
     set("value",400);
     set("long","这是武林的至宝之物，名为「马祖之守卫」。\n");
     set("armor_prop/armor",150);
     set("armor_prop/parry",40);
     set("armor_prop/mazu",1);
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
  
  if(owner->query_temp("apply/mazu")==5){
    	message_vision(HIG"$N"+HIG+"的身上隐隐发出阵阵波涛的声音，四周卷起一阵的清风。\n"NOR,owner);
    	owner->add_temp("apply/armor",200);
    	owner->add("max_kee",1500);
    	owner->add_temp("apply/dodge",100);}
    	
   return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
  
    if(owner->query_temp("apply/mazu")==4){
    	owner->add_temp("apply/armor",-200);
    	owner->add("max_kee",-1500);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
      
      owner->add_temp("apply/dodge",-100);}
    
    return 1;
}