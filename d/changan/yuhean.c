

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�������ţ�ٿ�ػ�Ȼ���ʣ�һ����ģֻ�ж������ķ�֮һ��С����
�ó�����ǰ����ʵ�޻������˶���׳������ĸ��ܡ�����д��"�����"
��������ͦ�ε��֡�
LONG);

  set("exits", ([ 
 "south":__DIR__"xiaojing",
]));
  
  set("valid_startroom", 1);
  setup();
 
}
