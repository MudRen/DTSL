
inherit NPC;
#include <ansi.h>
int do_jiehun(string arg);
int do_devorce(string arg);
void create()
{
   set_name(HIY"����"NOR,({ "yue lao","yue","lao"}) );
        set("gender", "����" );
        set("age", 62);
		
   set("long", "��������е�Ϊ��Ů��ϻ��������ϡ�\n");       
   set("combat_exp", 5000);
   set("str", 20);
   set("per", 25);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

void init()
{
   add_action("do_jiehun","jiehun");
   add_action("do_devorce","lihun");
   
}

int do_jiehun(string arg)
{
   object me,ob;string flag,id;
   object marry_token1,marry_token2;
   me=this_player();
   
   if(!arg||
     sscanf(arg,"%s %s",flag,id)!=2||flag!="with")
    return notify_fail("����Ц����"+RANK_D->query_respect(me)+",��Ҫ�ż�������jiehun with ��\n");
   if(me->query("class")=="bonze")
   return notify_fail("����ЦЦ���������Ĵ�Կգ��ҿ��㻹�����ˣ�\n");
   if(me->query("gender")=="Ů��")
   return notify_fail("��������Ů���Ӽ���ô�ܳ�ͷ�أ����з����ɣ�\n");
   if(me->query("couple"))
   return notify_fail("���Ѿ�����ˣ���ô���ѵ���Ҫ׽Ū��Ե��\n");
   if(!objectp(ob=present(id,environment(me))))
   return notify_fail("�������¿��˿����ף�û������˰���\n");
   if(ob->query("class")=="bonze")
   return notify_fail("����Ц�������ǳ����ˣ���ô���Ӧ���أ��ҿ���������Ե�޷ݰ���\n");
   if(ob->query("couple"))
   return notify_fail("����Ц����С�������ɷ������㣡\n");
   if(me->query_temp("marry")!=ob)
   return notify_fail("����������㲢û��������飡\n");
   if(ob->query_temp("marry")!=me)
   return notify_fail("�������������û�д�Ӧ��������⡢����ô���ԣ���\n");
   command("say �Ǻǣ�������λ����Եע����ף������λ��ͷ���ϣ��������ӡ�\n");
   command("smile\n");
   command("chat ������Ե�ף�"+me->name()+"��"+ob->name()+"��Ϊ�򸾡�\n");
   command("chat ף���ǰ�ͷ���ϣ�����ͬ�ģ�\n");
   marry_token1=new("/obj/yupei");
   marry_token1->move(ob);
   marry_token1->wear();
   marry_token2=new("/obj/xiangnang");
   marry_token2->move(me);
   marry_token2->wear();
   me->set("couple/couple_id",ob->query("id"));
   me->set("couple/couple_name",ob->name());
   ob->set("couple/couple_name",me->name());
   ob->set("couple/couple_id",me->query("id"));
   tell_object(me,"������������������������ʹ��makelove���\n");
   tell_object(ob,"������������������������ʹ��makelove���\n");
   tell_object(me,ob->name()+"�����ߺ�������㡣\n");
   tell_object(ob,me->name()+"�����˷ܵ������㡣\n");
   return 1;
}

int do_devorce(string arg)
{
   object me,ob;
   object token1,token2;
   string flag,id;
   me=this_player();
   if(!arg||sscanf(arg,"%s %s",flag,id)!=2||
      flag!="with")
   return notify_fail("���ϵ����������� lihun with �ˡ�\n");
   if(!me->query("couple"))
   return notify_fail("���ϵ����㻹û�н�飬��˭��鰡��\n");
   if(!objectp(ob=present(id,environment(me))))
   return notify_fail("�������¿�����û������˰���\n");
   if(me->query("couple/couple_id")!=ob->query("id"))
   return notify_fail("���ǲ��Ƿ򸾣������飿\n");
   command("say ��Ȼ������Ե���꣬��Ҳûʲô��˵�ġ�\n");
   command("say Ը�����Ժ����Ϊ֮��\n");
   if(me->query("gender")=="����")
   token1=present("xiang nang",me);
   else token1=present("yu pei",me);
   if(token1) destruct(token1);
   if(ob->query("gender")=="����")
   token2=present("xiang nang",ob);
   else token2=present("yu pei",ob);
   if(token2) destruct(token2);
   me->delete("couple");
   ob->delete("couple");
   command("chat "+me->name()+"��"+ob->name()+"��Ե��ɢ���Ժ�������\n");
   return 1;
}
   
    
