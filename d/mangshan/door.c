
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"�Ͼ���"NOR);
  set ("long", @LONG
����������Ǵ��Ʒ嶥���Ͼ����ˡ���������Կ�����ɽ�Ĳ�����
���ķ羰��Զ���ı��Ʒ�Ҳ����ңң��������ǰ����һ�������ң�����
д�š��Ͼ��ۡ������֡������������ѣ������Ѿ��ܾ�û������������
���ˡ�
LONG);

  set("exits", ([ 

  "down":__DIR__"shanlu9",
 "enter":__DIR__"tingyuan",
         ]));

  set("valid_startroom", 1);
  setup();
 
}

