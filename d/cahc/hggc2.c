
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���㳡");
  set ("long", @LONG
���ߵ���������������ϱ������ᶫ���ĳ���ʽ�㳡�İ�����
�������壬̾Ϊ��ֹ�������㳡���������ɣ��þ޴�ƽ���İ�ɫ����
ʯ�̳ɣ�����������������������ɵĳ����š�����ƽʱ����û��ʲô
�ˣ���������ڣ���͢���������������ٰ���͵���ף�����ʱ��
�ӻ���ϳ�����¥���֡�
LONG);

  set("exits", ([ 
 "north":__DIR__"chengtianmen",
 "south":__DIR__"tianjie4",
 "east":__DIR__"hggc3",
 "west":__DIR__"hggc1",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

