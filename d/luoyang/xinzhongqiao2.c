
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIC"������"NOR);
  set ("long", @long
�����Ž������ţ������ˮ�������ϱ���ֻ�����ŵĹ�ģ�������
��΢��˵������㵱����������˲ơ�
long);

  set("exits", ([ 
  

  "northdown":__DIR__"xinzhongqiao1",
  "southdown":__DIR__"xinzhongqiao3",
         ]));
   set("objects",([
          "/d/yinkui/npc/zhengshi-ru":1,
          ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

