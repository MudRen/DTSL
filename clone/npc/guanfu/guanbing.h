// guanbing.h
// all include �ٱ����佫 by Lklv 2002.1.18

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player())
	 && living(this_object())
	 && ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 0, ob);
        }
}

int accept_fight(object me)
{
	if (!me) return 0;
	if (query("id")=="wu jiang"){
		command("pei ");
		command("say �ҶԳ�͢�������񣬽����ô�ү�ҽ�ѵ��ѵ�㣡\n");
		fight_ob(me);
		return 1;
	}
	command("say ��ү����������ɱ�ţ��������㵹ù��\n");
	if (!is_killing(me->query("id")))
		me->add_condition("killer", 5);
	kill_ob(me);
	return 1;
}

void kill_ob(object ob)
{
	if (!ob) return;
	if (query("id") == "wu jiang")
		command("say �㣡�㣡�㣡���˰������������������������");
	else
		command("say �����������ߣ�����");
	::kill_ob(ob);
}
