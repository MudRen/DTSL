
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ݴ���");
  set ("long", @LONG
��������ݴ��������п�������һ�Ű����������Ϲ��Źع�����λ��
�Ա߷���������ɻ�ƿ�����ż�֧��ȸ�ᣬǽ��д�Ŵ���һ�����䡱
�����������Щ���ڽ����ϴ������ֽ�ϴ������,�ڳ��������������
�ݡ�
LONG);

  set("exits", ([ 
 
 "southdown":__DIR__"wuguan1",
        ]));
  set("objects",([
	  __DIR__"npc/gongsun":1,
	  ]));
set("valid_startroom", 1);
  setup();
 
}

