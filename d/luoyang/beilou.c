
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����Ժ��¥"NOR);
  set ("long", @LONG
����������Ժ�ı�¥��¥�Ͼ������㷼�Ĺ뷿��һ���Ѱ��������
û�и�������ġ�
LONG);

  set("exits", ([ 
	  "south":__DIR__"huayuan",
	  "up":__DIR__"guifang",
         ]));

  set("valid_startroom", 1);
  setup();
 
}
