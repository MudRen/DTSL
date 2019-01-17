// hammer.c

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name(HIC"����"NOR, ({ "shan dian","hammer" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
             
		set("value",300);
		set("super",9);
		set("long","����������������������Ϊ������֮���硹��\n");
                set("material", "iron");
                set("wield_msg",HIC"$N"+HIC+"�ó�һ��$n"+HIC+"��Ȼ���������У�ֻ����Χ���˵����⡣\n"NOR);
                set("unwield_msg", "$N�������е�$n��\n");
                set("weapon_prop/hammer",60);
                set("weapon_prop/canglong",1);
        }
        
        init_hammer(200,200,200);
        setup();
}

int wield()
{
    object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::wield()) return ::wield();
    
    if(owner->query("combat_exp")<3000000)
    return notify_fail("��Ŀǰ�޷�װ�������Ʒ��\n");
    
    owner->add("max_force",500);
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
    owner->add("max_force",-500);
    if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));
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
