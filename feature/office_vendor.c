
inherit NPC;

#include <dbase.h>
#include <ansi.h>


int do_buy(string what)
{
   string ob_file;
   object ob,me;
   int price;
   
   me=this_player();
   
   if(!what)
   return notify_fail("��Ҫ�ù�����һ�ʲô��\n");
   
   if( stringp(ob_file = query("vendor_goods/" + what)) ) {
     
     ob = new(ob_file);
     
     if(me->query("office_number")<ob->query("office_value"))
     return notify_fail("��Ĺ������������Զһ�"+ob->query("name")+"\n");
     
     if(!ob->move(me)) return 0;
  
     message_vision("$N��$n����һ�һ" + 
        ob->query("unit") + ob->query("name") + "��\n",
        me, this_object() );
     me->add("office_number",-ob->query("office_value"));
     me->save();
     return 1;
   }
   return notify_fail("û�������������Զһ���\n");
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

int do_list()
{
   mapping goods;
   string list, *name;
   int i;
   
   if( !mapp(goods = query("vendor_goods")) ) return 0;
   
   name = keys(goods);
   list = "����Զһ�������Щ������\n\n";
   for(i=0; i<sizeof(name); i++)  {
     list +=left(goods[name[i]]->query("name"),30);
     list +=left("("+name[i]+")",16);  
     list +=left("��Ҫ"+HIY+goods[name[i]]->query("office_value")+NOR"������",10);
    
      list +="\n";
      
        }
   write(list);
   return 1;   
}

void init()
{
   ::init();
   add_action("do_list","list");
   add_action("do_buy","duihuan");
  
}
