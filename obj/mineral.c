
inherit MONEY;
void create()
{
    set_name("��ʯ", ({ "mineral"}) );
      set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {  set("prep", "on");
                set("unit", "Щ");
                set("base_unit","��");
                set("long", "һЩ��ʯ��\n");
                set("mineral",1);
                set("base_value",10);
	      
        }
        set_amount(1);
} 