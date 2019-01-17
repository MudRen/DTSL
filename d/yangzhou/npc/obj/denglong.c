#define TIME_TICK1 ((time()-900000000)*60)
inherit ITEM;
#include <ansi.h>
int do_fire();
int do_see();
void create()
{
  set_name("�����", ({ "deng long", "deng","long" }) );
  set_weight(250);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "����һ��С�����������Ե�ȼ(fire)��,Ȼ��Ϳ��Կ�(see)��Χ�ˡ�\n");
set("value",50);
	set("no_drop",1);
    set("unit", "ֻ");
  }
  setup();
}

void init()
{
	add_action("do_fire","fire");
	add_action("do_see","see");
}

int do_fire()
{
	object ob;
	ob=this_player();
/*	if ((	(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") <= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") <= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") <= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") <= 0) ))
		return notify_fail("�����ģ���ʲô���򰡣�\n");*/
if(!present("deng long",ob))
return notify_fail("ʲô��\n");
	if(this_object()->query("lose"))
		return notify_fail("�������Ѿ�û�������ˡ�\n");
	if(this_object()->query("fired"))
		return notify_fail("�����Ѿ������ˡ�\n");
	message_vision("$NС�ĵص�ȼ��һֻС�������\n",ob);
	this_object()->set("name",HIR"�����"NOR);
	ob->set_temp("apply/short",({HIR""+ob->name()+"���Ÿ�С�����վ�����"NOR}));
	this_object()->set("fired",1);
call_out("lose",6,ob,this_object(),20);
	return 1;
}

void lose(object pal,object ob,int times)
{
	if(!ob){remove_call_out("lose");return;}
	tell_object(environment(ob),"������е����������ر�С�ˡ�\n");
	if(--times<=0)
	{
      tell_object(environment(ob),"������е���������ȼ���ˡ�\n");
	  ob->set("name",HIB"����"NOR);
	  ob->set("lose",1);
	  pal->delete_temp("apply/short");
	  remove_call_out("lose");
	  destruct(this_object());
	  return;
	}
	remove_call_out("lose");
	call_out("lose",6,pal,ob,times);
	return;
}

int do_see()
{
	object me,*ob,here;int i;mapping exits;string *d;
	me=this_player();
if(!present("deng long",me))
return notify_fail("ʲô?\n");
	here=environment(me);
	ob=all_inventory(here);
	exits=here->query("exits");
	if(this_object()->query("lose"))
		return notify_fail("���ɥ�ط��ֵ����Ѿ�û�����ˡ�\n");
	if(!this_object()->query("fired"))
		return notify_fail("��Ҫ�Ȱѵ������š�\n");
	tell_object(me,"���õ������Ĵ���ȥ�����������Χ��\n");
	if(sizeof(ob)<=1) tell_object(me,"ʲô��Ҳû�С�\n");
	else{
	for(i=0;i<sizeof(ob);i++)
	{   if(me!=ob[i]){
        tell_object(me,ob[i]->short()+"\n");
		tell_object(ob[i],me->name()+"���ŵ����������˼��¡�\n");}
	}
	}
	if( !mapp(exits) || !sizeof(exits) ){
		tell_object(me,"�㷢�����ܸ�����û��ʲô·��\n");}
	else{
        d=keys(exits);tell_object(me,"�㷢�����ܵĳ�����:\n");
	    for(i=0;i<sizeof(d);i++)
		{
		
tell_object(me,HIY+d[i]+NOR+"   ");
		}
tell_object(me,"\n");
	}
	return 1;

}
