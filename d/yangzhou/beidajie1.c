
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
���������ݳǵı���֡����������ݵ������������������ݵ����
����֮һ--�����С������ּۻ��۵��������������������������ַǷ���
���������ݵı��俴̨����ʱ�����ﴫ�����Ƚе�������
LONG);

  set("exits", ([ 
 "north":__DIR__"beijishi",
 "west":__DIR__"dangpu",
 "southwest":__DIR__"guangchang",
//"east":"/d/clone/room/leitai/kantai1",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

