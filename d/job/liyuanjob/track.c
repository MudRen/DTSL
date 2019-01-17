
#include <ansi.h>

inherit ITEM;
#define TIME_TICK1 (time()*60)
#define MAX_LIGHT_TIME 1200
int do_drive(string arg);
mapping default_dirs = ([
	"north":		"��",
	"south":		"��",
	"east":			"��",
	"west":			"��",
	"northup":		"����",
	"southup":		"�ϱ�",
	"eastup":		"����",
	"westup":		"����",
	"northdown":	"����",
	"southdown":	"�ϱ�",
	"eastdown":		"����",
	"westdown":		"����",
	"northeast":	"����",
	"northwest":	"����",
	"southeast":	"����",
	"southwest":	"����",
        "enter":                "��",
	"up":			"��",
	"down":			"��",
	"out":			"��",
]);
void create()
{
        set_name("���ݳ�", ({ "che" }) );
        set_weight(1000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���������ݵĴ󳵡�");
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
                set("no_get",1);
                set("material", "wood");
        }

        setup();
}

void init()
{
   add_action("do_drive","drive");
   if(!query("last_time"))
    set("last_time",time());
}

int do_drive(string arg)
{
  object ob;
  object env;
  object room;
  string dir;
  object *inv;
  
  ob=this_player();
  if(query("owner")!=ob&&!wizardp(ob))
  return notify_fail("�ⲻ���㻤�͵����ݳ���\n");
  if(!arg)
  return notify_fail("��Ҫ�ѳ����ĸ������ƣ�\n");
  if(time()-query("busy_time")<3+random(1))
  return notify_fail("����ЪЪ�ɣ�\n");
  if(ob->query("sen")<20)
  return notify_fail("��̫ƣ���ˣ�ЪЪ���߰ɣ�\n");
  if(ob->is_fighting())
  return notify_fail("�㻹���ȴ����̰ɣ�\n");
  if(ob->is_busy())
  return notify_fail("����æ���أ�\n");
  dir=environment(ob)->query("exits/"+arg);
  if(!stringp(dir))
  return notify_fail("����û���������\n");
  inv=all_inventory(ob);
  if(sizeof(inv)>=40)
  return notify_fail("�����ϵĶ���̫���ˣ������߲���·��\n");
  env=environment(ob);
  if(default_dirs[arg])
   if ((	(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ) 
		&& env->query("outdoors")
		&& ob->query_temp("light")<time()-MAX_LIGHT_TIME
		&& (!wizardp(ob) || !ob->query("env/wiz_look")))    
  message_vision("һ�����ʵ���Ӱ����$n��"+default_dirs[arg]+"��ȥ��\n",
                 this_object());
   else
  message_vision("$N����$n��"+default_dirs[arg]+"��ȥ��\n",
                 ob,this_object());
  room=load_object(dir);
  if(!objectp(room))
  return notify_fail("��е�������Щ�����ˣ�Ӧ�ñ���BUG�ˡ�\n");
  if ((	(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ") >= 0) ) 
		&& env->query("outdoors")
		&& ob->query_temp("light")<time()-MAX_LIGHT_TIME
		&& (!wizardp(ob) || !ob->query("env/wiz_look")))    
  tell_object(room,"һ�����ʵ���Ӱ����"+query("name")+"���˹�����\n");
  else
  tell_object(room,ob->name()+"����"+query("name")+"���˹�����\n");
  this_object()->move(room);
  set("busy_time",time());
  ob->add("sen",-10+random(10));
  ob->move(room);
  message_vision("$N�����س����´�����һ�£�������û�п��ɵ�����\n",ob);
  return 1;
}

int clean_up()
{
  if(time()-query("last_time")<3600*3)
   return 0;
  return 1;
}