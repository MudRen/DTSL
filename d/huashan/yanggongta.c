
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
��������һ���������������棬�������㡣վ�����ϣ����Կ�����
ɽ�����ķ�⡣������������˵��ּ�����Ϊ���̻�ɽ֮�ʡ����ܾ�ɫ
�����дУ��������У����˲��ɵú���������
LONG);

  set("exits", ([ 
 "southup":__DIR__"yunvfeng",
 "northwest":__DIR__"xianzhangya",
       ]));
       /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
  set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
