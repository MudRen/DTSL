// /d/shanhaiguan/dadao1.c
// Room in ɽ����
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "��ʯ·");
	set("long", @LONG
�ߴ�Զ�������пɼ���Ұ�ʵͰ���ũ���ţ������������������
��ζ����Զ����ľ�Ϸ·��������ƣ������ɾ��磬ʹ��ּ�ԡ��Ǿ�����
����Ȫ�����ˮ����
LONG
        );
set("outdoors", "/d/shanhaiguan");
set("exits", ([
                "eastdown":__DIR__"dadao1-2",  
                "westup":__DIR__"yinmayi",
                	]));
       setup();
	replace_program(ROOM);
}
