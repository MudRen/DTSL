
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ϴ��");
  set ("long", @LONG
���������ݳǵ��ϴ�֡�����������ݵ��ϳ����ˡ�������һ��Ǯ
ׯ�����������ݵ������֮һ�ϼ��С��������ַǷ���������������
ʱ��������ʿ����������߹�����ʱ����ֵ�����������㣬�ƺ����
�����Ͽ�������赵ĺۼ���
LONG);

  set("exits", ([ 
 "east":__DIR__"qianzhuang",
 "northwest":__DIR__"nanjishi",
 "southeast":__DIR__"nanmen",
        ]));
  set("objects",([
     "/d/clone/npc/simadekan":1,
     ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

