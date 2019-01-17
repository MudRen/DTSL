

inherit ITEM;

void create()
{
   set_name("ÐþÌú", ({ "xuan tie","xuan","tie"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "iron");
     set("unit", "¿é");
     set("value", 10000000);
	 set("weapon",([
		 "damage":60,
		 "strong":80,
		 ]));
    
   }
   setup();
}
