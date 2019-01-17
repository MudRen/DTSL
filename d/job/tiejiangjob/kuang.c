#include <ansi.h>
// #include <job_money.h>
inherit ITEM;
mapping name=([
RED"ºìÌú¿ó"NOR:"hongtie",
YEL"³ÈÌú¿ó"NOR:"chengtie",
HIY"»ÆÌú¿ó"NOR:"huangtie",
GRN"ÂÌÌú¿ó"NOR:"lvtie",
HIC"ÇàÌú¿ó"NOR:"qingtie",
BLU"À¶Ìú¿ó"NOR:"lantie",
MAG"×ÏÌú¿ó"NOR:"zitie",
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
     set("long","Ò»¿éÌú¿ó¡£\n");     
     set("no_sell",1);
//     set("no_give",1);
     set("no_save",1);
     set("nogive_player",1);
     set("material", "iron");
     set("unit", "¿é");
     set("value", 0);
     set("weapon",([
		 "damage":10,
		 "strong":10,
		 ]));
           
   }
   setup();
   
}

