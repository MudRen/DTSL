
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
���������ݳǵĶ��š���������˽��������������Ե�����������
�Թ����ݶ෱������Ȼ��ս�ң�Ҳ�ڸǲ������ݵ��������ա������м�
���ٱ�,��������������ˡ�
LONG);

  set("exits", ([ 
"west":__DIR__"dongdajie3",
"east":"/d/job/sjbjob/gangkou",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

