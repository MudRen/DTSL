
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ũ��");
  set ("long", @LONG
������һƬһ���޼ʵ�ũ�������˶���Ը���Ϊ������������
�ش�����ƽԭ�����ʷ��֣�����������������䲻��ԣ�����������Ҳ
���������ط�������������ࡣ
LONG);

  set("exits", ([ 
 "west":__DIR__"nongtian",
        ]));
  set("objects",([
      __DIR__"npc/nongfu":1,
      ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

