#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
��˵�������ºó�����û�뵽�����ϸ����졣��ô������治��Ϊǧ����ľ��
��������Ҷ��ï����˵�����ʱ���Ƕ���ģ���˱��Ϊ����������ĵط���
������ż������������������ӣ��м��ü�������֦����һ������һ���輸�ˡ�
����̧ͷ���Ͽ���ʱ���ƺ��и�Ӱ������֮���ƶ�������Ҳ���Ƿ紵������ɵ�
�����

LONG
        );
set("no_time", 1);
set("chat_room",1);
        set("freeze",1);
        set("no_clean_up", 0);
        set("exits", ([
        "down": "/d/yangzhou/guangchang",
        ]));
        set("objects", ([
       "/u/kouzhong/shizhe" : 1,
]));
         set("no_fight",1);
         set("no_magic",1);
         set("no_time",1);
          set("valid_startroom","1");
        set("freeze",1);
        setup();
        call_other("/obj/board/comm_b", "???");
}
void init()
{
    add_action("do_jump","tiao");
add_action("discmds",({"sleep","respitate","exert","array","duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","xi","learn","kill","steal","xue","conjure","fight","hit","xi","perform","prcatice","scribe","tuna","surrender"}));
    add_action("do_climb", "climb");
}
int no_action(string str)
{
       write(HIY"���ϱ����������� \n"NOR);
       return 1;
}
int discmds()
{
        tell_object(this_player(),"�����㻹��ר������ɣ�\n");
        return 1;
}



int do_jump(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg!="down") return notify_fail("��Ҫ��������\n");
      if (me->is_fighting() || me->is_busy() )  return notify_fail("����æ���أ�\n");
        message("vision",
                me->name() + "��ԥ��һ�£�����������������ȥ��\n���ء���һ���죬�ƺ�����"+me->name()+"�Һ���һ��!\n",
                environment(me), ({me}) );
                me->move("/d/yangzhou/guangchang");
        message("vision",
                me->name() + "�Һ�һ���������ϵ���������\n",
                environment(me), ({me}) );
        return 1;
}
int valid_leave(object me, string dir)
{

        if ( dir=="down" && !wizardp(me))
        return notify_fail("�̸���֪�����ĸ����һ￳����⣬����ֻ�����(tiao)��ȥ��\n");
         if ( dir=="up" && !wizardp(me))
        return notify_fail("����û��ֱ���ߣ�������ֻ����(climb)��ȥ��\n");

        else return 1;
}



