

inherit COMBINED_ITEM;
void create()
{
   set_name("Ìú¿ó", ({ "tie kuang","tie","kuang"}) );
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "iron");
     set("unit", "Ð©");
     set("base_unit","¿é");
	 set("weapon",([
		 "damage":20,
		 "strong":70,
		 ]));
    
   }
   set_amount(1);
  // setup();
}
