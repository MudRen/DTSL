
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "��·");
	set("long", @LONG
������һ����·������������������߹�������羰������ɽˮ��
�����������¡������кܶ�Ư����Ұ�����ѹ�Ӣ��ֲ���ʱ��Ұ�ô�
��Ľ���������
LONG);
	set("exits", ([
		"southwest":__DIR__"tulu1",
		"north":__DIR__"tulu3",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

