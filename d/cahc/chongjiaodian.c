
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��̵�");
  set ("long", @LONG
��̵���̫��ѧϰ�ĵط����ܶ൱���Ĵ�Ҷ��������̫��������
����ĸ�����Ϊ������һ��Ӣ���ľ�����Ŭ�������̫�Ӻ�����������
���ڣ�ֻ�м�����Ů������Ĳ��ô�ɨ��
LONG);

  set("exits", ([ 
 "north":__DIR__"guangtiandian",
 "south":__DIR__"xiandedian",
         ]));
  
  
  set("valid_startroom", 1);
  setup();
 
}

