inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
����һ������ɫ��ʯ�̳ɵĴ����������������������������
�������������������������������������Ĵ���ͷ���Ǵ�ֻת����
�ص㣬�����������ϴ������ת�˴��������ˮ�ʹ��˺����ʽ��㴦��
������������ϵĳ��������������ϡ�
LONG );

	set("exits", ([
               "south"      : __DIR__"qingshilu1",
               "northeast"      : __DIR__"xingze",
		
	]));

 	set("outdoors", "xingyang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



