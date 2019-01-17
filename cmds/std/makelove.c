// makelove.c

#include <ansi.h>
#include <login.h>
inherit F_CLEAN_UP;
object make_body(object ob);
int check_legal_id(string id);
int check_legal_name(string name);
string *banned_name=({});
int main(object me, string arg)
{
        object who;
        string target;

        if(me->is_busy() || me->is_fighting())
                return notify_fail("����æ���أ�����makeloveѽ��\n");

        if(!arg ) return notify_fail("ָ���ʽ��makelove with����ĳ�ˣ�\n");

        if ( sscanf( arg, "with %s", target ) != 1 ) 
                return notify_fail("ָ���ʽ��makelove with����ĳ�ˣ�\n");
        if ( target!= me->query("couple/couple_id") )
                return notify_fail("ֻ�з���֮�����������\n");

        if( !(who=present(target,environment(me))) )
                return notify_fail("�����ż�������ﰡ��\n"); 
        if ( ( me->query("gin") < me->query("max_gin")/2 )||
             ( me->query("kee") < me->query("max_kee")/2 ) )
                return notify_fail("��Ŀǰ������״��̫���ˣ���Ҫ����ֻ��������Σ�գ�\n");

        if ( ( who->query("gin") < who->query("max_gin")/2 )||
             ( who->query("kee") < who->query("max_kee")/2 ) )
                return notify_fail(who->name()+"Ŀǰ������״��̫���ˣ���Ҫ����ֻ��������Σ�գ�\n");

        // start making love between these two people :P
        me->start_busy(7);
        who->start_busy(7);
        me->set_temp("apply/short",({HIY"�����⿴"NOR}));
        who->set_temp("apply/short",({HIY"�����⿴"NOR}));
        environment(me)->set("makelove_room",1);
        if(me->query("gender") == "Ů��" ) 
            message_vision(CYN"$N������$n�Ļ�����к������������Ͻ������ޣ�\n"+
                "$nӵ����$N������$Nһ��������ǣ�\n"NOR,me,who);
        else 
            message_vision(CYN"$nӵ����$N������$Nһ��������ǣ�\n"+
                "$N������$n�Ļ�����к������������Ͻ������ޣ�\n"NOR,who,me);

        call_out("step2",2,me,who);
        return 1;
}

int step2(object me, object who)
{
        if(me->query("gender") == "����" ) 
            message_vision(YEL"$N�����ر�ס$n�������˵�����һ��������������һ�����£���\n"NOR,me,who);
        else
            message_vision(YEL"$N�����ر�ס$n�������˵�����һ��������������һ�����£���\n"NOR,who,me);

        call_out("remove_cloth",1,me);
        call_out("remove_cloth",1,who);
        call_out("step3",3,me,who);
        return 1;
}

int step3(object me, object who)
{
        message_vision(MAG"$N��$n�������Ҹ��ĺ������������������������\n"NOR,me,who);
        call_out("step4",2,me,who);
        return 1;
}

int step4(object me, object who)
{
        if(me->query_condition("xxx"))
                me->clear_condition("xxx");
        if(who->query_condition("xxx"))
                who->clear_condition("xxx");

        me->receive_damage("gin",me->query("max_gin")/2);
        me->receive_damage("kee",me->query("max_kee")/2);

        who->receive_damage("gin",who->query("max_gin")/2);
        who->receive_damage("kee",who->query("max_kee")/2);
        me->delete_temp("apply");
        who->delete_temp("apply");
        if(me->query("gender")=="Ů��"&&!me->query("have_baby"))
        me->add("makelove_times",1);
        else
        if(!who->query("have_baby")) 
        who->add("makelove_times",1);
        message_vision(HIW"����һ���ָֻ���ƽ����\n"NOR,me,who);
        environment(me)->delete("makelove_room");
       /* if(me->query("gender")=="Ů��"&&me->query("makelove_times")>=40)
        {
        	message_vision("$N��Ȼ���ø���һ����ʹ!\n",me);
        	me->delete("makelove_times");
        	call_out("birth",1,who,me);
        }
        if(who->query("gender")=="Ů��"&&who->query("makelove_times")>=40)
        {
        	message_vision("$N��Ȼ���ø���һ����ʹ!\n",who);
        	who->delete("makelove_times");
        	call_out("birth",1,me,who);
        }*/
        return 1;
}

int remove_cloth(object me)
{
        object *inv;
        string str;
        int i;
        // remove all staff before sleepping :P
        inv = all_inventory(me);
        for(i=0; i < sizeof(inv); i++ ) {
            if( inv[i]->query("equipped") == "worn" ) {
                if( inv[i]->unequip() ) {
                    if( !stringp(str = inv[i]->query("remove_msg")) )
                        switch(inv[i]->query("armor_type")) {
                                case "cloth":
                                case "armor":
                                case "surcoat":
                                case "boots":
                                        str = YEL "$N��$n����������\n" NOR;
                                        break;
                                case "bandage":
                                        str = YEL "$N��$n���˿ڴ�����������\n" NOR;
                                        break;
                                default:
                                        str = YEL "$Nж��$n��װ����\n" NOR;
                        }
                message_vision(str, me, inv[i]);
                }
            } else if ( inv[i]->query("equipped") == "wielded" ) {
                if(inv[i]->unequip() ) {
                    if( !stringp(str = inv[i]->query("unwield_msg") )) 
                        str = YEL "$N�������е�$n��\n" NOR;
                message_vision(str, me, inv[i]);
                }
            }
        }
}

void birth(object me,object ob)
{
   "/adm/daemons/marryd.c"->do_birth(me,ob);
   return;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : makelove with <��ż>
 
���ָ�������������ż������
 
HELP
    );
    return 1;
}
 
