
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
����������ɽ��ɽ�����ˡ�̧ͷ��ȥ������ɽ���̵�ɽɫ��
���۵ס����߲�ʱ�������������֮�����м������˴��������
�߹���������ȥɽ������ġ����ﻹ����һ����ʯ��������д��
�������֣�����ɽ��
LONG);

  set("exits", ([ 

   "southup":__DIR__"shanlu1",
   "northwest":"/d/dongming/xiaolu2",
          ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

