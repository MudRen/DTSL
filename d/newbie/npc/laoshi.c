inherit F_MASTER;
inherit NPC;

void create()
{
        set_name("ѧԺ��ʦ", ({"lao shi", "lao","shi"}));
        set("gender", "����");
        set("age", 34);
        set("long","����ѧԺ����ʦ���Ѿ������˶ʿѧλ��\n");
        set("str", 22);
        set("int", 24);
        set("dex", 18);
        set("con", 18);

        set("kee", 500); 
        set("max_kee", 500);
        set("gin", 100);
        set("max_gin", 100);
        set("sen",300);
        set("max_sen",300);
        set("combat_exp",300000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set("env/wimpy", 50);

        set_skill("literate",10);
        set_skill("force",10);
        set_skill("parry",10);
        set_skill("dodge",10);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);
        create_family("ѧԺ��",5,"˶ʿ");
        setup();
      
}

int is_apprentice_of(object ob)
{
	return 1;
}

int recognize_apprentice(object ob)
{
	
        return 1;
}

int prevent_learn(object ob,string skill)
{
  return 1;
  
}


void attempt_apprentice(object ob)
{   
	
	command("say ����ֻ��������ʾ��һ�£��������ġ�\n");
	command("say ��Ҳ����㼼�ܣ���Ҫ�ǲ���������ѧ�����Կ��ɣ�\n");
	return;
}