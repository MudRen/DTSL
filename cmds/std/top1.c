#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;
int top_list(object ob1,object ob2);
int get_score(object ob);
int main(object me, string arg)
{
        
        object *list,*ob;
        int i;
        string msg;

      ob = filter_array(objects(), (: userp($1) && !wizardp($1) :));
        list = sort_array(ob, (: top_list :));
      msg =  "\n              �� "+BLINK HIW+"    ����˫����"+HIC+"���߸������а� "NOR"    ��\n";
      msg += "�������������өߩ����������������������ө����������ߩө���������\n";
 msg += "��"+BCYN HIW+"  �� ��  "NOR+" ��"+BCYN HIW+"      ��        ��      "NOR+"��"+BCYN HIW+"  ��    ��  "NOR+"��"+BCYN HIW+" ��  �� "NOR+"��\n";
       msg += "�ĩ����������ة������������������������ة������������ة���������\n";
          for (i = 0 ;i < 20 ; i++) {
        if( i >= sizeof(list)) msg += "����ʱ��ȱ�� \n";
                else {
                if(list[i] == me) msg += BBLU HIY;
             msg += sprintf("��"+HIR+"  %-7s"NOR+" ��"+HIC+" %-12s"NOR+HIC+" %-10s"NOR+"��"+HIG+"%-12s"NOR+"��"+HIY+" %5d"NOR+"  ��\n",chinese_number(i+1),list[i]->query("name"),"["+
      list[i]->query("id")+"]", list[i]->query("family")?  list[i]->query("family/family_name"):"��ͨ����",
        get_score(list[i]));
                }
                         }
        msg += "����������������������������������������������������������������\n";
       msg += "              " +BCYN HIW+ NATURE_D->game_time() + "��\n"NOR;
        write(msg);
        return 1;

}
int top_list(object ob1, object ob2)
{
      int score1,score2;

        score1 = get_score(ob1);
        score2 = get_score(ob2);
     return score2 - score1;
}

int get_score(object ob)
{
        int tlvl,i,score;
        string *ski;
        mapping skills;

      reset_eval_cost();
        skills = ob->query_skills();
        if (!sizeof(skills)) return 1; 
        ski  = keys(skills);
          for(i = 0; i<sizeof(ski); i++) {
           if( (string)ob->query("id")=="kouzhong" ) return 1;     
                        tlvl += skills[ski[i]];
                        }  // count total skill levels
        score = tlvl/10;
        score += ob->query("max_force")/10;
        score += ob->query("max_mana")/10;
//        score += ob->query_str() + ob->query_int() + ob->query_dex() + ob->query_con();
       score += (int)ob->query("combat_exp")/5000;

        return score;
}
int help(object me)
{
write(@HELP
ָ���ʽ : top
 
���ָ���������֪������ʮ���������Щ����ȥ�����ǡ� 
 
HELP
    );
    return 1;
}


