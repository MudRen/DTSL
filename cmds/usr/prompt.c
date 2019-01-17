// prompt.c
/* create by dsm@jianghu 99-8-20
   this is only for jianghu lib.
   via the feature message.c control prompt string.
*/
#include <ansi.h>
inherit F_MESSAGE;

string *clr_msg=({"$RED$","$GRN$","$YEL$","$BLU$","$MAG$","$CYN$","$WHT$","$NOR$",
		"$HIR$","$HIG$","$HIY$","$HIB$","$HIM$","$HIC$","$HIW$","$BLK$"
});
string *clr=({RED,GRN,YEL,BLU,MAG,CYN,WHT,NOR,
		HIR,HIG,HIY,HIB,HIM,HIC,HIW,BLK
});

string replace_color(string arg);
string un_replace_color(string arg);
int string_length(string arg);
int set_prompt(string yn,string arg,string mark);

int main(object me,string arg)
{
	string str;
	if(!arg){
		str=me->query("prompt");
		if(!str) return notify_fail("δ�趨��ʾ����\n");
		else write("��ǰ����ʾ���ǣ�"+un_replace_color(str)+"\n"NOR);
		return 1;
	}
	if(arg=="NONE"){
		write("ȡ����ʾ���趨���Ƿ�ȷ��[Y/N]��");
		input_to("set_prompt","","delete");
		return 1;
	}
	if(string_length(arg)>20) return notify_fail("������ʾ��̫����\n");
	str=replace_color(arg);
	write("���趨����ʾ����ʽΪ��\n"+get_prompt(str)+NOR"\n"+"�Ƿ�ȷ��[Y/N]��");
	input_to("set_prompt",str,"set");
	return 1;
}
string replace_color(string arg)
{
	int i;
	for(i=0;i<sizeof(clr_msg);i++){
		arg=replace_string(arg,clr_msg[i],clr[i]);
	}
	return arg;
}
string un_replace_color(string arg)
{
	int i;
	for(i=0;i<sizeof(clr);i++){
		arg=replace_string(arg,clr[i],clr_msg[i]);
	}
	return arg;
}
int string_length(string arg)
{
	int i;
	for(i=0;i<sizeof(clr_msg);i++){
		arg=replace_string(arg,clr_msg[i],"");
	}
	i=strlen(arg);
	return i;
}
int set_prompt(string yn,string arg,string mark){
	if(yn!="Y" && yn!="y"){
		write("ȡ��������\n");
		return 1;
	}
	switch(mark){
		case "set":this_player()->set("prompt",arg);break;
		case "delete":this_player()->delete("prompt");break;
		default:break;
	}
	return 1;
}
int help(object me)
{
   write( @HELP
ָ���ʽ: prompt		��ʾ��ǰ��ʾ����
          prompt &n		ʹ��Ĭ�ϵĵ�n����ʾ����
          prompt text		��ʾһ�����֣�������20���ַ�����

���������пɰ������������ִ���
$BLK$	��ɫ		$NOR$	�ָ�������ɫ
$RED$	��ɫ		$HIR$	����ɫ
$GRN$	��ɫ		$HIG$	����ɫ
$YEL$	����ɫ		$HIY$	��ɫ
$BLU$	����ɫ		$HIB$	��ɫ
$MAG$	ǳ��ɫ		$HIM$	�ۺ�ɫ
$CYN$	����ɫ		$HIC$	����ɫ
$WHT$	ǳ��ɫ		$HIW$	��ɫ

$JING$	��ǰ�ľ���ֵ	$QI$	��ǰ����Ѫֵ
$TILI$	��ǰ������ֵ	

��������Ϊ��ʦר�á�
$DIR$	��ǰĿ¼
HELP
   );
   return 1;
}
