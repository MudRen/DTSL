// /d/yazhang/dongmen.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
��ͻ���ǲ�ԭ�İ������ʶ���ǽ��ķ�ͬһ�㣬��ǽ�������ɸߣ�
���Ž����ָ��ִ���������С�һ�����ͨ��ɽ���ء�
LONG
	);
set("outdoors", "/d/yazhang");
set("exits", ([
"northeast" : "/d/saiwai/shop",
                  "west" : __DIR__"dongdajie1",    
	]));
       setup();
	replace_program(ROOM);
}	
