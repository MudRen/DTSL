
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short",HIM"��·��"NOR);
  set ("long", @LONG
���ߵ����ͻȻ����ǰ���Ѿ�û·�ˣ�һ���߼�����ǧ�׵ľ��µ���
��ǰ���ƺ������ɶ�������Խ���׻�˵�����ԹŻ�ɽһ��·������Ȼû��
������Ҫ���ϻ�ɽ��ֻ���˻�ȥѰ��������·�ˡ�
LONG);

  set("exits", ([ 
//"eastup":__DIR__"shanlu5",
"southdown":__DIR__"shanlu3",
       ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

