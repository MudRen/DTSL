inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
����һ������ɫ��ʯ�̳ɵĴ����������������������������
�������������������������������������Ĵ���ͷ���Ǵ�ֻת����
�ص㣬�����������ϴ������ת�˴��������ˮ�ʹ��˺����ʽ��㴦��
��Ϊ�������ר���ٸ�ʹ�ã����Ե��ϼ���û�����ˡ�
LONG );

	set("exits", ([
               "south"      : __DIR__"ximen",
               "north"      : __DIR__"guanlu2",
		
	]));

 	set("outdoors", "xingyang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



