
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"����"NOR);
	set("long", @LONG
���������֡���������������̡����������һ�����̵������
�м���������������ɻ
LONG);
	set("exits", ([	     		
		"east":__DIR__"wchanglang1",
		"southwest":__DIR__"zhulin2",
		"northwest":__DIR__"jiashan",				
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

void init()
{
	add_action("do_zhong","zhong");
}

int do_zhong(string arg)
{
	object ob;
	ob=this_player();
	if(!ob->query_temp("popo_job1"))
		return notify_fail("��������æʲô��?\n");
	if((int)ob->query("sen",1)<8)
		return notify_fail("��̫���ˣ�ЪЪ��!\n");
	if(ob->is_busy())
		return notify_fail("����æ����?\n");
	if(!arg||arg!="����") return notify_fail("������ʲô?\n");
	else
	{ 
	
			ob->add_temp("count",1);
		
		ob->receive_damage("sen",random(8));
		ob->start_busy(1);
		message_vision("$N���������������.\n",ob);
		  if((int)ob->query_temp("count",1)>10+random(3))
		  { ob->delete_temp("popo_job");
		    ob->delete_temp("popo_job1");
			ob->set_temp("popo_ok",1);
		    ob->delete_temp("count");
			printf("����Ի�ȥ������!\n");
			return 1;
		  }
		  call_out("return_job",1,ob);
		  return 1;
	}
	
}

void return_job(object ob)
{
	switch(random(3))
	{
	case 0:message_vision("$N���˲�ͷ�ϵĺ���������һ���������þ���ö��ˡ�\n",ob);break;
	case 1:message_vision("$N���˲�ͷ�ϵĺ�������Ϊ���������ľ�ɫ������ס�ˡ�\n",ob);break;
	case 2:message_vision("$N���˲�ͷ�ϵĺ��������Լ���Ϊ����������һ�����¡�\n",ob);break;
	}

	remove_call_out("return_job");
}




