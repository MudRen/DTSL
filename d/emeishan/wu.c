
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","é��");
  set ("long", @LONG
����һ��é�ݣ�����򵥣�������Ϊ���˵���Ϣ��׼���İɡ�����
�羰������ɽˮ�续���������¡�Զ���ĵ����кܶ�Ư����Ұ�����ѹ�
Ӣ��ֲ���ʱ��Ұ�ô���Ľ���������
LONG);

  set("exits", ([ 
  "south":__DIR__"shulin",
       ]));
 set("valid_startroom", 1);
  setup();
 
}

