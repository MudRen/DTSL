
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"��н��"NOR);
  set ("long", @LONG
������һ��Ĳ�н�̲�Ӧ�ó�������ֵ��Աߣ����������н����
�ڲ�ͬ�������ṩ���ǻ��׹�����ʹ�õ��ղ���Ȼ�߹�һЩ�����Ա�
���������
LONG);

  set("exits", ([ 
      "west":__DIR__"tianjie",
  ]));

  set("valid_startroom", 1);
  setup();
 
}

