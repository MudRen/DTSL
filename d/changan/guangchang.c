
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ȸ�㳡");
  set ("long", @LONG
�����ǳ����ǵ������ˡ�һ���ܿ����Ĺ㳡��������ʯ���档һЩ
���ֺ��е��������������������������������ݡ����������Ϸ�
�������֡��������������һ������һ�����ǳ��ļž����㲻��������
�Ų���
LONG);

  set("exits", ([ 
 "east":__DIR__"gmdajie4",
 "west":__DIR__"gmdajie5",
 "north": "/d/cahc/zhuquemen",
 "south":__DIR__"zqdajie3",
        ]));
  set("objects",([
	  __DIR__"npc/lijing":1,
	  ]));
 
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

