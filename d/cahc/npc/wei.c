//Edit By Subzero
inherit NPC;

void create()
{
   set_name("Τ����",({ "wei gonggong","wei","gonggong" }) );
   set("gender", "����" );
   set("age", 54);
   set("long", "��̫���е���ģ��������ʮ��䣬��ò�������ڣ������ż�Ϊ������������
��ྻ�ĸо��������Ʋ���һ���������ھ���ʱ���̺���ᣬ����׷����㣬
���幬���书���ǿ��̫��ͷ�ӡ�쾵۱�ɱʱ�����ڽ�����ƾ�书ͻΧ���ߣ�
�Դ�Ͷ����Ԩ��������Ԩ����Ϊ�ڹ��࣬�������д�С̫���������Ͻ��
\n");
   set("shili","li");
   set("combat_exp", 1000000);
   set("str", 30);
   set("per", 18);
   set("dex", 30);
   set("int", 30);
   set("attitude", "peaceful");
   set_skill("unarmed",200);
   set_skill("parry",200);
   set_skill("dodge",200);
   set_skill("force",200);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("force",2500);
   set("max_force",2500);
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
}
