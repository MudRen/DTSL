
inherit NPC;
string give_book();
void create()
{
   set_name("������ʦ",({ "gongsun wushi","wushi","gongsun" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "���ǳ�����ݵĽ�ͷ���ڳ����в��ٵ��ӡ�\n");
       
   set("combat_exp", 120000);
   set("str", 28);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",90);
   set_skill("parry",90);
   set_skill("dodge",90);
   set_skill("force",90);
   set("max_force",500);
   set("force",500);
   set("inquiry",([
	   "����ȭ��":(:give_book:),
	   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
string give_book()
{
	object me,ob,book;
	me=this_player();ob=this_object();
	if(me->query_skill("unarmed",1)>100)
		return "��Ĺ��򲻵��ˣ�̫�����ˣ�\n";
	if(ob->query("get_book"))
		if(ob->query("get_book")==me->name())
			return "�Ҳ��Ǹո���һ���������ȥѧϰ�ɣ�\n";
		else return "�Ҹո���"+ob->query("get_book")+"һ��������ȭ�š�����ȥ����Ҫ�ɣ�\n";
	ob->set("get_book",me->name());
	book=new(__DIR__"obj/ubook");
	tell_object(me,""+ob->name()+"������һ��������ȭ�š���\n");
	book->move(me);
	return ""+RANK_D->query_respect(me)+",�����Ǹúú�ѧѧ���������ˣ�\n";
}
