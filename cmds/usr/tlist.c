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
    // if(!wizardp(me))return notify_fail("�����ڻ�����ʹ������ָ��.\n");
     if( !arg )
        return notify_fail("��Ҫ��˭�Ļ����б�? (tlist somebody)\n");
     if(!objectp(seller=present(arg,environment(me))))
        return notify_fail("����û�������.\n");  
      if(seller==me)name="��";
            else name=seller->name();
     if(!mapp(map = seller->query_temp("sellobj")))
           return notify_fail(name+"����ʲôҲ������.\n");
     if(sizeof(map)==0)
           return notify_fail(name+"����ʲôҲ������.\n");
          sellobname=keys(map);
      printf(name+"����Ϊ����һЩ�������:\n");
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
ָ���ʽ : tlist somebody
      �����鿴ĳ��(�����Լ�)�Ļ����б�.
HELP
    );
    return 1;
}
 
