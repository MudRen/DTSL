
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����Ǿ�����Ժ���������﹩����һ������������ͭ������
��ëʨ�����ߴ����������ܽ��Σ��������ǡ��м���ɮ�������̾���
��
LONG);

  set("exits", ([ 
	  "westdown":__DIR__"shijie1",
	  "eastup":__DIR__"shijie2",
  
         ]));
  
  set("objects",([
     __DIR__"npc/buchi":1,
     ]));

  set("valid_startroom", 1);
  setup();
 
}
