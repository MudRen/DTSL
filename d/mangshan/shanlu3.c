
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
��������һ����᫲�ƽ��ɽ·�ϣ�ż������һ�����Ұ�޽�
����ͷ����һЩ��֪����С����������ȥ�����ܴ����ܲ����ʻ�
�̲��������֣�����ɽ���ﴵ����������磬����������������
��һЩ�����Ļ��㡣���ڽ����������ң����Լ���û���������
LONG);

  set("exits", ([ 

  "westdown":__DIR__"shanlu2",
 "eastup":__DIR__"shanlu4",
 "north":__DIR__"shulin1",
         ]));

  set("valid_startroom", 1);
  setup();
 
}

