
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ʯ·");
  set ("long", @LONG
�����Ǿ�����Ժ��ʯ·�������߾�����Ժ�Ľ����ˡ��м���������
�����ػ������������о�֮��������������ƴ�ң����֪��Զ��������
������Ժ��
LONG);

  set("exits", ([ 
	  "east":__DIR__"houmen",
	  "west":__DIR__"shilu4",
  
         ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(dir=="east"&&objectp(present("bu pen",environment(me)))&&objectp(present("bu tan",environment(me)))&&!wizardp(me))
		return notify_fail("ֻ��һ������������˵����ʩ��������!\n");
	return ::valid_leave(me,dir);
}
