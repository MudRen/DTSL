/*
 * File    : ������ (/u/yanyan/dmjob/dmjob_0_17.c)
 * Author  : [1;37m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
����������ɽ�ķ������ˡ��ϱ���һ��ɽ�塣������һ�����¡���
����ƺܸߣ����Կ�����������ɽ�ľ�ɫ�����������֮ʱ����������
������������ա���˵����������ʩչ������������������Ϊ�����롣
������һ���ʯͷ���ƺ�������һ�¡�
LONG
);
        set("exits",([
	"southwest" : __DIR__"dmjob_2_15",
	"eastdown" : __DIR__"dmjob_2_19",
	"east" : __DIR__"dmjob_0_19",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}

void init()
{
   add_action("do_ci","za");
}

int do_ci(string arg)
{
   object me,weapon;
   me=this_player();
   if(!arg||arg!="ʯͷ")
   return notify_fail("��Ҫ��ʲô��\n");
   if(!objectp(weapon=me->query_temp("weapon")))
   return notify_fail("û����������Ҫ��������\n");
   if(weapon->query("skill_type")!="hammer")
   return notify_fail("��Ӷ�"+weapon->name()+"���˼��£����ֺ����ô���\n");
   if(weapon->query("flag")==1)
   return notify_fail("���ɥ�ķ������еı����Ѿ��ϵ��ˣ�\n");
   if(me->query("sen")<20)
   return notify_fail("�㾫��̫���ˣ�\n");
   if(me->query_skill("hammer",1)>=101)
   return notify_fail("��Ļ��������ܸ��ˣ��������Ѿ��޷�����ˣ�\n");
   if(me->is_busy())
   return notify_fail("����æ���أ�\n");
   
   message_vision(YEL"$N��һ�������������е�"+weapon->name()+"��ʯͷ��ȥ��\n"NOR,me);
   me->improve_skill("hammer",me->query_int()/2+20+random(5));
   me->add("sen",-20);
   if(me->query_skill("hammer",1)<50)
   message_vision("$N����ĺ����˼�����\n",me);
   else if(me->query_skill("hammer",1)<100)
   message_vision("ֻ������һ����ʯͷ��$N�ҳ�һ����ӡ�\n",me);
   else if(me->query_skill("hammer",1)<150)
   message_vision("ֻ������һ����ʯͷ��$N�ҵ��ѳ������ƣ�\n",me);
  
   return 1;
}
