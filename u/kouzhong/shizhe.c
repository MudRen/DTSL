// By Spiderii �İ棬��ʱ�������Ժ���ʱ�䶯��
#include <ansi.h>
#define SKILLS_LEVEL            182
#define KNOWLEDGE_LEVEL            120
#define GIVE_EXP                600000
#define MAX_NEILI               3500
#define MAX_JINGLI              2100
inherit NPC;
string ask_xx();
string ask_sk();
string ask_tianzi();
object ob = this_object();
void create()
{
    set_name(HIC"�϶�����"NOR, ({"change xianzi","change","xianzi" }));
    set("title", ""HIY"��"HIM"��"HIC"��"HIG"ʹ"NOR"");   
    set("gender", "Ů��");
    set("age", 22);
    set("per", 100);
    set("str", 40);
    set("int", 40);
    set("con", 40);
    set("dex", 40);
    set("qi",5000);
    set("jingli",6000);
    set("max_qi", 8000);
    set("max_jing", 5000);
    set("eff_jingli", 6000);
    set("jiali", 190);
    set("combat_exp", 9000000);
    set("shen", 25000);
    set("chat_chance_combat", 60);
    setup();
    set("inquiry", ([
        "�������" : "Ҳף��������֣���������Ҫʲô�����أ���ask xianzi about ���������͡���\n���Ը�2�㣿����Ǳ�ܣ��������ԣ�\n",
   "���Ը�2��" : (: ask_xx :),
   "����Ǳ��" : (: ask_sk :),
   "��������" : (: ask_tianzi :),
      ]) );
}

void greeting(object ob)
{
 if (!ob || !present(ob, environment())) return;
            write(HBRED"��ask xianzi about ������� ���ĵ�������\n"NOR);

}

string ask_xx()
{
    if (this_player()->query("shizhe_��ʦ")) return "�㲻��Ҫ��һ�����������\n";
    message_vision(HIY "�϶�"+ NOR "һ���֣���о���������Щ�仯��"+ NOR "\n",this_player());
    this_player()->add("str",2);
    this_player()->add("int",2);
    this_player()->add("dex",2);
    this_player()->add("shizhe_��ʦ",1);
    this_player()->add("con",2);
    return "ף��������!";
}
string ask_tianzi()
{
    if (this_player()->query("shizhe_��ʦ")) return "�㲻��Ҫ��һ�����������\n";
    message_vision(HIY "�϶�"+ NOR "һ���֣���о�����������϶��ܺã���Ҳ�о�Ư���˺ܶࡣ"+ NOR "\n",this_player());
    this_player()->set("kar",30);
    this_player()->set("per",30);
    this_player()->set("shizhe_��ʦ",1);
    return "�����ڵĸ�Դ����ò�Ǵ��Ƶ�һӴ��ף��������!";
}
string ask_sk()
{
    if (this_player()->query("shizhe_��ʦ")) return "�㲻��Ҫ��һ�����������\n";
    message_vision(HIY "�϶�"+ NOR "һ���֣���о�����ѧ�ľ�����ǿ�ˣ���ͨ�˺ܶ�ƽʱ�벻ͨ�ĵط�!"+ NOR "\n",this_player());
    this_player()->add("combat_exp",GIVE_EXP);
    this_player()->add("potential",2000);
    this_player()->set("shizhe_��ʦ",1);
    return "Ǳ����������ǰ���꣬���˲�Ҫ���Ұ�!";
}
