
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�ʷ�");
  set ("long", @LONG
�������μұ����ʷ��������μұ���һ����������μұ���ȫ��
�������⣬����ÿ��Ҫ�ɺܶ���μұ�����ȥȫ�����ز��ˣ��кܶ���
�ұ����Ӳ�ͣ��������������Ե�����ǳ����֡�
LONG);

  set("exits", ([ 

  "east":__DIR__"qingshilu2",
      ]));
  set("objects",([
	  __DIR__"npc/zhao":1,
	  ]));
 set("no_fight",1); set("no_exert",1);

  set("valid_startroom", 1);
 
  setup();
 
}

