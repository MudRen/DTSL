
#include <room.h>

inherit ROOM;
string do_look();
int do_wa();
int do_ke();
int do_tui(string arg);
int do_zuan(string arg);
void create()
{
	set("short", "�ص�");
	set("long", @LONG
����һ�صء�����ֻ��һ��������ķأ���֪���������ʲô�ˡ�
ǰ�滹����һ��ʯ��(bei) ��һ����紵�����㲻�����˸���ս��
LONG
	);


	set("exits", ([
		"east" :__DIR__"xiaojing2",
	]));
	set("item_desc",([
	 "bei":(:do_look:),
	 ]));
       set("outdoors", "�ɶ�");
	setup();
}

void init()
{
  add_action("do_ke","ketou");
  add_action("do_wa","wa");
 // add_action("do_tui","tui");
 // add_action("do_zuan","zuan");
}

string do_look()
{
  object ob;
  ob=this_player();
  if(!ob->query_temp("ask_shi"))
  return "������ּ����������֪����˭��Ĺ����\n";
  return "�Ե���ɽ֮Ĺ��\n";
}

int do_wa()
{
  object me;
  string msg;
  
  me=this_player();
  
  if(!me->query_temp("ask_shi")||
     !me->query_temp("ketou")
    )
  return notify_fail("�����˰��죬����ʲôҲ�ڲ�����\n");
  
  msg="\n$NͻȻ�ڵ�һ�����ᣬ�����������ɽ�����ľ�ѧ��\n"+
      "$N��ϸ���ž��ᣬ����������˰Ե��ľ��裡\n"+
      "$N����һ��˫�ۣ������ѳ�ƬƬ����ʧ�ڷ��С�\n";
  message_vision(msg,me);
  me->do_command("haha");
  me->set("perform_quest/badao",1);
  return 1;
  
}
int do_ke()
{
  object ob;
  ob=this_player();
  ob->set_temp("ketou",1);
  message_vision("$N���������ؿ���һ��ͷ��\n",ob);
  return 1;
}
/*int do_tui(string arg)
{
  object me;
  me=this_player();
  if(!arg||arg!="ʯ��"||!me->query_temp("ketou"))
  return notify_fail("ʲô?\n");
  if(me->query("force")<2000||
  me->query_skill("force",1)<100)
  return notify_fail("�����˰��죬����ʯ����˿������\n");
  if(me->query("sen")<20)
  return notify_fail("���۵�ͷ���ۻ���ʯ����˿������\n");
  message_vision("$N����һ�ƣ�ֻ��ʯ���ں�¡��������һ�ԣ�\n",me);
  tell_object(me,"ǰ��©��һ���ڶ����ƺ��������ȥ.\n"+
                 "ʯ������д�ż����֣���˶�ѧϰ�书�ߣ�\n"+
                 "һ��ֻ��һ�ν�ȥ�Ļ��ᣬ�úð��գ�\n");
  me->set_temp("can_zuan",1);
  return 1;
}

int do_zuan(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="��"||
  !ob->query_temp("can_zuan"))
  return notify_fail("ʲô��\n");
  if(ob->query("only/xiulian"))
  return notify_fail("һ����һ��ֻ�ܽ�ȥһ��!\n");
  if(ob->query("eff_kee")*100/ob->query("max_kee")>25)
  return notify_fail("���겻��ȥ��\n");
  message_vision("$N�ο��Ӳݣ����˽�ȥ��\n",ob);
  CHANNEL_D->do_channel(this_object(), "rumor",
   sprintf("%s��������������Ҫ�˳�����һ��ʱ���ˣ�", ob->name()));
  ob->add_array("only","xiulian");
  ob->move(__DIR__"mishi");
  return 1;
}
*/