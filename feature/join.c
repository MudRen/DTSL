
#include <dbase.h>

int do_join()
{
	object me,ob;string *killed_shili,shili,me_shili;
	
	me=this_player();
	ob=this_object();

	killed_shili=me->query("killed_shili");
	shili=ob->query("shili");
	me_shili=me->query("shili");
  if(shili==me_shili)
	  return notify_fail("�㲻���Ѿ���������?\n");
   if(me->query("king")) return notify_fail("���ǿɲ�����������ͷ�찡��\n");
	if(sizeof(killed_shili)>0)
		if(sizeof(killed_shili-({shili}))<sizeof(killed_shili))
		return notify_fail("��ɱ�������������ˣ��������?\n");
	message_vision("$NЦ��:��,��λ"+RANK_D->query_respect(me)+",�Ժ�����Ǳ�����������!\n",ob);
	me->set("shili",shili);
	me->set("guanzhi","����");
	log_file("shili/"+shili,sprintf("����.\n"));
	return 1;
}

int do_shengzhi()
{
	object me,ob;int score;
	me=this_player();ob=this_object();
    score=me->query("chaoting_score");
	if(me->query("shili")!=ob->query("shili"))
		return notify_fail("�㲻�����ǵ��ˣ�����ô�ܸ������٣�\n");
    if(score<30000) return notify_fail("�㻹����Ϊ��͢��Щ�����ɣ�\n");
	if(score<100000)
		if(me->query("guanzhi")=="shibing")
		{ message_vision("$NЦ�����ð���"+RANK_D->query_respect(me)+",�Ժ������Уξ�ˣ�\n",ob);
		  me->set("guanzhi","xiaowei");
		  return 1;
		}
		else if(me->query("guanzhi")=="xiaowei")
			 return notify_fail("�㻹����Ϊ��͢��Щ�����ɣ�\n");
	if(score<500000)
		if(me->query("guanzhi")=="shibing"||me->query("guanzhi")=="xiaowei")
		{
			message_vision("$NЦ�����ð���"+RANK_D->query_respect(me)+",�Ժ�����ǲν��ˣ�\n",ob);
			me->set("guanzhi","canjiang");
			return 1;
		}
		else if(me->query("guanzhi")=="canjiang")
			 return notify_fail("�㻹����Ϊ��͢��Щ�����ɣ�\n");
	if(score<900000)
		if(me->query("guanzhi")=="shibing"||me->query("guanzhi")=="xiaowei"
			||me->query("guanzhi")=="canjiang")
		{
			message_vision("$NЦ�����ð���"+RANK_D->query_respect(me)+",�Ժ�����ǹٲ��ˣ�\n",ob);
			me->set("guanzhi","guanchai");
			return 1;
		}
		else if(me->query("guanzhi")=="guanchai")
			 return notify_fail("�㻹����Ϊ��͢��Щ�����ɣ�\n");
	if(score<2000000)
		if(me->query("guanzhi")=="shibing"||me->query("guanzhi")=="xiaowei"
			||me->query("guanzhi")=="canjiang"
			||me->query("guanzhi")=="guanchai")
		{
			message_vision("$NЦ�����ð���"+RANK_D->query_respect(me)+",�Ժ�������佫�ˣ�\n",ob);
			me->set("guanzhi","wujiang");
			return 1;
		}
		else if(me->query("guanzhi")=="wujiang")
			 return notify_fail("�㻹����Ϊ��͢��Щ�����ɣ�\n");
    if(me->query("guanzhi")=="jiangjun")
		return notify_fail("���Ѿ������������ˣ����췴�𣡣�\n");
	message_vision("$NЦ�����ð���"+RANK_D->query_respect(me)+",�Ժ�����ǽ����ˣ�\n",ob);
			me->set("guanzhi","jiangjun");
			return 1;
}

int do_fenglu()
{
	object me,ob;object gold;
	me=this_player();
	ob=this_object();
	if(me->query("shili")!=ob->query("shili"))
		return notify_fail("�㲻�����ǵ��ˣ�����ô����ٺ»��\n");
	if(me->query("guanzhi")=="shibing")
		return notify_fail("���ź���ʿ����û��ٺ»�ġ�\n");
    if(time()-me->query("fenglu_time")<3600)
		return notify_fail("��һ���º�������ȡٺ»�ɣ�\n");
    gold=new("/clone/money/gold");
	if(me->query("guanzhi")=="xiaowei") gold->set_amount(5);
	else if(me->query("guanzhi")=="canjiang") gold->set_amount(15);
	else if(me->query("guanzhi")=="guanchai") gold->set_amount(35);
	else if(me->query("guanzhi")=="wujiang") gold->set_amount(60);
  	else if(me->query("guanzhi")=="jiangjun") gold->set_amount(100);
    else return notify_fail("��û���٣���ʲôٺ»��\n");
	me->set("fenglu_time",time());
	gold->move(me);
	tell_object(me,"���õ���ٺ»��\n");
	return 1;
}