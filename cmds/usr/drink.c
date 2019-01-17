

inherit F_CLEAN_UP;
#include <poison.h>
int do_drink(object me,object ob);
int main(object me, string arg)
{
   object where;object ob;
   where=environment(me);
   if(me->is_fighting())
	   return notify_fail("�㻹���ȴ����̰ɣ�\n");
   if(!arg){
   if(!where->query("resource/water"))
     return notify_fail("��ط�û��ˮ�ɺȣ�\n");
   if(me->query("water")>=me->max_water_capacity())
	   return notify_fail("��ȵ�̫���ˣ��Ѿ��Ȳ����ˣ�\n");
   if(me->is_busy())
	   return notify_fail("����æ���أ�\n");
   message_vision("$N���˼���ˮ�����úö��ˡ�\n",me);
   me->add("water",me->query_con()*2);
   POISON_D->apply_poison(me,where);
   me->start_busy(1);
   }
   else {
   	if(me->query("water")>=me->max_water_capacity())
	   return notify_fail("��ȵ�̫���ˣ��Ѿ��Ȳ����ˣ�\n");
	   if(!objectp(ob=present(arg,me)))
		   return notify_fail("������û�����ֶ�����\n");
	   if(!ob->query("liquid"))
	   return notify_fail("���ֶ������ܺ�ˮ��\n");
	   me->start_busy(1);
	   return (int)do_drink(me,ob);
	   
   }
   return 1;
}
int do_drink(object me,object ob)
{
	int remain,avai;	
        if(ob->query("liquid/remaining")<=0 )
                return notify_fail( ob->name() + (ob->query("liquid/name") ? 
"�Ѿ����ȵ�һ��Ҳ��ʣ�ˡ�\n":"�ǿյġ�\n"));
	remain =(int)ob->query("liquid/remaining") * 30;
	avai = me->max_water_capacity() - me->query("water");
	if( remain > avai )
	{
	me->add("water", avai);	
	ob->add("liquid/remaining", -(avai/30));
	}
	else
	{
	me->add("water",remain);
	ob->set("liquid/remaining", 0);
	}
        message_vision("$N����" + ob->name() + "������غ��˼���" + 
ob->query("liquid/name")
                + "��\n", me);
       if( !ob->query("liquid/remaining") )
                write("���Ѿ���" + ob->name() + "���" + ob->query("liquid/name")
                        + "�ȵ�һ��Ҳ��ʣ�ˡ�\n");

        // This allows customization of drinking effect.
        if( ob->query("liquid/drink_func") ) return 1;
        POISON_D->apply_poison(me,ob);
        switch(ob->query("liquid/type")) {
                case "alcohol":
                        me->apply_condition("drunk",
                                me->query_condition("drunk") 
                                + (int)ob->query("liquid/drunk_apply"));
                        break;
        }
        
        return 1;
}