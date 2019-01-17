//price.c
//create by zanlin
//1999.8.2
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object seller, sobj;
       string *sellobname,*obname,name;
      mapping map,item_map;

     int i;  
    // if(!wizardp(me))return notify_fail("你现在还不能使用这条指令.\n");
     if( !arg )
        return notify_fail("你要看谁的货物列表啊? (tlist somebody)\n");
     if(!objectp(seller=present(arg,environment(me))))
        return notify_fail("这里没有这个人.\n");  
      if(seller==me)name="你";
            else name=seller->name();
     if(!mapp(map = seller->query_temp("sellobj")))
           return notify_fail(name+"现在什么也不想卖.\n");
     if(sizeof(map)==0)
           return notify_fail(name+"现在什么也不想卖.\n");
          sellobname=keys(map);
      printf(name+"现在为以下一些东西标价:\n");
      for(i=0;i<sizeof(map);i++)
         {   item_map=map[sellobname[i]];
             obname=keys(item_map);
             printf("%s(%s)  :  %s \n",
                       (string)obname[0],
                       sellobname[i],
                       MONEY_D->price_str(item_map[obname[0]]));
          }
       return 1;

}
int help(object me)
{
  write(@HELP
指令格式 : tlist somebody
      用来查看某人(包括自己)的货物列表.
HELP
    );
    return 1;
}
 
