
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIY"�޹�"NOR);
  set ("long", @LONG
������������ʹ����޹��ˡ����������������ߵ�ǽ�Ϲ�������
���ֻ����������ɺ��̺��������Ż��ϵĿ��Ĵ�������������϶�
�˺ܶ�󳼵����ۣ����ǿ������ܾ�û�����ˣ��Ѿ�����һ��ҳ���
LONG);

  set("exits", ([ 
  "south":__DIR__"yuhuayuan",

         ]));
  set("objects",([
	  __DIR__"npc/yangguang":1,
	  ]));
  set("sleep_room",1);
  set("valid_startroom", 1);
  setup();
 
}

