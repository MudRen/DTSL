//for dtsl.
#include <ansi.h>
#include <org.h>
inherit F_CLEAN_UP;


int main(object me, string arg)
{
   object ob;
   if(!arg) return notify_fail("������˭��ս��\n");
   if(!objectp(ob=present(arg,environment(me))))
    return notify_fail("����û������ˡ�\n");
   if(me->query("shili/name")!=ob->query("shili/name"))
    return notify_fail("����������ͬ������fight��!\n");
   if(!userp(ob)&&!ORG_D->is_leader(ob->query("shili_id")))
    return notify_fail(ob->name()+"ЦЦ���Ҳ������죬��������սʲô����\n");
   if(!userp(ob)&&ob->query("shili/leader"))
   {  me->set_temp("gage",ob);
      ob->set_temp("gage",me);
      message_vision("$NһЦ������Ȼ������ս����֮λ��ָ���ˣ���\n",ob);
      return (int)ob->accept_gage(me);
    }
    
    if(ob->query_temp("gage")==me)
    { message_vision("$Nһ��ȭ��ָ���ˣ�\n",me);
      me->set_temp("gage",ob);
      me->fight_ob(ob);
      return 1;
     }
    if(userp(ob)&&!ob->query("shili/leader"))
    return notify_fail("���������������죬�㻹��fight��!\n");
    me->set_temp("gage",ob);
    tell_object(ob,me->name()+"Ҫ������ս��������ܣ���ʹ��gage���\n");
    tell_object(me,"����"+ob->name()+"��ս����ȴ���Ӧ��\n");  
   return 1;
}
