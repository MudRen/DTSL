
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","Ʈ���¥");
  set ("long", @LONG
���������ݳǵ�һ����ʷ�ƾõľ�¥����཭���ú��������ݣ���
Ҫ������ȵ�ơ�ֻ������Ȱ�Ƶ�������һ�����ֵľ��󡣵�С������
���ӣ���æ�ش����ڸ�������֮�䣬æ����ͣ��
LONG);

  set("exits", ([ 
 "east":__DIR__"nandajie2",
        ]));
 set("objects",([
	 __DIR__"npc/li":1,
	 ]));
 set("resource/water",1);
  set("valid_startroom", 1);
  setup();
 
}

