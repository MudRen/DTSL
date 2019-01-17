// food.c

#include <dbase.h>
#include <name.h>
#include <poison.h>
void init()
{
	add_action("do_eat", "eat");
	if (!query("decay")&&!query("no_decay")) {
		set("decay", 1);
               call_out("decay", 280);
	}
}

int do_eat(string arg)
{
	int avai,remain;
	if( !this_object()->id(arg) ) return 0;
/*        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɡ�\n");*/
/*this_player()->start_busy(1);*/
	if( !query("food_remaining") )
		return notify_fail( name() + "�Ѿ�ûʲ��óԵ��ˡ�\n");
	if( (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() )
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");
	remain = (int) query("food_remaining") * (int) query("food_supply");
	avai = (int)this_player()->max_food_capacity() - (int)this_player()->query("food");
        if( remain > avai )
        {
        this_player()->add("food", avai);
        add("food_remaining", -(avai/(int)query("food_supply")));
        }
        else
        {
        this_player()->add("food",remain);
        set("food_remaining", 0);
        }

	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	// This allows customization of drinking effect.
	if( query("eat_func") ) return 1;
        POISON_D->apply_poison(this_player(),this_object());
	set("value", 0);
	if( !query("food_remaining") ) {
		message_vision("$N��ʣ�µ�" + name() + "�Ե�ǬǬ������\n", this_player());
		if( !this_object()->finish_eat() )
			destruct(this_object());
	} else 
		message_vision("$N����" + name() + "ҧ�˼��ڡ�\n", this_player());

	return 1;
}

void decay()
{
	object me = this_object(), ob = environment();
        if (!me || !ob) return;
	switch(query("decay", 1)) {
		case 2:
			set_temp("apply/long", ({ query("long") + "���ǿ��������Ǻ����ʡ�\n" }));
			tell_object(ob, me->name()+"����ɫ��Щ�����ˡ�\n");
			break;
		case 3:
			set_temp("apply/long", ({ query("long") + "��������ɢ����һ�����ŵ�ζ����\n" }));
			tell_object(ob, me->name()+"ɢ����һ�����ŵ�ζ����\n");
			break;
		case 4:
			set_temp("apply/long", ({ query("long") + "������Щ�����ˡ�\n" }));
			tell_object(ob, me->name()+"��Щ�����ˣ������̱ǵ�ζ����\n");
			break;
		default:
			tell_object(ob, me->name()+"�������õ��ˡ�\n");
			destruct(this_object());
			return;
	}
	add("decay", 1);
	call_out("decay",180);
}