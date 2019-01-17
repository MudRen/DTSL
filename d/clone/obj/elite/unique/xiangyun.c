
#include <armor.h>
#include <ansi.h>

inherit BOOTS;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIW"����"NOR, ({ "xiang yun","boots"}) );
   set_weight(200);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Ƥ");
     set("unit", "˫");
     set("value",400);
     set("long","���������е���������Ϊ������֮���ơ���\n");
     set("armor_prop/armor", 40);
     set("armor_prop/dodge_skill",60);
      set("armor_prop/jiaolong", 1);
   }
   setup();
}

int wear()
{
   object owner;
   
   if(!(owner = environment())->is_character()) return 0;
   
   if(!::wear()) return ::wear();
   
   if(owner->query("combat_exp")<800000)
    return notify_fail("��Ŀǰ�޷�װ�������Ʒ��\n");
   
    if(owner->query_temp("apply/jiaolong")==5){
    	message_vision(HIC"$N"+HIC+"�����Ϸ�����������������þò�����\n"NOR,owner);
    	owner->add_temp("apply/damage",100);
    	owner->add("max_kee",500);
    	owner->add("max_force",2000);}
    	
   return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
   
    if(owner->query_temp("apply/jiaolong")==4){
    	owner->add_temp("apply/damage",-100);
    	owner->add("max_kee",-500);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
    	owner->add("max_force",-2000);
    	if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));}
    
    return 1;
}