
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��԰");
  set ("long", @LONG
������һ����԰��԰�����˸��ֻ��ݣ�����ʤ�ա�����Ļ���Ʒ��
���Ǻܶ࣬�������˺ܶ�����ҩ�ġ����ֻ�����ͷף�ɫ����������
��������Ŀ����԰��Χ�˻������أ��ض��ǳ��Գɶ���������֮�֡�
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"zhutang",
	  "southeast":__DIR__"xiaojing1",
      ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
