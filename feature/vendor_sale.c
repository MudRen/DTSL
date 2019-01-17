
#include <dbase.h>
#include <ansi.h>

inherit NPC;

#define EVENT_D "/obj/event.c"

int price_ratio=10;

int is_vendor()
{
  return 1;
}

int buy_object(object me, string what)
{
   string ob;object vendor;int i;

   if( stringp(ob = query("vendor_goods/" + what)) ){
     vendor=new(ob);
     i=ob->query("value");
     destruct(vendor);
     return i;}
   else
     return 0;
}

int complete_trade(object me, string what)
{
   string ob_file;
   object ob;
   int price;

   if( stringp(ob_file = query("vendor_goods/" + what)) ) {
       int sale_price=price_ratio;

     ob = new(ob_file);
     if(!ob->move(me)) return 0;

     message_vision("$N��$n����һ" + 
        ob->query("unit") + ob->query("name") + "��\n",
        me, this_object() ); 
     if(me->query_skill("trade",1)<300)
     	me->improve_skill("trade",random(me->query("kar")*2));
     return 1;
   }
   return notify_fail("û��������������\n");
}

// price is the original price.
// paid is what the buyer paid.

string price_string(int v)
{
    string str="";
    int val;
    
    val=v/10000;
    if(val) str+=chinese_number(val) + "���ƽ�";
    val=(v%10000)/100;
    if(val) str+=chinese_number(val) + "������";
    val=(v%100);
    if(val) str+=chinese_number(val)  + "��Ǯ";
    
    if(str=="") str="����Ǯ";

     return str;
}

string no_color(string arg)
{
        arg = replace_string(arg,  BLK, "");
	arg = replace_string(arg,  RED, "");
	arg = replace_string(arg,  GRN, "");
	arg = replace_string(arg,  YEL, "");
	arg = replace_string(arg,  BLU, "");
	arg = replace_string(arg,  MAG, "");
	arg = replace_string(arg,  CYN, "");
	arg = replace_string(arg,  WHT, "");
	arg = replace_string(arg,  HIR, "");
	arg = replace_string(arg,  HIG, "");
	arg = replace_string(arg,  HIY, "");
	arg = replace_string(arg,  HIB, "");
	arg = replace_string(arg,  HIM, "");
	arg = replace_string(arg,  HIC, "");
	arg = replace_string(arg,  HIW, "");
	arg = replace_string(arg,  NOR, "");
	arg = replace_string(arg,  BLINK, "");
	return arg;
}

string left(string str,int long)
{
	int space,len,i;
	string s,oldstr;
	s="";oldstr=str;
	str=no_color(str);
	len=strlen(str);
	space=(long-len);
	for(i=0;i<space;i++) s+=" ";
	return sprintf("%s%s",oldstr,s);
}  

int do_vendor_list(string arg)
{
   mapping goods;
   string list, *name;
   int i;
   
   if( !mapp(goods = query("vendor_goods")) ) return 0;
   if( arg && !this_object()->id(arg) ) return 0;
   name = keys(goods);
   list = "����Թ���������Щ������\n";
   for(i=0; i<sizeof(name); i++)  {
     list +=left(goods[name[i]]->query("name"),30);
     list +=left("("+name[i]+")",16);  
     list +=left(
        price_string(goods[name[i]]->query("value")
          *price_ratio/10 ),10);
    if(EVENT_D->if_event_goods(goods[name[i]])){
    	if(EVENT_D->get_value()>0)
    	   list +=" "+"�۸񸡶� "+    	         	   
    	   EVENT_D->get_value()+"%";
    	else
    	   list +=" "+"�۸񸡶� "+    	     
    	   EVENT_D->get_value()+"%";}
      list +="\n";
      
        }
   write(list);
   return 1;   
}

void init()
{
    ::init();
   
}

void reload(string filename)
{
	
}



