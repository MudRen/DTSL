inherit ROOM;

void create()
{
	set("short", "ݷ��");
	set("long", @LONG
�������κ�ص�����ݷ���ˣ���Ϊ�������´��ң���·Ӣ���ӸͶ�
��ս�𲻶ϣ������פ�����������࣬���ҶԹ����Ŀ����̲��ʮ��
�ϸ񣬲�ʱ�п���ӳ���ɳ۶��������ڹ�����ˮ��������ˡ�	
LONG );

	set("exits", ([
	        "east"      : __DIR__"wushui",
		"southwest"      : __DIR__"edao5",
		
	]));


 	set("outdoors", "xucheng");
	setup();
	replace_program(ROOM);
}



