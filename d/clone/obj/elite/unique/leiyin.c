
#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIB"����"NOR, ({ "lei yin","blade" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
             
		set("value",300);
		//set("super",7);
		set("long","���Ƿ�����������������Ϊ����Ħ֮��������\n");
                set("material", "iron");
                set("wield_msg",HIC"$N"+HIC+"�ó�һ��$n"+HIC+"��Ȼ���������У�ֻ��һ������ֱ��������\n"NOR);
                set("unwield_msg", "$N�������е�$n��\n");
                set("weapon_prop/mantuoluo",1);
        }
        
        init_blade(200,200,200);
        setup();
}

int wield()
{
    object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::wield()) return ::wield();
    
    if(owner->query("combat_exp")<1000000)
    return notify_fail("��Ŀǰ�޷�װ�������Ʒ��\n");
    
    owner->add("max_force",100);
    
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
    owner->add("max_force",-100);
    if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));
  
    if(owner->query_temp("apply/mantuoluo")==4){
    	owner->add_temp("apply/damage",-100);
    	owner->add("max_force",-1000);
    	if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));}
    
    return 1;
}
