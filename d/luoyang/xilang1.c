
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"����"NOR);
  set ("long", @LONG
���������ȡ�ǽ���ϻ��źܶ��ͼ�����������������ҵĳ���֮����
�����Ѿ��ǻʹ����ڲ��ˣ������кܶ�����������ص�Ѳ�ߡ����ȵ���
����һ��ˮ�أ�ˮ�����������Կ�����������������ζ����м�����Ů
���ڳر���ˣ��
LONG);

  set("exits", ([ 
  
  "east":__DIR__"changlang",
  "west":__DIR__"xilang2",

         ]));

  
  set("valid_startroom", 1);
  setup();
 
}

