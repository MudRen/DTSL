
inherit NPC;

void create()
{
   set_name("��С��",({ "dian xiaoer","xiaoer","dian"}) );
   set("gender", "����" );
   set("age", 22);
		
   set("long", "�����м��ջ�ĵ�С����\n");
       
   set("combat_exp", 30000);   
   set_skill("unarmed",50);
   set_skill("dodge",50);
   set_skill("parry",50);
 
   setup();
 
}

void init()
{
if(!living(this_object()))
	return;
remove_call_out("welcome");
call_out("welcome",1);
}

void welcome()
{

switch(random(3)){
	case 0:	
		command("say ����������������Ķ��ˣ��͹���Ҳ����һ��ɣ�");
		break;
	case 1:
		command("say ��λү����һ������Ҫɨ���ˡ�");
		break;
	case 2:
		command("say ƴ��������������ʲô�ã��ҿ��������Ȣ��ϱ���ã�");
		break;
}
	
}
	

