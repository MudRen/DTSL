// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "������");
	set("long", @LONG
�����Ǹ����������š�����͵��˳��У�Զ����ɽ�˺�����������
��������������һ����·ͨ��η�����������һЩִ�ڵı�ʿ��������
��Ķ���������ʿ��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"south" : __DIR__"xuanwu-2",
        	"north" : __DIR__"shanlu1",
        	"northeast":__DIR__"shanlu6",
        	"northwest":__DIR__"shanlu9",
	]));
set("objects",([
  "/d/yjp/npc/gai":1,
  __DIR__"npc/guanbing":2,
  __DIR__"npc/wujiang":1,
  ]));
       setup();
	
}

int valid_leave(object ob,string dir)
{
  if(ob->query_temp("gaoli_xunluo"))
    ob->add_temp_array("xunluo_dir","xuanwu");
  return ::valid_leave(ob,dir);
}
