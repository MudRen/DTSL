

inherit ITEM;

void create()
{
   set_name("����", ({ "letter","xin" }) );
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
	 set("long","����һ���¼�ű������ѱ����š�\n");
	 set("unit", "��");
         set("wanhuan_quest",1);
         set("nogive_player",1);
   }
   setup();
}
