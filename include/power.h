
//power.h for power.c
#include <ansi.h>
mapping wide=([
"changan":"����","luoyang":"����","xiangyang":"����",
"chengdu":"�ɶ�","baling":"����","hefei":"�Ϸ�",
"jiujiang":"�Ž�","yangzhou":"����","hangzhou":"����",
"xingyang":"����","liyang":"����","xucheng":"���",
"pengliang":"����","leshou":"����","yuyang":"����",
"shanhaiguan":"ɽ����","taiyuan":"̫ԭ","mayi":"����",
"dingxiang":"����","saiwai":"����","suiye":"��Ҷ",
"tuyuhun":"���Ȼ�","gaoli":"����",]);

string check_wide(string w)
{
  if(!wide[w]) return "�޴�";
  return wide[w];
}

string get_power(int power)
{
   switch(power)
   {
    case 2: return "�μ�";break;
    case 3: return "���ϼ�";break;
    case 4: return "�м�";break;
    case 5: return "���¼�";break;
    case 6: return "�¼�";break;
    case 7: return "���¼�";break;
    case 8: return "��ͼ�";break;
    default: return "û���κμ���";break;
   }
}

string get_leader(object ob)
{
  switch(ob->query("shili/leader"))
  {
    case "lifa_b": return HIW"�����"NOR;break;
    case "songjia_b": return HIW"�μұ�����"NOR;break;
    case "duzun_b": return HIW"���𱤱���"NOR;break;
    case "feima_b": return HIW"������������"NOR;break;
    case "dajiang_b": return HIW"��������"NOR;break;
    case "haisha_b": return HIW"��ɱ�����"NOR;break;
    default: return HIR"���صİ���"NOR;
   }
}

string strleft(string msg,int blank)
{
while(strlen(msg)<blank)
	msg = msg+" ";

return msg;	
		
}

string str2left(string msg,int blank)
{
if(strlen(msg)%2!=0)
	msg = msg+" ";
while(strlen(msg)<blank)
	msg = msg+"��";

return msg;	
		
}