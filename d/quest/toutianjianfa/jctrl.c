
#include <ansi.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

object member;
int i=0;

void create()
{

  
}

int is_full()
{
  if(objectp(member))
  return 1;
  return 0;
}

int if_join(object ob)
{
  if(!objectp(member))
  return 0;
  if(ob==member)
  return 1;
  return 0;
}

void add_member(object ob)
{
   member=ob;
   remove_call_out("check_mem");
   call_out("check_mem",30);
}

void check_mem()
{
   if(!objectp(member)){
     member=0;
     remove_call_out("check_mem");
     return;
   }
   i++;
   if(i==60){
     tell_object(member,HIW"\n�������̫���������Ķ����ɢ�ˣ�\n"NOR);
     i=0;
     member=0;
     return;
   }
   call_out("check_mem",30);
}