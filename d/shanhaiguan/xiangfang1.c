// /d/gaoli/xiangfang1.c
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�᷿");
	set("long", @LONG
���ݵĶ��߿�ǽ��λ����һ��ľ�洲��һЩ���ڹ��Ű��ӣ�����ľ
�崲�ϣ��壬ʮ�ĺ��ţ�ԭ�����ڶ�Ǯ��
LONG
	);
set("exits", ([
                "south" : __DIR__"siheyuan",       
	]));
       setup();
	replace_program(ROOM);
}	
