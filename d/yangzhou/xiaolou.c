
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����¥��");
  set ("long", @LONG
���������ݵķ���¥�󣬾�˵��������������������̫���Ͼ�����
���������졣�ϱ���һ���ƾɵĿ�ջ����˵�������ǹ���ɭɭ��������
�˻�ȥ���
LONG);

  set("exits", ([ 
 "east":__DIR__"beidajie2",
 "up":"/d/wiz/wizroom",
  "south":__DIR__"hotel",
  "west":"/d/wiz/wizroom4",
        ]));
 
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(!wizardp(me)&&dir=="up")
		return notify_fail("��ֻ�е�һ�����ص�������ֹ�������ȥ!\n");
	return ::valid_leave(me,dir);
}

