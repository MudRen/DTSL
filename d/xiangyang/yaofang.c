#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ҩ��");
  set ("long", @LONG
����ҩʦ�����ҩ����������һ���ܴ����ҩ����һ��ҩʦ������
���Ÿ��ֵĵ�ҩ���Ա���һ��ҩ�����ŵ���ҩ�����洫����һ��Ũ��
��ҩ�㡣
LONG);

  set("exits", ([ 
 "west":__DIR__"yaoshigh",
       ]));
  set("objects",([
	  "/d/job/yishengjob/yisheng2":1,
	  "/d/job/yishengjob/ding":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

