// /d/gaoli/shufang.c
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�鷿");
	set("long", @LONG
������Į��������鷿������ɾ�����������Ϸ�������ѧ�伮��
�鰸�϶�����Į�����������š�
LONG
	);
set("exits", ([
                "west" : __DIR__"baihutang",       
	]));
       setup();
	replace_program(ROOM);
}	
