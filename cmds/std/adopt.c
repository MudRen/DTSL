//for dtsl.
#include <ansi.h>

inherit F_CLEAN_UP;


int main(object me, string arg)
{
   object ob;
   if(!arg) return notify_fail("�������˭����������\n");
   if(!objectp(ob=present(arg,environment(me))))
    return notify_fail("����û������ˡ�\n");
   if(!userp(ob))
       return notify_fail("�㻹��������Ҽ��������ɣ�\n");
   if(!me->query("shili/leader"))
       return notify_fail("�㲻�����������죬Ъ�Űɣ�\n");
   if(ob->query("shili/leader"))
     return notify_fail("����һ�����������죬���Ҫ�𣿣�\n");
   if(me->query_temp("mark_join")!=ob->name())
    return notify_fail("����˲�û��Ҫ��������ǵ�������\n");
    ob->set_temp("mark_join",me->query("shili/name"));
   message_vision("$N��������$n�����Լ���������\n",me,ob);
   CHANNEL_D->do_channel(this_object(), "rumor",
	sprintf("%s��������%s�����Լ���������", me->name(),ob->name()));
   me->delete_temp("mark_join");
   tell_object(ob,HIG"\n��ȥ���������񴦴� "+HIY+"join"+HIG+" ����Ϳ�����ʽ�����ˣ�\n\n"NOR);
   return 1;
}
