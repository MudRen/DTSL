// event.c
// author: lanxin@jianghu
//add trade system by Yanyan@dtsl
#include <ansi.h>


inherit F_CLEAN_UP;


nosave int trade_value=0;

string trade_type="";

int get_value()
{
   return trade_value;
}

string get_type()
{
   return trade_type;
}

int get_trade_value(object ob,int i)
{
	if(ob->query("skill_type")&&
        ob->query("skill_type")==get_type())
         i=i+i*get_value()/100;
     else
     if(ob->query("armor_type")&&
        ob->query("armor_type")==get_type())
         i=i+i*get_value()/100;
     else
     if(ob->query("food_supply")&&
        get_type()=="food_supply")
        i=i+i*get_value()/100;
     else
     if(ob->query("liquid")&&
        get_type()=="liquid")
        i=i+i*get_value()/100;
     else
     if(ob->query("skill")&&
        get_type()=="skill")
        i=i+i*get_value()/100;
     else return i;

     return i;
}

int if_event_goods(object ob)
{
    if(ob->query("skill_type")&&
        ob->query("skill_type")==get_type())
         return 1;
     else
     if(ob->query("armor_type")&&
        ob->query("armor_type")==get_type())
         return 1;
     else
     if(ob->query("food_supply")&&
        get_type()=="food_supply")
        return 1;
     else
     if(ob->query("liquid")&&
        get_type()=="liquid")
       return 1;
     else
     if(ob->query("skill")&&
        get_type()=="skill")
        return 1;
     else return 0;

}

void time_report() {
	seteuid( getuid() );
//        reclaim_objects();
       remove_call_out("trade_system");
       call_out("trade_system",15);
       users()->receive_message("event", HIY "\n����ʱ�� ����ʱ��: " + CHINESE_D->chinese_newdate( time(), 1 ) + ".\n" + NOR + HIG"����˫����ʦ����������ҪӰ��ѧϰ����Ϣ���͹�����\n"+NOR);

}


mapping types=([
"sword":"����","hammer":"����","axe":"����","blade":"����",
"dagger":"ذ����","fork":"����","staff":"����","whip":"����",
"spear":"ǹ��",
"cloth":"�·�","armor":"����","head":"ͷ��","neck":"����",
"waist":"����","wrists":"����","shield":"����","finger":"��ָ",
"hands":"����","boots":"ѥ��",
"food_supply":"ʳ��","liquid":"����Ʒ","skill":"�鼮",
]);


void trade_system()
{

   string *all_type;
   string type;
   int i;

   all_type=keys(types);
   i=random(sizeof(all_type));

   type=all_type[i];
   trade_type=type;

   switch(random(2)){

   case 0:
   trade_value=100+random(500);
   if(trade_value==0)
   trade_value=1;
   message("vision",HIM"���̻���Ϣ��:���ڹٸ����Ӹ�˰��"+types[type]+"�ļ۸������"+chinese_number(trade_value/100)+"�ɡ�\n"NOR,users());
   break;
   case 1:
   trade_value=-(100);
   if(trade_value==0)
   trade_value=-1;
   message("vision",HIM"���̻���Ϣ��:���ڹٸ����⸳˰��"+types[type]+"�ļ۸��������͡�\n"NOR,users());

   break;}
  return;
}
