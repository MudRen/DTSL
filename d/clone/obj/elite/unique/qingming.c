
#include <armor.h>
#include <ansi.h>

inherit NECK;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIC"����"NOR, ({ "qing ming","neck"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "��");
     set("value",400);
     set("long","���������е���������Ϊ���ɷ�֮��������\n");
     set("armor_prop/armor", 40);
      set("armor_prop/feifeng", 1);
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
   owner->add("max_kee",100);
   
   if(owner->query_temp("apply/feifeng")==5){
    	message_vision(HIY"$N"+HIY+"�������ֳ������ɫ�Ļ��󣬾þò�����ʧ��\n"NOR,owner);
    	owner->add_temp("apply/damage",100);
    	owner->add("max_kee",1000);
    	owner->add("max_force",200);
    	owner->add_temp("apply/dagger",50);}
    	
   return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
    owner->add("max_kee",-100);
    if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
      
    if(owner->query_temp("apply/feifeng")==4){
    	owner->add_temp("apply/damage",-100);
    	owner->add("max_kee",-1000);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
      
      owner->add("max_force",-200);
    if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));
      
      owner->add_temp("apply/dagger",-50);}
    
    return 1;
}