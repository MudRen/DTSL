
inherit ROOM;
#include <ansi.h>
int do_enter(string arg);
void create()
{
	set("short", GRN"��ɽ"NOR);
	set("long", @LONG
�����Ǽ�ɽ����ɽ���������͵��֣������ޱȡ��㿴�˿�����ɽ��
������һ������
LONG);
	set("exits", ([
		"southeast":__DIR__"zhulin",
			]));
      set("objects",([
		  __DIR__"npc/shanyudie":1,
		  ]));
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

void init()
{
	add_action("do_enter","zuan");
}

int do_enter(string arg)
{
  object me;
  me=this_player();
  if(!arg||(arg!="��"&&arg!="hole"))
	  return notify_fail("��Ҫ��ʲô��\n");
  if(present("shan yudie",environment(me)))
	  return notify_fail("�������ס���㣬ι����ʲô�أ�\n");
  message_vision("$N����ɽ�Ķ������˽�ȥ��\n",me);
  me->move(__DIR__"hole");
  return 1;
}

