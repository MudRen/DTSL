
inherit ITEM;

void create()
{
        set_name("�ϳ���", ({ "duanchang cao","cao" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
				set("long","����һ�ö��ݡ�\n");
                set("value", 3);
		set("quest_poison",1);
		set("poison_id","duanchang cao");		
                
        }

      
        setup();
}
