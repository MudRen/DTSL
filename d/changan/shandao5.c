
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ɽ");
  set ("long", @LONG
�����೤�ı���ɽ��λ�ڳ���֮������һ����Ȼ�����Ͻ���ԭ����
��ָ����������ɽ���е�һ��ɽ�壬�������򱱣����ߵ�����Ĳ�
�䣬�����߾͵��˳����ˡ���������˲��Ǻܶ࣬���ܴ����ܲ����ʻ�
�̲��������֣�����ɽ���ﴵ����������磬������������������һЩ
�����Ļ��㡣
LONG);

  set("exits", ([ 
"northdown":__DIR__"shandao4",
"southdown":__DIR__"shandao6",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

