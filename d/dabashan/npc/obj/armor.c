
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(MAG"���׼�"NOR, ({"zilin jia","jia","armor"}) );
   set_weight(8000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","����һ���Ϻõ����׼ף������Ѿ���ʧ�����ܾ��ˡ�\n");
     set("rumor",1);
     set("material", "iron");
     set("unit", "��");
     set("value", 400000);
     set("no_sell",1);
     set("no_save",1);
     set("armor_prop/armor", 200);
   }
   setup();
}
