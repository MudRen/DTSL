
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����¥");
  set ("long", @LONG
���������˹�����Է���鷿��ֻ�����е������Ǿ���ż�
�ѻ���ɽ��ǽ�Ϲ��������ֻ���������һ����ɫ���������Ա߼�
�����ӡ�������һ�Ž�β���٣���Է�򸾳���������ʫ���٣���
����⡣
LONG);

  set("exits", ([ 
 "west":__DIR__"xsl",
      ]));
 set("valid_startroom", 1);
  setup();
 
}

