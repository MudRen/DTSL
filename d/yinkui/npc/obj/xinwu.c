
inherit ITEM;

void create()
{
   set_name("����", ({ "xin wu","wu"}) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ�����\n");
     set("unit", "��");
     set("quest_hong",1);
   
   }
   setup();
}
