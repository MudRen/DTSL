
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"ʯ��"NOR);
  set ("long", @LONG
������ʯ�ס��������ߣ��Ϳ��Ե��ʹ������Ͻ���ˡ����ʹ��μ�
���ϵĴ��Ƕ�Ҫ�������ʯ��ʮ�ֿ������վ�������Ĺٱ���ƽ
ʱ����û�������
LONG);

  set("exits", ([ 
  
  "enter":__DIR__"zijindian",
  "down":__DIR__"guangchang4",
         ]));
  set("objects",([
	  __DIR__"npc/guanbing":4,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

