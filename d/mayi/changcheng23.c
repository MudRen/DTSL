inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����ǳ��ǵ�һ�����ڣ��س����ӳ��ǣ�ÿ����ʮ�ｨ��һ������
����פ�����ӣ�����������İ���ƽ�����йٱ���������Ѳ�ߣ�����ͻ
�ʿ��������Ҳû��ʲô�����ˡ�
LONG
	);
set("outdoors", "/d/mayi");
set("valid_startroom", 1);
set("exits", ([
	        "westdown" : __DIR__"changcheng22",
	        "northeast" : "/d/shanhaiguan/changcheng4",

	]));
       setup();
	replace_program(ROOM);
}
