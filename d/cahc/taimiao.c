
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","̫��");
  set ("long", @LONG
̫������ܴ󣬴��������Ϊ������Ҫ������������Ϊ��
��ţ�����������ӡ�̫�������Ӽ���ĵط�������ֻ�м���ʱ��
�Ե�����Щ���������ӣ�ֻ�м���̫�࿴�أ��ǳ����塣
LONG);

  set("exits", ([ 
 "west":__DIR__"tianjie4",
         ]));
   
  set("valid_startroom", 1);
  setup();
 
}

