// /d/gaoli/yizhan
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "��վ");
	set("long", @LONG
������ɽ����Ψһ��һ����վ��������Ϊս������Ҳ���������ţ�
��Ҫ����ʲô��Ʒ�Ļ��������������ת������Ȼ��Ҫ��Ǯ���ˡ���ֻ
Ҫ�ǽ����������Ʒ��ͷ��ĺ��ˣ����������������һָ�ġ�
LONG
	);
set("exits", ([
                "west" : __DIR__"beidajie",       
	]));
       setup();
	replace_program(ROOM);
}	
