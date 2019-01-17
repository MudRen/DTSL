
inherit ITEM;

void create()
{
        set_name("√‹∫Ø", ({"mi han", "han","yinguibaishimihan"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "∑‚");
                set("long", "’‚ «“ª∑‚√‹∫Ø°£\n");
                set("material", "paper");
                set("no_drop",1);
                set("nogive_player",1);
                set("yinguibaishimihan",1);
              
        }

        setup();
}

