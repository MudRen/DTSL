
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ƕ��ȡ�������һ����ʯ·�����ȵ�ǽ���Ͽ̻���һЩ������
�ڻ������෱�࣬��ɽˮ������ȡ��������㹤����������ʱ��һЩ��
�ұ����Ӵ�������ԴҴ��߹���
LONG);

  set("exits", ([ 

  "west":__DIR__"donglang2",
  "north":__DIR__"qingshilu1",
       ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

