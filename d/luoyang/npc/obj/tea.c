
inherit ITEM;

void create()
{
   set_name("��ѿҶ", ({ "huang yaye","tea","yaye"}) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","���ǲ��м�Ʒ��ѿҶ��\n");
     set("unit", "��");
     set("value", 60);
     set("no_sell",1);
     set("order",1);
     set("nogive_player",1);
  }
   setup();
}
