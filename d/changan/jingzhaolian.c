
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","����������");
  set ("long", @LONG
�����ǹ��е�һ���ɣ����������������ڣ������������ĸ�������
���ֵ���Ͷ����̫�ӵ�����������߸����ԣ������Ѿ�����ʮ��Σ����
ʱ�̡�
LONG);

  set("exits", ([ 
 "west":__DIR__"qydajie1",
         ]));
set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}
