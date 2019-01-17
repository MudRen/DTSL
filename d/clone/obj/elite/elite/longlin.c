
#include <armor.h>
#include <ansi.h>

inherit ARMOR;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIY"����"NOR, ({ "long lin","armor"}) );
   set_weight(9000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "����");
     set("unit", "��");
     set("value",400);
     set("long","���������е��������ף���Ϊ������֮������\n");
     set("armor_prop/armor", 300);
     set("armor_prop/parry", 60);
     set("armor_prop/dodge", 100);
     
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
    
    
    return 1;
}