
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��µ�");
  set ("long", @LONG
��µ�ڵ���ʯ̨��֮�ϣ������Ի�������שΧ��͸�������ǽ��
�������߼䣬�������䣬����Ъɽʽ�����������ʼ�Ϊ�ο������׻���
������ȸ�棬���λ���ûʸ�����������Ԫ����ס�����
LONG);

  set("exits", ([ 
 "west":__DIR__"xineiyuan",
         ]));
  set("objects",([
          "/d/cahc/npc/liyuanji":1,
          ]));

    
  set("valid_startroom", 1);
  setup();
 
}

