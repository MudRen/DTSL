#include <ansi.h>
// #include <job_money.h>
inherit ITEM;
mapping name=([
RED"金银花"NOR:"jinyinhua",
YEL"川乌"NOR:"chuanwu",
HIY"冰片"NOR:"bingpian",
GRN"天冬"NOR:"tiandong",
HIC"血竭"NOR:"xuejie",
BLU"大黄"NOR:"dahuang",
MAG"巴豆"NOR:"badou",
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
                set("unit", "颗");
     set("no_sell",1);
//     set("no_give",1);
     set("nogive_player",1);
     set("no_save",1);
     set("long","这是一颗草药，它能用来炼制药物。\n");
                set("value", 0);
				set("heal",([
					"heals":60,
					]));
           
   }
   setup();
   
}

