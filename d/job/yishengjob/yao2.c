#include <ansi.h>
// #include <job_money.h>
inherit ITEM;
mapping name=([
RED"������"NOR:"jinyinhua",
YEL"����"NOR:"chuanwu",
HIY"��Ƭ"NOR:"bingpian",
GRN"�춬"NOR:"tiandong",
HIC"Ѫ��"NOR:"xuejie",
BLU"���"NOR:"dahuang",
MAG"�Ͷ�"NOR:"badou",
]);
void create()
{
   string *n;int i;
   string *w;
    
   n=keys(name);
   i=random(sizeof(n));
   set_name(n[i],({name[n[i]]}));
   set_weight(50000);
   
   if( clonep() )
     set_default_object(__FILE__);
   else {
                set("unit", "��");
     set("no_sell",1);
//     set("no_give",1);
     set("nogive_player",1);
     set("no_save",1);
     set("long","����һ�Ų�ҩ��������������ҩ�\n");
                set("value", 0);
				set("heal",([
					"heals":60,
					]));
           
   }
   setup();
   
}

