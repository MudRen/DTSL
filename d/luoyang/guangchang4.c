
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"�㳡"NOR);
  set ("long", @LONG
�������߾��Ǵ���ˡ�����ٹ��ϳ�֮ǰ��Ҫ��������Ϣ��������
���̵����ӣ�һ�����ǳ�������֮�����ʹ��䱸ɭ�ϣ����ٿ���������
����
LONG);

  set("exits", ([ 
  "up":__DIR__"shijie1",
  "south":__DIR__"guangchang2",
         ]));

  set("objects",([
   __DIR__"npc/taijian1":2,
   ]));
   
  set("valid_startroom", 1);
  setup();
 
}

