// /d/gaoli/baihutang.c
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�׻���");
	set("long", @LONG
��������һ�ż����������ĺ�����һ�Ż�Ƥ���Σ��������ʮ���
���ӣ�ǽ�Ϲ���һ���ͻ���ɽͼ���������Į���Ȩ������--�׻��á�
LONG
	);
set("exits", ([
	        "west" : __DIR__"siheyuan",
            	"east" : __DIR__"shufang",
	]));
       setup();
	replace_program(ROOM);
}	
