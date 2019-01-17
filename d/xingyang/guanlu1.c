inherit ROOM;

void create()
{
	set("short", "青石路");
	set("long", @LONG
这是一条由青色条石铺成的大道，道面由四辆马车并行那样宽，这
条大道是用语连接荥阳和荥泽，荣泽等若荣阳的大码头，是船只转驳的
地点，而荣阳则是南船北马的转运处，又是洧水和大运河物资交汇处。
因为这条大道专供官府使用，所以道上几乎没有行人。
LONG );

	set("exits", ([
               "south"      : __DIR__"ximen",
               "north"      : __DIR__"guanlu2",
		
	]));

 	set("outdoors", "xingyang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



