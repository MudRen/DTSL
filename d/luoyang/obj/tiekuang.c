

inherit COMBINED_ITEM;
void create()
{
   set_name("����", ({ "tie kuang","tie","kuang"}) );
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "iron");
     set("unit", "Щ");
     set("base_unit","��");
	 set("weapon",([
		 "damage":20,
		 "strong":70,
		 ]));
    
   }
   set_amount(1);
  // setup();
}
