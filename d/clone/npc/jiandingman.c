
inherit NPC;
#include <ansi.h>
string *strong=({BLU"����һ��"NOR,BLU"�����ʵ"NOR,HIB"�ȽϽ�ʵ"NOR,GRN"�ǳ���ʵ"NOR,
GRN"����쳣"NOR,HIG"�᲻�ɴ�"NOR,HIR"�޿�ƥ��"NOR,});

string *damage=({BLU"Ѱ������"NOR,BLU"΢���˺�"NOR,HIB"�ľ��˺�"NOR,CYN"��΢����"NOR,
CYN"�޴�����"NOR,HIC"��ͬ����"NOR,HIC"��ͬ����"NOR,GRN"�����ױ�"NOR,GRN"�޿�ƥ��"NOR,
HIG"�������"NOR,HIG"���亱��"NOR,HIW"������˫"NOR,HIW"��������"NOR,HIR"��������"NOR,});
int do_jianding(string arg);
string show_damage();
string show_strong();
void create()
{
   set_name("�н�ʦ",({ "shang jianshi","shang"}) );
        set("gender", "����" );
        set("age", 32);
        set("str",30);
        set("jiali",200);
        set("max_gin",1000);
        set("max_sen",1000);
        set("max_kee",1000);
        set("max_force",1000);
        set("force",1000);
        create_family("������",5,"��ʦ");
        set("inquiry",([
            "�˺�":(:show_damage:),
            "��ǿ��":(:show_strong:),
            ]));
    setup();
   //carry_object("/obj/cloth/mandongming3")->wear();
  
}
void init()
{
  object ob;
  add_action("do_jianding","jianding");
  ob=this_player();
  if(ob&&!ob->is_busy()&&!ob->is_fighting()){
   remove_call_out("welcome");
   call_out("welcome",1,ob);}
  
}

void welcome(object ob)
{
   if(!ob) return;
   switch(random(3)){
     
     case 0: message_vision("$N��$nЦ�������������ѯ�ʡ��˺�������֪Ŀǰ�˺���������\n",
             this_object(),ob);
             break;
     case 1: message_vision("$N��$nЦ�������������ѯ�ʡ���ǿ�ȡ�����֪Ŀǰ�˺���������\n",
             this_object(),ob);
             break;
     case 2: message_vision("$N��$nЦ���������ʹ�á�jianding����������ı�����\n",
             this_object(),ob);
             break;}
  return;
}

string get_strong(object weapon)
{
  int sto;
  sto=weapon->query("strong");
  if(sto>300) sto=300;
  return strong[sto/50];
}

string get_damage(object weapon)
{
  int dam;
  dam=weapon->query("weapon_prop/damage");
  dam+=weapon->query("user_skill")/2;
  if(weapon->query("super"))
  dam+=weapon->query("super")*weapon->query("super");
  if(dam>13*50) dam=13*50;
  return damage[dam/50];
}
  

int do_jianding(string arg)
{
  object ob,weapon;
  string str1,str2;
  ob=this_player();
  if(!arg)
  return notify_fail("��ʦ�������Ҫ���Ҽ���ʲô��\n");
  if(arg==ob->query("id")){
  message_vision("$N��$n���ص�һЦ���ҿ�������Ҳ���Ǹ��׳գ�����Ҳ���Ǹ�����Ǻǡ�\n",this_object(),ob);
  return 1;}
  if(!objectp(weapon=present(arg,ob)))
  return notify_fail("��ʦ��ϸ���˿���������û�������������\n");
  if(!weapon->query("skill_type"))
  return notify_fail("��ʦЦЦ���Բ�����ֻ���������ġ�\n");
  if(weapon->query("super")>4)
  return notify_fail("��ʦһ���֣���ô�õı��������Ҽ�����\n");
  str1=get_strong(weapon);
  str2=get_damage(weapon);
  message_vision("$N����ָ���ᵯ�˵�"+weapon->name()+":�����ǿ�ȣ�Լ��"+str1+"�ɣ�\n",this_object());
  message_vision("$N�����˼���"+weapon->name()+":�����˺�����Լ��"+str2+"�ɣ�\n",this_object());
  return 1;
}

string show_damage()
{
   string msg;
   int i;
   
   msg="";
   for(i=0;i<sizeof(damage);i++)
    msg +=damage[i]+"\n";
   
  this_player()->start_more(msg);
  return "�����Ŀǰ�˺����ĸ�����������úÿ����ɣ�\n";
}

string show_strong()
{
   string msg;
   int i;
   
   msg="";
   for(i=0;i<sizeof(strong);i++)
    msg +=strong[i]+"\n";
   
  this_player()->start_more(msg);
  return "�����Ŀǰ��ǿ�ȵĸ�����������úÿ����ɣ�\n";
}
   