
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"�뷿"NOR);
  set ("long", @LONG
���㷼�Ĺ뷿��û����������ô������Ҳû��һ˿�����װ��Ʒ��
�������˸о���������֮ʿ�����ҡ�
LONG);

  set("exits", ([ 
	  "down":__DIR__"beilou",
  ]));

  set("valid_startroom", 1);
  setup();
 
}
