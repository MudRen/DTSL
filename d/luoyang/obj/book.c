
inherit ITEM;

void create()
{
   set_name("���", ({ "book","steal_busiyin_obj" }) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("material", "paper");
     set("long", "����һ����������ƺ�������ĳ���书��\n");
     set("nogive_player",1);
     set("no_drop",1);
     set("no_get",1);
     
   }
   
   setup();
}
