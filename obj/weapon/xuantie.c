

inherit ITEM;

void create()
{
   set_name("����", ({ "xuan tie","xuan","tie"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "iron");
     set("unit", "��");
     set("value", 10000000);
	 set("weapon",([
		 "damage":60,
		 "strong":80,
		 ]));
    
   }
   setup();
}
