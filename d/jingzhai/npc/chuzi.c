
inherit NPC;
string give_food();
void create()
{
   set_name("����",({ "chu zi","chu","zi" }) );
   set("gender", "Ů��" );
   set("age", 46);
   set("long", "���ǴȺ���ի�ĳ��ӡ�\n");
       
   set("combat_exp",100000);
   set("max_force",300);
   set("force",300);
   set("attitude", "peaceful");
   set_skill("sword",80);
   set_skill("cuff",80);
   set_skill("strike",80);
   set_skill("dodge",80);
   set_skill("finger",80);
   set_skill("literate",80);
   set_skill("force",80);
   set_skill("sekong-jianfa",80);
   set_skill("xiuluo-zhi",80);
   set_skill("wuwang-jing",80);
   set_skill("qingxin-force",80);
   set_skill("lingyun-shenfa",80);
   
   create_family("�Ⱥ���ի",8,"����");
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
  return "����һЦ���ⲻ�Ƿ�����ͷô��������Ҫʲô��\n";
  food=new("/d/jingzhai/obj/mantou");
  food->move(ob);
  return "�ðɣ��Ҿ͸���һ����ͷ�ɣ�\n";
}
