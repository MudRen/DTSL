
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��Զ�ھ�");
  set ("long", @LONG
�����ǳ��������ھ�--��Զ�ھֵ��ſڡ��ſڵ�����������ʯʨ
�ӣ������ޱȡ��ſ�����һ������ˣ�����Ʈ����һ����죬����д��
�ĸ����֣���Զ�ھ֡��кܶ��˽������������������ڡ��ſ�վ�ż���
�������к��Ž����Ŀ��ˡ�
LONG);

  set("exits", ([ 
 "west":__DIR__"csdajie2",
 "east":__DIR__"dayuan",
       ]));
  set("objects",([
	  __DIR__"npc/biaoshi":1,
	  ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

