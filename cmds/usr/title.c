// title.c (Mon  09-04-95)
 
#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string str)
{

 if( wizhood(me) == "(arch)" || wizhood(me) == "(admin)" || wizhood(me) == "(wizard)" || wizhood(me) == "(imm)" ) 
 {
 if(str){
 	str = replace_string(str, "$BLK$", BLK);
	str = replace_string(str, "$RED$", RED);
	str = replace_string(str, "$GRN$", GRN);
	str = replace_string(str, "$YEL$", YEL);
	str = replace_string(str, "$BLU$", BLU);
	str = replace_string(str, "$MAG$", MAG);
	str = replace_string(str, "$CYN$", CYN);
	str = replace_string(str, "$WHT$", WHT);
	str = replace_string(str, "$HIR$", HIR);
	str = replace_string(str, "$HIG$", HIG);
	str = replace_string(str, "$HIY$", HIY);
	str = replace_string(str, "$HIB$", HIB);
	str = replace_string(str, "$HIM$", HIM);
	str = replace_string(str, "$HIC$", HIC);
	str = replace_string(str, "$HIW$", HIW);
	str = replace_string(str, "$NOR$", NOR);
	  me->set("title",str);
	  }
    printf(BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(me),me->short(1) );
    return 1;

}
else{
    printf(BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(me),me->short(1) );
    return 1;
    }
}
 
int help(object me)
{
    write(@HELP
ָ���ʽ: title
 
��ʾ��Ŀǰ�Ľ׼���ͷ�Ρ�
 
HELP
    );
}
 
