
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @long
�����Ǳ���֡���������쳣�Ķࡣ����������������¥����Ժ
�����洫�����������������м����������ſ��к������������ˡ���
��������������ʿ��������ȥѰ�����֡�
long);

  set("exits", ([ 
  
      "south":__DIR__"beijie2",
      "west":__DIR__"manqingyuan",
      "north":__DIR__"beimen",
         ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
}

