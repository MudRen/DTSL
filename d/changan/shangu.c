
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
������һ������ɽ�ϵ�һ��ɽ�ȡ����Ƶ�����ɽ���Ե��й�������
����ܴ����ܲ����ʻ��̲��������֣�����ɽ���ﴵ����������磬
������������������һЩ�����Ļ��㡣
LONG);

  set("exits", ([ 
"westup":__DIR__"shandao2",
"southup":__DIR__"shandao7",
"east":__DIR__"xinggong",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

