
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","��������ַ");
  set ("long", @LONG
��������س�����������ַ���۵�֮�����ǲ�ԫ�ϱڣ����뵱�긻
���ûʵİ�����һҹ֮���ɷ��棬����ʹ��п���ǧ��
LONG);

  set("exits", ([ 
 "northeast":__DIR__"guandao4",
         ]));
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}
