
inherit ITEM;
inherit F_LIQUID;

void create()
{
   set_name("�̲�", ({"tea"}));
   set_weight(100);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "����һ�����̲衣\n");
     set("unit", "��");
     set("value", 30);
     set("max_liquid",30);
   }

  
   set("liquid", ([
     "type": "��",
     "name": "�̲�",
     "remaining":30,
     "drunk_supply":20,
   ]));
}

int is_get_of(object pal,object ob)
{
  if(pal->query("family/family_name")!="ͻ��")
  return notify_fail("ֻ��ͻ�ʵ��ӿ��Լ�����Ķ�������\n");
  return 1;
}
