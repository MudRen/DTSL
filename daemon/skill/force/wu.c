
#include <ansi.h>

int exert(object me, object target)
{
	string str,arg;
	
	if(me->is_fighting())
	return notify_fail("ս���в�������������\n");
	
	if(me->is_busy())
	return notify_fail("����æ���أ�\n");
	
	if(target!=me)
	return notify_fail("��ֻ���Լ�����������\n");
	
	message_vision("$N������������ʼڤ˼����������\n",me);
        str=HIY+me->name()+HIY+"���������������ڤ˼����"NOR;
	me->set_temp("apply/short",({str}));
	arg="changsheng-jue";
        me->start_busy((:call_other,this_object(),"doing_lingwu",me,arg:),
                 (:call_other,this_object(),"halt",me:));
        return 1;
}

int doing_lingwu(object ob,string arg)
{
   int i;
   if(ob->query("potential")>=30)
   i=30;
   else i=ob->query("potential");
  
   ob->improve_skill(arg,(ob->query_int()/3+random(10))*i
                          );  
   if(ob->query("gin")>15)
   ob->receive_damage("gin",15);
   if(ob->query("potential")>30)
   ob->add("potential",-30);
   else ob->set("potential",0);
   if(ob->query("gin")<15||ob->query("potential")<=0){
   message_vision(HIY"$N"+HIY+"����ͷ��һ��ѣ�Σ���æվ��������\n"NOR,ob);
   ob->delete_temp("apply/short");
   ob->delete_temp("mark/lingwu");
   return 0;}
   else return 1;
}

int halt(object ob)
{
  message_vision("$N���������˿�����������վ��������\n",ob);
  ob->delete_temp("apply/short");
  ob->delete_temp("mark/lingwu");
  return 1;
}

	
