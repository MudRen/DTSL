

inherit COMBINED_ITEM;
void create()
{
   set_name("����", ({ "tie kuang","tie","kuang"}) );
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "iron");
     set("unit", "Щ");
     set("no_drop",1);
     set("no_get",1);
     set("base_unit","��");
	 set("weapon",([
		 "damage":70,
		 "strong":70,
		 ]));
    
   }
   set_amount(1);
  // setup();
}
