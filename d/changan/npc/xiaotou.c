
inherit NPC;

void create()
{
   set_name("С͵",({ "thief"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����һλ�ڳ����ǹ���С͵��\n");
       
   set("combat_exp", 20000);
   set("str", 25);
   set("per", 22);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	object me,ob;
	me=this_object();
	ob=this_player();
	if(ob&&!ob->is_fighting()) call_out("thief",1,me,ob);
}

void thief(object me,object ob)
{
	object money;
	if(me->query("combat_exp")<ob->query("combat_exp"))
	{ message_vision("$N��������ȥ͵$n��Ǯ��$nŭĿһ�ӣ�$N�Ͻ�������ȥ��\n",me,ob);
	  remove_call_out("thief");
	  return;
	}
	if(random(5)>3)
	{if(!objectp(money=present("silver",ob)))
	{ remove_call_out("thief");return;}
	money->move(me);
	message_vision("$N͵����$n���ϵİ�����\n",me,ob);
	}
	remove_call_out("thief");
	return;
}