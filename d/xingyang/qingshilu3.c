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
               "east"      : __DIR__"qingshilu4",
               "west"      : __DIR__"xingze",
		
	]));

 	set("outdoors", "xingyang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



