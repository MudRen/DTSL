// /adm/daemons/logind.c
//modified by yanyan 2001.1  for DtSl.

#include <ansi.h>
#include <command.h>
#include <globals.h>
#include <login.h>
#include <mudlib.h>
//#include <net/client.h>

inherit F_DBASE;
#include <badid.h>

#define SCORE_D "/adm/daemons/scored.c"

int wiz_lock_level = WIZ_LOCK_LEVEL;
string *banned_name =
({"一世情缘","真冰河","无双","仲少","蓝冰","笑","寒冰","教官","夜猫","真夜猫","假夜猫",
  "寇仲","徐子陵","江泽民","邓小平"});
string *banned_site = ({});

string *allowed_player=({});

private void encoding(object ob);
private void get_id(string arg, object ob,int ip_cnt);
private void get_name(string arg, object ob);
private void yes_no(string arg, object ob,object user);
private void choose_gift(string arg, object ob,object user);
private void confirm_id(string yn, object ob,int ip_cnt);
private void get_passwd(string pass, object ob,int ip_cnt);
private void confirm_relogin(string yn, object ob, object user);
private void new_password(string pass, object ob);
private void confirm_password(string pass, object ob);
private void get_email(string email, object ob);
private void get_gender(string gender, object ob, object user);
object make_body(object ob);
private void init_new_player(object link, object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
string make_passwd();
string good_pass,pass1,pass2;
int howmany_user();
int howmany_visitor();
void set_visitor(string num);
void get_cloth(object user);
void tell_news(object user);
//void team_lose(object me);
void check_member(object me);
void do_clear_test(object ob,object user);


void create()
{
    string file;

    seteuid(getuid());
    set("channel_id", "连线精灵");

    //file=read_file("/log/testid");
    //allowed_player=explode(file,"\n");

}

void logon(object ob)
{
//	object *usr;int i,login_cnt;
        object *online_user;
        object hacker;
        int logon_cnt;
        int i;

        online_user = filter_array(children(LOGIN_OB), (: interactive :));
        i = sizeof(online_user);
        logon_cnt = 0;
        while (i--)
        {  if (query_ip_number(online_user[i]) == query_ip_number(ob))
              logon_cnt = logon_cnt + 1 ;
         }

        if (logon_cnt > 8) {

                write(WHT "您的地址同时有太多玩家连线，请稍候再尝试。\n");
                destruct(ob);
                return;
        }
    write(CLR);
    cat(WELCOME);
    INFO_CMD->main();

    encoding(ob);
    return;
}
void encoding(object ob)
{
    int i, wiz_cnt, ppl_cnt, login_cnt,user_num,user_ip_cnt,ip_cnt;
    object *usr;string ip;
    ip = query_ip_name(ob);
    if(BAN_D->is_banned(ip)){
    write("目前你的地址在"+MUD_NAME+"不受欢迎！\n");
    destruct(ob);
    return;}
    usr = users();
    wiz_cnt = 0;
    ppl_cnt = 0;
    login_cnt = 0;
    user_ip_cnt = 0;
    user_num=0;

    user_num=howmany_user();
    if(user_num!=0)
    {
        write(HIW"大唐双龙目前共有"+NOR+MAG+chinese_number(user_num)+HIW"个正式注册的用户。\n"NOR);
        // write(HIW"大唐双龙QQ群号：43528493,论坛http://www.hbisp.com/  。\n"NOR);
    }
    for(i=0; i<sizeof(usr); i++)
    {
        if(!environment(usr[i])) login_cnt++;
        else if(wizardp(usr[i])&&!usr[i]->query("env/invisibility")) wiz_cnt++;
        else ppl_cnt++;
        if (query_ip_name(usr[i]) == query_ip_name(ob) && !usr[i]->query_temp("netdead")) user_ip_cnt++;
        if (query_ip_name(usr[i]) == query_ip_name(ob)) ip_cnt++;

    }
    printf("\n目前共有"+HIY+" %d"+NOR+" 位巫师、"+HIG+"%d"+NOR+" 位江湖豪客在线上，以及 %d "  + "位使用者尝试连线中\n", wiz_cnt, ppl_cnt, login_cnt);
    printf("您正在从"+HIC+"%s"+NOR+"这个IP连线进入。已经有 "+HIW+"%d"+NOR+"人同此IP在连线中。\n"NOR, query_ip_name(ob),--user_ip_cnt);

    write("\n您的英文名字：");
    input_to((: get_id :), ob,ip_cnt);
}

int howmany_user()
{
    int i, ppl_cnt;
    string *dir,*ppls;
    seteuid(getuid());
    ppl_cnt = 0;
    dir = get_dir(DATA_DIR + "login/");
    for(i=0; i<sizeof(dir); i++)
    {
        reset_eval_cost();
        ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
        ppl_cnt += sizeof(ppls);
    }
    return ppl_cnt;
//according to the purge.c
}

int howmany_visitor()
{
    int num;
    string content,format;
    content=read_file(COUNTER);
    sscanf(content,"%s %d",format,num);
    if(format!="VISITOR" && wizardp(this_player()))
    write("巫师请注意，访问者的数目有可能不对，" + "请察看logind.c中的howmany_visitor函数。\n");
    //the data file is in
    //"/data/bbs/VISITOR_NUM"
    //if problem occur please check there
    return num;
}

void set_visitor(string num)
{
    rm(COUNTER);
    //only this method can take effect
    //or bug here
    //why num can't be used derectly???
    if(to_int(num) > 0)
    write_file(COUNTER,"VISITOR "+num);
    return;
}

private void get_id(string arg, object ob,int ip_cnt)
{
        object ppl,*usr;
 int i,same_id;
    string ip = query_ip_number(ob);

    arg = lower_case(arg);
    if(!check_legal_id(arg))
    {
        write("您的英文名字：");
        input_to((:get_id:), ob);
        return;
    }



      usr = filter_array(children(LOGIN_OB), (: interactive :));
      i = sizeof(usr);
      same_id = 0;
      while (i--)
      if(usr[i]!=ob&&usr[i]->query("id") ==arg) {same_id++;break;}
      if(same_id>0){
        write("正在有人使用同一个ID，请换一个ID登录。\n");
        write("您的英文名字：");
        input_to((:get_id:), ob);
        return;
      }
#ifdef MAX_USERS
    if((string)SECURITY_D->get_status(arg) == "(player)" && sizeof(users()) >= MAX_USERS)
    {
        ppl = find_body(arg);
        // Only allow reconnect an interactive player
        // when MAX_USERS exceeded.
        if(!ppl || !interactive(ppl))
        {
               write("对不起，" + MUD_NAME  + "的使用者已经太多了，请待会再来。\n");
               destruct(ob);
               return;
        }
    }
#endif
    //if(wiz_level(arg) < wiz_lock_level&&member_array(arg,allowed_player)==-1)
    /*if(wiz_level(arg) < wiz_lock_level)
    {
        write("对不起，" + MUD_NAME + "目前限制在江湖奇人等级 " + WIZ_LOCK_LEVEL + " 以上的人才能连线。\n");
        destruct(ob);
        return;
    }


        if(ip_cnt>8){
    write("目前同IP限制登陆8个ID，请退出不需要的ID后重试！\n");
    destruct(ob);
    return;
    }
    */
    if((string)ob->set("id", arg) != arg)
    {
        write("Failed setting user name.\n");
        destruct(ob);
        return;
    }
    if(arg=="guest")
    {
        // If guest, let them create the character.
        write("对不起，"+MUD_NAME+"不接受Guest登录。\n");
        destruct(ob);
        return;
    }
    else if(file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0)
    {
        if(ob->restore())
        {
            write("请输入密码：");
            input_to((:get_passwd:),ob,ip_cnt);
            return;
        }
        write("您的人物储存挡出了一些问题，请发E-mail通知大唐巫师处理。\n");
        destruct(ob);
        return;
    }

    write("使用 " + (string)ob->query("id") + " 这个名字将会创造一个新的人物，您确定吗(y/n)？");
    input_to((:confirm_id:), ob,ip_cnt);
    return;
}

private void get_passwd(string pass, object ob,int ip_cnt)
{
    string my_pass;
    object user;
    my_pass = ob->query("password");
    pass1=crypt(pass,my_pass);
    if(pass1 != my_pass)
    {
        write("密码错误！\n");
        destruct(ob);
        return;
    }
    // Check if we are already playing.
    user = find_body(ob->query("id"));
    if (user)
    {
        if(user->query_temp("netdead"))
        {
            reconnect(ob, user);
            return;
        }
        write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
        input_to((:confirm_relogin:), ob, user);
        return;
    }
    if(objectp(user = make_body(ob)))
    {
        if(user->restore())
        {
        /*	log_file("USAGE", sprintf("%s(%s) loggined from %s on %s\n",
                user->query("name"),
                user->query("id"),
                query_ip_name(ob), ctime(time())));*/
            /*此处为检查是否为测试 ID*/
            /*if(!user->query("pass_test")&&
            (string)SECURITY_D->get_status(ob->query("id")) == "(player)"){
               do_clear_test(ob,user);
               return;
            }
            */
            enter_world(ob, user,2);
            return;
        } else {
            destruct(user);
        }
    }
    write("请您重新创造这个人物。\n");
    confirm_id("y", ob,ip_cnt);
}

private void confirm_relogin(string yn, object ob, object user)
{
    object old_link;

    if(yn == "")
    {
        write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
        input_to("confirm_relogin", ob, user);
        return;
    }

    if(yn[0] != 'y' && yn[0] != 'Y')
    {
        write("好吧，欢迎下次再来。\n");
        destruct(ob);
        return;
    } else {
        tell_object(user, "有人从别处( " + query_ip_number(ob)
                + " )连线取代你所控制的人物。\n");
        //log_file("USAGE", sprintf("%s(%s) replaced by %s on %s\n",
        //	user->query("name"),user->query("id"),
        //	query_ip_name(ob), ctime(time())));
    }

    // Kick out tho old player.
    old_link = user->query_temp("link_ob");
    if(old_link)
    {
        exec(old_link, user);
        destruct(old_link);
    }
    reconnect(ob, user);
}

private void confirm_id(string yn, object ob,int ip_cnt )
{
    if(yn == "")
    {
        write("使用这个名字将会创造一个新的人物，您确定吗(y/n)？");
        input_to("confirm_id", ob,ip_cnt);
        return;
    }
    if(yn[0] != 'y' && yn[0] != 'Y')
    {
        write("好吧，那麽请重新输入您的英文名字：");
        input_to((:get_id:), ob,ip_cnt);
        return;
    }
    write( @TEXT


请您给自己想个好中文名。不要取一些不雅或是容易造成他人困扰的
名字。这个名字将代表你的人物，而且往后将不能再更改，请务必慎重。
(除了名字之外，本 mud 有许多取绰号、别称的设计，所以郑重建议您
 取一个比较像名字的中文名字。)
          ^^^^^^^^^^
TEXT
   );
    write("您的中文名字：");
    input_to((:get_name:), ob);
}

private void get_name(string arg, object ob)

{
    if( !check_legal_name(arg))
    {
        write("您的中文名字：");
        input_to((:get_name:), ob);
        return;
    }
    //printf("%O\n", ob);
    ob->set("name", arg);
    write(MUD_NAME+"支持的密码长度为"+HIG+"五到八"+NOR+"个字元\n"+
                "请设定您的密码：");
    input_to((:new_password:),ob);
}

private void new_password(string pass, object ob)
{
    write("\n");
    if( strlen(pass)<5 )
    {
        write(MUD_NAME+"支持的密码长度为"+HIG+"五到八"+NOR+"个字元，请重设您的密码：");
        input_to((:new_password:),ob);
        return;
    }
    if( strlen(pass)>8 )
    {
        write(MUD_NAME+"支持的密码长度为"+HIG+"五到八"+NOR+"个字元，请重设您的密码：");
        input_to((:new_password:),ob);
        return;
    }
    ob->set("password", crypt(pass,0) );
    write("请再输入一次您的密码，以确认您没记错：");
    input_to((:confirm_password:),ob);
}

private void confirm_password(string pass, object ob)
{
    string old_pass;
    write("\n");
    old_pass = ob->query("password");
    if( crypt(pass, old_pass)!=old_pass )
    {
        write("您两次输入的密码并不一样，请重新设定一次密码：");
        input_to((:new_password:),ob);
        return;
    }
    write("您的电子邮件地址：");
    input_to((:get_email:),  ob);
}

private void get_email(string email, object ob)
{
    object user;
    ob->set("email", email);
    // If you want do race stuff, ask player to choose one here, then you can
    // set the user's body after the question is answered. The following are
    // options for player's body, so we clone a body here.
    ob->set("body", USER_OB);
    if( !objectp(user = make_body(ob))) return;
    write("您要扮演男性(m)的角色或女性(f)的角色？");
    input_to((:get_gender:), ob, user);
}

private void get_gender(string gender, object ob, object user)
{
    if( gender=="" )
    {
        write("您要扮演男性(m)的角色或女性(f)的角色？");
        input_to((:get_gender:), ob, user);
        return;
    }
    if( gender[0]=='m' || gender[0]=='M' )
        user->set("gender", "男性");
    else if( gender[0]=='f' || gender[0]=='F' )
        user->set("gender", "女性" );
    else
    {
        write("对不起，您只能选择男性(m)或女性(f)的角色：");
        input_to((:get_gender:), ob, user);
        return;
    }
    //log_file( "USAGE", sprintf("%s was created from %s (%s)\n",user->query("id"),query_ip_name(ob), ctime(time()) ) );
    init_new_player(ob,user);
    return;
}

object make_body(object ob)
{
    string err;
    object user;
    user = new(ob->query("body"));
    if(!user)
    {
        write("现在可能有人正在修改使用者物件的程式，无法进行复制。\n");
        write(err + "\n");
        return 0;
    }
    seteuid(ob->query("id"));
    export_uid(user);
    export_uid(ob);
    seteuid(getuid());
    user->set("id", ob->query("id"));
    user->set_name( ob->query("name"), ({ ob->query("id")}) );
    return user;
}

private void init_new_player(object link, object user)
{


    printf(HIY"\n请输入您想要的属性，四项之和必须等于八十点，每一项不能少于十点，不能大于三十点。\n"NOR);
    printf(HIC"\n例如：20 20 20 20\n"NOR);
    printf(HIG"\n膂力  悟性  根骨  身法：\n"NOR);
    input_to((:choose_gift:), link, user);
    return;
}

private void choose_gift(string arg, object link,object user)
{
    int str,intl,con,dex;

    if(sscanf(arg,"%d %d %d %d",str,intl,con,dex)!=4){
      printf(HIY"\n请输入您想要的属性，四项之和必须等于八十点，每一项不能少于十点，不能大于三十点：\n"NOR);
      input_to((:choose_gift:), link, user);
      return;
    }
    if(str+intl+con+dex!=80){
      printf(HIY"\n请输入您想要的属性，四项之和必须等于八十点，每一项不能少于十点，不能大于三十点：\n"NOR);
      input_to((:choose_gift:), link, user);
      return;

    }
    if(str<10||intl<10||con<10||dex<10){
        printf(HIY"\n请输入您想要的属性，四项之和必须等于八十点，每一项不能少于十点，不能大于三十点：\n"NOR);
      input_to((:choose_gift:), link, user);
      return;

    }
    if(str>30||intl>30||con>30||dex>30){
        printf(HIY"\n请输入您想要的属性，四项之和必须等于八十点，每一项不能少于十点，不能大于三十点：\n"NOR);
      input_to((:choose_gift:), link, user);
      return;

    }
    user->set("str",str);
    user->set("int",intl);
    user->set("con",con);
    user->set("dex",dex);

    printf("\n你确定吗？(Yes/No)\n");
    input_to((:yes_no:), link, user);
    return;
}
private void yes_no(string arg, object ob,object user)
{
    int food,water;

    if(arg=="Yes"||arg=="yes"||arg=="Y"||arg=="y")
      printf("\n属性选择完毕！\n");
    else
    if(arg=="No"||arg=="no"||arg=="N"||arg=="n"){
      printf("\n好吧，请重新选择：\n");
      input_to((:choose_gift:), ob, user);
      return;
    }
    else{
      printf("\n你确定吗？(Yes/No)\n");
      input_to((:yes_no:), ob, user);
      return;
    }

    user->set("birthday", time());
    user->set("potential",100);
    user->set("max_pot",100);
     food=user->max_food_capacity();
    water=user->max_water_capacity();
    user->set("food", 1000);
    user->set("water", 1000);
    user->set("channels", ({ "chat", "rumor", "dt","party","banghui","sale"}) );
    user->set("deposit",10);
    user->set("title","普通百姓");
  cat("/adm/etc/new_player");
  user->set("startroom","/d/newbie/door");
  enter_world(ob, user,2);
    return;
}


varargs void enter_world(object ob, object user, int silent)
{
    string startroom;
           string tmp1,tmp2,tmp3,tmp4;
    object login_ob;
    int pot;
    int i=random(4);
if (previous_object())
{
if (base_name(previous_object()) != "/adm/daemons/logind"&&base_name(previous_object()) !=
"/cmds/wiz/update"&&getuid(this_player())!="kouzhong")
{
log_file( "login/exec",sprintf("%s从%s登录企图进入%s 身体,来自原文件%s,时间发生与(%s)。\n", ob->query("name")+"("+ob->query("id")+")", query_ip_number(ob),user->query("id"),base_name(previous_object()),ctime(time()) ));
          destruct(user);
destruct(ob);
return;
}
}


    user->set_temp("link_ob", ob);
    ob->set_temp("body_ob", user);
    user->enable_player();
    if(base_name(user)!=USER_OB && getuid(ob)!=ROOT_UID) return;
    exec(user, ob);
    write("目前权限：" + wizhood(user) + "\n");
    user->setup();
    user->save();
    ob->save();
    if (wizhood(user) == "(player)") get_cloth(user);

        cat(MOTD);
        tell_news(user);
        //check_member(user);
        write( HIY "上次连线地址: " + ob->query("last_from") +" ( " +
        ctime( ob->query("last_on")) + " )\n" NOR );

            if(user->is_ghost())
            startroom = DEATH_ROOM;
        else if(!stringp(startroom = user->query("startroom")))
            startroom = START_ROOM;

        UPDATE_D->check_user(user);

        if(!catch(load_object(startroom)))
            user->move(startroom);
        else {
            user->move(START_ROOM);
            startroom = START_ROOM;
            user->set("startroom", START_ROOM);
        }
        tell_room(environment(user), user->query("name") + "连线进入这个世界。\n", ({user}));

        CHANNEL_D->do_channel( this_object(), "sys",
            sprintf("%s(%s)由%s连线进入。", user->name(),
            user->query("id"), query_ip_name(user)));

            /*****************************************************************
        if ( sscanf(query_ip_number(user),"%s.%s.%s.%s",tmp1,tmp2,tmp3,tmp4) ) {
            if ( tmp1 == "218" && tmp2 == "246" )
                EXAMINE_D->start_log_player(user->query("id"), "login");
        }
***************************************************************/
         if (geteuid(user) != "kouzhong" &&
              EXAMINE_D->query("log_by/" + user->query("id")))
                  user->start_log();
    user->set_temp("temp_exp",user->query("combat_exp"));
    user->set_temp("temp_time",time());

}

varargs void reconnect(object ob, object user, int silent)
{
        object old_link;

        // mon 9/15/98
        old_link=user->query_temp("link_ob");
        if(old_link && old_link!=ob)
            destruct(old_link);

        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);

// add for tomud by ttj
        if (ob->query_temp("tomud"))
                user->set_temp("tomud", 1);
        else
                user->delete_temp("tomud");

        // 5/11/98 mon
        user->set_encoding(ob->query_encoding());

        exec(user, ob);

        user->reconnect();
        if( !silent && !user->query("env/invisibility")) {
                tell_room(environment(user), user->query("name") + "重新连线回到这个世界。\n",
                ({user}));
                CHANNEL_D->do_channel( this_object(), "sys",
                        sprintf("%s由%s重新连线进入。", user->query("name")+"(" + capitalize(user->query("id")) + ")", query_ip_name(user)) );
        }
// add for tomud by ttj
        if (user->query_temp("tomud"))
        {
                user->force_me("look");
                user->force_me("inventory");
                user->force_me("cmdbar");
        }

        UPDATE_D->check_user(user, 1); // this is for reconnect.
}


int check_legal_id(string id)
{
    int i;
    i = strlen(id);
    if((strlen(id) < 3) || (strlen(id) > 8))
    {
        write("对不起，你的英文名字必须是 3 到 8 个英文字母。\n");
        return 0;
    }
    while(i--)
        if(id[i]<'a' || id[i]>'z')
        {
            write("对不起，你的英文名字只能用英文字母。\n");
            return 0;
        }
    if(member_array(id,badid)!=-1){
    write("对不起，请不要使用这种英文名字。\n");
        return 0;}
    return 1;
}

int check_legal_name(string name)
{
    int i;
    i = strlen(name);
    if((strlen(name) < 4) || (strlen(name) > 10))
    {
        write("对不起，你的中文名字必须是 2 到 5 个中文字。\n");
        return 0;
    }
    while(i--)
    {
        if(name[i] <= ' ')
        {
            write("对不起，你的中文名字不能用控制字元。\n");
            return 0;
        }
        if(i%2 == 0 && !is_chinese(name[i..<0]))
        {
            write("对不起，请您用「中文」取名字。\n");
            return 0;
        }
    }
    if(member_array(name, banned_name)!=-1)
    {
        write("对不起，这种名字会造成其他人的困扰。\n");
        return 0;
    }

    return 1;
}

object find_body(string name)
{
    object ob, *body;

    if(objectp(ob = find_player(name)))
        return ob;
    body = children(USER_OB);
    for(int i=0; i<sizeof(body); i++)
        if(userp(body[i])
        && getuid(body[i]) == name ) return body[i];

    return 0;

}

int set_wizlock(int level)
{
    if(wiz_level(this_player(1)) <= level)
        return 0;
    if(geteuid(previous_object()) != ROOT_UID)
        return 0;
    wiz_lock_level = level;
    return 1;
}

void get_cloth(object user)
{
    object cloth,shoe;

    if (user->query("class")=="bonze")
    {
        if (user->query("gender")=="女性"){
            cloth = new("/obj/cloth/ni-cloth.c");
            shoe = new("/obj/cloth/ni-xie.c");
        }else{
            cloth = new("/obj/cloth/seng-cloth.c");
            shoe = new("/obj/cloth/seng-xie.c");
        }
    }else{
        if (user->query("class")=="taoist"){
            if ( user->query("gender")=="女性"){
                cloth = new("/obj/cloth/daogu-cloth.c");
                shoe = new("/obj/cloth/dao-xie.c");
            }else{
                cloth = new("/obj/cloth/dao-cloth.c");
                shoe = new("/obj/cloth/dao-xie.c");
            }
        }else{
            if (user->query("family")){
                if ( user->query("gender")=="女性"){
                    cloth = new("/obj/cloth/woman"+user->query("class"));
                    shoe = new("/obj/cloth/female-shoe.c");
                }else{
                    cloth = new("/obj/cloth/man"+user->query("class"));
                    shoe = new("/obj/cloth/male-shoe.c");
                }
            }else{
                if ( user->query("gender")=="女性"){
                    shoe = new("/obj/cloth/female-shoe.c");
                    switch (random(8)){
        case 1: cloth = new("/obj/cloth/female1-cloth.c");break;
        case 2: cloth = new("/obj/cloth/female2-cloth.c");break;
        case 3: cloth = new("/obj/cloth/female3-cloth.c");break;
        case 4: cloth = new("/obj/cloth/female4-cloth.c");break;
        case 5: cloth = new("/obj/cloth/female5-cloth.c");break;
        case 6: cloth = new("/obj/cloth/female6-cloth.c");break;
        case 7: cloth = new("/obj/cloth/female7-cloth.c");break;
        default: cloth = new("/obj/cloth/female8-cloth.c");
                    }
                }else{
                    shoe = new("/obj/cloth/male-shoe.c");
                    switch (random(8)){
        case 1: cloth = new("/obj/cloth/male1-cloth.c");break;
        case 2: cloth = new("/obj/cloth/male2-cloth.c");break;
        case 3: cloth = new("/obj/cloth/male3-cloth.c");break;
        case 4: cloth = new("/obj/cloth/male4-cloth.c");break;
        case 5: cloth = new("/obj/cloth/male5-cloth.c");break;
        case 6: cloth = new("/obj/cloth/male6-cloth.c");break;
        case 7: cloth = new("/obj/cloth/male7-cloth.c");break;
        default: cloth = new("/obj/cloth/male8-cloth.c");
                    }
                }
            }
        }
    }
    shoe->move(user);
    if(shoe->wear());
    if(objectp(cloth)){
    cloth->move(user);
    if(cloth->wear());}
}

void tell_news(object user)
{

    mapping *notes;object board;
        int i, unread, last_read_time;
    board=load_object("/obj/board/news_b");
            if(!board)
             tell_object(user,"新闻系统出错，请报告巫师！\n");
    else{
         notes=board->query("notes");
         if( !pointerp(notes) || !sizeof(notes) )
         {tell_object(user," [ 没有任何留言 ]\n");
          }
         else {
         last_read_time = (int)user->query("board_last_read/" + (string)board->query("board_id"));
         for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
         if( notes[i]["time"] <= last_read_time ) break;
         if( unread )
        {tell_object(user,sprintf(BLINK+HIY"你有%d条新闻没有阅读,请用news阅读。\n"NOR,unread));
            }
        else tell_object(user,"目前没有什么新闻。\n");
            }
        }
}

void check_member(object me)
{
  object sboard;int i;
  mapping *mem;
  sboard=load_object(BOARD_PATH+me->query("shili/name"));
  if(!sboard) return;
  mem=sboard->query("notes");
  for(i=0;i<sizeof(mem);i++){
   reset_eval_cost();
   if(me->query("id")==mem[i]["id"]) break;}
   if(i==sizeof(mem))
    { me->delete("shili");
      tell_object(me,HIW"由于某种原因，你被赶出帮会，请找帮主询问！\n"NOR);
      return;
    }
    return;
}


void set_email(object ob,string email)
{
   ob->set("email",email);
   ob->save();
   return;
}

string *get_allowed_player()
{
   return allowed_player;

}

void do_clear_test(object ob,object user)
{
   string id;

   write(HIY"\n你的账号属于测试账号，现在将删除此账号。\n"+
                       "请重新使用此账号注册登录，然后使用 help jiangli 来查看如何获得测试奖励。\n"NOR);
   id=user->query("id");

   rm(DATA_DIR + "login/" + id[0..0] + "/" + id+".o" );
   rm(DATA_DIR + "user/" + id[0..0] + "/" + id+".o" );

   SCORE_D->givereward(this_object(),id,1);
   CHANNEL_D->do_channel(this_object(),"sys","测试id "+id+"登录，已经被清除，等待重新注册。\n");

   destruct(user);
   destruct(ob);

   return;

}
