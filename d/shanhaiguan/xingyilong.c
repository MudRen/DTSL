// /d/gaoli/xingyilong
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "����¡");
	set("long", @LONG
����һ��ר����Ƥ���ĵ��̣�����¡��������ȴ�����ţ��ع����ţ�
���ߵ�ǽ���ú�����д��"���űյ�"��
LONG
	);
set("exits", ([
                "east" : __DIR__"beidajie",       
	]));
       setup();
	replace_program(ROOM);
}	
