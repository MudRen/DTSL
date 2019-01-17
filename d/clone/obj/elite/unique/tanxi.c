
#include <armor.h>
#include <ansi.h>

inherit NECK;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIR"̾Ϣ"NOR, ({ "tan xi","neck"}) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "��");
     set("value",400);
     set("long","�������ֵ�����֮���Ϊ����Į֮̾Ϣ����\n");
     set("armor_prop/armor",70);
     set("armor_prop/parry",20);
     set("armor_prop/damo",1);
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
   
    if(owner->query_temp("apply/damo")==4){
    	owner->add_temp("apply/damage",-50);
    	owner->add("max_kee",-500);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
      
      owner->add_temp("apply/parry",-60);}
    
    return 1;
}