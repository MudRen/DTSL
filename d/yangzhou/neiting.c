
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
���������ݳǵ��ܹܸ���������ƽʱξ��ʤ�����ﴦ��������
�������ң������Ѿ���ͬ���衣ƽʱ���Ǻ����������������������
������һ�Ŵ��ң�����д�ţ�����Т�� �ĸ����֡�
LONG);

  set("exits", ([ 
 "out":__DIR__"zongguanfu",
 "enter":"/d/clone/room/cityroom/yangzhou",
        ]));
  set("objects",([
	  __DIR__"npc/weichisheng":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

