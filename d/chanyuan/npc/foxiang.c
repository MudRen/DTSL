
inherit ITEM;

void create()
{
   set_name("ŭĿ���", ({ "numu jingang","jingang","foxiang" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("material", "iron");
     set("long", "����һ��ŭĿ��յķ��񣬿������ǳ����ϡ�\n");
   }
   setup();
}

int is_get_of(object ob,object obj)
{
   ob->set("gin",0);
   ob->set("sen",0);
   ob->set("kee",0);
   return notify_fail("����˰��쾡�����ָ����������������\n");
}

string long()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("perform_quest/fumo_action1")||
      ob->query("perform_quest/fumo"))
   return query("long");
   ob->set("perform_quest/fumo",1);
   return "�㿴��ŭĿ��շ��񣬴���������˷�ħ�ȷ��ľ�ѧ��";
}