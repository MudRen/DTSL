

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ͬ����");
  set ("long", @LONG
����һ��Ӫ��ˮ������ĵ��̣��ſھۼ�����������������װ��
����͸��һ�ֽ��ŵ����Ѱ�������ա���������İ�ᱳ����һ�ɺ�ǿ
��������ڰ���֧�֣�����̫�ӣ�����������Ҳ��һ���ܱȵ��ϡ�����
����������������ͷ��
LONG);

  set("exits", ([ 
 "south":__DIR__"tydajie1",
 "east":__DIR__"matou",
       ]));
  set("valid_startroom", 1);
  setup();
 
}

