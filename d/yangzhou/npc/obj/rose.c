
#include <ansi.h>
inherit ITEM;

void create()
{
   set_name(HIR"õ�廨"NOR, ({"rose"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��õ�廨��������͸��Լ�ϲ����Ů���ӡ�\n");
                set("unit", "��");
                set("value", 600);
             
        }
}

