
#include <armor.h>
#include <ansi.h>

inherit WAIST;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIG"��Ը"NOR, ({ "xin yuan","waist"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "��");
     set("value",400);
     set("armor_prop/armor",100);
     set("armor_prop/parry",60);
     set("armor_prop/whip",60);
     set("armor_prop/mazu",1);
   }
   setup();
}

int wear()
{
   object owner;
   
   if(!(owner = environment())->is_character()) return 0;
   
   if(!::wear()) return ::wear();
   if(owner->query("combat_exp")<3000000)
    return notify_fail("��Ŀǰ�޷�װ�������Ʒ��\n");
   owner->add("max_kee",500);
   
   if(owner->query_temp("apply/mazu")==5){
    	message_vision(HIG"$N"+HIG+"�������������������ε����������ܾ���һ�����硣\n"NOR,owner);
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
    owner->add("max_kee",-500);
    if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
    
    if(owner->query_temp("apply/mazu")==4){
    	owner->add_temp("apply/armor",-200);
    	owner->add("max_kee",-1500);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
      
      owner->add_temp("apply/dodge",-100);}
    
    return 1;
}