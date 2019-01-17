
#include <ansi.h>
inherit ROOM;

int do_yell();
void create ()
{
  set ("short","���µ�");
  set ("long", @LONG
�����Ǹ������µ��������Ѿ��Ƿ����������Ɽ�ˡ��ϱ��Ƿ���
�����ĵ��š��ŵ�����������ͷľͷ�����ǵ���ȥ������������Ҳ����
��Ϊ���ˡ����Գ���������������뿿����ͨ�У������ȷ��һ�򵱹أ�
����Ѷ�֮�ơ�����Ը�����(yell)���������µ��š�
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"podao2",
	
         ]));
  set("objects",([
	  __DIR__"npc/dizi":1,
	  ]));
  set("outdoors","feima");
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
    object bridge;
	me=this_player();
	where=environment(me);
    if(where->query("eixts/out")) return notify_fail("�����Ѿ���������!\n");
    bridge=load_object(__DIR__"bridge");
    if(bridge->query("exits/enter"))
    return notify_fail("�����Ѿ���������!\n");
	call_out("do_bridge",5,where);
	message_vision("��������$N������:"+RANK_D->query_respect(me)+",��һ��,����ͷ��µ���!\n",me);
	tell_object(where,"ֻ��¡¡����,�����������ķ�������.\n");
	return 1;
}

void do_bridge(object where)
{
    object bridge;
	bridge=load_object(__DIR__"bridge");
	tell_object(where,"ֻ���ѵ�һ��,�����Ѿ���������!\n");
	tell_object(bridge,"ֻ���ѵ�һ��,�����Ѿ���������!\n");
	where->set("exits/out",__DIR__"bridge");
	where->set("can_go",1);
	bridge->set("exits/enter",__DIR__"podao1");
	remove_call_out("do_bridge");
	call_out("do_close",20,where,bridge);
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
