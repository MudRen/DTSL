
inherit NPC;

void create()
{
   set_name("�ɲ���",({ "man"}) );
        set("gender", "����" );
           set("long", "����һ�������ڳ���ɽ�ɲε��ˡ�\n");
          set("combat_exp", 50000);
        set("inquiry",([
              "�����":"Ŷ����˵�������ڸ���ƺһ�����֣�ȥ�껹����ҵ��˲��أ�\n",
              ]));
   set("str",30);
   set("attitude", "peaceful");
   setup();
  
}

