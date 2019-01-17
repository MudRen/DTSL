
#include <armor.h>
#include <ansi.h>

inherit FINGER;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIM"����"NOR, ({ "cai ling","finger"}) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "ö");
     set("value",400);
     set("long","�������ֵ�����֮���Ϊ������֮������\n");
     set("armor_prop/armor",40);
     set("armor_prop/damage",150);
     set("armor_prop/dodge",150);
     set("armor_prop/finger",80);
     set("armor_prop/hand",80);
     set("armor_prop/cuff",80);
     set("armor_prop/strike",80);
     set("armor_prop/leg",80);
     
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
   
   owner->add("max_kee",800); 
   owner->add("max_force",800); 
  
   return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
    
    owner->add("max_kee",-800);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
    
    owner->add("max_force",-800);
    	if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));
    
   
    return 1;
}