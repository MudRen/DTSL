
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ�㳡");
  set ("long", @LONG
��ʯ�㳡���д�������һ������������ͭ�����ڽ�ëʨ�����ߴ�
���������Ի���ҩʦ�����Ⱥ����ӵ������𡣲��ܽ��Σ��������ǣ�
�������˾����е㲻��һ����Ժ������
LONG);

  set("exits", ([ 
	  "eastup":__DIR__"shijie1",
	  "west":__DIR__"shilu2",
          "southdown":__DIR__"zhulin",
         ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

