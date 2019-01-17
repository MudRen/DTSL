//³����.
inherit NPC;
string give_jiguan();
string give_junshi();
string give_miji();
string give_mask();

void create()
{
   set_name("³����",({ "lu miaozi","lu","zi" }) );
        set("gender", "����" );
		
        set("age", 42);
   set("long", "�����ǽ����ϵ�����--³���ӡ��������ģ�\n"+
               "������ѧ�����µȷ��涼�ж��кܸߵ���\n"+
               "�衣\n");
       
   set("combat_exp",500000);
   set("str", 20);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",170);
   set_skill("dodge",170);
   set_skill("parry",170);
   set("inquiry",([
	   "����ѧ":(:give_jiguan:),
	   //"�书":(:give_miji:),
	   "���":(:give_mask:),
	   ]));
   set("no_clean_up",1);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

string give_jiguan()
{
	object me,ob,book;
	me=this_player();
	ob=this_object();
	if(me->query_int()<40)
		return "�������̫���ˣ�����ô���㰡��\n";
	if(ob->query("no_jiguan"))
		return "�������ˣ�������ѧ�����Ѿ�����"+ob->query("no_jiguan")+"\n";
	book=new(__DIR__"obj/jiguanxue");
	book->move(me);
	message_vision("$N����$nһ��������ѧ����\n",ob,me);
	ob->set("no_jiguan",me->name());
	return "��Ҫ�ú�ѧϰ�ҵġ�����ѧ������\n";
}

string give_junshi()
{
	object me,ob,book;
	me=this_player();
	ob=this_object();
	if(me->query("int")<30)
		return "�������̫���ˣ�����ô���㰡��\n";
	if((int)me->query_skill("literate",1)<=180)
		return "����Ļ�ˮƽ̫���ˣ��������ҵ���ģ�\n";
	if(me->query("combat_exp")<300000)
		return "����书ʵ���ǵ�΢���Ȿ�������˵ûʲô�õģ�\n";
	if(ob->query("no_junshi"))
		return "�������ˣ�������ѧ�����Ѿ�����"+ob->query("no_junshi")+"\n";
	book=new(__DIR__"obj/junshixue");
	book->move(me);
	message_vision("$N����$nһ��������ѧ����\n",ob,me);
	ob->set("no_junshi",me->name());
	return "��Ҫ�ú�ѧϰ�ҵġ�����ѧ������\n";
}

string give_miji()
{
	object me,ob,book;
	me=this_player();
	ob=this_object();
	if(me->query_int()<45)
		return "�������̫���ˣ�����ô���㰡��\n";
	if(me->query("combat_exp")<800000)
		return "����书ʵ���ǵ�΢���Ȿ�������˵ûʲô�õģ�\n";
	if(ob->query("no_miji"))
		return "�������ˣ�����ѧ�ķ������Ѿ�����"+ob->query("no_miji")+"\n";
	book=new(__DIR__"obj/miji");
	book->move(me);
	message_vision("$N����$nһ������ѧ�ķ�����\n",ob,me);
	ob->set("no_miji",me->name());
	return "�Ȿ����ѧ�ķ���������书���кܴ���ߵģ�\n";
}

string give_mask()
{
	object ob,mask;
	object *target;
	int i,flag;
	
    ob=this_player();
    	    
	if(this_object()->query("no_mask"))
		return "�ҵ�����Ѿ��������ˣ��������ˣ�\n";
	target=children(__DIR__"obj/mask");
	flag=0;
	for(i=0;i<sizeof(target);i++)
		if(environment(target[i])){
			flag=1;
			break;
		}
	
	if(flag>0)
	return "�ҵ�����Ѿ��������ˣ��������ˣ�\n";
	mask=new(__DIR__"obj/mask");
	mask->move(ob);
	this_object()->set("no_mask",1);
	return "�����Ҿ�����������Ƥ��ߣ����Ҫ�úñ��ܣ�\n";
}