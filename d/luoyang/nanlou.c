
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����Ժ��¥"NOR);
  set ("long", @LONG
����������Ժ����¥��¥�Ͼ����Ϲ�����ס������Ϊ����Ժ������
�Ϲ���ֻ��������Ϊ���ʵĿ��˵�����ȥ���͡�
LONG);

  set("exits", ([ 
	  "north":__DIR__"huayuan",
	  "up":__DIR__"yashi",
         ]));

  set("valid_startroom", 1);
  setup();
 
}
