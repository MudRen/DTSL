

inherit ITEM;

void create()
{
   set_name("����", ({ "black iron","iron"}) );
   set_weight(6000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "iron");
	 set("long","����һ��������Ǵ���������Ϻÿ�ʯ��\n");
     set("unit", "��");
     set("value", 10000);
	 set("weapon",([
		 "damage":150,
		 "strong":150,
		 ]));
    
   }
   setup();
}
