
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ�����̣������кܶ��鼮������ѧ�ģ����ĵģ��书����
�ĵȵȡ���Ȼ��һ�����̣���Ҳ�ⲻ�˱������������ѹ���ϰ徭��Ҫ
��΢����������ȡ���ܴ�һ������Ϊ�����ѡ����������������壬�ϰ�
����������ϵ�һ�����鷢����
LONG);

  set("exits", ([ 
 "south":__DIR__"dongdajie2",
        ]));
 set("objects",([
	 __DIR__"npc/kong":1,
	 ]));
 set("valid_startroom", 1);
  setup();
 
}

