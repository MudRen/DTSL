// kouzhong by dtsl

string get_place(string str)
{
	string *place = explode(str, "/");

	str = "";

	if(place[0] == "d")
	switch(place[1]){
		case "baling":		str = "����";		break;
		case "cahc":	str = "�����ʳ�";		break;
		case "changan":		str = "������";		break;
		case "changbaishan":		str = "����ɽ";		break;
		case "chanyuan":		str = "������Ժ";		break;
		case "yangzhou": 		str = "���ݳ�";		break;
		case "chengdu":		str = "�ɶ�";	break;
		case "dajianglian":		str = "����";		break;
		case "death":	str = "�ظ�";		break;
		case "dingxiang":		str = "����";		break;
		case "dongming":		str = "����";		break;
		case "emeishan":		str = "��üɽ";		break;
		case "feima-muchang":	str = "��������";		break;
		case "gaoli":		str = "����";		break;
		case "huashan":		str = "��ɽ";		break;
		case "haisha":		str = "��ɳ��";		break;
		case "hangzhou":		str = "���ݳ�";		break;
		case "hefei":		str = "�Ϸ�";		break;
		case "hengshan":		str = "��ɽ";		break;
		case "jingzhai":	str = "�Ⱥ���ի";		break;
		case "jiujiang":	str = "�Ž�";		break;
		case "leshou":		str = "����";		break;
		case "lingnan":		str = "�μұ�";		break;
		case "liyang":		str = "����";	break;
		case "luoyang":		str = "����";	break;
		case "luoyange":		str = "������";		break;
		case "mangshan":	str = "��ɽ";		break;
		case "mayi":		str = "����";		break;
		case "yangzhoubei":		str = "���ݱ�";		break;
		case "outyang" :		str = "�������";		break;
		case "pengliang":	str = "����";		break;
		case "saiwai":	str = "����";		break;
		case "shanhaiguan":		str = "ɽ����";		break;
		case "slwg":		str = "ʯ�����";		break;
		case "suiye":		str = "��Ҷ";	break;
		case "taishan":		str = "̩ɽ";		break;
		case "taiyuan":	str = "̫ԭ";		break;
		case "tujue":		str = "ͻ��";		break;
		case "wuyishan":	str = "����ɽ";		break;
		case "xiangyang":		str = "����";		break;
		case "xingyang":	str = "����";		break;
		case "yjp":		str = "�Ľ���";		break;
		case "xuchengn":	str = "���";		break;
		case "yuyang":	str = "����";		break;
		case "yinkui":		str = "������";		break;
//		case "zhiye":		str = "����";		break;
		default:		str = "��ԭ����";	break;
	}
	return str;
}
