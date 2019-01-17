
inherit F_CLEAN_UP;
inherit F_DBASE;

#include <ansi.h>

int quest_flag =0;

string *rooms = ({"shandong1","shandong2","shandong3","shandong4","shandong5"});

mapping *objnames = ({

([
"name":HIY"ǧ���˲�"NOR,
"id":({"ren shen","ren","shen"}),
]),
([
"name":WHT"��ɽѩ��"NOR,
"id":({"tianshan xuelian","xuelian"}),
]),
([
"name":MAG"ǧ�������"NOR,
"id":({"qiannian heshouwu","heshouwu"}),
]),
([
"name":HIY"�����"NOR,
"id":({"bainian jindan","jindan"}),
]),

});

int startquest(object ob)
{
	object room;
	mapping thing;
	
	quest_flag = 1;
	
	room = load_object(__DIR__+rooms[random(sizeof(rooms))]);
	
	thing = objnames[random(sizeof(objnames))];
	
	room->set("can_search/name",thing["name"]);
	room->set("can_search/id",thing["id"]);
	
	room = load_object(__DIR__+rooms[random(sizeof(rooms))]);
	ob->move(room);	
	
	call_out("stopquest",180,ob);
	
	return 1;
	
}

void stopquest(object ob)
{
	int i;
	object *killer;
	
	quest_flag = 0;
		
	killer = children(__DIR__"npc/killer");
	for(i=0;i<sizeof(killer);i++)
		if(objectp(killer[i]))
			destruct(killer[i]);
			
	if(!ob)
		return;
		
	
	tell_object(ob,"\nһ����Ӱ������Ϣ������������ߡ�����������\n\n"+
					"�㻹û��Ӧ��������Ӱһ���֣��Ѿ�ץס��ı��ģ�\n"+
					"ת˲֮�䣬��Ӱ�������뿪��ɽ����\n\n");
						
	ob->move("/d/changan/mishi");
	
	return;
	
}

int query_flag()
{
	return quest_flag;
}