
#include <armor.h>
//#include <ansi.h>
inherit WAIST;

void create()
{
   set_name("����", ({ "yao dai","dai","waist"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "����");
     set("long","����һ����ͨ��������\n");
     set("unit", "��");
     set("value",300);
     set("armor_prop/armor",5);
  }
   setup();
}
