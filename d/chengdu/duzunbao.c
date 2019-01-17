
inherit ROOM;
#include <ansi.h>
int do_yell();
void create()
{
	set("short",HIC"����"NOR);
	set("long", @LONG
�����Ƕ��𱤵Ĵ��ſڡ������ǳɶ�����������͵�ס����ƽʱ
û���˸�������ͣ���������ǳɶ����������һ���ط�������ƽʱҲ
�кܶ����ֺ�����Ͷ���������Ը�������(yell)���ڵĻ���������
���𱤡�
LONG);
	set("outdoors", "�ɶ�");

	set("exits", ([
        "northeast" : __DIR__"hubianlu",
	
	]));
	set("objects",([
		__DIR__"npc/dizi2":1,
		]));

	setup(); 
	
"/obj/board/duzun_b"->foo();
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
	beipan=(int)me->query("beipan",1);
	if(beipan>=3)
		return notify_fail("���𱤵�������������:�������ֶ����������ͽ,��������Ƕ���!\n");
    if(where->query("can_go")||query("exits/enter"))
		return notify_fail("�����Ѿ���������!\n");
	call_out("do_bridge",5,where);
	message_vision("��������$N������:"+RANK_D->query_respect(me)+",��һ��,����ͷ��µ���!\n",me);
	tell_object(where,"ֻ��¡¡����,�����������ķ�������.\n");
	return 1;
}

void do_bridge(object where)
{   
    object neibao;
	neibao=load_object(__DIR__"neibao");

	tell_object(where,"ֻ���ѵ�һ��,�����Ѿ���������!\n");
	tell_object(neibao,"ֻ���ѵ�һ��,�����Ѿ���������!\n");
	neibao->set("exits/out",__DIR__"duzunbao");
	where->set("can_go",1);
	where->set("exits/enter",__DIR__"neibao");
	remove_call_out("do_bridge");
	call_out("do_close",5,where,neibao);
	return;
}

void do_close(object where,object neibao)
{
	tell_object(where,"ֻ��¡¡����,���ű�����ȥ��.\n");
	tell_object(neibao,"ֻ��¡¡����,���ű�����ȥ��.\n");
	where->delete("exits/enter");
	where->delete("can_go");
	neibao->delete("exits/out");
	remove_call_out("do_close");
	return;
}
