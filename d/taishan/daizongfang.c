
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ڷ�");
  set ("long", @LONG
������̩ɽ����ڷ�����������ȥ���Ϳ��Ե�̩ɽ���������ˡ���
�ܶ����˴��������߹���̧ͷ��ȥ��̩ɽ���ʵ�ɽ���Ѿ������ƶˡ�
LONG);

  set("exits", ([ 

   "up":__DIR__"baihequan",
   "northup":__DIR__"wshandao1",
   "east":"/d/yangzhoubei/taishanjiao",
   //"south":"/d/leshou/eroad3",
          ]));
 set("objects",([
     __DIR__"npc/youke":2,
     ]));
set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

