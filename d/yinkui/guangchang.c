
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�㳡");
  set ("long", @LONG
�����������ɵĹ㳡�����Ｋ����������и���̨����̨��Χ��
һЩ��¯�ȶ������㳡�ĵ���������ϵȵĴ���ʯ�̳ɡ�ÿ����������
ʲô���£����������ɵĵ��Ӷ��ۼ����������ƽʱ�����塣
LONG);
  set("exits",([
	  "south":__DIR__"huayuan",
	  "north":__DIR__"qingshilu1",
	  "east":__DIR__"qingshilu4",
	  "west":__DIR__"qingshilu3",
	  ]));
set("outdoors","yinkui");
  
  set("valid_startroom", 1);
  setup();
 
}

