// /d/gaoli/nanmennei
// Room in É½º£¹Ø
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "ÄÏ³ÇÃÅ");
	set("long", @LONG
ÕâÀïÊÇÉ½º£¹ØµÄÄÏ³ÇÃÅ£¬ÄãÌ§Í·ÍûÈ¥Ö»¿´¼û[33mÌì ÏÂ µÚ Ò» ¹Ø[0mÎå
¸ö¶·´óµÄ×Ö£¬É½º£¹ØÊÇ³öÈë¹ØµÄÑÊºí£¬ÒÔÇ°ÓĞÖØ±ø°ÑÊØ£¬ÏÖÔÚÌìÏÂ
´óÂÒÕâÀï³ÉÁËÈı²»¹ÜµØ½ç£¬±±Ãæ¾Íµ½ÁË³ÇÖĞ£¬ÄÏÃæÊÇÈë¹ØµÄ´óµÀ£¬
Í¨ÏòºÓ±±ºÍÉ½¶«¡£
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
		"north" : __DIR__"nandajie",
		"south" : __DIR__"dadao2",
	        "eastup" : __DIR__"chengqiangshang1",
            	"westup" : __DIR__"chengqiangshang2",
                "southeast":"/d/yangzhoubei/haibin1"
	]));
 set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang":1,
	]));
       setup();
	replace_program(ROOM);
}
