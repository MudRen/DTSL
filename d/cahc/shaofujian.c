
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ٸ���");
  set ("long", @LONG
�ٸ����ǳ�͢���������������ר���ƹ�֯�칬͢ʹ��������ֹ�
ҵ���������ٸ��ࡱ�������岿�֣����з������з������з�����Ⱦ����
��ұ�����乤����һ���ǧ���ˡ�
LONG);

  set("exits", ([ 
 "west":__DIR__"tianjie3",
 "east":__DIR__"jingfengmen",
        ]));
  

  
  set("valid_startroom", 1);
  setup();
 
}

