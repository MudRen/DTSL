
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"����"NOR);
  set ("long", @LONG
�����Ƕ��ȡ�ǽ���ϻ��źܶ��ͼ�����������������ҵĳ���֮����
�����Ѿ��ǻʹ����ڲ��ˣ������кܶ�����������ص�Ѳ�ߡ����ȵ���
����һ��ˮ�أ�ˮ�����������Կ�����������������ζ����м�����Ů
���ڳر���ˣ��
LONG);

  set("exits", ([ 
  
  "east":__DIR__"donglang2",
  "west":__DIR__"changlang",

         ]));

  
  set("valid_startroom", 1);
  setup();
 
}

