
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
��������һ����᫲�ƽ��ɽ·�ϣ�ż������һ�����Ұ�޽�����ͷ
����һЩ��֪����С����������ȥ�����ܴ����ܲ����ʻ��̲��������֣�
����ɽ���ﴵ����������磬������������������һЩ�����Ļ��㡣��
���ǰ���Ķ��š���������˺ܶࡣ
LONG);

  set("exits", ([ 

  "west":__DIR__"xiaolu1",
  "southeast":__DIR__"shashilu1",
  "southwest":__DIR__"qiuling4",
       ]));
 
set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

