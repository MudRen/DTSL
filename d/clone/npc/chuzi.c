
inherit NPC;
string give_food();
void create()
{
   set_name("����",({ "chu zi","chu","zi" }) );
   set("gender", "����" );
   set("age", 46);
   set("long", "����һ�����ӡ�\n");
       
   set("combat_exp",100000);
   set("max_force",300);
   set("force",300);
   set("attitude", "peaceful");
      
   set("inquiry",([
   "ʳ��":(:give_food:),
   "food":(:give_food:),
   ]));
   setup();
}
string give_food()
{
  object ob,food;
  ob=this_player();  
  if(present("mantou",ob))
  return "�ⲻ�Ƿ�����ͷô��������Ҫʲô��\n";
  food=new(__DIR__"obj/mantou");
  food->move(ob);
  return "�ðɣ��Ҿ͸���һ����ͷ�ɣ�\n";
}
