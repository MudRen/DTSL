
inherit ITEM;
#include "map.h"
mapping name=([
"�ر�ͼ":"cangbao tu",
"�书�ؼ�":"miji",
]);

int do_wa();
int do_linghui(string arg);

void create()
{
	string *n;
	int i;
	n=keys(name);
	i=random(sizeof(n));
	set_name(n[i], ({ name[n[i]] }));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_drop",1);
		set("no_give",1);
		set("no_get",1);
		set("material", "��");		
	}
	setup();
}

string long()
{
   string *here;
   int i;
   if(query("long"))
   return query("long");
   if(query("name")=="�ر�ͼ"){
   	here=keys(map);
   	i=random(sizeof(map));
   	set("here",here[i]);
   	set("long","��˵����һ���ر�ͼ����˵���ز���"+map[here[i]]+"��\n");}
   else{
   set("skill",1);
   set("long","��˵����书�ؼ����԰��������[linghui]�Լ����书��\n");}
   return query("long");
}

void init()
{
  add_action("do_wa","wa");
  add_action("do_linghui","linghui");
}

int do_wa()
{
  object ob;
  object money;
  
  ob=this_player();
  if(!query("here")) return 0;
  if(query("here")!=base_name(environment(ob)))
  return notify_fail("�����ƺ����ǲ��б��صĵط���\n");
  message_vision("$N���˫������������\n",ob);
  money=new("/obj/money/gold");
  money->set_amount(5000);
  money->move(environment(ob));
  message_vision("$N�ڳ���һ�ѻƽ�\n",ob);
  destruct(this_object());
  return 1;
}

int do_linghui(string arg)
{
   object ob;
   
   ob=this_player();
   if(!query("skill")) return 0;
   if(!arg) return notify_fail("��Ҫ���ʲô�书��\n");
   if(!ob->query_skill(arg,1))
   return notify_fail("��û��ѧ������书��\n");
   message_vision("$N�����书�ؼ��������书����\n",ob);
   ob->set_skill(arg,ob->query_skill(arg,1)+10);
   if(ob->query_skill(arg,1)>ob->query("max_pot")-100)
   ob->set_skill(arg,ob->query("max_pot")-100);
   destruct(this_object());
  return 1;
}