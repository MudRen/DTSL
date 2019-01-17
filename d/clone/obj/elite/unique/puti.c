
#include <armor.h>
#include <ansi.h>

inherit WRISTS;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIY"����"NOR, ({ "pu ti","neck"}) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "��");
     set("value",400);
     set("long","���Ƿ��ŵ�����֮���Ϊ������Ĳ��֮���᡹��\n");
     set("armor_prop/armor",40);
     set("armor_prop/dodge",100);
     set("armor_prop/moni",1);
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
   
   if(owner->query_temp("apply/moni")==5){
    	message_vision(HIY"$N"+HIY+"��������������ʥ��һ�����ɫ���þ�Ҳ����ɢ��\n"NOR,owner);
    	owner->add_temp("apply/damage",100);
    	owner->add("max_kee",1000);
    	owner->add("max_force",200);}
    	
   return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
   
    if(owner->query_temp("apply/moni")==4){
    	owner->add_temp("apply/damage",-100);
    	owner->add("max_kee",-1000);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
    	owner->add("max_force",-200);
    	if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));}
    
    return 1;
}