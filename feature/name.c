// name.c

#include <ansi.h>
#include <dbase.h>

nosave string *my_id;

void set_name(string name, string *id)
{
    set("name", name);
    set("id", id[0]);
    my_id = id;
}

int id(string str)
{
    string *applied_id;

    if( this_player() && !this_player()->visible(this_object()) ) return 0;

    if( pointerp(applied_id = query_temp("apply/id"))
    &&	sizeof(applied_id) )
        if( member_array(str, applied_id)!=-1 )
            return 1;
        else
            return 0;

    // If apply/id exists, this object is "pretending" something, don't
    // recognize original id to prevent breaking the pretending with "id"
    // command.

    if( pointerp(my_id) && member_array(str, my_id)!=-1 )
        return 1;
    else
        return 0;
}

string *parse_command_id_list()
{
    string *applied_id;

    if( pointerp(applied_id = query_temp("apply/id"))
    &&	sizeof(applied_id) )
        return applied_id;
    else
        return my_id;
}

varargs string name(int raw)
{
    string str, *mask;

    if( !raw && sizeof(mask = query_temp("apply/name")) )
        return mask[sizeof(mask)-1];
    else {
        if( stringp(str = query("name")) )
            return str;
        else
            return file_name(this_object());
    }
}

string get_shili(string s)
{
    if(s=="duzun_b") return "�����𱤡�";
    else if(s=="lifa_b") return "����  ����";
    else if(s=="songjia_b") return "���μұ���";
    else if(s=="dajiang_b") return "��������";
    else if(s=="haisha_b") return "����ɳ�";
    else if(s=="jianghuai_b") return "����������";
    else if(s=="feima_b") return "������������";
    else return "��������";
}
string get_guanzhi(string g)
{
    if(stringp(g))
       if(g=="lifa_b")
         return "�����";
       else if(g=="songjia_b")
             return "�μұ�����";
       else if(g=="duzun_b")
             return "���𱤱���";
       else if(g=="dajiang_b")
             return "��������";
       else if(g=="haisha_b")
             return "��ɳ�����";
       else if(g=="feima_b")
             return "������";
    if(stringp(g))
     return g;
    return "��";
}

varargs string short(int raw)
{
    string title, nick, str, *mask;string shili_name,shili_leader;

    if( !stringp(str = query("short")) )
        str = name(raw) + "(" + capitalize(query("id")) + ")";

    if( !this_object()->is_character() ) return str;

    if( !raw && sizeof(mask = query_temp("apply/short")) )
        str = (string)mask[sizeof(mask)-1];
    else {
        if( stringp(nick = query("nickname")) )
            str = sprintf("��%s��%s", nick, str);

        if( stringp(title = query("title")) )
            str = sprintf("%s%s%s", title,(nick?"":" "), str);
        /*if(stringp(shili_name=query("shili/name")))
         {
            shili_name=get_shili(shili_name);
            str=sprintf("%s%s��������%s%s",title,(nick?"":" "),shili_name);
          }
        if(stringp(shili_leader=query("shili/leader")))
          {
             shili_leader=get_guanzhi(shili_leader);
             str=sprintf("%s%s%sְ��%s%s",title,(nick?"":" "),shili_name,shili_leader);
           }	 */
    }

    if( !raw ) {
        if( this_object()->is_ghost() ) str = HIB "(����) " NOR + str;
                if( this_object()->query("killer") ) str += HIR " (����)"NOR;
        if( this_object()->query("pker") ) str += HIR "��ͨ������"NOR;
        if( this_object()->query("thief") ) str += HIY " (����)"NOR;
        if( this_object()->is_fighting()) str +=HIR"<ս����>"NOR;
        if( query_temp("netdead") ) str += HIG " <������>" NOR;
        if( in_input() ) str += HIC " <����������>" NOR;
        if( in_edit() ) str += HIY " <�༭������>" NOR;
        if( interactive(this_object())
        &&	query_idle( this_object() ) > 120 )
            str += HIM + sprintf(" <���� %d ����>[2;37;0m",
                ( query_idle( this_object() ) / 60 ) );
        if( !living(this_object()) ) str += HIR + query("disable_type") + NOR;

    }

    return str;
}

varargs string long(int raw)
{
    string str, extra, *mask;

    if( !raw && sizeof(mask = query_temp("apply/long")) )
        str = mask[sizeof(mask)-1];
    else if( !stringp(str = query("long")) )
        str = short(raw) + "��\n";

    if( stringp(extra = this_object()->extra_long()) )
        str += extra;

    return str;
}

string *get_this_id()
{
   if(!pointerp(my_id))
     return 0;
   else return my_id;
}
