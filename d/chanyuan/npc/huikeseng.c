
inherit NPC;

int do_action1();

void create()
{
  
   set_name("���ɮ",({ "seng ren","seng","ren"}));
   set("gender", "����" );
   set("class","bonze");
   set("long","���Ǿ�����Ժ���ɮ�����������ҪЩ����");
   set("combat_exp",50000);
   set("inquiry",([
     "����":(:do_action1:),
     ]));
  setup();
  
}

int do_action1()
{
   object ob,obj;
   int value;
   
   ob=this_player();
   
   value=50;
   switch(MONEY_D->player_pay(ob,value)){
   	case 0:
   	case 2:
   	command("say ϣ��ʩ���ܸ�����һ�����Ǯ����");
   	return 1;
   	default:break;
   }
   obj=new(__DIR__"obj/xiangzhu");
   obj->move(ob);
   tell_object(ob,query("name")+"������һ"+obj->query("unit")+
     obj->query("name")+"��\n");
   return 1;
}