
#include <armor.h>
//#include <ansi.h>
inherit HEAD;

void create()
{
   set_name("ͷ��", ({ "tou kui","hui"}) );
   set_weight(500);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "����");
     set("long","����ʿ�������õ�ͷ����\n");
     set("unit", "��");
     set("value",800);
     set("armor_prop/armor",10);
  }
   setup();
}
