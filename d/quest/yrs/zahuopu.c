inherit ROOM;
#include <ansi.h>
string joke();
int do_search(string arg);
void create()
{
	set("short","�ӻ���");
	set("long", @LONG
���ǾŽ���һ���ӻ��̡�����������ң����Ե���������ⲻ�Ǻ�
��������������Ҳû�м������ˡ��ϰ弸��Ҫſ�ڹ�̨��˯���ˡ���̨
���Ա�����һ�Ű�ֽ[paper].
LONG);
        set("exits",([
 "west":"/d/jiujiang/beidajie1",
          ]));     
        set("item_desc",([
          "paper":(:joke:),
          ]));
        set("objects",([
          __DIR__"boss":1,
          ]));
	setup();      
}
string joke()
{
  object ob;
  ob=this_player();
  return HIW+ob->name()+"Ƿ����������ƽ����겻����ȷʵ�޳ܵĿ��ԡ�\n\n"NOR+
                        "                                    �ӻ����ƹ�\n";
}
void init()
{
  add_action("do_search","sou");
}
int do_search(string arg)
{
  object ob;
  object killer;
  ob=this_player();
  if(!ob->query_temp("yrs_find/mianfen"))
  return 0;
  if(time()-query_temp("no_mianfen")<15*60)
  return notify_fail("�����˰��죬����ʲôҲ�Ѳ�����\n");
  set_temp("no_mianfen",time());
  killer=new(__DIR__"guard");
  killer->move(environment(ob));
  tell_object(ob,"��ͻȻ����һ����ۣ���æ�������У�\n");
  message_vision(HIR"$N��æ��$n���˹�����������С͵��ɺ��ˣ������ɣ�\n"NOR,killer,ob);
  tell_object(ob,"���������������е���ۣ���\n");
  killer->kill_ob(ob);
  return 1;
}
