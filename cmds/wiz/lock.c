//written by yanyan.
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
     object ob;
     ob = me->query_temp("link_ob");
   if( !ob ) return 0;
   while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");
     tell_object(me,HIW"�ն˽�����ʱ�����������Լ��ĵ�¼���������նˡ�\n"+NOR+"");
 //    return 1;}
     input_to("unlock",1,ob);
     return 1;        
}
void unlock(string arg,object ob)
{
  string pass;int p;
  pass=ob->query("password");
  if(crypt(arg,pass)!=pass){
  tell_object(this_player(),"error password!\n");
  input_to("unlock",1,ob);
  return;}
  tell_object(this_player(),HIY"�ն˳ɹ��򿪣�\n"NOR);
  return;
}
