
inherit ROOM;
 void create()
{
       set("short", "热带雨林");
       set("long", @LONG
这是一片热带雨林。厚厚的树木遮挡住了阳光，你觉得有些凉快了。
但又必须小心雨林的毒蛇猛兽。
LONG);
       set("exits", ([
               "northeast" : __DIR__"shalu2",
               "south" : __DIR__"shulin2",
                    ]));

       setup(); 
       replace_program(ROOM);
}


