
#include <armor.h>
#include <ansi.h>

inherit SHIELD;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIB"风暴"NOR, ({ "feng bao","shield"}) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "玄铁");
     set("unit", "个");
     set("value",400);
     set("long","这是武林中的至宝护盾，名为「大漠之风暴」。\n");
     set("armor_prop/armor", 200);
     set("armor_prop/parry", 60);
     set("armor_prop/dodge", 100);
     set("armor_prop/damo", 1);
   }
   setup();
}

int wear()
{
   object owner;
   
   if(!(owner = environment())->is_character()) return 0;
   
   if(!::wear()) return ::wear();
   
   if(owner->query("combat_exp")<3000000)
    return notify_fail("你目前无法装备这件物品。\n");
   owner->add("max_kee",1500);
   
   if(owner->query_temp("apply/damo")==5){
    	message_vision(HIY"$N"+HIY+"的身上隐隐发出阵阵狂风的声音，四周卷起一阵的风沙。\n"NOR,owner);
    	owner->add_temp("apply/damage",50);
    	owner->add("max_kee",500);
    	owner->add_temp("apply/parry",60);}
    	
   return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
    owner->add("max_kee",-1500);
    if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
    
    if(owner->query_temp("apply/damo")==4){
    	owner->add_temp("apply/damage",-50);
    	owner->add("max_kee",-500);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
      
      owner->add_temp("apply/parry",-60);}
    
    return 1;
}