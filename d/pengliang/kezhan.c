inherit ROOM;

void create()
{
	set("short", "������ջ");
	set("long", @LONG       
����������ջ���ϰ�����ǳ���¡������οͶ�ѡ��������ţ���
������������������صķ������顣��С����������æ������ת���Ӵ�
����ǻ�����Ŀ��ˡ��������˽�������С����æӭ��ǰȥ����ջ�����
ǽ�Ϲ���һ����Ŀ������(paizi)��
LONG
	);

	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ����������\n",
	]));

	set("objects", ([
         __DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
          "south" : __DIR__"dongdajie",
		"up" : __DIR__"kedian2",
	]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("gived_money") && dir == "up" )
		return notify_fail("��ô�ţ����ס����\n");

	if ( me->query_temp("gived_money") && dir == "south" )
		return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ����˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
