//dt 
//
#include <ansi.h>

string query_rank(object ob)
{
 string *sword,*blade;int age,exp,mks,pks,deadtimes,i;
	age=(int)ob->query("age",1);
	exp=(int)ob->query("combat_exp",1);
	mks=(int)ob->query("MKS",1);
	pks=(int)ob->query("PKS",1);
	deadtimes=(int)ob->query("deadtimes",1);
	sword=ob->query("sword");blade=ob->query("blade");
	if(ob->query("env/class")) return HIG"��"+ob->query("env/class")+HIG"��"NOR;
	if(ob->query_temp("rank/class")) return HIG"��"+ob->query_temp("rank/class")+HIG"��"NOR;
	if(ob->is_ghost())
		return HIB "�� ��  �� ��" NOR;
	switch(ob->query("gender"))
	{
	case "����":
		{
			switch(wizhood(ob))
			{
			case "(admin)": return HIG"�� ��  �� ��"NOR;
                        case "(arch)" : return HIR"�� ��  �� ��"NOR;
                        case "(wizard)" : return HIW"�� ��  �� ��"NOR;
                        case "(apprentice)" : return HIY"�� ��  �� ��"NOR;
			case "(immortal)": return HIG"�� ��  �� ��"NOR;
			default:
				{
					if(ob->query("vocation")=="����"&&ob->query("vocation_score")>=1000000)
						   return HIG"��������ʦ��"NOR;
					else if(ob->query("vocation")=="ҩʦ"&&ob->query("vocation_score")>=1000000)
							return HIY"��ҩ��������"NOR;
					else if(ob->query("vocation")=="ɱ��"&&ob->query("vocation_score")>=1000000)
							return HIR"��ɱ��֮����"NOR;
                                        else  if(ob->query("vocation")=="����"&&ob->query("vocation_score")>=1000000)
                                        return HIY"����    ��"NOR;
                                        else if(ob->query("xiaqi/weiqi")>=900) return HIY"��Χ���ʦ��"NOR;
                                        else if(ob->query("xiaqi/wuziqi")>=900) return HIY"�����Ӵ�ʦ��"NOR;
					else if(sizeof(sword)>=10&&sizeof(blade)>=10) return HIG"������˫����"NOR;
					else if(sizeof(sword)>=10) return HIG"�� ��  �� ��"NOR;
					else if(sizeof(blade)>=10) return HIG"�� ��  �� ��"NOR;
					else if(age<20&&exp>2000000) return HIG"�������漣��"NOR;
					else if(age<20&&exp>1000000) return HIG"������������"NOR;
					else if((mks+pks)>=1000000) return HIG"��ɱ�˿�ħ��"NOR;
					else if(deadtimes>=100) return HIR"������սʿ��"NOR;
                                        else if(ob->query("family/family_name")=="������Ժ"){
                                               if(ob->query("family/generation")==8)
                                               return HIC"���׼ҵ��ӡ�"NOR;
                                               if(ob->query("family/generation")==7)
                                               return HIC"������ɮ�ˡ�"NOR;
                                               if(ob->query("family/generation")==6)
                                               return HIY"�������޺���"NOR;
                                               if(ob->query("family/generation")==5)
                                               return HIY"���������ߡ�"NOR;
                                               if(ob->query("family/generation")==4)
                                               return HIY"�������ʦ��"NOR;
                                               if(ob->query("family/generation")==3)
                                               return HIY"��һ����ʦ��"NOR;
                                              }					
					else 
					 switch(ob->query("class"))
					{
			                  case "shibing": return HIG"�� ʿ  �� ��"NOR;
					  case "xiaowei": return HIG"�� У  ξ ��"NOR;
					  case "canjiang": return HIG"�� ��  �� ��"NOR;
					  case "guanchai": return HIG"�� ��  �� ��"NOR;
					  case "wujiang": return HIG"�� ��  �� ��"NOR;
					  case "jiangjun": return HIG"�� ��  �� ��"NOR;
			                  case "fighter": return HIG"�� ս  ʿ ��"NOR;//can add more
			               //yin gui rank
					  case "yin1": return HIY"�� ��  �� ��"NOR;
					  case "yin2": return HIG"�� ��  �� ��"NOR;
					  case "yin3": return HIW"�� ��  �� ��"NOR;
					  case "bonze": return HIG"�� ��  �� ��"NOR;
				      //songjia-bao rank
				          case "song1": return HIG"���μ���ͽ��"NOR;
				          case "song2": return HIG"���μ�������"NOR;
				          case "song3": return HIG"�����ϵ�����"NOR;
				     //dongming rank
				          case "dongming1": return HIG"������������"NOR;
				          case "dongming2": return HIG"������ս����"NOR;
				          case "dongming3": return HIG"�����黤����"NOR;
				    //huajian rank.
				          case "hua1": return HIW"������������"NOR;
				          case "hua2": return HIW"�����令����"NOR;
				   //yi jian pai rank
				          case "yijian1": return HIG"���Ľ����ӡ�"NOR;
				          case "yijian2": return HIG"���Ľ���ʦ��"NOR;
				          case "yijian3": return HIY"���Ľ���ʦ��"NOR;
				          case "gaoli1": return HIG"��������ʿ��"NOR;
				          case "gaoli2": return HIG"����͢��ʿ��"NOR;
				  //tujue rank
				          case "tujue1": return HIY"��ͻ�����ߡ�"NOR;
				          case "tujue2": return HIY"��ͻ����ʿ��"NOR;
				          case "tujue3": return HIY"��ͻ�ʻ�˧��"NOR;
				  	default:
						  
						  {   i=ob->query("age");
							  if(i<=18) return "�� ��  �� ��";
							  if(i<=30) return "���������ӡ�";
							  if(i<=40) return "���������ӡ�";
							  if(i<=60) return "���������ӡ�";
							  if(i<=100) return "���������ˡ�";
							  if(i>100) return "����̶���ǡ�";
						  }
					}
				}
			}
		}

    case "Ů��":
		{
			switch(wizhood(ob))
			{
			case "(admin)": return HIG"�� ��  �� ��"NOR;
                        case "(arch)" : return HIR"�� ��  Ů ��"NOR;
                        case "(wizard)" : return HIW"�� ��  Ů ��"NOR;
                        case "(apprentice)" : return HIY"�� Ѳ  ʹ ��"NOR;
			case "(immortal)": return HIG"�� ��  �� ��"NOR;
			default:
				{
					if(ob->query("vocation")=="����"&&ob->query("vocation_score")>=1000000)
						   return HIG"��������ʦ��"NOR;
					else if(ob->query("vocation")=="ҩʦ"&&ob->query("vocation_score")>=1000000)
							return HIY"��ҩ��������"NOR;
					else if(ob->query("vocation")=="ɱ��"&&ob->query("vocation_score")>=1000000)
							return HIR"��ɱ��֮����"NOR;
                                        else  if(ob->query("vocation")=="����"&&ob->query("vocation_score")>=1000000)
                                        return HIY"����    ��"NOR;
                                        else if(ob->query("xiaqi/weiqi")>=900) return HIY"��Χ���ʦ��"NOR;
                                        else if(ob->query("xiaqi/wuziqi")>=900) return HIY"�����Ӵ�ʦ��"NOR;
					else if(sizeof(sword)>=10&&sizeof(blade)>=10) return HIG"������˫����"NOR;
					else if(sizeof(sword)>=10) return HIG"�� ��  �� ��"NOR;
					else if(sizeof(blade)>=10) return HIG"�� ��  �� ��"NOR;
					else if(age<20&&exp>2000000) return HIG"�������漣��"NOR;
					else if(age<20&&exp>1000000) return HIG"������������"NOR;
					else if((mks+pks)>=1000000) return HIG"��ɱ��ħŮ��"NOR;
					else if(ob->query_skill("wuwang-jing",1)>400) return HIY"��һ�����᡿"NOR;
					else if(deadtimes>=100) return HIG"������սʿ��"NOR;
					else if(ob->query("family/family_name")=="�Ⱥ���ի"&&
					        ob->query("class")=="bonze") return HIY"����ի���᡿"NOR;
					else if(ob->query("execute_quest/xinyoulingxi"))
					     return HIG"��������Ϭ��"NOR;
					else if(ob->query("execute_quest/jianxintongming"))
					     return HIG"������ͨ����"NOR;
					else
					switch(ob->query("class"))
					{
			                  case "shibing": return HIG"�� ʿ  �� ��"NOR;
					  case "xiaowei": return HIG"�� У  ξ ��"NOR;
					  case "canjiang": return HIG"�� ��  �� ��"NOR;
					  case "guanchai": return HIG"�� ��  �� ��"NOR;
					  case "wujiang": return HIG"�� ��  �� ��"NOR;
					  case "jiangjun": return HIG"�� ��  �� ��"NOR;
			                  case "fighter": return HIG"�� ս  ʿ ��"NOR;//can add more
			                  case "bonze": return HIG"�� ��  �� ��"NOR;
					  //yingui rank                                          
			                  case "yin_guan": return HIR"���������ӡ�"NOR;
			                  case "yin1": return HIY"�� ��  �� ��"NOR;
                                          case "yin2": return HIG"�� ��  �� ��"NOR;
					  case "yin3": return HIW"�� ��  �� ��"NOR;
					  //lingnan rank
					  case "song1": return HIG"���μ���ͽ��"NOR;
				          case "song2": return HIG"���μ�������"NOR;
				          case "song3": return HIG"�����ϵ�����"NOR;
				          //dongming rank
				          case "dongming1": return HIG"������Ů����"NOR;
				          case "dongming2": return HIG"���������ӡ�"NOR;
				          case "dongming3": return HIG"�����黤����"NOR;
				          //jingzhai rank.
				          case "jingzhai1": return HIW"���Ⱥ����ӡ�"NOR;
				          case "jingzhai2": return HIW"���Ⱥ����ӡ�"NOR;
				          //huajian rank.
				          case "hua1": return HIW"������Ů����"NOR;
				          case "hua2": return HIW"�����令����"NOR;
				          //yi jian pai rank
				          case "yijian1": return HIG"���Ľ����ӡ�"NOR;
				          case "yijian2": return HIG"���Ľ���ʦ��"NOR;
				          case "yijian3": return HIY"���Ľ���ʦ��"NOR;
				          case "gaoli1": return HIG"��������ʿ��"NOR;
				          case "gaoli2": return HIG"����͢��ʿ��"NOR;
				          //tujue rank
				          case "tujue1": return HIY"������Ů����"NOR;
				          case "tujue2": return HIY"��ͻ��Ů�١�"NOR;
				          case "tujue3": return HIY"��ͻ�ʻ�˧��"NOR;
				          
				          case "bonze":  return HIY"����    �á�"NOR;
					  default:
						 
						  {   i=ob->query("age");
							  if(i<=18) return "�� ��  Ů ��";
							  if(i<=30) return "������Ů�ӡ�";
							  if(i<=40) return "������Ů�ӡ�";
							  if(i<=60) return "������Ů�ӡ�";
							  if(i<=100) return "���������ˡ�";
							  if(i>100) return "����̶���ǡ�";
						  }
					}
				}
			}
		}
	}
} 


string query_respect(object ob)
{
	int age;
       if(ob->query("race")!="����")
			return "Ұ��";
   age=ob->query("age");
   if(ob->query("rank_respect"))
    return ob->query("rank_respect");
	switch(ob->query("gender"))
	{
	case "����":
		{
			if((string)ob->query("class")=="bonze")
			{
				if(age<18) return "С����";
				else if(age<30) return "ɮ��";
				else if(age<40) return "��ʦ";
				else return "��ɮ";
			}
			else
			{
				if(age<18) return "С�ֵ�";
				else if(age<30) return "׳ʿ";
				else if(age<60) return "��̨";
				else return "������";
			}
		}
	case "Ů��":
		{
			if((string)ob->query("class")=="bonze")
			{
				if(age<18) return "Сʦ̫";
				else if(age<30) return "ʦ̫";
                else return "��ʦ̫";
			}
			else
			{
				if(age<18) return "С����";
				else if(age<40) return "����";
				else if(age<60) return "����";
				else return "����";
			}
		}
	}
}

string query_rude(object ob)
{
	int age;string race;
	race=(string)ob->query("race");
	if(ob->query("race")!="����")
			return "Ұ��";
	if(ob->query("rank_rude"))
    return ob->query("rank_rude");
	age=ob->query("age");
 switch(race)
 {
  case "����": 
  case "Ұ��": return "С����";
  default:
   {  
	switch(ob->query("gender"))
	{
	 case "����":
		 {
			 if((string)ob->query("class")=="bonze")
			 {
				 if(age<18) return "Сͺ¿";
				 else if(age<30) return "ͺ¿";
				 else return "��ͺ¿";
			 }
			 else
			 {
				 if(age<18) return "С���˵�";
				 else if(age<30) return "�ϻ쵰";
				 else return "��ƥ��";
			 }
		 }
	 case "Ů��":
		 {
			 if((string)ob->query("class")=="bonze")
			 {
				 if(age<18) return "�����";
				 else if(age<30) return "�����";
				 else return "�����";
			 }
			 else
			 {
				 if(age<18) return "С����";
				 else if(age<30) return "����";
				 else return "��������";
			 }
		 }
	}
   }

 }
}

string query_self(object ob)
{
   int age;string str;
   age=ob->query("age");
   if( stringp(str = ob->query("rank_info/self_rude")) )
                return str;
   switch(ob->query("gender"))
   {
     case "����":
		 {
			 if((string)ob->query("class")=="bonze")
			 {
				 if(age<18) return "Сɮ";
				 else if(age<60) return "ƶɮ";
				 else return "��ɮ";
			 }
			 else
			 {
				 if(age<18) return "С��";
				 else if(age<60) return "����";
				 else return "��ͷ��";
			 }
		 }
	 case "Ů��":
		 {
			 if((string)ob->query("class")=="bonze")
			 {
				 if(age<18) return "С��";
				 else if(age<60) return "ƶ��";
				 else return "����";
			 }
			 else
			 {
				 if(age<18) return "СŮ��";
				 else if(age<60) return "���";
				 else return "������";
			 }
		 }

   }
}
		 
  
string query_self_rude(object ob)
{
   int age;string str;
   age=ob->query("age");
   
        if( stringp(str = ob->query("rank_info/self_rude")) )
                return str;
   switch(ob->query("gender"))
   {
     case "����":
		 {
			 if((string)ob->query("class")=="bonze")
			 {
				 if(age<18) return "С����";
				 else if(age<30) return "������";
				 else return "�Ϻ�����";
			 }
			 else
			 {
				 if(age<18) return "Сү��";
				 else if(age<30) return "�๫��";
				 else return "��үү��";
			 }
		 }
	 case "Ů��":
		 {
			 if((string)ob->query("class")=="bonze")
			 {
				 if(age<18) return "С�����";
				 else if(age<30) return "�����";
				 else return "�������";
			 }
			 else
			 {
				 if(age<18) return "��С��";
				 else if(age<30) return "������";
				 else return "������";
			 }
		 }

   }
}
		 	

string query_close(object ob, int age, string rgender)
{
	int a1, a2;
	string gender;
	if (objectp(ob) )       {
		if( !age )
			a1 = this_player()->query("age");
		else
			a1 = ob->query("age");
		if( !age)
			a2 = ob->query("age");
		else    a2 = age;
	}
	
	if( !rgender )
		gender = ob->query("gender");					   
	else    gender = rgender;

	switch ( gender ) {
	case "Ů��" :
		if (a1 > a2)
			return "����";
		else
			return "���";
		break;
	default :
		if (a1 > a2)
			return "�ܵ�";
		else
			return "���";
	}
}

string query_self_close(object ob, int age)
{
	int a1, a2;
	string gender;
	
	if(!ob)
	return "";
	
	if( objectp(ob) ) {
		if( !age )
			a1 = this_player()->query("age");
		else
			a1 = ob->query("age");
		if( !age)
			a2 = ob->query("age");
		else    a2 = age;
	}

	if( age )
		gender = ob->query("gender");
	else
		gender = this_player()->query("gender");

	switch (gender) {

	case "Ů��" :
		if (a1 > a2)
			return "�����";
		else
			return "С����";
		break;
	default :
		if (a1 > a2)
			return "������";
		else
			return "С����";
	}
}


