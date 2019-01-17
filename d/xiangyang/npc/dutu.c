
inherit NPC;
string start_bet();
int do_zuozhuang(string arg);
int do_start(string arg);
int do_fapai(string arg);
int do_kaipai(string arg);
void clear(object me,object ob);
int do_close();
void create()
{
   set_name("��ͽ",({ "du tu","du","tu"}) );
        set("gender", "����" );
        set("age", 32);
		
   set("long", "����һ���öĳ��ԵĶ�ͽ,�����Ǯ����Ҫ����ˡ�\n");
       
   set("combat_exp", 5000);
   set("str", 20);
   set("per", 25);
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
  set("attitude", "peaceful");
  set("inquiry",([
	  "�Ĳ�":(:start_bet:),
	  ]));

   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

void init()
{
	add_action("do_zuozhuang","zuozhuang");
	add_action("do_start","start");
	add_action("do_fapai","fapai");
	add_action("do_kaipai","kaipai");
	add_action("do_close","enough");
}

string start_bet()
{
	object me,ob;
	me=this_player();
	ob=this_object();
	if(ob->query("betting")) return "�����ͱ��˶���,��Ȼ��!\n";
	message_vision("$N˵��:�ð�,�������Ķ�ʮһ���!\n",ob);
	return "���������ׯ,�Ϳ����� zuozhuang ��ʼ,���������ׯ,������start��ʼ.\n";
}

int do_zuozhuang(string arg)
{
	object me,ob,obj;object paper,pa1,pa2;
	string item,money;int count;
	me=this_player();ob=this_object();
	if(!arg) return notify_fail("���� zuozhuang ��Ǯ��Ŀ ��Ǯ����\n");
	if(sscanf(arg,"%s %s",item,money)!=2)
		return notify_fail("���� zuozhuang ��Ǯ��Ŀ ��Ǯ����\n");
	if(sscanf(item,"%d",count)!=1)
		return notify_fail("���� zuozhuang ��Ǯ��Ŀ ��Ǯ����\n");
    if(!objectp(obj=present(money,me)))
		return notify_fail("������û�����ֻ���!\n");
	if(!obj->query("money_id")) return notify_fail("��ֻ������Ǯ�Ĳ�!\n");
	if(obj->value()<100) return notify_fail("����ҲҪ1�����Ӳſ��ԲμӶĲ�!\n");
    if(obj->query_amount()<count) return notify_fail("������û����ô���"+obj->name()+"\n");
	obj->set_amount((obj->query_amount())-count);
	ob->set("betting",1);
	me->set("betting",1);
	me->set("bet/count",count);
	me->set("bet/money",obj);
	paper=new(__DIR__"obj/papers");
	paper->move(me);
	message_vision("$N˵��:����,�췢��(fapai)��!\n",ob);

	return 1;
}

int do_fapai(string arg)
{
	object target,pa;int i;
	object me;object papers;object ob;
	me=this_player();ob=new(__DIR__"dutu");
	if(!arg) return notify_fail("��ʹ�� fapai ����\n");
	if(!objectp(target=present(arg,environment(me))))
		return notify_fail("����û�������\n");
	if(!objectp(papers=present("papers",me)))
		return notify_fail("������û��ֽ��\n");
	if(!me->query("betting")) return notify_fail("�����¿�ʼ��ׯ��!\n");
	if(papers->query("amounts")<=0)
	{   destruct(papers);
		return notify_fail("ֽ��������,��������ׯ��!\n");
	}
	if(!me->query("bet/target"))
	me->set("bet/target",target);
	else 
	{if(me->query("bet/target")==target&&!target->query("bet/enough")) 
	     return notify_fail("�����ܸ�һ���˷���!\n");
	  me->set("bet/target",target);
	}
	papers->add("amounts",-1);
	i=random(5)+random(5)+random(3);
	pa=new(__DIR__"obj/paper");
	pa->set("short",pa->short()+chinese_number(i)+"��");
	pa->move(target);
	if(userp(target)) me->add("desc",i);
	else ob->add("desc",i);
	if(userp(target))
	{  if(target!=me)
		tell_object(target,"��Ҫ����?\n");
	   else tell_object(target,"������Լ�һ����\n");
	}
	else
	{
       if((int)target->query("desc",1)<10)
		   tell_object(me,target->name()+"���ͷ:����һ�Ű�!\n");
	   else if((int)target->query("desc",1)<15)
		   tell_object(me,target->name()+"��Щ��ԥ:����һ�Ű�!\n");
	   else 
	   {tell_object(me,target->name()+"��:������,���Կ���(kaipai)��!\n");
	     me->set("bet/enough",1);
	   }
	}
	return 1;
}

int do_kaipai(string arg)
{
	object me,ob;int c1,c2;int m1,m2;object money;
	me=this_player();
	if(!arg) return notify_fail("��ʹ��kaipai �Ĳ�����\n");
	if(!objectp(ob=present(arg,environment(me))))
		return notify_fail("����û�������!\n");
	c1=me->query("desc");
	c2=ob->query("desc");
	if(c1>21&&c2>21)
	{
		money=me->query("bet/money");
		money->set_amount(money->query_amount()+me->query("bet/count"));
		clear(me,ob);
		return notify_fail("˫������,ƽ��!\n");
	}
	if(c1>21)
	{clear(me,ob);
	return notify_fail("�㱩����,��һ��������!\n");}
		if(c2>21)
	{
       money=me->query("bet/money");
		money->set_amount(money->query_amount()+2*me->query("bet/count"));
		clear(me,ob);
		return notify_fail("�Է�����,��һ����Ӯ��!\n");
	}
	if(c2>c1)
	{clear(me,ob);
	return notify_fail("�Է�����ȡʤ,��һ��������!\n");}
	if(c1>c2)
	{
		money=me->query("bet/money");
		money->set_amount(money->query_amount()+2*me->query("bet/count"));
		clear(me,ob);
		return notify_fail("���Ե���ȡʤ,��һ����Ӯ��!\n");
	}
	if(c1==c2)
	{
		
		money=me->query("bet/money");
		money->set_amount(money->query_amount()+me->query("bet/count"));
		clear(me,ob);
		return notify_fail("˫��������ͬ,ƽ��!\n");
	}

	return 1;
}

void clear(object me,object ob)
{
	me->delete("bet");
	me->delete("betting");
	me->delete("desc");
	ob->delete("desc");
    ob->delete("bet");
	ob->delete("betting");
	return;
}

int do_close()
{
	object me,ob;
	me=this_player();
	ob=new(__DIR__"dutu");
	ob->set("bet/enough",1);
	tell_object(me,"�������Ҫ����\n");
	return 1;
}