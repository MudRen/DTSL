
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ʯ��");
  set ("long", @LONG
������һ��ʯ�š�һ��СϪ������������������Ϫˮ���м�������
������ȥ���м������𱤵ĵ������е�վ���������죬����ˮ�е�����
��̸Ц��
LONG);

  set("exits", ([ 
  
	  "northeast":__DIR__"shilu",
	  "south":__DIR__"zhutang",
         ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
