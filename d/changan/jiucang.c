
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�Ʋ�");
  set ("long", @LONG
����λ�ڳ������������һ���Ʋ֣�����ƽ�����˻��ͻ����˳���
����;����������û���˹���������ƽʱ�����塣�˲ֽ�������������
�����д�С����������Ը�ǽΧ�ơ� 
LONG);

  set("exits", ([ 

  "north":__DIR__"xpdajie1",

         ]));
  set("objects",([
         __DIR__"npc/jiubao":2,
         ]));
  set("valid_startroom", 1);
  setup();
 
}

