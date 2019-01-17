
inherit F_VENDOR_SALE;
inherit F_REPAIR;

void create()
{
   reload("xy_tiejiang");
   
   set_name("����",({ "tie jiang","tie","jiang","tiejiang" }) );
   set("gender", "����" );
   set("age", 40);
   set("long", "����������������������ı������Ǻܺá�\n");
   set("shop_id",({ "tie jiang","tie","jiang","tiejiang" }) );
   set("combat_exp",300000);
   
   set("force",500);
   set("max_force",500);
   set("kee",800);
   set("max_kee",800);
   set("sen",500);
   set("max_sen",500);
   
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("force",80);
   set_skill("duanzao-jishu",100);
   
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "changjian":__DIR__"obj/changjian",
	  "blade":__DIR__"obj/blade",
	  "axe":__DIR__"obj/axe",
	  "changmao":__DIR__"obj/changmao",
	  "duanjian":__DIR__"obj/duanjian",
	  "gangcha":__DIR__"obj/gangcha",
	  "gangzhang":__DIR__"obj/gangzhang",
	  "toukui":__DIR__"obj/toukui",
	  "yaodai":__DIR__"obj/yaodai",
	  ]));
   set("vocation","����");
   set("vocation_skill","duanzao-jishu");
   set("inquiry",([
     "��֧":"Ŀǰ������������֧��\n"+
            "1�����������(weapon) 2��������ס�ҩ����(armor) 3���������Ϳ��������(poison)��\n"+
            "�����ʹ��choose ��ѡ���� choose weapon ��\n",
   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	::init();
	add_action("do_vendor_list", "list");
	add_action("do_repair",({"repair","xiu"}));
	add_action("do_choose","choose");
	
}
int regenerate()
{
        set("called", 0);
        return 1;
}

int is_apprentice_of(object ob)
{
        return 1;
}

int recognize_apprentice(object ob)
{
   return 1;
}

int prevent_learn(object me,string skill)
{
   if(me->query("vocation")!=query("vocation")){
     command("say ���ֲ���"+query("vocation")+"���ҿɲ������㼼�ܣ�");
     return 1;
   }
   if(skill!=query("vocation_skill")){
    command("say ��ֻ����"+to_chinese(query("vocation_skill"))+
             "��"+query("vocation_skill")+"����");
    return 1;
   }
   return 0;
}
    
int do_choose(string arg)
{
   object ob;
   
   ob=this_player();
   
   if(ob->query("vocation")!="����")
   return notify_fail("�㻹���ȵ������ɣ�\n");
   
   if(ob->query("vocation_fenzhi"))
   return notify_fail("���޷������Լ��ķ�֧��\n");
   
   if(!arg||
      (arg!="weapon"&&arg!="armor"&&arg!="poison")
     )
   return notify_fail("��Ҫѡ��ʲô��֧��\n");
   
   tell_object(ob,"��ѡ���� "+arg+" ��֧��\n");
   ob->set("vocation_fenzhi",arg);
   return 1;
}
   