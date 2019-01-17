#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","��ɽ");
  set ("long", @LONG
������һ����ɽ����˵����ʢ���ܶ�õĿ�ʯ�������������
�￪�ɿ�ʯ���������������Ҫ���ǳ�Σ�ա���ˣ����ﾭ�����ֿ�ʯ
�����󹤵��¼���
LONG);

  set("exits",([
    "south":"/d/wuyishan/shulin3",
   ]));
  set("no_fight",1);
  set("no_exert",1);
  
  setup();

}

void init()
{
	add_action("do_cai","kaicai");
}

int do_cai(string arg)
{
	object me,ob,tool;
	
	me=this_player();
	
	if(!arg||arg!="��ʯ")
		return notify_fail("���뿪��ʲô��\n");
	if(!objectp(tool=me->query_temp("weapon")))
		return notify_fail("������ô���ɿ�ʯ��\n");
	if(tool->query("skill_type")!="fork")
		return notify_fail("�㻹���ø�ͷ���ɰɣ�\n");
	if(me->is_busy())
		return notify_fail("�����ں�æ��ЪЪ��!\n");
	if(me->is_fighting())
		return notify_fail("�㻹���ȴ�������˵�ɣ�\n");
	if(time()-query("no_kaicai")<60*30)
		return notify_fail("��������û�п�ʯ����Ȼ������ɣ�\n");
	message_vision("$N��"+tool->name()+"�������ʯ����\n",me);
	me->start_busy(3);
	me->receive_damage("sen",50+random(5));
	
	if(me->query_skill("dodge",1)<120){
	  message_vision("$N����ʯ�������У�\n",me);
	  me->unconcious();
	}
	
	set("no_kaicai",time());
	
	if(random(100)<95){
	 message_vision("$NʲôҲû���ɵ���\n",me);
	 return 1;
	}
	
	ob=new(__DIR__"obj/tiekuang1");
	if(!ob->move(me)){
	  ob->move(environment(me));
	  tell_object(me,"�㸺�ع����ˣ�\n");
	}
	message_vision("$N���ɳ�һ��"+ob->name()+"����\n",me);
		
	return 1;
}
