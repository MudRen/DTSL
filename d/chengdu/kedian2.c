
inherit ROOM;

void create()
{
	set("short", "�͵��¥");
	set("long", @LONG
�������ڿ͵��¥�������ϣ����������ӿͷ��ﲻʱ�غ����Ĵ�
����һ��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ�����������¥�µ��ƹ�
����Ǯ������˯����
LONG);

	set("exits", ([
		"down" : __DIR__"kedian",
	]));

set("sleep_room",1);
	setup();
	
}
int valid_leave(object ob,string dir)
{
  if(dir=="down")
  ob->delete_temp("rent_paid");
  return ::valid_leave(ob,dir);
}
