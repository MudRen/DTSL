
inherit NPC;

void create()
{
   set_name("���ر�",({ "chen shoubei","chen","shoubei"}) );
        set("gender", "����" );
        set("age",38);
        set("long","������ܹ����ݵĳ��ر���\n");
        set("inquiry",([
         "����":"����������͵�˶�������֪����\n",
         "���Ļ���":"���Ĵ�˧������׷��͵��������С͵���⼸����ۻ��ˡ�\n",
         "������":"���С����͵�˶�����㺦����ͷ­������ץס��һ���ú���������\n",
         "����":"���С����͵�˶�����㺦����ͷ­������ץס��һ���ú���������\n",
         ]));
        set("chat_chance",20);
        set("chat_msg",({
         (:random_move:),
         "���ر������ȵ����������������ˣ���������׷��С͵��������һ�ɸ�ɱ���ۣ�\n",
         "���ر�����������˭����������Ϳ�������С�����򱾹پٱ������н�����\n",
        }));
        set("combat_exp",80000);
        set_skill("parry",80);
        set_skill("dodge",80);
        set_skill("force",80);
        set_skill("blade",80);
        
    setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/blade")->wield();
  
}

