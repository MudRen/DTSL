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
               "southeast"      : __DIR__"beimen",
               "northeast"      : __DIR__"huanghe_dukou2",
               "west"      : __DIR__"qingshilu3",
               "east"      : __DIR__"dadao1",
		
	]));

 	set("outdoors", "xingyang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



