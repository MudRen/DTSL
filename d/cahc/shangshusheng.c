
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ʡ");
  set ("long", @LONG
��͢����������ʡ���໥�ƺ⡣�ֱ�Ϊ������ʡ����������ʡ������ ��
��ʡ ��������������ʡȨ����󣬽�������Ȩ�����������ƣ����ǳ�͢
�����𲽵���������ʡ��Ȩ����һ���������ż����������С�
LONG);

  set("exits", ([ 
 "east":__DIR__"tianjie2",
         ]));
  
  
  set("valid_startroom", 1);
  setup();
 
}

