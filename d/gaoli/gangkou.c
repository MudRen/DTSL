// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
#include <ansi.h>
#define SHIPDIR "/d/job/sjbjob/ship"
#define FROM __DIR__"gangkou"
#define TO "/d/job/sjbjob/gangkou"
#include "/std/shiproom.c";
void create()	
{
	set("short", "�ۿ�");
	set("long", @LONG
������һ���ۿڣ�����ǳ����֣�ͣ���Ÿ��ִ�ֻ���л������̴�
�ȵȡ��ܶ��ÿʹ���������ۿڣ��д���ԭ���ģ�Ҳ�д������ط����ġ�
���С�������������������һ������(pai)��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"north" : __DIR__"dadi6",
   "east":"/d/job/killhaidao/gangkou",
        	//"south":__DIR__"gangkou",
	]));
	set("item_desc",([
  "pai":"ÿ�δ�������ʮ������Ʊ���ա�\n",
  ]));
  	set("no_duhe",1);
       setup();
	
}

int valid_leave(object ob,string dir)
{
  if(ob->query_temp("gaoli_xunluo"))
    ob->add_temp_array("xunluo_dir","gangkou");
  if(dir=="enter"){
  switch(MONEY_D->player_pay(ob,1000)){
  	case 0:return notify_fail("ˮ��˵������Ĵ�Ǯ������!\n");
  	case 2:return notify_fail("ˮ��˵������Ʊ�����Ҳ����ģ�\n");
  	default:break;}
   return ::valid_leave(ob,dir);}
  return ::valid_leave(ob,dir);
}

