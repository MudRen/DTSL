inherit ROOM;

void create()
{
	set("short", "κ��");
	set("long", @LONG
�������κ�ص�����κ���ˣ�κ�����������Ķ�����κ���ǿ�
���������Ĺؼ��ص�֮һ���������´��ң���·Ӣ���ӸͶ���ս
�𲻶ϣ������פ�����������࣬���ҶԹ����Ŀ����̲��ʮ����
�񣬲�ʱ�п���ӳ���ɳ۶�����	
LONG );

	set("exits", ([
	        "east"      : __DIR__"shanlu",
		"southwest"      : __DIR__"edao",
		
	]));


 	set("outdoors", "xucheng");
	setup();
	replace_program(ROOM);
}



