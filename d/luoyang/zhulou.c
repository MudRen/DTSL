

inherit ROOM;

void create()
{
	set("short", "竹楼");
	set("long", @LONG
这是一个竹楼，下面就是洛阳的钟鼓楼。从这里望去，洛阳城的景
色尽收眼底，钟鼓楼下面人来人往，热闹非凡。这里放着一张大床，床
头还放着一些荔枝，看起来香甜可口。
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

