
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��������ɽ·����˵����·�Ͼ�����ǿ�˳�û���㲻���ӿ��˽Ų���
�����Ӳݴ�����ֻ�м�ֻҰ�ò�ʱ����Ľ�ǰ�ܹ���
LONG);
	set("exits", ([
		"southeast":__DIR__"chaguan",
		"northwest":__DIR__"shanlu2",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

