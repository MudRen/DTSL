inherit ROOM;

void create()
{
	set("short", "��ˮ");
	set("long", @LONG
�������κ�ص�����ݷ���ˣ���Ϊ�������´��ң���·Ӣ���ӸͶ�
��ս�𲻶ϣ������פ�����������࣬���ҶԹ����Ŀ����̲��ʮ��
�ϸ񣬲�ʱ�п���ӳ���ɳ۶������򶫾�������ˡ�	
LONG );

	set("exits", ([
	        "west"      : __DIR__"xinxian",
		"southeast"      : __DIR__"dadao9",
		
	]));


 	set("outdoors", "xucheng");
	setup();
	replace_program(ROOM);
}



