
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"�㳡"NOR);
  set ("long", @LONG
�����ǵ�ǰ�㳡��ͨ���ʹ���������Ｘ��û��ʲô��������ƽ
ʱ��ʿ��������Ѳ�ߡ��������߾��Ǵ���ˡ����������̵����ӣ�һ��
���ǳ�������֮�����ʹ��䱸ɭ�ϣ����ٿ��������߹���
LONG);

  set("exits", ([ 
  "north":__DIR__"guangchang4",
  "west":__DIR__"guangchang1",
  "east":__DIR__"guangchang3",
  "south":__DIR__"door",
         ]));
  set("objects",([
   __DIR__"npc/guanbing":2,
   ]));
  
  set("valid_startroom", 1);
  setup();
 
}

