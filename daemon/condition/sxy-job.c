#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

mapping *sxy = ({ 
         ([ "sxy":"�㳡","where":"/d/changan/guangchang"]),   
         ([ "sxy":"�ϴ��","where":"/d/changan/nanjie3"]),   
         ([ "sxy":"�����","where":"/d/changan/beijie3"]),   
         ([ "sxy":"���㳡","where":"/d/changan/xguangchang"]),   
         ([ "sxy":"���㳡","where":"/d/changan/dguangchang"]),   
   
                });
                
mapping query_sxy()
{
        return sxy[random(sizeof(sxy))];
}

int update_condition(object me, int duration)
{
        mapping sxy,sxywhere;
        object ob;
        sxy = this_object()->query_sxy();
        sxywhere = sxy["where"];
            
   if( duration < 1 )
   {
      tell_object(me, HIB "���������������ʱ�޵��ˣ����ȥ�����\n" NOR );     
      me->delete("shoucheng_job/sxy");
      me->set("shoucheng_job/sxy-done",1);   
      return 0;
   }
   if( !living(me) ) {
      message("vision", me->name() + "��������سǲ����������Ҵ���ѽ����\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "��Ȼ�������˴������" + sxy["sxy"] + "�����˵��˵��ټ���\n" NOR );
        ob = new("/u/chris/shoucheng/killer");
        ob->invocation(me,4);
        ob->move(sxywhere);
   }

   me->apply_condition("sxy-job", duration - 1);

   if( duration < 1 )
   {
      tell_object(me, HIB "����س�������ʱ�޵��ˣ����ȥ�����\n" NOR );
      me->delete("shoucheng_job/sxy");
      me->set("shoucheng_job/sxy-done",1);        
      return 0;
   }
   return CND_CONTINUE;
}
