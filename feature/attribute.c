// attribute.c

#include <dbase.h>
#include <skill.h>
int query_str()
{
	int i;
	if(query_skill("unarmed",1)>query_skill("finger",1))
	 i=query_skill("unarmed",1);
	else i=query_skill("finger",1);
	if(i<query_skill("cuff",1))
	i=query_skill("cuff",1);
	if(i<query_skill("strike",1))
	i=query_skill("strike",1);
	if(i<query_skill("leg",1))
	i=query_skill("leg",1);
	return (int)query("str") + (int)query("force_factor")+i/30
		+ query_temp("apply/strength");
}

int query_dex()
{
	return (int)query("dex") + (int)query_skill("dodge",1)/30+
	  query_temp("apply/dodgeaction");
}

int query_int()
{
return (int)query("int")+(int)query_skill("literate",1)/10
                +query_temp("apply/intelligence");
}

int query_spi()
{
	return (int)query("spi")
                + ( query_temp("apply/spirituality") >= 15 ? 15: query_temp("apply/spirituality"));
}

int query_cps()
{
	return (int)query("cps") + (int)query("force_factor") / 2
                + ( query_temp("apply/composure") >= 15 ? 15: query_temp("apply/composure"));
}

int query_per()
{
	return (int)query("per")+query_skill("tianmo-dafa",1)/50+query_skill("tianmo-dafa",1)/50
                +query_temp("apply/personality");
}

int query_con()
{
	return (int)query("con")+(int)query_skill("force",1)/30
                +query_temp("apply/constitution");
}

int query_kar()
{
	return (int)query("kar")
                +query_temp("apply/karma");
}

int query_quest_kar()
{
	int exp;
	
	exp = query("combat_exp");
	
    if(exp<1000000)
        return random(5);
	
    exp = exp/1000000;
	if(exp>=20)
		exp = random(exp);
	if(exp>=27&&random(100)<95)
		exp = random(20);
	return exp;
	
}

int query_agi()
{
        return (int)query("agi")
                + ( query_temp("apply/agility") >= 15 ? 15: query_temp("apply/agility"));
}
int query_dur()
{
        return (int)query("dur")
                + ( query_temp("apply/durability") >= 15 ? 15: query_temp("apply/durability"));
}
int query_fle()
{
        return (int)query("fle")
                + ( query_temp("apply/flexibility") >= 15 ? 15: query_temp("apply/flexibility"));
}
int query_tol()
{
        return (int)query("tol")
                + ( query_temp("apply/tolerance") >= 15 ? 15: query_temp("apply/tolerance"));
}

