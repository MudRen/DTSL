// natured.c

/* modify by lanxin 99-03-06
   last modify by dsm@jianghu 99-8-20
*/

#include <ansi.h>

#define TIME_TICK ((time())*60)
string *clr_msg=({"RED","GRN","YEL","BLU","MAG","CYN","WHT",
        "HIR","HIG","HIY","HIB","HIM","HIC","HIW","BLK"
});
string *clr=({RED,GRN,YEL,BLU,MAG,CYN,WHT,
        HIR,HIG,HIY,HIB,HIM,HIC,HIW,BLK
});

nosave int current_day_phase;
mapping *day_phase;
mapping *read_table(string file);
void init_day_phase();
void event_midnight();
void event_noon();

void create()
{
    day_phase = read_table("/adm/etc/nature/day_phase");
    init_day_phase();
}

void init_day_phase()
{
    mixed *local;
    int i, t;

    // Get minutes of today.
    local = localtime(TIME_TICK);
    t = local[2] * 60 + local[1];	   // hour * 60 + minutes

    // Find the day phase for now.
    for( i=0; i < sizeof(day_phase); i++)
        if( t >= day_phase[i]["length"] )
            t -= (int)day_phase[i]["length"];
        else
            break;

    current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);

    remove_call_out("init_day_phase");
    call_out("init_day_phase", 3600);

    // Since in our time scale, 1 minute == 1 second in RL, so we don't need
    // any conversion before using this number as call_out dalay, if you
    // changed the time scale, be sure to convert it.

    call_out("update_day_phase",
      (int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

void update_day_phase()
{
    int i;
    string color="";
    remove_call_out("update_day_phase");

    current_day_phase = (++current_day_phase) % sizeof(day_phase);

    for(i=0; i<sizeof(clr_msg); i++) if(day_phase[current_day_phase]["outcolor"]==clr_msg[i]){color=clr[i];break;}
    message("outdoor:vision", color + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());

    if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
        call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

    call_out("update_day_phase", day_phase[current_day_phase]["length"]);
}
void event_midnight()
{
    string get_month, get_day;
    get_day = CHINESE_D->chinese_monthday(TIME_TICK);
    get_month = CHINESE_D->chinese_month(TIME_TICK);
    switch(get_month)
    {
        //spring weather
        case "三":
        case "四":
        case "五":
            switch(random(3)){
                case 0: day_phase = read_table("/adm/etc/nature/spring_rain");break;
                case 1: day_phase = read_table("/adm/etc/nature/spring_sun");break;
                case 2: day_phase = read_table("/adm/etc/nature/spring_wind");break;
            }break;
        //summer weather
        case "六":
        case "七":
        case "八":
            switch(random(3)){
                case 0: day_phase = read_table("/adm/etc/nature/summer_rain");break;
                case 1: day_phase = read_table("/adm/etc/nature/summer_sun");break;
                case 2: day_phase = read_table("/adm/etc/nature/summer_wind");break;
            }break;
        //autumn weather
        case "九":
        case "十":
        case "十一":
            switch(random(3)){
                case 0: day_phase = read_table("/adm/etc/nature/autumn_rain");break;
                case 1: day_phase = read_table("/adm/etc/nature/autumn_sun");break;
                case 2: day_phase = read_table("/adm/etc/nature/autumn_wind");break;
            }break;
        //winter weather
        case "十二":
        case "一":
        case "二":
            switch(random(3)){
                case 0: day_phase = read_table("/adm/etc/nature/winter_rain");break;
                case 1: day_phase = read_table("/adm/etc/nature/winter_sun");break;
                case 2: day_phase = read_table("/adm/etc/nature/winter_wind");break;
            }break;
        default:day_phase = read_table("/adm/etc/nature/day_phase");
    }
    switch(get_day)
    {
        case "一月一日":
             day_phase = read_table("/adm/etc/nature/spring");
             break;
/*		case "五月五日":
        case "七月七日":
        case "八月十五日":
        case "九月九日":
        case "十二月八日":*/
    }
}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase

void event_noon()
{
    object *ob;
    int i, skill,con,con1,con2,con3;
    string get_month,msg;
    get_month = CHINESE_D->chinese_month(TIME_TICK);
    switch(get_month)
    {
        case "三":HIG+"三月的春风轻轻拂过你的额头，你觉得清凉多了。\n"+NOR;break;
        case "四":HIG+"一阵阵地花香草香扑鼻而来，到处充满了春天的气息。\n"+NOR;break;
        case "五":
             msg = HIG + "忽然喉头一阵痕痒，你感觉似乎要咳嗽了。\n" + NOR;
             break;
        case "六":HIG+"一阵暖风吹来，你觉得天气有些闷热了。\n"+NOR;break;
        case "七":HIG+"四周静悄悄的，不时只能听到几声蝉鸣。\n"+NOR;break;
        case "八":
             msg = HIG+"突然你胸臆之间一阵翻腾，你中暑了。\n" + NOR;
             break;
        case "九":HIG+"火辣辣的太阳照耀着大地，你不绝得有些头晕了。\n"+NOR;break;
        case "十":HIG+"天气渐渐变得有些凉了，秋风慢慢地吹了起来。\n"+NOR;break;
        case "十一":
             msg = HIG+"陡的你打了个冷战，头昏沉沉的，你得伤寒病了。\n"+NOR;
             break;
        case "十二":HIW+"一阵大风吹来，漫天的大雪扑面而来。\n"+NOR;break;
        case "一":HIG+"刺骨地寒风不停地吹着，四周变成一片冰封的世界。\n"+NOR;break;
        case "二":
             msg = HIG+"你肢体末端一阵僵直，看来你被冻伤了。\n"+NOR;
             break;
    }
    if(random(2))
    {
        msg = HIG+"你偶感风寒，竟而发起烧来。\n"+NOR;
    }
    ob = users();
    for(i=0; i<sizeof(ob); i++)
    {
        if( !environment(ob[i]) ) continue;
        if( !environment(ob[i])->query("outdoors") ) continue;
        if( ob[i]->query("age")==14 ) continue;
        con1 = ob[i]->query("kee");
        con2 = ob[i]->query("max_kee");
        (int)con = con1/con2*50;//形成第一个生病判断条件
        con3 = ob[i]->query("force");
        con2 = ob[i]->query("max_force");
        if( con2 == 0) con2 = 1;
        (int)con1 = con3/con2*50;//形成第二个生病判断条件
        if(random(con)+random(50)+random(con1)<25)
        {
            tell_object(ob[i], msg);
        }
    }
}

string outdoor_room_description()
{
    return "    " + day_phase[current_day_phase]["desc_msg"] + "。\n";
}
string outdoor_room_outcolor()
{
    return day_phase[current_day_phase]["outcolor"];
}

string game_time()
{
    return CHINESE_D->chinese_date(TIME_TICK);
}

mapping *read_table(string file)
{
    string *line, *field, *format;
    mapping *data;
    int i, rn, fn;

    line = explode(read_file(file), "\n");
    data = ({});
    for(i=0; i<sizeof(line); i++) {
        if( line[i]=="" || line[i][0]=='#' ) continue;
        if( !pointerp(field) ) {
            field = explode( line[i], ":" );
            continue;
        }
        if( !pointerp(format) ) {
            format = explode( line[i], ":" );
            continue;
        }
        break;
    }

    for( rn = 0, fn = 0; i<sizeof(line); i++) {
        if( line[i]=="" || line[i][0]=='#' ) continue;
        if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
        sscanf( line[i], format[fn], data[rn][field[fn]] );
        fn = (++fn) % sizeof(field);
        if( !fn ) ++rn;
    }
    return data;
}

mapping *query_day_phase() { return day_phase; }

#define TIME_TICK1 ((time())*60)

int is_night(object me,object env)
{
if(
    env->query("outdoors") &&
       !me->query("env/invisibility")&&
       ((strsrch(CHINESE_D->chinese_date(TIME_TICK1), "子时") >= 0) ||
       (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "丑时") >= 0) ||
       (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "亥时") >= 0)
      )
  )
    return 1;
else
    return 0;

}

int is_look_night(object me,object env)
{
if (me->query("age")>15		&&
    ((strsrch(CHINESE_D->chinese_date(TIME_TICK1), "子时") >= 0) ||
     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "丑时") >= 0) ||
     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "亥时") >= 0)
     ) 				   		&&
    env->query("outdoors")	&&
    //me->query_temp("light")<time()-MAX_LIGHT_TIME &&
    !present("fire",me)		&&
    !me->query("env/wiz_look")
    )
    return 1;
else
    return 0;

}
