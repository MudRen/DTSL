
#include <armor.h>
#include <ansi.h>
inherit WAIST;

void create()
{
   set_name(HIY"��ç����"NOR, ({ "jinmang yaodai","yaodai"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��Ƥ");
     set("long","��˵�����ú����Ľ�ɫ����Ƥ�Ƴɵ�������\n");
     set("unit", "��");
     set("value",5000);
     set("armor_prop/armor",30);
     set("armor_prop/dodge",2);
   }
   setup();
}
