
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����¥");
  set ("long", @LONG
���������ݳǵ�������¥--����¥������Ĺ��ﶼ�����ݱ��µ�
Ů�ӡ����������Ľ������ͣ������������¥������û�������Ĺ����
�ݳǡ�����������ң�����Ҳ��һ�������ӱ���ʵ�����Լ��ĺõط���
LONG);

  set("exits", ([ 
 "west":__DIR__"nandajie1",
       ]));
  set("objects",([
	  __DIR__"npc/girl":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

