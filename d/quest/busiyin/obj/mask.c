
inherit ITEM;

void create()
{
   set_name("���", ({ "mask"}) );
   set_weight(500);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��Ƥ");
     set("unit", "��");
     set("dtsl_quest_bsy",1);
   }
   setup();
}
