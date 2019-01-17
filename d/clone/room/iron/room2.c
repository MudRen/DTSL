#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","Ͽ��");
  set ("long", @LONG
ӳ����������һƬ��ʯ��������ֱ̬����̾Ϊ��ֹ���������ڹ���
�ı�����ӳ���������߲ʣ���ʱ�������ĺ����ڻ�����ƫƫ���裬���
��Щ�����С�����ʯ����̽��ͷ������Ŀ����㣬΢�����촵������
���Ŀ��������ޱ��泩��
LONG);
  
  set("exits",([
   "up":"/d/changan/shanyao",
   ]));
  set("no_fight",1);
  set("no_exert",1);
  
  setup();

}

void init()
{
	add_action("do_search","search");
}

int do_search()
{
	object me,ob;
	
	me=this_player();
		
	if(me->is_busy())
                return notify_fail("�������Ĵ������أ�\n");
	if(me->is_fighting())
		return notify_fail("�㻹���ȴ�������˵�ɣ�\n");
	if(me->query("vocation")!="����")
		return notify_fail("��ʲôҲ�Ҳ�����\n");
	if(me->query_skill("duanzao-jishu",1)<60)
		return notify_fail("��ʲôҲ�Ҳ�����\n");
	if(time()-query("no_kaicai")<60*30)
		return notify_fail("��ʲôҲû�ҵ���\n");
	message_vision("$N�����ܵĲݴ���������ȥ��\n",me);
	me->start_busy(3);
	me->receive_damage("sen",50+random(5));
		
	set("no_kaicai",time());
	
        if(random(100)<80){
	 message_vision("$NʲôҲû�ҵ���\n",me);
	 return 1;
	}
	
	ob=new(__DIR__"obj/tiekuang2");
	if(!ob->move(me)){
	  ob->move(environment(me));
	  tell_object(me,"�㸺�ع����ˣ�\n");
	}
	message_vision("$N�۾�һ�����ڲݴ��з���һ�鲻ͬѰ����ʯͷ��$N���Ͽ���\n"+
	               "����һ����������ϵȱ�������ʯ����æ����������\n",me);
		
	return 1;
}
