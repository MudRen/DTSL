
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
����һ��λ�ڹ�������ϵİ�ɫʯ�ţ���Խ���ϱ������������֮
�ϣ���������������������Գ����������ܾ��Ǿ�լ���������Ϸ���
���������������ˡ�
LONG);

  set("exits", ([ 
  "westdown":__DIR__"xishibeikou2",
  "eastdown":__DIR__"gmdajie6",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

