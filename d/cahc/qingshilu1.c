
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
���������������ʯ��·����·�����ɾ�������������·�汻��
ˮ��ù����羵����·�������Ų���Ĺ�ľ���������ϵ�С��ʱ����ʱ
��������������ﵽ����ɢ���Ű������������ա����������Ͼ���Ҵͥ
���ĺ����ˡ�
LONG);

  set("exits", ([ 
 "southup":__DIR__"houdian",
 "east":__DIR__"qingshilu2",
        ]));
 

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}