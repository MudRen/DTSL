
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short","��·");
  set ("long", @LONG
������һ����·�������Ǻ���ʡ�ı߽��ˡ����������У���������
ʡ�ˡ��������ߣ��Ϳ��Ե������ˡ�������·�ǳ�����������̫ƽ��
�¡�
LONG);

  set("exits", ([ 
"west":__DIR__"tulu2",
"east":__DIR__"dalu2",
       ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

