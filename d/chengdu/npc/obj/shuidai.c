
inherit ITEM;
inherit F_LIQUID;

void create()
{
   set_name("ţƤˮ��", ({"shuidai","dai"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "һ������װˮ��ˮ����\n");
     set("unit", "��");
     set("value", 20);
     set("max_liquid", 20);
   }

  
   set("liquid", ([
     "type": "water",
     "name": "��ˮ",
     "remaining": 20,
     "drunk_supply": 6,
   ]));
}

