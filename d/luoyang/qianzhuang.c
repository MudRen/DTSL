
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���Ǯׯ");
  set ("long", @LONG
����������������Ǯׯ��������������̫ƽ���������Ǯׯ������
һ��ܺá�Ǯׯ�ϰ�������������̣���ʱ�����۴����Ž����Ŀ��ˡ�
��̨���Ա߷���һ�������ӣ�����д�ţ������Ʊ��ȫ��ͨ�á�
LONG);

  set("exits", ([ 
 
  "west":__DIR__"yongdongjie2",
         ]));
  set("objects",([
	  __DIR__"npc/sun":1,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

