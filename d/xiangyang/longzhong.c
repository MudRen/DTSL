
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","¡��");
  set ("long", @LONG
���������ʱ����������������֮�������յ���Դ֮����ϡ�ɼ���
������ľïʢ��Զ�������ķ羰ӳ���������������ܴ����ܲ����ʻ��̲�
�������֣���ʱ����������ͷ�Ϸɹ���
LONG);

  set("exits", ([ 
  "southwest":__DIR__"shulin1",
         ]));

  set("valid_startroom", 1);
  set("outdoors","xiangyang");
  setup();
 
}

