
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
������һ����ʯ·��·�������Ϻõ���ש�̳ɡ������������ɵ���
�¹㳡��������������ģ�ƽʱû��ʲô����������������ɵ�����
������������һ��������
LONG);
  set("exits",([
	  "west":__DIR__"qingshilu4",
	  "northeast":__DIR__"chitang",
	  "north":__DIR__"danfang",
	  ]));

  set("outdoors","yinkui");

  set("valid_startroom", 1);
  setup();
 
}

