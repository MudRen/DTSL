
#include <room.h>

inherit ROOM;

string look_gaoshi();
string *d=({"north","south","east"});
void create()
{
	set("short", "С����");
	set("long", @LONG
����һƬС���֡����Ѿ��Ҳ�����·�ˡ�
LONG
	);


	set("exits", ([
		"north" :__DIR__"youlin2",
		"south":__DIR__"youlin3",
		"west":__DIR__"youlin4",
		"east":__DIR__"youlin2",
	]));
       set("outdoors", "�ɶ�");
	setup();
}

int valid_leave(object me,string dir)
{
	int lev,lev2;
	lev=(int)me->query_skill("dodge",1);
	lev2=(int)me->query_skill("jiguanxue",1);
	message_vision("$N�������Ų���ͻȻ��֪��ʲô�ط�����һ֧����ֱ����$N��ü�ģ�\n",me);
	if(lev>=120&&lev2<120)
	{message_vision("$N��æһ�������˿�����\n",me);
		message_vision("$N����������ԭ�ش�ת��\n",me);
	    return ::valid_leave(me,d[random(sizeof(d))]);
	}
	else if(lev>=120&&lev2>=120)
	{message_vision("$N��æһ�������˿�����\n",me);
	  message_vision("$N�������µĵ��Σ����˷������˹�ȥ��\n",me);
       return ::valid_leave(me,d[random(sizeof(d))]);
	}
	else
	{
		message_vision("���ֱ������$N��$Nʹ�ؼ�����ȥ��\n",me);
		me->unconcious();
		return 0;
	}
}



