
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ʯ·");
  set ("long", @LONG
�����Ǿ�����Ժ��ʯ·��ǰ����Ǿ�����Ժ�İ�ʯ�㳡�ˡ�������
Ժ���������ﶼ�����������������ŵ��������ϣ���ͭ��Ϊ��Ժ�����ģ�
��ģ������һ��
LONG);

  set("exits", ([ 
	  "west":__DIR__"shilu1",
	  "east":__DIR__"baishiguangchang",
          "northup":__DIR__"muwu",
         ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

