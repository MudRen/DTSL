//for dtsl.
#include <ansi.h>
#include <org.h>
inherit F_CLEAN_UP;


int main(object me, string arg)
{
   object ob;
   
   if(!arg) return notify_fail("�������˭��������\n");
   if(!objectp(ob=present(arg,environment(me))))
    return notify_fail("����û������ˡ�\n");
   if(me->query("shili")&&ob->query("shili")&&
      me->query("shili/name")==ob->query("shili/name"))
   return notify_fail("�����Ѿ���һ���������ˣ�\n");
   if(me->query("shili"))
   return notify_fail("�����Ҫ�����µİ������˳�ԭ���İ�ᣡ\n");
   if(!userp(ob)&&!ORG_D->is_leader(ob->query("shili_id")))
    return notify_fail(ob->name()+"ЦЦ���Ҳ������죬�����˵û�õġ�\n");
   if(!userp(ob))
     if(!ob->accept_enroll(me))
       return ob->accept_enroll(me);
       //return notify_fail(ob->name()+"���������������������\n");
     else return 1;
   if(!ob->query("shili/leader"))
     return notify_fail("���������������죬�����˵û�õģ�\n");
   ob->set_temp("mark_join",me->name());
   tell_object(ob,HIY+me->name()+"��������ǵ����������Ը��Ļ������� adopt �������ļ���\n"NOR);
   tell_object(me,HIY"�������"+ob->name()+"����������ȴ����Ļ�Ӧ\n"NOR);
   return 1;
}
