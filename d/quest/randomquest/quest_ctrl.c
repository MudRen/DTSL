

inherit F_CLEAN_UP;
inherit F_DBASE;

#include <ansi.h>
#include "map.h"

void start_quest()
{
   string *where;
   int i;
   object ob;
   
   where=keys(map);
   i=random(sizeof(where));
   
   ob=new(__DIR__"man");
   ob->move(where[i]);
   
   message("vision",HIM"��ҥ�ԡ�ĳ�ˣ���˵������Я����һ��"+HIG+"����"+HIM+"������"+map[where[i]]+"��\n"NOR,users());
   return;
}