
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("…ﬂµ®", ({"she dan","dan"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "’‚ «“ª√∂…ﬂµ®°£\n");
                set("unit", "√∂");
                set("food_remaining",40);
                set("food_supply", 40);
        }
}

