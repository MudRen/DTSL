
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
���������ݳǵĶ����̡�����ľ�ɫ�ͱ����̲�ͬ���ľ����ţ�����
�����������̲�������ż������һЩ���Ӽ���������ѱ�ͬ�Σ�һ������
��ϵľ���
LONG);

  set("exits", ([ 
 "southwest":__DIR__"donghudi2",
 "north":"/d/yangzhou/guangchang1",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

