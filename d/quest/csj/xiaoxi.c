
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","СϪ");
	set("long", @LONG
����һ��СϪ�ߣ�����羰�������������Σ��������ƺ�ƽʱû��
�����������ǳ��ž������˼�����������У�û�а����Ϣ������
�����������Ѿ���Զ�ˡ�
LONG);
        set("exits",([          
          "down":__DIR__"migong10",
          ]));
        set("objects",([
         __DIR__"npc/fu":1,
        ]));
	setup();      
}
