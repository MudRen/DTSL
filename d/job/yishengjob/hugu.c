#include <ansi.h>

inherit ITEM;

string *heals=({"��Ѫ","����","��Ѫ"});

void create()
{
   set_name(BLU"����"NOR,({"hugu"}));
   set_weight(500);
   if( clonep() )
     set_default_object(__FILE__);
   else {
                set("unit", "��");
     set("no_sell",1);
//     set("no_give",1);
     set("nogive_player",1);
     set("no_save",1);
     set("long","����һ������ҩ�ģ�������������ҩ�\n");
     set("value", 5000);
	set("medicine_type",([
         "type" :heals[random(sizeof(heals))],
         "gongxiao" :10+random(30),
         ])); 
           
   }
   setup();
   
}

string long()
{
  return query("long")+"\n"+"��������"+query("medicine_type/type")+"�Ĺ�Ч��\n";
}