#include <ansi.h>
// #include <job_money.h>
inherit ITEM;
mapping name=([
RED"�컨"NOR:"honghua",
YEL"��Ƥ"NOR:"chenpi",
HIY"�˲�"NOR:"renshen",
GRN"����"NOR:"danggui",
HIC"ѩ��"NOR:"xuelian",
BLU"����"NOR:"shengdi",
MAG"������"NOR:"heshouwu",
]);

string *heals=({"��Ѫ","����","��Ѫ"});

void create()
{
   string *n;int i;
   string *w;
    
   n=keys(name);
   i=random(sizeof(n));
   set_name(n[i],({name[n[i]]}));
   set_weight(500);
   
   set("unit", "��");
   set("no_sell",1);
   set("nogive_player",1);
   set("no_save",1);
   set("long","����һ�Ų�ҩ��������������ҩ�\n");
   set("medicine_type",([
         "type" :heals[random(sizeof(heals))],
         "gongxiao" :10,
         ])); 
              
   setup();
   
}

string long()
{
  return query("long")+"\n"+"��������"+query("medicine_type/type")+"�Ĺ�Ч��\n";
}
