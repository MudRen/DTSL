
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"matou"
#define TO __DIR__"jiangbei"
#include "/std/shiproom.c";
void create ()
{
  set ("short","�Ž���ͷ");
  set ("long", @LONG
�����ǾŽ�����ͷ�����ﴬֻ�ǳ��࣬��Ϊ�������������ˡ��ϱ�
���Ǿ��ǾŽ��ı����ˡ�����������Խд�(yell boat)��������
LONG);

  set("exits", ([ 

  "south":__DIR__"beimen",
  "west":"/d/job/sjbjob/gangkou2",
         ]));
set("outdoors","jiujiang");
  set("valid_startroom", 1);
  setup();
 
}

