
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ӻ���");
  set ("long", @LONG
�����ǳ������ӻ��̣�������������������г��õ������Ʒ��
�ϰ�վ�ڹ�̨���棬��һ˫С�۾����´������㣬ͨ������Ŀ����Կ�
�����ó����̡��Աߵ�С���������������к���
LONG);

  set("exits", ([ 
 "west":__DIR__"dongshidongjie5",
       ]));
  set("objects",([
	  __DIR__"npc/xiaoer4":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

