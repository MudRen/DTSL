
inherit ITEM;

void create()
{
   set_name("�־�", ({"shou juan","juan"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "����һ���־������¼�ű����ĵ����ԡ�\n");
     set("unit", "��");
     set("hj_bsy_quest_obj",1);
     set("no_save",1);
     
   }

}

