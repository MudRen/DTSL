
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ�����������������˺ܶ��㣬�������������ڵ�������ȥ��
���������������Ǹ��˼��ɾ��������������ɱ�������ס�������治ʱ��
��Ů�ӵĻ�Ц��������
LONG);
  set("exits",([
	  "southwest":__DIR__"qingshilu5",
	  "northeast":__DIR__"mishi",
	  ]));

  set("objects",([
	  __DIR__"npc/dizi3":1,
	  ]));
  set("valid_startroom", 1);
  set("outdoors","yinkui");

  setup();
 
}
