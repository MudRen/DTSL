
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
���������ݳǵĶ����.����Ƚ��徻.���������ݵ�һ����Ժ����
������������������ʵĶ���������Ժ�����������������İ��Ϸ��ӣ�
��Ȼս�����꣬���ǻ��кܶ������Լ��ĺ�����������顣�ϱ�������
������ͤ������ɾ���������ֵ���Ե��
LONG);

  set("exits", ([ 
 "east":__DIR__"dongdajie3",
 "southwest":__DIR__"dongdajie1",
 "north":__DIR__"shuyuan",
 "south":__DIR__"yuelaoting",
        ]));
  set("objects",([
	  __DIR__"npc/boy":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

