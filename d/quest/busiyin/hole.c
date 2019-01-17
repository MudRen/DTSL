
inherit ROOM;

void init()
{
	add_action("do_search","search");
	
}

int do_search()
{
	object ob,killer;
	object thing;
	
	ob = this_player();
	
	if(!ob->query_temp("do_bsy_quest2"))
		return 0;
	if(!environment(ob)->query("can_search"))
		return notify_fail("������������һ�£�ʲôҲû���֡�\n");
	
	thing = new(__DIR__"obj/thing");
	thing->set_name(environment(ob)->query("can_search/name"),
					environment(ob)->query("can_search/id"));
	environment(ob)->delete("can_search");
	
	thing->move(ob);
	tell_object(ob,"\n�㷭�˷����ϵ�����ͻȻ�ҵ���һ"+thing->query("unit")+
				thing->query("name")+"��\n\n");
	
	killer = new(__DIR__"npc/killer");
	killer->set_status(ob,1);
	killer->move(environment(ob));
	
	message_vision("\n$N����������"+RANK_D->query_rude(ob)+"������������Ķ������������ɣ�\n��",
					killer);
	
	killer->kill_ob(ob);
	
	return 1;
	
}