
inherit NPC;
string give_book();
string give_book2();
string give_book3();
string give_book4();

void create()
{
   set_name("��ʦ",({ "wu shi","wu","shi" }) );
   set("gender", "����" );
   set("age", 32);
   set("long", "������Զ�ھֵ���ʦ���������������ݡ�\n");
       
   set("combat_exp", 90000);
   set("str", 28);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",70);
   set_skill("parry",70);
   set_skill("dodge",70);
   set_skill("force",70);
   set("max_force",200);
   set("force",200);
   set("inquiry",([
	   "�����м�":(:give_book:),
	   "����ȭ��":(:give_book2:),
	   "����ذ��":(:give_book3:),
	   "�����ȷ�":(:give_book4:),
	   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
string give_book()
{
	object me,ob,book;
	me=this_player();ob=this_object();
	if(me->query_skill("parry",1)>100)
		return "��Ļ�������ܺ��ˣ��ҿ�ûʲôָ����ˣ�\n";
	if(ob->query("get_book"))
		if(ob->query("get_book")==me->name())
			return "���Ǹո���һ�����𣿻�����������ʲô����\n";
		else return "�Ҹո���"+ob->query("get_book")+"һ���������мܡ�����ȥ����Ҫ�ɣ�\n";
	book=new(__DIR__"obj/pbook");
	ob->set("get_book",me->name());
	tell_object(me,""+ob->name()+"������һ���������мܡ���\n");
	book->move(me);
	return ""+RANK_D->query_respect(me)+"���Ǻú�ѧϰ�����ɣ�\n";
}
string give_book2()
{
	object me,ob,book;
	me=this_player();ob=this_object();
	if(me->query_skill("cuff",1)>100)
		return "��Ļ�������ܺ��ˣ��ҿ�ûʲôָ����ˣ�\n";
	if(ob->query("get_book2"))
		if(ob->query("get_book2")==me->name())
			return "���Ǹո���һ�����𣿻�����������ʲô����\n";
		else return "�Ҹո���"+ob->query("get_book2")+"һ��������ȭ��������ȥ����Ҫ�ɣ�\n";
	book=new(__DIR__"obj/cbook");
	ob->set("get_book2",me->name());
	tell_object(me,""+ob->name()+"������һ��������ȭ������\n");
	book->move(me);
	return ""+RANK_D->query_respect(me)+"���Ǻú�ѧϰ�����ɣ�\n";
}
string give_book3()
{
	object me,ob,book;
	me=this_player();
	ob=this_object();
	
	if(me->query_skill("dagger",1)>100)
		return "��Ļ�������ܺ��ˣ��ҿ�ûʲôָ����ˣ�\n";
	if(ob->query("get_book3"))
		if(ob->query("get_book3")==me->name())
			return "���Ǹո���һ�����𣿻�����������ʲô����\n";
		else return "�Ҹո���"+ob->query("get_book3")+"һ��������ذ��������ȥ����Ҫ�ɣ�\n";
	book=new(__DIR__"obj/dbook");
	ob->set("get_book3",me->name());
	tell_object(me,""+ob->name()+"������һ��������ذ������\n");
	book->move(me);
	return ""+RANK_D->query_respect(me)+"���Ǻú�ѧϰ�����ɣ�\n";
}
string give_book4()
{
	object me,ob,book;
	me=this_player();
	ob=this_object();
	
	if(me->query_skill("staff",1)>100)
		return "��Ļ�������ܺ��ˣ��ҿ�ûʲôָ����ˣ�\n";
	if(ob->query("get_book4"))
		if(ob->query("get_book4")==me->name())
			return "���Ǹո���һ�����𣿻�����������ʲô����\n";
		else return "�Ҹո���"+ob->query("get_book4")+"һ���������ȷ�������ȥ����Ҫ�ɣ�\n";
	book=new(__DIR__"obj/sbook");
	ob->set("get_book4",me->name());
	tell_object(me,""+ob->name()+"������һ���������ȷ�����\n");
	book->move(me);
	return ""+RANK_D->query_respect(me)+"���Ǻú�ѧϰ�����ɣ�\n";
}