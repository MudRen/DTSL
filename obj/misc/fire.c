inherit ITEM;
void create()
{
	set_name("���", ({ "fire stick","fire" }));
       	set("long", "����һ����ͨ�Ļ�ѡ�\n");
	set("weight", 30);
	set("unit", "��");
	set("value", 5);
	set("material", "ľ");
	setup();
}	
void init()
{
	add_action("fire","fire");
}
int fire()
{
	object me=this_player();
	me->set_temp("light",time());
	message_vision("$N����ѵ�ȼ��\n",me);
	set("long","ȼ���ŵĻ�ѡ�\n");
	set("value", 0);
	call_out("delay", 300, 1);
	return 1;
}
void delay(int phase)
{
	switch(phase) {
	case 1:
		write("����Ѿ��յ�һ���ˡ�\n" );
		set("long","�յ�һ��Ļ�ѡ�\n");
		call_out("delay", 240, phase + 1);
		break;
	case 2:
		write("����Ѿ���������ˣ�������ȥ��Ҫ�յ�������ˡ�\n" );
		set("long", "�������˵Ļ�ѡ�\n");
		call_out("delay", 60, phase + 1);
		break;
	case 3:
		write("�������У���Ѿ�Ҫ�յ�������ˣ��������ӵ������еĻ�ѡ�\n" );
		message_vision("$N���չ��Ļ���ӵ����ϡ�\n",this_player());
		this_player()->delete_temp("light");
		destruct(this_object());
		break;
	}
}
