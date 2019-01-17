
#include <armor.h>
#include <ansi.h>

inherit NECK;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIB"��ħ"NOR, ({ "xin mo","neck"}) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "�鱦");
     set("unit", "��");
     set("value",400);
     set("long","�������ֵ�����֮���Ϊ������֮��ħ����\n");
     set("armor_prop/parry",60);
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
    return notify_fail("��Ŀǰ�޷�װ�������Ʒ��\n");
    
   owner->add("max_sen",500);
    owner->add("eff_sen",500);
   
   if(owner->query_temp("apply/canglong")==5){
    	message_vision(HIB"$N"+HIB+"�����������������������������ܵĿ�������һ���𶯡�\n"NOR,owner);
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
    
    owner->add("max_sen",-500);
    owner->add("eff_sen",-500);
    if(owner->query("sen")>owner->query("eff_sen"))
      owner->set("sen",owner->query("eff_sen"));
   
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