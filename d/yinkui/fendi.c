
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ص�");
  set ("long", @LONG
������һ���س�����������һ�������ذɡ��㲻�����˸���ս����
���м��ô�������֦�Ѿ����㣬������ɢ�����ż�ֻ��ѻ�����������
�Ƶؽ��š�
LONG);

  set("exits",([
	  
	  "southeast":__DIR__"xiaolu2",
	  ]));
  set("outdoors","yinkui");
  set("valid_startroom", 1);
  setup();
 
}

