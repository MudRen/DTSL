

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"��ʯ·"NOR);
  set ("long", @LONG
����������ʯ·��ͨ���ʹ������š��ſھ���ͣ�ż����󳵣�����
�μ����ϵĴ����������ġ�ƽʱ����䱸ɭ�ϣ��ٱ���������ͨ����
������ͣ���ġ�
LONG);

  set("exits", ([ 
  
  "northeast":__DIR__"westdoor",
  "south":__DIR__"xiangwangjie1",
         ]));

  
  set("valid_startroom", 1);
  setup();
 
}

