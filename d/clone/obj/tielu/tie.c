

inherit ITEM;

void create()
{
   set_name("����", ({ "tie"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "iron");
     set("unit", "��");
     set("value",0);
	 set("weapon",([
		 "damage":10,
		 "strong":10,
		 ]));
    
   }
   setup();
}
