
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"huafang"
#define TO __DIR__"matou"
#include "/std/shiproom.c";
void create ()
{
  set ("short",HIR"��"HIG"��"NOR);
  set ("long", @long
�����������������Ļ���������ʮ�ߣ�ʮ�־޴󣬴�������Լ����
����˿��֮�����Ǵ��ĵط������ǻ����Ĵ�ͷ��
long);

  set("exits", ([ 
  "north":__DIR__"chuancang",
         ]));

  set("valid_startroom", 1);
  set("outdoors","yangzhou");
  setup();
 
}

