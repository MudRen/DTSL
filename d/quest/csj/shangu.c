
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","ɽ��");
	set("long", @LONG
����һ���ž���ɽ�ȣ��羰���������ﻨ�㡣��紵������������
�̲�ɳɳ���������ŵ�����Ļ��㡣�������ƫƧ���������ܾ�û����
���ˡ�
LONG);
        set("exits",([          
          "down":__DIR__"xiaoxi",
          ]));
        
	setup();      
}
