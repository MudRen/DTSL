
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short",HIW"��ʦ������"NOR);
  set ("long", @LONG
��������ʦ����ĵط���������һ�����԰壬��������ʦ�����ԡ�
���������ʮ���ƽ����ʮ��������
LONG);

  set("exits", ([ 
 "east":__DIR__"wizroom",
 "north":__DIR__"wizroom5",
 "west":__DIR__"qc",
        ]));
  set("objects",([
 "/u/yanyan/box":1,
    ]));
  set("valid_startroom", 1);
  setup();
  call_other("/obj/board/wiz_b", "???"); 
  
}


