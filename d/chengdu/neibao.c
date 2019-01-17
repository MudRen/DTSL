
#include <ansi.h>
inherit ROOM;

int do_yell();
void create ()
{
  set ("short","�ڱ�");
  set ("long", @LONG
�����Ƕ��𱤵��ڱ��ˡ��м���������æ��æȥ�������ڳɶ���
�ܴ����������������ļ��Ҳ�Ƿǳ��ϸ����������𱤣������
��������(yell)���ŵĶ��𱤵��ӡ�
LONG);

  set("exits", ([ 
  
	  "south":__DIR__"zhaobi",
	
         ]));
  set("objects",([
	  __DIR__"npc/dizi2":1,
	  ]));
  set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
void init()
{
	add_action("do_yell","yell");
}

int do_yell()
{
    int beipan;object me;object where;
    
	me=this_player();
	where=environment(me);
    if(where->query("can_go")||query("exits/out")) return notify_fail("�����Ѿ���������!\n");
	call_out("do_bridge",5,where);
	message_vision("��������$N������:"+RANK_D->query_respect(me)+",��һ��,����ͷ��µ���!\n",me);
	tell_object(where,"ֻ��¡¡����,�����������ķ�������.\n");
	return 1;
}

void do_bridge(object where)
{
    object bridge;
	bridge=load_object(__DIR__"duzunbao");
	tell_object(where,"ֻ���ѵ�һ��,�����Ѿ���������!\n");
	tell_object(bridge,"ֻ���ѵ�һ��,�����Ѿ���������!\n");
	where->set("exits/out",__DIR__"duzunbao");
	where->set("can_go",1);
	bridge->set("exits/enter",__DIR__"neibao");
	remove_call_out("do_bridge");
	call_out("do_close",5,where,bridge);
	return;
}

void do_close(object where,object bridge)
{
	tell_object(where,"ֻ��¡¡����,���ű�����ȥ��.\n");
	tell_object(bridge,"ֻ��¡¡����,���ű�����ȥ��.\n");
	where->delete("exits/out");
	where->delete("can_go");
	bridge->delete("exits/enter");
	remove_call_out("do_close");
	return;
}
