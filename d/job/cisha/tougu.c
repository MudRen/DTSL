
#include <armor.h>

inherit HEAD;

void create()
{
   set_name("�ֹ�", ({ "gang gu","gu"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("long","����һ�����д��ĸֹ���\n");
     set("unit", "��");
     set("value",60);
     set("armor_prop/armor",3);
   }
   setup();
}
