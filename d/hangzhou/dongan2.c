
#include <ansi.h>
inherit ROOM;
#include <job_money.h>

void create ()
{
  set ("short","��������");
  set ("long", @LONG
�����������Ķ���������ɻ���㣬����ƽ���羵����ʱ���οʹ�
�����߹���
LONG);

  set("exits", ([ 
 "south":__DIR__"dongan1",
        ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}
void init()
{
	object *ob;object here;int i;
	here=find_object(__DIR__"dongan2");
	ob=all_inventory(here);
	for(i=0;i<sizeof(ob);i++)
	{
		if(ob[i]->query_temp("shang_kill_pantu/6")&&!ob[i]->query_temp("shang_kill_pantu/start"))
		{   ob[i]->set_temp("shang_kill_pantu/start",1);
			call_out("tao_come",1,ob[i]);
		}
	}
	return;
}

void tao_come(object ob)
{
	object killer;
	if(!objectp(ob)) {remove_call_out("tao_come");return;}
	killer=new("/d/job/feima/taoshu-sheng");
	copy_object(killer,ob);
	killer->set_name("����ʢ",({"tao shusheng","tao"}));
	killer->set("title","��ͽ");
	killer->delete("family");
	killer->delete("nickname");
	killer->delete("shili");
	killer->delete("title");
	killer->set("combat_exp",ob->query("combat_exp")*3/2);
	set_all_skill(killer,ob->query("max_pot")-130);
	killer->move(environment(ob));
	message_vision("$N��Ц��:����Ҳ����ɱ��!\n",killer);
	killer->kill_ob(ob);
    remove_call_out("tao_come");
	call_out("tao_go",300,killer);
	return;
}

void tao_go(object ob)
{
	if(!objectp(ob)) {remove_call_out("tao_go");return;}
	message_vision("$N���ò���,�Ҵ�����!\n",ob);
	destruct(ob);
    remove_call_out("tao_go");return;
}

