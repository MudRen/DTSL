
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIY"�޹�"NOR);
  set ("long", @LONG
������������ʹ����޹��ˡ����������������ߵ�ǽ�Ϲ�������
���ֻ����������ɺ��̺��������Żʺ�Ŀ��Ĵ��������ɨ��һ��
��Ⱦ��ƽʱ�й�Ů�����
LONG);

  set("exits", ([ 
  
  
  "south":__DIR__"liangtai",

         ]));

  set("sleep_room",1);
  set("valid_startroom", 1);
  setup();
 
}

