
inherit ITEM;

void create()
{
   set_name("����", ({ "xiang liao","liao","elite_thing_xiangxiao"}) );
   //{elite_thing_xiangxiao}�����жϵı�־������
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","�����ü�Ʒ�������ɵ����ϡ�\n");
     set("unit", "��");
     set("super", 1);
     set("value",100000);
     set("no_sell",1);
     set("order",2);
     set("quest_order",1);
     set("nogive_player",1);
  }
   setup();
}
