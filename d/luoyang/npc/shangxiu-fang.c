
inherit NPC;

void create()
{
   set_name("���㷼",({ "shang xiufang","shang","xiu","fang" }) );
        set("gender", "Ů��" );
        set("age", 18);
   set("long", "�����������ĵ�һ�������㷼��\n"+
               "���������޳��ȳƵ���Σ���̬\n"+
               "��ǧ�ľ�ֹ�����⣬�����˵���\n"+
               "���Ƕ��ܹ������ǵ���ˮ˫ͫ��\n"+
               "�京����������Ŵ����Դ���ɬ\n"+
               "��ӯӯǳЦ��ȷ��û�������ܵ�\n"+
               "����ס�ġ�\n");
       
   set("combat_exp", 100);
   set("famous",1000000);
   set("str", 14);
   set("per", 28);
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
   add_money("coin", 50);
}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	::init();
	if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	call_out("welcome",1,ob,ob2);
	
}

void welcome(object ob,object ob2)
{
   
	if(!ob||environment(ob)!=environment(this_object()))
	return;
	
	if(wizardp(ob))
	{message_vision("$N��æ��ǰ��ԭ������ʦ���ˣ���ʲô�����԰�æ����\n",ob2);
	return;}
	//this is a joke.
	
	if(ob->query("gender")=="����")
   {
	   if((int)ob->query("famous",1)>5000)
	   {
		   if((int)ob->query("per")==30)
			   message_vision("$N���������˵������λ"+RANK_D->query_respect(ob)+"���������ܾ��ˣ�\n",ob2);
		   else if((int)ob->query("per",1)==29)
			    message_vision("$N΢΢һЦ����λ"+RANK_D->query_respect(ob)+"���������ܾ��ˣ�\n",ob2);
		   else if((int)ob->query("per",1)==28)
			   message_vision("$N����һЦ����δ"+RANK_D->query_respect(ob)+"���������ܾ��ˣ�\n",ob2);
	   }
	   else message_vision("$N��$n����һЦ��\n",ob2,ob);
   }
   else
   {
	   if((int)ob->query("famous",1)>5000)
	   {
		   if((int)ob->query("per")==30)
			   message_vision("$N����������˵������λ"+RANK_D->query_respect(ob)+"���������ܾ��ˣ�\n",ob2);
		   else if((int)ob->query("per",1)==29)
			    message_vision("$N΢΢һЦ����λ"+RANK_D->query_respect(ob)+"���������ܾ��ˣ�\n",ob2);
		   else if((int)ob->query("per",1)==28)
			   message_vision("$N����һЦ����λ"+RANK_D->query_respect(ob)+"���������ܾ��ˣ�\n",ob2);
	   }
	   else message_vision("$N��$n����һЦ��\n",ob2,ob);
   }
   return;
}
 
