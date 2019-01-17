

inherit ITEM;

void create()
{
   set_name("Ìú¿é", ({ "tie"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "iron");
     set("unit", "¿é");
     set("value",0);
	 set("weapon",([
		 "damage":10,
		 "strong":10,
		 ]));
    
   }
   setup();
}
