
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"��Ϸ���ŷ�������"NOR);
  set ("long", @LONG
��������Ϸ���ŷ�������������ʦ������Ϸ���ŵĵط�����������
ʦ�Ĺ������������Ǵ���˫�������а���������԰������ŷ����õģ�
���Ҫ�������ţ���������post�����Ҫ��ʦ�ڲ����ԣ��뵽���ߵ���
�԰�post��
LONG);

  set("exits", ([ 
 "down":"/d/yangzhou/xiaolou",
 "west":__DIR__"wizroom2",
 "east":__DIR__"courthouse",
 "north":__DIR__"wizroom3",
        ]));

  set("valid_startroom", 1);
  setup();
  call_other("/obj/board/news_b", "???"); 
}

