
#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(HIG"�̻�"NOR, ({ "jiao hua","staff" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	        set("value", 400);
	        set("long","���Ƿ��ŵ�������������Ϊ������Ĳ��֮�̻�����\n");
                set("material", "wood");
               // set("super",9);
                set("weapon_prop/staff",30);
                set("weapon_prop/dodge",80);
                set("weapon_prop/moni",1);
        }
        init_staff(300,300,300);

        set("wield_msg", HIY"$N"+HIY+"��$n"+HIY+"�������У���������һ�����ɫ�Ĺ�â��\n"NOR);
        set("unwield_msg", "$N�ɿ������е�$n��\n");


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
    
    owner->add("max_kee",1000);
    
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
    owner->add("max_kee",-1000);
    if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
      
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
