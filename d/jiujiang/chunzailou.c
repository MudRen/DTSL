
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����¥");
  set ("long", @LONG
�����ǾŽ��������ļ�Ժ--����¥���ſ��м�λƯ���Ĺ���������
���ϵ����ˡ��кܶ๫�Ӹ������������Ц��������
LONG);

  set("exits", ([ 
 "west":__DIR__"beidajie2",
        ]));
  set("objects",([
	  __DIR__"npc/girl":1,
"/d/job/xiang/xiang":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

