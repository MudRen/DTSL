
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ƽ��");
  set ("long", @LONG
�������ڷ��뷻�䶼��Χǽ�ֵ��ָ�����Ȼ����ÿ�����ţ���Ҫ
�ֵ�����ʮ���ι�ͨ���ŵ�ʯ��·��С��ɷ�����״ͨ�������֡���
����Ӷ�Ϊ�Ͱ���שľ�����������룬Ժ��ɭ��ʱ��������������һƬ
�������ʵľ�ס���ա� 
LONG);

  set("exits", ([ 
 "east":__DIR__"wxdajie1",
 "south":__DIR__"shibanlu",
         ]));
  set("objects",([
         __DIR__"npc/baixing":2,
         ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

