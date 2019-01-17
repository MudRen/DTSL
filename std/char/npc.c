// npc.c last update from lanxin@jianghu 99-2-9
//modify by yanyan.2001. for dt.

#include <command.h>
inherit CHARACTER;
inherit F_CLEAN_UP;

object carry_object(string file)
{
        object ob;

        if(!objectp(ob = new(file))) return 0;
        ob->move(this_object());
        return ob;
}

object add_money(string type, int amount)
{
        object ob;

        ob = carry_object("/obj/money/" + type);
        if(!ob) return 0;
        ob->set_amount(amount);
}

int accept_fight(object who)
{
        string att;

        att = query("attitude");

        if(is_fighting()){       
                switch(att) 
                {
                case "heroism":
                        command("say �ߣ����аɣ�\n");
                        break;
                default:
                        command("say ���ж�Ϊʤ���ⲻ������̫����\n");
                        return 0;
        }}

        if((int)query("gin") * 100 / (int)query("max_gin") >= 90
        && (int)query("kee") * 100 / (int)query("max_kee") >= 90)
        {
                switch(att) 
                {
                case "friendly":
                        command("say " + RANK_D->query_self(this_object())
                                + "���������" + RANK_D->query_respect(who)
                                + "�Ķ��֣�\n");
                                return 0;
                case "aggressive":
                case "killer":
                        command("say �ߣ����аɣ�\n");
                        break;
                default:
                        if(!is_fighting())
                                command("say ��Ȼ" + RANK_D->query_respect(who)
                                        + "�ͽ̣�" + RANK_D->query_self(this_object())
                                        + "ֻ�÷��㡣\n");
                }
                return 1;
        } else
                return 0;
}

// This function is called by the reset() of the room that creates this
// npc. When this function is called, it means the room demand the npc
// to return its startroom.
int return_home(object home)
{
        // Are we at home already?
        if(!environment()
        || environment() == home)
                return 1;

        // Are we able to leave?
        if(!living(this_object())
        || is_fighting()
        || !mapp(environment()->query("exits"))) 
                return 0;

        // Leave for home now.
        message("vision", this_object()->name() + "����ææ���뿪�ˡ�\n",
                environment(), this_object());
        return move(home);
}

// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.
int chat()
{
        string *msg;
        int chance, rnd;

        if(!environment()) return 0;
		if(query("force")>=20&&query("max_force")>=20
			&&(query("race")=="����"||!query("race"))&&!is_busy()
			&&query_skill("force",1)
			&&!query_skill("bencao-shuli",1))
		{
			if(query("eff_sen")>0&&query("sen")*100/query("eff_sen")<=60)
				command("exert shen");
			if(query("eff_kee")>0&&query("kee")*100/query("eff_kee")<=60)
				command("exert qi");
			if(query("eff_gin")>0&&query("gin")*100/query("eff_gin")<=60)
			        command("exert jing");
		}
		if(query("force")>=20&&query("max_force")>=20
			&&(query("race")=="����"||!query("race"))&&!is_busy()
			&&query_skill("force",1)
			&&query_skill("bencao-shuli",1)&&!is_fighting())
		{
		    if(query("eff_gin")<query("max_gin")||
		       query("eff_kee")<query("max_kee"))
		       command("exert heal");
		}

        if(!chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance"))
                return 0;

        if(arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) 
        {
                if(random(100) < chance) 
                {
                        rnd = random(sizeof(msg));
                        if(stringp(msg[rnd]))
                                say(msg[rnd]);
                        else if(functionp(msg[rnd]))
                                return evaluate(msg[rnd]);
                }
                return 1;
        }
}

// Default chat function: Let the npc random move to another room.
int random_move()
{
        mapping exits;
        string *dirs;

        if(!mapp(exits = environment()->query("exits"))) return 0;
        dirs = keys(exits);
        command("go " + dirs[random(sizeof(dirs))]);
}

// Default chat function: Let the npc cast his/her enabled spells
void cast_spell(string spell)
{
        string spell_skill;

        if(stringp(spell_skill = query_skill_mapped("spells")))
                SKILL_D(spell_skill)->cast_spell(this_object(), spell);
}


int exert_function(string func)
{
     if(!living(this_object())) //not living Npc can't fight. Modify by Yanyan.
      return 0;
     command("exert "+func);
}


int perform_action(string action)
{
     string martial_skill;object weapon;
     if(!living(this_object()))
      return 0;
    command("perform "+action);
	 return 1;
}

int apply_action(string arg,int i,string j)  //for apply commands.
{
	if(!living(this_object()))
      return 0;
	command("apply "+arg+" "+i+" "+j+"");
}
