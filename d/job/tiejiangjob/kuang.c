#include <ansi.h>
// #include <job_money.h>
inherit ITEM;
mapping name=([
RED"������"NOR:"hongtie",
YEL"������"NOR:"chengtie",
HIY"������"NOR:"huangtie",
GRN"������"NOR:"lvtie",
HIC"������"NOR:"qingtie",
BLU"������"NOR:"lantie",
MAG"������"NOR:"zitie",
]);

void create()
{
   string *n;int i;
   string *w;
    
   n=keys(name);
   i=random(sizeof(n));
   set_name(n[i],({name[n[i]]}));
   set_weight(600);
   
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","һ������\n");     
     set("no_sell",1);
//     set("no_give",1);
     set("no_save",1);
     set("nogive_player",1);
     set("material", "iron");
     set("unit", "��");
     set("value", 0);
     set("weapon",([
		 "damage":10,
		 "strong":10,
		 ]));
           
   }
   setup();
   
}

