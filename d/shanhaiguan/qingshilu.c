// /d/shanhaiguan/dadao1.c
// Room in 山海关
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "青石路");
	set("long", @LONG
高处远望，间中可见田野问低矮的农舍和牛羊，颇有与世隔绝无争
的味儿，远处林木上仿佛云气缭绕，如神仙境界，使人旨迷。那就是饮
马温泉升起的水气。
LONG
        );
set("outdoors", "/d/shanhaiguan");
set("exits", ([
                "eastdown":__DIR__"dadao1-2",  
                "westup":__DIR__"yinmayi",
                	]));
       setup();
	replace_program(ROOM);
}
