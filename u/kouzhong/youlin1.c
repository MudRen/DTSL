
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "С����");
	set("long", @LONG
����һƬС���֡�������С�����ƺ����ϻ���֮���㲻��С����
������˵��ȥ���˺������ܻ��ų���������С��Ϊ�
LONG
	);


	set("exits", ([
        "east" : "/d/chengdu/wroad2",
		"west":__DIR__"youlin2",
	]));
       set("outdoors", "�ɶ�");
	setup();
}

int valid_leave(object ob,string dir)
{
  if(dir=="west"&&ob->query_skill("dodge",1)<120){
  ob->add_temp("mark/youlin1",1);
  if(ob->query_temp("mark/youlin1")<5)
  return notify_fail("ֻ��ವ�һ����һ֧�������ͷ����������������亹��ͣס�˽Ų���\n");
  else{
  message_vision("ֻ��ವ�һ����һ֧������$N�Ķ�ͷ��\n",ob);
  ob->delete_temp("mark/youlin1");
  ob->unconcious();
  return 0;
  }}
  return ::valid_leave(ob,dir);
}

