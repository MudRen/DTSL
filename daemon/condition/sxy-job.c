#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

mapping *sxy = ({ 
         ([ "sxy":"广场","where":"/d/changan/guangchang"]),   
         ([ "sxy":"南大街","where":"/d/changan/nanjie3"]),   
         ([ "sxy":"北大街","where":"/d/changan/beijie3"]),   
         ([ "sxy":"西广场","where":"/d/changan/xguangchang"]),   
         ([ "sxy":"东广场","where":"/d/changan/dguangchang"]),   
   
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
      tell_object(me, HIB "你的守卫长安任务时限到了，快回去报告吧\n" NOR );     
      me->delete("shoucheng_job/sxy");
      me->set("shoucheng_job/sxy-done",1);   
      return 0;
   }
   if( !living(me) ) {
      message("vision", me->name() + "大呼道：守城不利，天亡我大唐呀！！\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "忽然城里有人大呼，在" + sxy["sxy"] + "发现了敌人的踪迹！\n" NOR );
        ob = new("/u/chris/shoucheng/killer");
        ob->invocation(me,4);
        ob->move(sxywhere);
   }

   me->apply_condition("sxy-job", duration - 1);

   if( duration < 1 )
   {
      tell_object(me, HIB "你的守长安任务时限到了，快回去报告吧\n" NOR );
      me->delete("shoucheng_job/sxy");
      me->set("shoucheng_job/sxy-done",1);        
      return 0;
   }
   return CND_CONTINUE;
}
