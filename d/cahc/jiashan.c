
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ɽ");
  set ("long", @LONG
����ǰ������һ���޴�ļ�ɽ��һ��Ƭ��Ҳ�Ƶ����ٴӼ�ɽ��к��
������ע��ǰ���һ��������У�����������������кˮͨ����������
ˮȴ�������硣�ʹ�Ϊ�������԰��Ҳ��֪�����˶���������������
LONG);

  set("exits", ([ 
 "east":__DIR__"yuhuayuan",
         ]));
  
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

