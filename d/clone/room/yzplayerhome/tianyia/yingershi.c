
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short","Ӥ����");
	set("long", @LONG
������Ӥ������ǽ�������ſ�ͨͼ���ı�ֽ���м���һ��Ӥ
����,������������ĵ�̺��С���ϸ������һӦ��ȫ��
LONG);
    set("exits", ([
	        "out" : __DIR__"woshi",	       
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
