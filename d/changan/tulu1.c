
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","��·");
  set ("long", @LONG
������һ����·����紵�𣬾����ɳ���󣬼�����ס�����˫�ۡ�
��ʱ�м������������������Գ۹���������������������ɽ��ɽ�ˣ�
ңң��ȥ����ɽ��Լ�ɼ���
LONG);

  set("exits", ([ 
"northwest":__DIR__"shanlu2",
"southeast":__DIR__"tulu2",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

