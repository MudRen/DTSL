
#include <ansi.h>
inherit ROOM;
int do_yell();

void create ()
{
  set ("short",HIY"����"NOR);
  set ("long", @LONG
�����ǳ�����������ĵ��š��ŵ�����������ͷľͷ�����ǵ���ȥ
������������Ҳ������Ϊ���ˡ����Գ���������������뿿����ͨ�У�
�����ȷ��һ�򵱹أ�����Ѷ�֮�ơ�����Ը�����(yell)����������
���š�
LONG);
  set("exits",([
	  "southeast":"/d/luoyange/shanlu3",
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
    object podao;
	me=this_player();
	where=environment(me);
	beipan=(int)me->query("beipan",1);
	if(beipan>=3)
		return notify_fail("����������������������:�������ֶ����������ͽ,��������Ƿ�������!\n");
    if(where->query("exits/enter"))
		return notify_fail("�����Ѿ���������!\n");
    podao=load_object(__DIR__"podao1");
    if(podao->query("exits/out"))
    return notify_fail("�����Ѿ���������!\n");
	call_out("do_bridge",5,where);
	message_vision("��������$N������:"+RANK_D->query_respect(me)+",��һ��,����ͷ��µ���!\n",me);
	tell_object(where,"ֻ��¡¡����,�����������ķ�������.\n");
	return 1;
}

void do_bridge(object where)
{   
    object podao1;
	podao1=load_object(__DIR__"podao1");

	tell_object(where,"ֻ���ѵ�һ��,�����Ѿ���������!\n");
	tell_object(podao1,"ֻ���ѵ�һ��,�����Ѿ���������!\n");
	podao1->set("exits/out",__DIR__"bridge");
	where->set("can_go",1);
	where->set("exits/enter",__DIR__"podao1");
	remove_call_out("do_bridge");
	call_out("do_close",20,where,podao1);
	return;
}

void do_close(object where,object podao1)
{
	tell_object(where,"ֻ��¡¡����,���ű�����ȥ��.\n");
	tell_object(podao1,"ֻ��¡¡����,���ű�����ȥ��.\n");
	where->delete("exits/enter");
	where->delete("can_go");
	podao1->delete("exits/out");
	remove_call_out("do_close");
	return;
}