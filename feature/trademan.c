
inherit NPC;
int do_teach(string arg);
void create()
{
   set_name("������",({ "maimai wang","maimai","wang"}) );
        set("gender", "����" );
        set("age", 40);
   set("long", "����һ�����ˣ��˳�[������]������������һ�ס�\n");
   set("combat_exp",300000);
   set("str",26);
   set("per", 22);
   set("force",500);
   set("max_force",500);
   set("kee",800);
   set("max_kee",800);
   set("sen",500);
   set("max_sen",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
    set("vocation","����");
   setup();
   carry_object("/obj/armor/cloth")->wear();
  
}

void init()
{
  add_action("do_teach","qingjiao");
}
int do_teach(string arg)
{
	object me,ob;
	me=this_player();
	ob=this_object();
	if(!arg)
		return notify_fail("��Ҫ��˭��̣�\n");
	if(!present(arg,environment(me)))
		return notify_fail("����û����ˣ�\n");
	if(me->query("vocation")!="����")
		return notify_fail("���ֲ������ˣ��������ʲô��?\n");
	if(me->query("gin")<=3)
		return notify_fail("��̫���ˣ���ЪЪ�ˣ�\n");
        if(me->is_busy())
        return notify_fail("��̫æ�ˣ�\n");
	switch(MONEY_D->player_pay(me,10)){
		case 0:return notify_fail("������һ����:ûѧ������ô���㣿\n");
		case 2:return notify_fail("������һЦ�������ڲ��������ˣ���Ʊ����ô�ҵÿ���\n");
		default:break;}
	if(me->query("potential")<=0)
	return notify_fail("���Ǳ�ܲ����ˣ�\n");
	if(me->query_skill("trade",1)>me->query("int")*8)
	return notify_fail("����ּۻ����Ѿ�ѧ�������ˣ������Լ�ȥ��ϰ�ɣ�\n");
	me->add("potential",-1);
	me->improve_skill("trade",me->query_int()/2+random(3));
	me->receive_damage("gin",3+random(3));
	message_vision("$N��$n���[�ּۻ���]�����⣬��������һЩ�ջ�\n",me,ob);
	return 1;
}


