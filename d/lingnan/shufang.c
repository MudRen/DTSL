
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�鷿");
  set ("long", @LONG
�������μұ��ı�����ȱ���鷿��������źܶ��书����鼮����
���������ܸɾ����ƺ��ո����˴�ɨ��������Ϸ��˺ܶ��鼮��������
��ѧ����ģ��������顢�徭���鼮��
LONG);

  set("exits", ([ 

  "south":__DIR__"xilang2",
       ]));

  set("valid_startroom", 1);
  
  setup();
 
}

