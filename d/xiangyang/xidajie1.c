
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
����������������֡�������������������ˡ�����ս�ң����Ժ�
�����ϰ���������������������ξ֣������ݵ��ξֱ��������е���
ϵ���������������˻����γ��������߹����ϱ���һ����Ӫ���м�����
�����ڱ�Ӫ���ſڴ��
LONG);

  set("exits", ([ 
 "east":__DIR__"xidajie2",
 "south":__DIR__"bingying1",
 "west":__DIR__"ximen",
 "north":__DIR__"yanju",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

