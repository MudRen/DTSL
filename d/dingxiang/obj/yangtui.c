
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("������", ({"kao yangtui","yangtui"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ����������Ŀ����ȡ�\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 30);
                set("food_supply", 50);
        }
}

int is_get_of(object pal,object ob)
{
  if(pal->query("family/family_name")!="ͻ��")
  return notify_fail("ֻ��ͻ�ʵ��ӿ��Լ�����Ķ�������\n");
  return 1;
}