

inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
����һ����¥����������������ӹ�¥����������ȥ�������ǵľ�
ɫ�����۵ף��ӹ�¥�����������������ַǷ����������һ�Ŵ󴲣���
ͷ������һЩ��֦������������ɿڡ�
LONG
	);

	set("exits", ([
		"down" : __DIR__"zhonggulou",
	]));
  set("sleep_room",1);
        
        set("objects",([
         __DIR__"obj/lizhi":4,
         ]));
        setup();
	 "/obj/board/party_hj_b.c"->foo();
}

