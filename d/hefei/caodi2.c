
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������Ƭ�ݵء��ϱ߾��ǳ����ı����ˡ�����羰������ɽˮ�续��
�������¡���ˮ�ĳ�ʪ��Ϣ�˱Ƕ����������кܶ�Ư����Ұ�����ѹ�Ӣ��
ֲ���ʱ��Ұ�ô���Ľ���������
LONG);

  set("exits", ([ 

  "north":__DIR__"shanlu3",
  "south":"/d/jiujiang/jiangbei",
       ]));
  
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

