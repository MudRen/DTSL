


inherit ITEM;

void create()
{
   set_name("һ��ֽ��", ({ "papers"}) );
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
	 set("long","���ǶĲ��õ�ֽ��.\n");
     set("unit", "��");
	 set("amounts",52);
     set("value", 1);
     set("desc",1);
   }
   setup();
}
