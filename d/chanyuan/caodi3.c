
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������һƬ�ݵء�ƽʱ�������˵�����������������Ժ������Ϣ��
�ط�����ʱ����˯�����������������������о�֮��������������ƴ�
ң����֪��Զ��������������Ժ��
LONG);

  set("exits", ([ 
	  "northwest":__DIR__"caodi2",
	  "east":__DIR__"woshi",

         ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

