// /d/gaoli/siheyuan
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�ĺ�Ժ");
        set("long", @LONG
��������Į�����̳�����������Ķ�����Į��İ��ڣ�����
���߾��Ǿ�����Į��İ׻��ã����������᷿�ǰ���ס�ĵط���
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
            	"west" : __DIR__"saimobang",
                "east" : __DIR__"baihutang",
                "north" : __DIR__"xiangfang1",
                "south" : __DIR__"xiangfang2",
	]));
       setup();
	replace_program(ROOM);
}
