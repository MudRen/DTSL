
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
���������ȡ��������μұ��ı�����ȱ���鷿��������һ��С�š�
���ȵ�ǽ���Ͽ̻���һЩ�����ıڻ������෱�࣬��ɽˮ������ȡ���
�����㹤����������ʱ��һЩ�μұ����Ӵ�������ԴҴ��߹���
LONG);

  set("exits", ([ 

  "east":__DIR__"xilang1",
  "north":__DIR__"shufang",
  "southwest":__DIR__"xiaoqiao3",
       ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

