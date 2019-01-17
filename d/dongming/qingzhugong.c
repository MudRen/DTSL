
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"���ƹ�"NOR);
	set("long", @LONG
������ǡ����ƹ����ˡ������Ƕ��������Ŷ������ס�ĵط�����
�ߵ�ǽ�Ϲ���һ��������������ԭ���ݳǵķ�⣬�������е����ݳǻ�
�Ƿǳ����������ߵ�ǽ�Ϲ���һ�����������ӵ����з���һ��������
��������һ����Ϊд���ʫ�ʡ�
LONG);
	set("exits", ([
		"north":__DIR__"dayuan",
		"enter":__DIR__"woshi",
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

void init()
{
	add_action("do_sao","sao");
}

int do_sao(string arg)
{
	object ob;
	ob=this_player();
	if(!ob->query_temp("popo_job2"))
		return notify_fail("��������æʲô��?\n");
	if((int)ob->query("sen",1)<8)
		return notify_fail("��̫���ˣ�ЪЪ��!\n");
	if(ob->is_busy())
		return notify_fail("����æ����?\n");
	if(!arg||arg!="��") return notify_fail("������ʲô?\n");
	else
	{ 
	
			ob->add_temp("count",1);
		
		ob->receive_damage("sen",random(8));
		ob->start_busy(1);
		message_vision("$N�����ɨ�����ƹ���.\n",ob);
		  if((int)ob->query_temp("count",1)>10+random(3))
		  { ob->delete_temp("popo_job");
		    ob->delete_temp("popo_job2");
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
	case 0:message_vision("$N���������е�ɨ�㣬��������ȸղŸɾ����ˡ�\n",ob);break;
	case 1:message_vision("$N���˲����������Լ���Ϊ�����ɳ���һ������\n",ob);break;
	case 2:message_vision("$N���������е�ɨ�㣬��������ȸղŸɾ����ˡ�\n",ob);break;
    }
	remove_call_out("return_job");
}                              