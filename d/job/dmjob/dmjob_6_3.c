/*
 * File    : ����ɽ (/u/yanyan/dmjob/dmjob_6_3.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
int do_cai(string arg);
void create()
{
	set("short", "����ɽ");
        set("long", @LONG
����������ɽ�ı���ɽ����˵���������ǳ��ã����Զ����ɵĵ�
�ӿ��Դ�����ǳ��ı��������������Ҫ��ɽ������������Ҳ�Ǵ�ݲ�
����
LONG
);
        set("exits",([
	"northeast" : __DIR__"dmjob_4_5",
	"southwest" : __DIR__"dmjob_8_1",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
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
	if(me->query("family/family_name")!="������")
	return notify_fail("ֻ�ж����ɵĵ��ӿ��������￪�ɿ�ʯ��\n");
	if(me->query("combat_exp")<200000)
	return notify_fail("����������������ʸ������￪�ɡ�\n");
	message_vision("$N��"+tool->name()+"�������ʯ����\n",me);
	me->receive_damage("sen",100+random(50));
	me->start_busy(3);
	if(random(9)>2)
	{ob=new("/obj/iron/iron");
	ob->move(me);
	message_vision("$N���ɳ�һ��"+ob->name()+"����\n",me);
	}
	else
	{
		message_vision("ͻȻһ����ʯ��ɽ�Ϲ���������\nֱ������$N!\n",me);
		if((int)me->query_skill("dodge",1)>=100&&random(100)>20)
		{
			message_vision("$N���Ʋ��ã���æ���˿�����\n",me);
            ob=new("/obj/iron/iron");
	        ob->move(me);
			return 1;
		}
		else
		{
			message_vision("$N����ʯ�������У�\n",me);
            ob=new("/obj/iron/iron");
	        ob->move(me);
			me->unconcious();
			return 1;
		}
	}
	return 1;
}