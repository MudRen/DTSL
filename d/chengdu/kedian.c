
inherit ROOM;

void create()
{
	set("short", "�ɶ��͵�");
	set("long", @LONG       
���ǳɶ��͵ꡣ����͵���ǳɶ������Ŀ͵꣬�Ѿ���Ӫ�˶�ʮ��
�ꡣ����ÿ�춼�кܶ���ˣ������������ַǷ����ϰ�͵�С����ǰǰ
����æ����ͣ���������һ������(paizi)��
LONG);

	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ����������\n",
	]));

	set("objects", ([
         __DIR__"npc/xiaoer2" : 1,
           
			 
	]));

	set("exits", ([
          "west" : __DIR__"beidajie4",
		"up" : __DIR__"kedian2",
	]));

	setup();
	
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("��ô�ţ����ס����\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
		return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ����˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
