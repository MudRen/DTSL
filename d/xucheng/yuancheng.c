inherit ROOM;

void create()
{
	set("short", "Ԫ��");
	set("long", @LONG
�������κ�ص�����Ԫ���ˣ���Ϊ�������´��ң���·Ӣ���ӸͶ�
��ս�𲻶ϣ������פ�����������࣬���ҶԹ����Ŀ����̲��ʮ��
�ϸ񣬲�ʱ�п���ӳ���ɳ۶�����	
LONG );

	set("exits", ([
	        "north"      : __DIR__"edao5",
		"west"      : __DIR__"edao6",
		
	]));


 	set("outdoors", "xucheng");
	setup();
	replace_program(ROOM);
}



