
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"����"NOR);
  set ("long", @LONG
�����Ƕ��ȡ��������߾��ǻʵ۵��޹��ˡ������Ѿ��ǻʹ����ڲ�
�ˣ������кܶ�����������ص�Ѳ�ߡ����ȵ��Ա���һ��ˮ�أ�ˮ����
�������Կ�����������������ζ����м�����Ů���ڳر���ˣ��
LONG);

  set("exits", ([ 
  
  "east":__DIR__"liangtai",
  "west":__DIR__"donglang1",

         ]));

  set("objects",([
   __DIR__"npc/guanbing":1,
   __DIR__"npc/taijian1":1,
   ]));
  set("valid_startroom", 1);
  setup();
 
}

