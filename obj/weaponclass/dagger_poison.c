
#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name("ذ��", ({ "dagger" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "steel");
	}
	init_dagger(4,20,20);

	set("wield_msg", "$N�ӻ�������һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n���뻳�С�\n");
	setup();
}

void init()
{
  add_action("do_sandu","sandu");
  add_action("do_zha","zha");
}

int do_sandu(string arg)
{
   object ob,target;
   string msg;
   
   ob=this_player();
   
   if(!arg)
   return notify_fail("��Ҫ��˭ɢ����\n");
   if(!objectp(target=present(arg,environment(ob))))
   return notify_fail("����û������ˡ�\n");
   if(ob->query("vocation")!="ҩʦ")
   return notify_fail("ֻ��ҩʦ�ܸ���ɢ����\n");
   if(ob->query_skill("bencao-shuli",1)<60)
   return notify_fail("��ı�������̫���ˣ��޷����Է�ɢ����\n");
   if(ob==target)
   return notify_fail("�㲻�ܸ��Լ�ɢ����\n");
   if(!target->query("env/sandu"))
   return notify_fail("�Է����ڲ�������˸���ɢ����\n");
   if(!target->query("liandu_times")&&!target->query("dazao_poison"))
   return notify_fail("�Է���������ܺã�û��Ҫɢ����\n");
   
   msg="$N����"+query("name")+"����$n�������ϸ���һ�����ӣ�ֻ��һ����ɫ�Ķ�֭���˳�����\n";
   msg+="$n���һ����״�Ʒ�񲣬����������ȥ����\n\n";
   target->set("gin",0);
   target->set("kee",0);
   target->set("sen",0);
   target->set("liandu_times",0);
   
   if(target->query("dazao_poison")){
     if(ob->query_skill("bencao-shuli",1)<target->query("dazao_poison")-100)
       message_vision("$n�еĶ��ǳ���������$N�ı��������޷�ɢ����\n",target,ob);
     else
     target->set("dazao_poison",0);
   }
   
   msg+="ֻ��"+query("name")+"˲���ѳ��˺�ɫ��$N��æ�ӵ���"+query("name")+"��\n";
   
   message_vision(msg,ob,target);
   
   destruct(this_object());
   return 1;  
}

int do_zha(string arg)
{
   object ob,target;
   string msg;
   int dlev;
   
   ob=this_player();
   
   if(!arg)
   return notify_fail("��Ҫ��˭��\n");
   if(!objectp(target=present(arg,environment(ob))))
   return notify_fail("����û������ˡ�\n");
   if(ob->query("vocation")!="ҩʦ")
   return notify_fail("ֻ��ҩʦ��ʹ��"+query("name")+"��\n");
   if(ob->query_skill("poison",1)<60)
   return notify_fail("��Ķ���̫���ˣ��޷�ʹ��"+query("name")+"��\n");
   if(ob==target)
   return notify_fail("�㲻�����Լ���\n");
   
   if(target->query("vocation")!="����")
   return notify_fail("�Է�����������\n");
   
   if(target->query("vocation_degree")>=3)
   return notify_fail("һ����Ǳ�����ޣ�ʹ�ö�ҩ�޷��ڼ���"+target->name()+"��Ǳ���ˡ�\n");
   
   if(target->query("dazao_poison"))
   return notify_fail("�Է��Ѿ����о綾���޷�����Ǳ�ܣ�\n");
   
   msg="$N����"+query("name")+"���͵س�$n���ֱ���ȥ��\n";
   msg+="$n���һ������˫Ŀȴ�����˾��񣬻����ƺ���������ľ�����\n\n";  
   target->add("vocation_degree",1);
   target->save();
   msg+="ֻ��"+query("name")+"˲���ѳ��˺�ɫ��$N��æ�ӵ���"+query("name")+"��\n";
   
   message_vision(msg,ob,target);
   if(ob->query_skill("poison",1)>=400)
    dlev=ob->query_skill("poison",1)-100;
   else
    dlev=ob->query_skill("poison",1)/3;
   target->set_temp("duanzao_skills",dlev);
   target->set("dazao_poison",ob->query_skill("poison",1));
   destruct(this_object());
   return 1;  
}
   