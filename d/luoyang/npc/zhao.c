
inherit NPC;

void create()
{
   set_name("�Թ�Ա",({ "zhao" }) );
        set("gender", "����" );
        set("age", 42);
   set("long", "���������ǵĲ����ܹܣ����������Ĳ������¡�\n");
       
   set("combat_exp", 500000);
   set("shili","luoyang");
   set("str", 10);
   set("per", 22);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/guanfu")->wear();
  
}

/*int accept_object(object who,object ob)
{
	int value,old_value;
	if(ob->query("money_id"))
	{
		value=ob->value();
		if(file_size("/log/guoku/luoyang")>0)
		{
			sscanf(read_file("/log/guoku/luoyang"),"%d",old_value);
			value=value+old_value;
		}
		write_file("/log/guoku/luoyang","",1);
		log_file("guoku/luoyang",sprintf("%d",value));
		message_vision("$NЦ����лл�ˣ���Ϊ�����������˹���!\n",this_object());
		return 1;
	}
	else return notify_fail("��������ҿɲ���Ҫ!\n");
*/
