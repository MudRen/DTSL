// �ɿ�
// caikuang-chang11.c
// augx@sj 9/10/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","�ɿ�");
	set("long",
"������һ����ɽ��һ��ɽ�壬�����Ѿ����ڳ�һ����ӣ����ǻ����в���
�ɿ������˵��ڿ�
"); 
        
	set("exits",([
		"out" : __DIR__"caikuang-chang1",
	]));
	
	set("kuangshi",30);
	set("outdoors", "���ݽ���");
	set("incity",1);
	setup();
}

#include "caikuang-chang.h"