
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ƕ��ȡ��������μұ��������ˡ����ȵ�ǽ���Ͽ̻���һЩ��
���ıڻ�����ɽˮ������ȡ��������㹤����������ʱ��һЩ�μұ���
�Ӵ�������ԴҴ��߹���
LONG);

  set("exits", ([ 

  "west":__DIR__"zhengting",
  "east":__DIR__"donglang2",
       ]));
  set("objects",([
	  __DIR__"npc/songfaliang":1,
	  ]));
  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

