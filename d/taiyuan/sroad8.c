// /d/taiyuan/nroad1.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "��ٵ�");
	set("long", @LONG
����һ������ʯ�̳ɵ��������Ϊ����̫ƽ�Ĺ�ϵ�����������˿�
�̻��Ƚ϶࣬�����߾�Ҫ������ϵĵؽ��ˣ���������Կ���̫ԭ�ĳ�
ǽ��
LONG
        );
set("outdoors", "/d/taiyuan");
set("valid_startroom", 1);
set("exits", ([
                "southeast" : "/d/luoyang/huanghe_dukou2",
                "north":__DIR__"sroad7", 
	]));
       setup();
	replace_program(ROOM);
}
