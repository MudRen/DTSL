
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
���������ݳǵĶ���֡����������ݵ��������ߡ����������Ҳ��
�ܶ࣬˿����ѷɫ�������ط�������������������������ӣ���������
�ǳ��ã�ƽʱ�кܶ��������������ˡ�������һ�ұ����꣬������Ϳ�
����������ƹ�Ҵ��������������
LONG);

  set("exits", ([ 
 "northeast":__DIR__"dongdajie2",
 "northwest":__DIR__"donghudi3",
  "south":__DIR__"bingqidian",
        ]));
  set("objects",([
     "/d/clone/npc/suanming":1,
     ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

