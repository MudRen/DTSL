
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������һƬ�ݵء��ݵ�ƽ̹��������ʮ���������������Ժ�ı���
�⣬������һ�����ȡ���ʱ�м�����Ժ���Ӵ���������߹�����������
�о�֮��������������ƴ�ң����֪��Զ��������������Ժ��
LONG);

  set("exits", ([ 
	  "west":__DIR__"bingqiku",
	  "eastup":__DIR__"changlang3",

         ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

