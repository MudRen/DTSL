
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·�������Ӻ��������ߡ����������һ�����ӡ�����
����û��ʲô�ˣ�һƬ������ɪ�����ա������Ӳݴ�����ֻ�м�ֻҰ��
��ʱ����Ľ�ǰ�ܹ���
LONG);

  set("exits",([
	  "eastdown":__DIR__"xiaolu2",
	  "west":__DIR__"cundong",
	  ]));
  set("outdoors","yinkui");
  set("valid_startroom", 1);
  setup();
 
}

