
inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
   set_name(HIR"��˫ϲ"NOR, ({"hong shuangxi"}));
   set_weight(30);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "�����������½�������д����˵�ϲ�ơ�\n");
     set("unit", "��");
     set("value", 20);
     set("no_sell",1);
     set("max_liquid",50);
   }

  
   set("liquid", ([
     "type": "alcohol",
     "name": "�׾�",
     "remaining":35,
     "drunk_supply":30,
   ]));
}

