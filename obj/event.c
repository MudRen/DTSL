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
       users()->receive_message("event", HIY "\n【报时】 现在时间: " + CHINESE_D->chinese_newdate( time(), 1 ) + ".\n" + NOR + HIG"大唐双龙巫师组提醒您不要影响学习、休息、和工作！\n"+NOR);

}


mapping types=([
"sword":"剑类","hammer":"锤类","axe":"斧类","blade":"刀类",
"dagger":"匕首类","fork":"叉类","staff":"杖类","whip":"鞭类",
"spear":"枪类",
"cloth":"衣服","armor":"甲胄","head":"头盔","neck":"护颈",
"waist":"护腰","wrists":"护腕","shield":"盾牌","finger":"板指",
"hands":"护掌","boots":"靴子",
"food_supply":"食物","liquid":"饮用品","skill":"书籍",
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
   message("vision",HIM"【商会消息】:近期官府增加赋税，"+types[type]+"的价格提高了"+chinese_number(trade_value/100)+"成。\n"NOR,users());
   break;
   case 1:
   trade_value=-(100);
   if(trade_value==0)
   trade_value=-1;
   message("vision",HIM"【商会消息】:近期官府减免赋税，"+types[type]+"的价格都有所降低。\n"NOR,users());

   break;}
  return;
}
