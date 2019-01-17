#include <ansi.h>
#include <command.h>
#include <login.h>
#include <job_money.h>

inherit NPC;

#define JIANYU "/d/death/jianyu.c"

object make_body(object ob);
int check_legal_id(string id);
int check_legal_name(string name);
string *banned_name=({});
void lose(object ob);
int do_zhuanshi();
string *death_msg = ({
        HIB "$N˵����ι�������ģ����ʲô���֣�\n\n" NOR,
        HIB "$N̾��������������ң������ﱨ��������Խ��Խ���ˡ�\n\n" NOR,
        HIB "$N���ߡ���һ�����������ͳ�һ�����ʲ�Ķ��������š�\n\n" NOR,
        HIB "$N���ϲ��ӣ�˵�����ף�����δ������ô���ܣ�\n\n" NOR,
        HIB "$N̾�������˰��ˣ����߰ɡ�\n\n"
                "һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n" NOR,
});

void create()
{
        string *first_name = ({ "�ع�","����","�ε�","����","����","ƽ��","̩ɽ","����","���","ת��" }); 

        set_name(first_name[random(sizeof(first_name))]+"��", ({ "ming wang", "ming", "wang" }) );
        set("title",  BLU"ʮ��ڤ��֮"NOR );
        set("long", "�㿴����������Ŀ��ֻ���������ϲ����κ�ϲŭ���֡�\n");
        set("attitude", "peaceful");
        set("chat_chance", 5);
        set("chat_msg", ({ 
"һ�����紵�����㲻�������˶���\n",
"��Ȼ��һ������Ĳҽд�Զ��������������ë���Ȼ����ס������\n",
        }) );
       /* set("inquiry",([
        "ת��Ͷ̥":"��ʹ�� zhuanshi ����\n",
        ]));
        */
        set("age", 3000);
        set("combat_exp", 200000);
        set("max_gin", 1000);
        set("max_kee", 1000);
        setup();
}

void init()
{
        object ob;
        //add_action("do_zhuanshi","zhuanshi");
        
        ob=previous_object();
        if(!ob) return;
        call_out("death_stage",5,ob);
}

void death_stage(object ob,int stage)
{
	int i;string msg;
        object *inv;
	if(!objectp(ob)){ return;}
	if(!ob->is_ghost()){
		message_vision("$N�������ô���˸����ˣ������Ǻڰ��޳�Ū���ˣ�\n",this_object());
		message_vision("ͻȻ�ڰ��޳�ð�˳���������$Nһ�β����ˣ�\n",ob);
		ob->reincarnate();
		ob->move(REVIVE_ROOM);
		tell_object(ob,HIW"��о�һ��ѣ�Σ��Ѿ��ص������䣡\n"NOR);
		message("vision","���Ȼ������Ӱ��֪��ʲô�ط�ð�˳�����\n", environment(ob), ob);
		
		return;}
	msg = death_msg[stage];
    msg = replace_string(msg, "$N", this_object()->name());
        tell_object(ob, msg);
 	if(++stage<sizeof(death_msg)){
		
		call_out("death_stage",5,ob,stage);
		return;}
	else ob->reincarnate();
	inv =  all_inventory(ob);
        for (i = 0; i < sizeof(inv); i++)
              if(!inv[i]->query("save_box"))
                DROP_CMD->do_drop(ob, inv[i]);
	if(!ob->query("invalid_death")&&ob->query("age")>12)
        lose(ob);
	else ob->delete("invalid_death");
	if(ob->query("zuolao"))
	ob->move(JIANYU);
	else
	if(ob->query("combat_exp")>=20000)
	ob->move(REVIVE_ROOM);
	else
	ob->move("/d/slwg/zoulang1");
    message("vision","���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);
	
	return;
}
void lose(object ob)
{
	int lost_combat;int exp;
	exp=ob->query("combat_exp");
	lost_combat=((ob->query("pker_lose")+2)/2)*exp/(100);
	ob->add("combat_exp",-lost_combat);	
	ob->add("deadtimes",1);
	ob->skill_death_penalty();
	ob->set("bellicosity",0);
	ob->delete("pker_lose");
	JOBSYS_D->clear_job_npc(ob);

}

int do_zhuanshi()
{
  object me;object ob;
  me=this_player();
  "/adm/daemons/logindd.c"->do_zhuanshi(me);
  return 1;
}
