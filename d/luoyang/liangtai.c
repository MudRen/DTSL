
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"��̨"NOR);
  set ("long", @LONG
��������̨������羰�����������Ѿ��ǻʹ����ڲ��ˣ������к�
������������ص�Ѳ�ߡ���̨��������һ����ء��кܶ�Ľ���������
����ȥ���м�����Ů���ڳر���ˣ��
LONG);

  set("exits", ([ 
  
  "north":__DIR__"qingong2",
  "west":__DIR__"donglang2",

         ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

