// /d/suiye/minzhai
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "���");
	set("long", @LONG
����һ����ӣ������ص�װ�����˿�������һ����ͨ�˼ң���û��
�뵽�����ͨ�˼�ȴ����׵Ĺʾӡ�
LONG
	);
set("exits", ([
		
		"north" :  __DIR__"dongdajie2",
               
	]));
       setup();
	replace_program(ROOM);
}	
