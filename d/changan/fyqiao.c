
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
����һ����ɫ��ʯ�ţ���Խ���ϱ������������֮�ϣ����������
�����������Գ����������ܾ��Ǿ�լ������վ��������Զ����ȥ����
����������Ĺ����ź������Ծ���š�
LONG);

  set("exits", ([ 
  "westdown":__DIR__"xishidongjie2",
  "eastdown":__DIR__"xishidongkou1",
        ]));
  set("objects",([
   __DIR__"npc/gongzi":1,
   ]));
   
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

