
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�׺�Ȫ");
  set ("long", @LONG
������̩ɽ�İ׺�Ȫ������ˮ��������Ϊ̩ɽ֮���Ȫˮ����
ӿ�����ϣ������ˮ���ɺ������ų��ϴ��һ�����������Ϊ�׺�Ȫ��
������ǿ�ʼ�ʵ�̩ɽ��·�ˡ�
LONG);

  set("exits", ([ 

   "down":__DIR__"daizongfang",
   "eastup":__DIR__"shanlu1",
          ]));
 /*set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("resource/water",1);
set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

