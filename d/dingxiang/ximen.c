// /d/yazhang/ximen.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
��ͻ���ǲ�ԭ�İ������ʶ���ǽ��ķ�ͬһ�㣬��ǽ���������ɸߣ�
���Ž����ָ��ִ���������С�
LONG
	);
set("outdoors", "/d/yazhang");
set("exits", ([
                  "east" : __DIR__"xidajie1",  
                  "west" : "/d/suiye/caoyuan",    
	]));
       setup();
	replace_program(ROOM);
}	
