
inherit ITEM;

void create()
{
        set_name("������", ({ "he shou wu","he","shou","wu" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
				set("long","����һ[������]��������ҩ�Ｋ�õ�ҩ�ġ�\n");
                set("value", 30000);
				set("heal",([
					"heals":30,
					]));
                
        }

      
        setup();
}
