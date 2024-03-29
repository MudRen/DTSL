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
    if(s=="duzun_b") return "「独尊堡」";
    else if(s=="lifa_b") return "「李  阀」";
    else if(s=="songjia_b") return "「宋家堡」";
    else if(s=="dajiang_b") return "「大江联」";
    else if(s=="haisha_b") return "「海沙帮」";
    else if(s=="jianghuai_b") return "「江淮军」";
    else if(s=="feima_b") return "「飞马牧场」";
    else return "势力不明";
}
string get_guanzhi(string g)
{
    if(stringp(g))
       if(g=="lifa_b")
         return "李阀阀主";
       else if(g=="songjia_b")
             return "宋家堡堡主";
       else if(g=="duzun_b")
             return "独尊堡堡主";
       else if(g=="dajiang_b")
             return "大江联盟主";
       else if(g=="haisha_b")
             return "海沙帮帮主";
       else if(g=="feima_b")
             return "飞马场主";
    if(stringp(g))
     return g;
    return "无";
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
            str = sprintf("「%s」%s", nick, str);

        if( stringp(title = query("title")) )
            str = sprintf("%s%s%s", title,(nick?"":" "), str);
        /*if(stringp(shili_name=query("shili/name")))
         {
            shili_name=get_shili(shili_name);
            str=sprintf("%s%s所属势力%s%s",title,(nick?"":" "),shili_name);
          }
        if(stringp(shili_leader=query("shili/leader")))
          {
             shili_leader=get_guanzhi(shili_leader);
             str=sprintf("%s%s%s职务%s%s",title,(nick?"":" "),shili_name,shili_leader);
           }	 */
    }

    if( !raw ) {
        if( this_object()->is_ghost() ) str = HIB "(鬼气) " NOR + str;
                if( this_object()->query("killer") ) str += HIR " (反贼)"NOR;
        if( this_object()->query("pker") ) str += HIR "（通缉犯）"NOR;
        if( this_object()->query("thief") ) str += HIY " (窃贼)"NOR;
        if( this_object()->is_fighting()) str +=HIR"<战斗中>"NOR;
        if( query_temp("netdead") ) str += HIG " <断线中>" NOR;
        if( in_input() ) str += HIC " <输入文字中>" NOR;
        if( in_edit() ) str += HIY " <编辑档案中>" NOR;
        if( interactive(this_object())
        &&	query_idle( this_object() ) > 120 )
            str += HIM + sprintf(" <发呆 %d 分钟>[2;37;0m",
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
        str = short(raw) + "。\n";

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
