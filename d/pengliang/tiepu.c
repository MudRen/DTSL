inherit ROOM;


void create()
{
	set("short", "������");
	set("long", @LONG
����ԭ����һ�Ҽ����ª�������̡��������Ļ����������������
�����̱���˧�����ã���Ϊ�ٰ�������Ŀǰ��ģ�ܴ�һ������Ϊ��˧
���������ס������ȣ��Լ�����ﱸ�س����ʡ�ֻ����ʮ������������
������æ����ͣ��
LONG
	);
    
	set("exits", ([
		"north" : __DIR__"jiedao1",
	]));
         set("objects", ([
		__DIR__"npc/tiejiang" : 1
	]));
	setup();
	replace_program(ROOM);
}

