
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(YEL"ʯ��"NOR, ({"shila"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
    else  {
           set("unit", "��");
           set("value",200);
           set("yrs","shila");
           set("long", "����һ��ʯ����\n");
        }
}


