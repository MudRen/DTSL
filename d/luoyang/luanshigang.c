
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ��");
  set ("long", @LONG
��������ʯ�ڡ�����û�к�����������������Եõ���Щ������
��˵���ﾭ����ǿ����û���㲻��С��������
LONG);

  set("exits", ([ 
"southeast":__DIR__"shanlu1",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

