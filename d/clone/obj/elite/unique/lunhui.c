
#include <armor.h>
#include <ansi.h>

inherit BOOTS;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIG"�ֻ�"NOR, ({ "lun hui","boots"}) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "˫");
     set("value",400);
     set("long","���Ƿ����е���������Ϊ����Ħ֮�ֻء���\n");
     set("armor_prop/dodge",50);
     set("armor_prop/dodge_skill",30);
     set("armor_prop/mantuoluo",1);
   }
   setup();
}

int wear()
{
   object owner;
   
   if(!(owner = environment())->is_character()) return 0;
   
   if(!::wear()) return ::wear();
   if(owner->query("combat_exp")<1000000)
    return notify_fail("��Ŀǰ�޷�װ�������Ʒ��\n");
   
   if(owner->query_temp("apply/mantuoluo")==5){
    	message_vision(HIY"$N"+HIY+"��������������һ���ɫ�Ĺ�â���յ����ܷǳ�������\n"NOR,owner);
    	owner->add_temp("apply/damage",100);
    	owner->add("max_force",1000);}
    	
   return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
    
    if(owner->query_temp("apply/mantuoluo")==4){
    	owner->add_temp("apply/damage",-100);
    	owner->add("max_force",-1000);
    	if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));}
    
    return 1;
}