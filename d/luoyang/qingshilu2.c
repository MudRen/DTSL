
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"��ʯ·"NOR);
  set ("long", @LONG
����������ʯ·��ͨ���ʹ��Ķ��š��ſھ���ͣ�ż����󳵣�����
�μ����ϵĴ����������ġ�ƽʱ����䱸ɭ�ϣ��ٱ���������ͨ����
������ͣ���ġ�
LONG);

  set("exits", ([ 
  "northwest":__DIR__"eastdoor",
  "south":__DIR__"xiangwangjie3",
         ]));

  
  set("valid_startroom", 1);
  setup();
 
}

