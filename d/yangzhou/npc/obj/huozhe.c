
#include <ansi.h>

inherit ITEM;

void create()
{
  set_name("����", ({ "huo zhe", "huo","zhe","fire" }) );
  set_weight(250);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "����������ۣ���Ϳ����ں��쿴��·�ˡ�\n");
    set("value",500);
    set("unit", "��");
  }
  setup();
}
