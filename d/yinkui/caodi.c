
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������һƬ�ݵء�����ǳ��������Գ�������͵����ա���������
�ܶ��ʻ�������ɫ�����ޣ������ޱȣ�һ����֪���Ƕ������ݡ�������
���ߣ����������ɳ��ϱ߲����������ˡ�
LONG);
  set("exits",([
	  "southeast":__DIR__"houdian",
	  "north":__DIR__"xiaojing1",
	  ]));

  set("outdoors","yinkui");

  set("valid_startroom", 1);
  setup();
 
}

