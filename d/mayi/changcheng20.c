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
	        "northeast" : __DIR__"changcheng21",
	        "southwest" : __DIR__"changcheng19",
 "southeast" : "/d/yuyang/zhuojun",

	]));
       setup();
	replace_program(ROOM);
}
