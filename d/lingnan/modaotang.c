
#include <ansi.h>

inherit ROOM;
string do_joke();
int do_skill(string arg);
void create ()
{
  set ("short","ĥ����");
  set ("long", @LONG
�������μұ���ĥ���á���������һ���ʯ����Ի[ĥ��ʯ](shi)��
������ŵ����ֶ���[�쵶]��ȱҪɱ֮�ˡ�
LONG);

  set("exits", ([ 

   "northwest":__DIR__"caodi",
   "south":"/d/job/sjbjob/zhifatang",
   "east":"/d/clone/room/orgsaferoom/songjia/xuandaotang",
       ]));
  set("item_desc",([
	  "shi":(:do_joke:),
    ]));

  set("valid_startroom", 1);
 
  setup();
 
}

void init()
{
	add_action("do_skill","pi");
	
}

int do_skill(string arg)
{
	object weapon,me;
	me=this_player();
	if(!arg||arg!="ʯͷ")
		return notify_fail("��Ҫ��ʲô��\n");
    weapon=me->query_temp("weapon");
	if(!objectp(weapon))
		return notify_fail("û��������ʲô����\n");
	if(weapon->query("skill_type")!="blade")
		return notify_fail("�㻹���õ����ɣ�\n");
	if(me->query("gin")<=25)
		return notify_fail("��̫���ˣ�����ЪЪ�ɣ�\n");
	if(weapon->query("flag")==1)
		return notify_fail("�����Ŷϵ��ı�����ʲô�ð���\n");
	if(me->is_busy()) return notify_fail("����æ���أ�\n");
	if(me->query_skill("blade",1)>=101)
		return notify_fail("��Ļ��������Ѿ��ܸ��ˣ������Ѿ��޷���ϰ�ˣ�\n");
	message_vision("$N����"+weapon->name()+"����ĥ��ʯ��ȥ����������ǣ�\n",me);
	me->receive_damage("gin",25);
	//weapon->add("strong",-5+random(5));
	me->improve_skill("blade",me->query_int()/2+20+random(5));
	/*
	if(weapon->query("strong")<=0){
	message_vision("ֻ����������һ����$N���е�"+weapon->name()+"�ϳ������أ�\n",me);
	weapon->set("strong",0);
	weapon->set("flag",1);
	weapon->set("org_name",weapon->name());
	weapon->set("name","�ϵ���"+weapon->name());
  }
 */
	return 1;
}

string do_joke()
{
	return "ֻ��ĥ��ʯ�Ͽ��ţ�\n"HIR"    "+this_player()->name()+"\n"NOR;
}
