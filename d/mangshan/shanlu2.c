
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
��������ɽ·������·��ͨ����ɽ�ġ�������ľïʢ��Զ��������
�羰ӳ���������������ܴ����ܲ����ʻ��̲��������֣���ʱ�������
���ͷ�Ϸɹ�����˵ɽ�������Ͼ��ۡ���
LONG);

  set("exits", ([ 

  "southwest":__DIR__"shanlu1",
 "eastup":__DIR__"shanlu3",
         ]));

  set("valid_startroom", 1);
  setup();
 
}

