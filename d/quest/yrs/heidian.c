inherit ROOM;
#include <ansi.h>
string joke();
int do_search(string arg);
void create()
{
	set("short","������ջ");
	set("long", @LONG
����һ���ջ�����ǿ������������壬�����ϰ嶼��֪���ܵ�����
ȥ�ˡ������ϻ��˺���һ��ҡ�һ����紵�����㲻��ӿ�������⡣
�ŵ��Ա߻���һ��Сֽ��paper��
LONG);
        set("exits",([
          "south":"/d/dongming/dalu7",
          ]));     
        set("item_desc",([
          "paper":(:joke:),
          ]));
        set("resource/water",1);
	setup();      
}
string joke()
{
  object ob;
  ob=this_player();
  return HIR+ob->name()+"Ƿ����һ�����ƽ����겻����ȷʵ�޳ܵĿ��ԡ�\n\n"NOR+
                        "                                    ������ջ�ƹ�\n";
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
  if(!ob->query_temp("yrs_find/skin"))
  return 0;
  if(time()-query_temp("no_skin")<15*60)
  return notify_fail("�����˰��죬����ʲôҲ�Ѳ�����\n");
  set_temp("no_skin",time());
  killer=new(__DIR__"killer");
  killer->move(environment(ob));
  message_vision(HIR"$N�����Ų˵���$n���˹�����������ĺڵ���Ҳ���ѣ�����������\n"NOR,killer,ob);
  killer->kill_ob(ob);
  return 1;
}
