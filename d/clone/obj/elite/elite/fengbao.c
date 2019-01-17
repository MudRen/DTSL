
#include <armor.h>
#include <ansi.h>

inherit SHIELD;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIB"�籩"NOR, ({ "feng bao","shield"}) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "����");
     set("unit", "��");
     set("value",400);
     set("long","���������е��������ܣ���Ϊ����Į֮�籩����\n");
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
    return notify_fail("��Ŀǰ�޷�װ�������Ʒ��\n");
   owner->add("max_kee",1500);
   
   if(owner->query_temp("apply/damo")==5){
    	message_vision(HIY"$N"+HIY+"������������������������������ܾ���һ��ķ�ɳ��\n"NOR,owner);
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