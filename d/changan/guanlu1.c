
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
������һ����·�����߾��ǳ����Ķ����ˡ���������˺ܶ࣬�Ե�
��Щ���֡������������ɽ����������ս��ʱ�������ǳ����������
�з������Գ����Ե÷ǳ���������Ͷ�������Ҳ�Ǻܶࡣ����һ��
��·����֪����ͨ�����
LONG);

  set("exits", ([ 
"west":__DIR__"dongmen",
"east":__DIR__"guanlu2",
"north":__DIR__"dadao1",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

