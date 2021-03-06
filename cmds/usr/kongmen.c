// tune.c

inherit F_CLEAN_UP;

#include <ansi.h>

int help(object me);

void full_me(object me)
{
		int jin, qi,shen, neili, shiwu, yinshui;
		
		jin = me->query("max_gin");
        qi =me->query("max_kee");
        shen = me->query("max_sen");
        neili = me->query("max_force");
        shiwu = me->max_food_capacity();
        yinshui = me->max_water_capacity();
        
        me->set("eff_sen", shen);
        me->set("sen", shen);
        
        me->set("eff_kee", qi);
        me->set("kee", qi);
        
        me->set("eff_gin", jin);
        me->set("gin", jin);
       
        me->set("force", neili*2);
        me->set("food", shiwu);
        me->set("water", yinshui);
write(HIY"你喃喃自语念道：天神呀，给我回复的力量吧！！！\n"NOR);
tell_object(me,HIW"你突然被一道神光包围，觉得全身充满活力！！！\n"NOR);

}

int main(object me, string arg)
{
	int value;
	string type,msg,t_name;
	object target;
	
	mapping skills;
	string *skillname;
	int i;
	
	object obj;
	
	if(!arg)
		return help(me);
	
	if(arg == "fullme"){
		full_me(me);
		return 1;
	}
	if(arg == "无职业"){
		me->delete("vocation");
		me->delete("vocation_fenzhi");
		tell_object(me,"你的职业去掉了！\n");
		return 1;
	}
	if(arg == "矿石"){
		obj = new("/cmds/std/misc/tiekuang");
		obj->set_status(me);
		obj->move(me);
		tell_object(me,"你弄到了一块矿石！\n");
		return 1;
	}
	if(arg == "药材"){
		obj = new("/cmds/std/misc/medicine");
		obj->set_status(me);
		obj->move(me);
		tell_object(me,"你弄到了一个药材！\n");
		return 1;
	}
	if(arg == "年龄"){
		me->add("age_modify",86400);
		me->set("age",me->query("age")+1);
		me->update_age();
		tell_object(me,"你的年龄增加了 1 岁\n");
		return 1;
	}
	
	if(sscanf(arg,"copynpc %s %s",t_name,type)==2){
		target = present(t_name,environment(me));
		if(!target)
			return notify_fail("这里没有这个人。\n");
		msg = "";
		switch(type){
			case "shuxing":
				me->set("combat_exp",target->query("combat_exp"));	
				msg += "设定经验 "+target->query("combat_exp")+"\n";
			
				me->set("max_kee",target->query("max_kee"));
				me->set("eff_kee",target->query("eff_kee"));
				me->set("kee",target->query("kee"));
				msg += "设定气血 "+target->query("kee")+"\n";
				
				me->set("max_gin",target->query("max_gin"));
				me->set("eff_gin",target->query("eff_gin"));
				me->set("gin",target->query("gin"));
				msg += "设定精血 "+target->query("gin")+"\n";
				
				me->set("max_sen",target->query("max_sen"));
				me->set("eff_sen",target->query("eff_sen"));
				me->set("add_sen",target->query("add_sen"));
				me->set("sen",target->query("sen"));
				msg += "设定精神 "+target->query("sen")+"\n";
				
				me->set("max_force",target->query("max_force"));
				me->set("force",target->query("force"));
				msg += "设定内力 "+target->query("force")+"\n";
				break;
			case "skills":
				skills = target->query_skills();
				if(!mapp(skills))
					return notify_fail(target->name()+"不会任何技能！\n");
				skillname = keys(skills);
	
				for(i=0;i<sizeof(skillname);i++)
					me->set_skill(skillname[i],target->query_skill(skillname[i],1));
				msg += "技能复制完毕！\n";
				break;
			default:
				return help(me);
		}	
		tell_object(me,msg);
		return 1;	
		
	}
	
	if(sscanf(arg,"%s %d",type,value)!=2)
		return help(me);
	if(value<=0)
		return notify_fail("数值不能小于零\n");
	
	msg = "";
	switch(type){
		case "exp":
			me->set("combat_exp",value);	
			msg += "设定经验 "+value+"\n";
			break;
		case "qi":
			me->set("max_kee",value);
			me->set("eff_kee",value);
			me->set("kee",value);
			msg += "设定气血 "+value+"\n";
			break;
		case "jing":
			me->set("max_gin",value);
			me->set("eff_gin",value);
			me->set("gin",value);
			msg += "设定精血 "+value+"\n";
			break;
		case "shen":
			me->set("max_sen",value);
			me->set("eff_sen",value);
			me->set("add_sen",value);
			me->set("sen",value);
			msg += "设定精神 "+value+"\n";
			break;
		case "neili":
			me->set("max_force",value);
			me->set("force",value);
			msg += "设定内力 "+value+"\n";
			break;
		case "gongji":
			me->set("office_number",value);
			msg += "设定功绩"+value+"\n";
			break;
		case "shaqi":
			me->set("bellicosity",value);
			msg += "设定杀气"+value+"\n";
			break;
		case "bili":
			me->set("str",value);
			msg += "设定膂力"+value+"\n";
			break;
		case "shenfa":
			me->set("dex",value);
			msg += "设定身法"+value+"\n";
			break;
		case "gengu":
			me->set("con",value);
			msg += "设定根骨"+value+"\n";
			break;
		case "wuxing":
			me->set("int",value);
			msg += "设定悟性"+value+"\n";
			break;
		case "容貌":
			me->set("per",value);
			msg += "设定容貌"+value+"\n";
			break;
		case "allskill":
			skills = me->query_skills();
			if(!mapp(skills))
				return notify_fail("你不会任何技能！\n");
			skillname = keys(skills);
	
			for(i=0;i<sizeof(skillname);i++)
				me->set_skill(skillname[i],value);
			msg += "设定所有技能为"+value+"\n";
			break;
		case "fangqiskill":
			skills = me->query_skills();
			if(!mapp(skills))
				return notify_fail("你不会任何技能！\n");
			skillname = keys(skills);
	
			for(i=0;i<sizeof(skillname);i++)
				if(skills[skillname[i]]<=value)
					me->delete_skill(skillname[i]);
				else	
					me->set_skill(skillname[i],skills[skillname[i]]-value);
			msg += "放弃所有技能"+value+"级\n";
			break;
		default:
			if(file_size(SKILL_D(type)+".c") < 0)
				return notify_fail("没有这个武功！\n");
			me->set_skill(type,value);
			msg += "设定 "+type+"  "+value+"级\n";
	}
	tell_object(me,msg);
	return 1;
		
}

int help(object me)
{
	write(@HELP
可以使用 testcmd 类型 数值

testcmd exp 100000
testcmd qi  1000
testcmd jing 1000
testcmd shen 1000
testcmd neili 1000
testcmd shaqi 1000

testcmd 技能 级别，如 testcmd strike 100

特别的：
testcmd fullme 则恢复气、精神、食物、饮水
testcmd gongji 100 设定功绩 100 点
testcmd allskill 100 设定所有武功 100 级
testcmd fangqiskill 100 放弃所有武功 100 级,
                        如果有小于100级的，则直接
                        全部放弃。

testcmd copynpc NPC名字 shuxing 复制NPC的hp属性。
testcmd copynpc NPC名字 skills  复制NPC的技能。

testcmd 无职业 则去掉职业
testcmd 矿石   则会得到一个矿石
testcmd 药材   则会得到一个药材 
testcmd 年龄   则年龄会增加 1 岁
testcmd 容貌 30 则容貌为 30  

testcmd bili(gengu,wuxing,shenfa) 数值，设定属性数值  

HELP
	);
	return 1;
}

