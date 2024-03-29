// zhujianlu.c
// by augx@sj 9/6/2001

#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIR"火炉"NOR, ({ "huo lu" , "lu" }));
    set_weight(1000000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "座");
        set("long",
HIR"这是一座日夜炉火通明的火炉，和普通打铁铺的火炉并不相同。
此炉以特殊材料制成，能耐无法想像的高温，是专门用来锻造兵器的！\n\n"NOR+
"你可以用这个火炉来：

锻造(duanzao)：duanzao 兵器种类 原料
（现在可以锻造的兵器有：sword，xiao，axe，blade，brush，club，
  dagger，fork，hammer，hook，spear，staff，stick，whip）

修理(xiu):     xiu 兵器id

改名(gaiming): gaiming 新名字 兵器id
注意：
    1.不要加上种类名字如『剑』『刀』之类，系统会自动加上！
    2.武器ID会变成你的 ID + 武器 ID。
    3.你可以使用 $颜色$ 字串加上颜色，颜色说明见help color。
    4.名字的最后不需要加 $NOR$ 字串，系统会自动添加。
    5.请勿使用不雅观的名字命名，否则巫师有权利收回你的兵器。
    6.请使用中文命名，否则巫师有权利收回你的兵器。
");

        set("value", 3000);
        set("no_get", 1);
    }
    setup();
}

void init()
{
    add_action("do_duanzao","duanzao");
    add_action("do_xiu","xiu");
    add_action("do_xiu","fix");
    add_action("do_rename","gaiming");
    add_action("do_rename","rename");

    add_action("do_recover","restore");
}

int do_duanzao(string arg)
{
    object me = this_player() ,obj,obj2,weapon;
    int delay,level,i,j,k,time;
    string type,kuangcai;

    if (me->is_busy()) return notify_fail("你正忙着呢！\n");
    if (me->is_fight()) return notify_fail("你正忙着呢！\n");
    if (!arg) return notify_fail("你要锻造什么？\n");
    if ( sscanf(arg,"%s %s",type,kuangcai)<2 )
        return notify_fail("你要用什么锻造什么？\n");
    if ( !objectp(obj = present(kuangcai, me)) )
        return notify_fail("你身上没有这样东西。\n");
    obj = present(obj->query("id"), me);
    if ( !objectp(obj2= present(obj->query("id")+" 2", me)) )
        return notify_fail("你必须用两块"+obj->query("name")+"来锻造兵器。\n");
    if( !(int)obj->query("kuangcai") || !(int)obj->query("level") )
        return notify_fail("在这里只能用从矿石中提炼出来的材料锻造兵器。\n");
    if ( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="tiechui" )
        return notify_fail("你必须装备铁锤才能来锻造。\n");
    if ( !weapon->query("worker_tool"))
        return notify_fail("你必须装备铁锤才能来锻造。\n");
    if ( !wizardp(me) && (time()<(int)me->query("worker/duanzao")) )
        return notify_fail("你刚刚锻造过兵器，感觉过于劳累！\n");

    time = time()- me->query("pk_time");
    if ( time < 432000)
        return notify_fail("你目前的状态无法锻造。\n");

    level = (int)me->query_skill("duanzao",1);
    if ( level<1 )
        return notify_fail("你根本就不会打造兵器！\n");

    switch(type){
        case "sword":
        case "axe":
        case "blade":
        case "brush":
        case "club":
        case "dagger":
        case "fork":
        case "hammer":
        case "hook":
        case "spear":
        case "staff":
        case "stick":
        case "xiao":
        case "whip": break;
        default:
            return notify_fail("这里不能锻造这种武器。\n");
    }

    switch( (int)obj->query_level() ) {
        case 1: break;
        case 2: if(level<40)  return notify_fail("你的锻造技能不够！\n"); break;
        case 3: if(level<80)  return notify_fail("你的锻造技能不够！\n"); break;
        case 4: if(level<120) return notify_fail("你的锻造技能不够！\n"); break;
        case 5: if(level<170) return notify_fail("你的锻造技能不够！\n"); break;
        case 6: if(level<220) return notify_fail("你的锻造技能不够！\n"); break;
        case 7: if(level<270) return notify_fail("你的锻造技能不够！\n"); break;
        case 8: if(level<330) return notify_fail("你的锻造技能不够！\n"); break;
        case 9: if(level<390) return notify_fail("你的锻造技能不够！\n"); break;
    }

    message_vision(HIY"$N开始从各个角度锤击"+obj->query("name")+HIY"，一点点把原始的材料变成无双的兵器......\n"NOR, me);

    if(level>390) level = 390 + (level-390)*11;
    switch((int)obj->query_level()) {
        case 1: i = 40;  if(level>100) level=100;j=0; break;
        case 2: i = 80;  if(level>150) level=150;j=0; break;
        case 3: i = 120; if(level>200) level=200;j=1; break;
        case 4: i = 170; if(level>300) level=300;j=1; break;
        case 5: i = 800; if(level>350) level=350;j=2; break;
        case 6: i = 999; if(level>450) level=450;j=2; break;
        case 7: i = 2000;if(level>500) level=500;j=3; break;
        case 8: i = 3000;if(level>500) level=500;j=3; break;
        case 9: i = 9999;if(level>500) level=500;j=4; break;
    }
    if(wizardp(me) && me->query("env/test") && i>500) i=500;

    delay = 10 + random(20);
    k = random(level+i);
    if( k>=((level+i)/2-level/2) && k<=((level+i)/2+level/2) ) {
        if(wizardp(me) && (int)me->query("env/test")) delay = 6;
        if (j>=3) {
            WORKER_D->update_UniqueValues("weapon","","");
            delay = 60;
            if(wizardp(me) && (int)me->query("env/test")) delay = 10;
        }
        call_out("duanzao_makeweapon",delay,me,type,j,obj,delay);
    }
    else {
        if(wizardp(me) && (int)me->query("env/test")) delay = 3;
        call_out("duanzao_finish",delay*2-1,me,obj,0);
    }

    me->start_busy(delay+1);
    destruct(obj2);
    return 1;
}

void duanzao_makeweapon(object me,string type,int qua,object obj,int delay)
{
    object wp,shi;
    string str,st;

    if(!objectp(me) || !userp(me) || !objectp(obj)) return;
/*
        if( qua>=3 && WORKER_D->query_UniqueValues("weapon","") <0 ) {
                tell_object(me , "网络错误：无法连接同步服务器，你将无法打造高等级兵刃！\n");
                qua = 2;
                delay = 10;
        }
        if( qua==4 && WORKER_D->query_UniqueValues("weapon",me->query("id")) <1 ) {
                tell_object(me , "一级兵刃已经达到限制数，无法打造！\n");
                qua = 2;
                delay = 10;
        }
        if( qua==3 && WORKER_D->query_UniqueValues("weapon2",me->query("id"))<1 ) {
                tell_object(me , "二级兵刃已经达到限制数，无法打造！\n");
                qua = 2;
                delay = 10;
        }
  */
    wp = WORKER_D->make_weapon(me,type,qua,obj->query("material"));
    //wp->set("value" , (obj->query("value")*4)/100 * (wp->query("value")/30)/100 );
    wp->set("value" , obj->query("value") * (25+random(40)) / 10 );
    wp->set("weapon_mp/value" , wp->query("value"));
    if(!wp) {
        tell_object(me, "武器生成出错! \n");
        return;
    }
    if( !environment(this_object()) || !(shi=present("zhujian shi",environment(this_object()))) ) {
        tell_object(me, "无法找到铸剑师! \n");
        return;
    }
    if(!wp->move(shi)) {
        tell_object(me, "武器移动错误! \n");
        return;
    }
    me->set_temp("worker/wp" , wp);

    if( qua>=3 ) {
        if ( stringp(wp->query("name_st")) && strlen(wp->query("name_st"))>3 )
            st = wp->query("name_st");
        else
            st = "";
        str = sprintf("save_id=%s&time=%d&level=%d&wscore=%d&wuser=%s&wname=%s&details=%s",wp->query("weapon_mp/save_id"),time(),qua+1,
            WORKER_D->weapon_rank(wp),wp->query("maker"),wp->query("name")+"("+wp->query("id")+")",st);
        WORKER_D->update_UniqueValues("addweapon",str,wp->query("weapon_mp/save_id"));
    }
    call_out("duanzao_finish",delay,me,obj,1);
}

void duanzao_finish(object me,object obj,int win)
{
    object tools,wp;
    string str;
    int level, kuangshi, i=1, improve;

    if(!objectp(me) || !userp(me) || !objectp(obj)) return;
    me->start_busy(-1);
    me->interrupt_me();
    tools = me->query_temp("weapon");
    level = (int)me->query_skill("duanzao",1);
    if(level>390) level = 390 + (level-390)*11;
    kuangshi = (int)obj->query_level();

    message_vision(HIY"$N把已经锤击过无数次的兵器放入冷水之中......\n"NOR, me);
    if ( objectp(tools) && tools->query("id")=="tiechui" ) tools->use();

    switch(kuangshi) {
        case 1: i = 40;  break;
        case 2: i = 80;  break;
        case 3: i = 120; break;
        case 4: i = 170; break;
        case 5: i = 220; break;
        case 6: i = 270; break;
        case 7: i = 330; break;
        case 8: i = 390; break;
        case 9: i = 500; break;
    }
    i = 100 - (level - i)/2;
    if(i>200) i = 200;
    if(i< 10) i = 10;

    if ( me->query_temp("user_type") != "worker")
        improve = me->query_int(1)*i/100;
    else
        improve = me->query_int()*i/100;

    if( win ) {
        me->improve_skill("duanzao", improve*9);
        if ( environment(me)->query("no_zhiye")
         || me->query_temp("user_type") == "worker") {
            me->add("combat_exp", random(improve*4/5));
            me->add("potential", random(improve/5*3));
        }
        wp = (object)me->query_temp("worker/wp");
        if(!wp) return;
        me->delete_temp("worker/wp");
        if( wp->query("weapon_mp/imbued")>3 && WORKER_D->query_UniqueValues("addweapon",wp->query("weapon_mp/save_id"))<0 ) {
            tell_object(me , "网络错误：无法连接同步服务器，武器生成失败！\n");
            destruct(wp);
            return;
        }
        if(!wp->move(me)) {
            wp->move(environment(me));
            tell_object(me , "但是你拿不动了！\n");
        }

        message_vision(HIC"$N从水缸中取出一"+wp->query("unit")+wp->name()+"。\n"NOR, me);
    }
    else {
        me->improve_skill("duanzao", improve*3);
        if ( environment(me)->query("no_zhiye")
         || me->query_temp("user_type") == "worker") {
            me->add("combat_exp", random(improve/3));
            me->add("potential", random(improve/5));
        }
        message_vision(HIC"但是$N锻造的兵器一放到冷水里，就四分五裂了！\n"NOR, me);
    }
    destruct(obj);
    if ( (int)me->query("potential", 1) > (int)me->query("max_pot", 1) )
        me->set("potential" , me->query("max_pot", 1) );
    me->set("worker/duanzao",time()+10+random(20));

    str = WORKER_D->worker_title(me,"duanzao");
    // 工匠title
    me->set_temp("title", str);
}

int do_xiu(string arg)
{
    object me = this_player() ,obj,obj2,weapon;
    int delay,level;
    string str;

    if (me->is_busy()) return notify_fail("你正忙着呢！\n");
    if (me->is_fight()) return notify_fail("你正忙着呢！\n");
    if (!arg) return notify_fail("你要修什么？\n");
    if ( !objectp(obj = present(arg, me)) )
        return notify_fail("你身上没有这样东西。\n");
    if ( !mapp(obj->query("weapon_prop")) || !(int)obj->query("imbued") )
        return notify_fail("在这里只能维修由玩家制造的兵器。\n");
    if ( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="tiechui" )
        return notify_fail("你必须装备铁锤才能来维修兵器。\n");
    if ( obj->query("weapon_mp/dur") >= obj->query("weapon_mp/max_dur") )
        return notify_fail("这件兵器完好无损，无需修理。\n");
    if ( obj->query("weapon_mp/dur") <= 0  )
        return notify_fail("这件兵器已经彻底损坏了，无法修理。\n");

    switch( (string)obj->query("material") ){
        case "xuantie":	  str = WHT"玄铁"NOR; break;
        case "shentie":   str = RED"万年神铁"NOR; break;
        case "jintie":    str = HIY"金铁"NOR; break;
        case "ruanying":  str = HIW"软银"NOR; break;
        case "liuhuashi": str = RED"流花石"NOR; break;
        case "lushi":     str = HIG"绿石"NOR; break;
        case "ruantie":   str = YEL"软铁"NOR; break;
        case "shengtie":  str = YEL"生铁"NOR; break;
        case "qingtong":  str = GRN"青铜"NOR; break;
        default: str =	"精钢";	break;
    }
    if ( !objectp(obj2 = present((string)obj->query("material"), me)) )
        return notify_fail("你需要一块"+str+"，才能维修这件兵器。\n");

    level = (int)me->query_skill("duanzao",1);
    switch( (int)obj2->query_level() ) {
        case 1: if(level<10)  return notify_fail("你的锻造技能不够！\n"); break;
        case 2: if(level<40)  return notify_fail("你的锻造技能不够！\n"); break;
        case 3: if(level<80)  return notify_fail("你的锻造技能不够！\n"); break;
        case 4: if(level<120) return notify_fail("你的锻造技能不够！\n"); break;
        case 5: if(level<170) return notify_fail("你的锻造技能不够！\n"); break;
        case 6: if(level<220) return notify_fail("你的锻造技能不够！\n"); break;
        case 7: if(level<270) return notify_fail("你的锻造技能不够！\n"); break;
        case 8: if(level<330) return notify_fail("你的锻造技能不够！\n"); break;
        case 9: if(level<390) return notify_fail("你的锻造技能不够！\n"); break;
    }

    message_vision(HIY"$N开始仔细的维修"+obj->query("name")+HIY"，不时用铁锤敲敲打打......\n\n"NOR, me);
    delay = 15 + random(30);
    if(wizardp(me) && (int)me->query("env/test")) delay = 3;
    me->start_busy(delay);
    destruct(obj2);
    call_out("xiu_finish",delay*2-1,me,obj);
    return 1;
}

int decvar(object ob,string type,int times,int decmin,int min)
{
    int i,j;

    if( times <= 0 ) return 0;
    i = (int)ob->query(type) * 100;
    if( i == 0 ) return 0;
    decmin *= 100;
    min *= 100;

    j = i / times;
    if( j < decmin ) j = decmin;
    i = i - j;
    if( i < min ) i = min;

    ob->set(type,i/100);
    return i/100;
}

void xiu_finish(object me,object obj)
{
    object tools;
    int i;

    if(!objectp(me) || !userp(me) || !objectp(obj) ) return;

    message_vision(HIY"$N仔细的维修"+obj->query("name")+HIY+"，总算大致恢复了它的原貌。\n"NOR, me);
    me->improve_skill("duanzao", me->query_int()/2);

    i = decvar(obj,"weapon_mp/max_dur",9,10,100);
    obj->set("dur",i);
    obj->set("weapon_mp/dur",i);
    obj->set("weapon_mp/max_dur",i);

    decvar(obj,"weapon_prop/damage",5+random(7),10,10);
    decvar(obj,"weapon_prop/qi",5+random(7),50,10);
    decvar(obj,"weapon_prop/jing",5+random(7),50,10);
    decvar(obj,"weapon_prop/jingli",5+random(7),50,10);
    decvar(obj,"weapon_prop/neili",5+random(7),50,10);
    decvar(obj,"weapon_prop/attack",5+random(8),3,1);
    decvar(obj,"weapon_prop/dodge",5+random(8),3,1);
    decvar(obj,"weapon_prop/parry",5+random(8),3,1);

    i = decvar(obj,"weapon_mp/rigidity",5,1,1);
    obj->set("rigidity",i);
    i = decvar(obj,"weapon_mp/sharpness",5,1,1);
    obj->set("sharpness",i);
    i = decvar(obj,"weapon_mp/value",6,10,1);
    obj->set("value",i);

    obj->save_weapon(me);

    tools = me->query_temp("weapon");
    if ( objectp(tools) && tools->query("id")=="tiechui" ) tools->use();
}

nosave string *banned_name = ({
// Mud 保留名字
"杀手","闪电","雪人","我们","天神","总管","龙神","仙人","巫师","玩家","书剑","杀人犯","祈雨","迎风",
// Mud 地名，门派名
"少林","丐帮","明教","密宗","慕容","古墓","全真","铁掌","大理","白驼","桃花","星宿",
"天龙寺","大轮寺","五毒教","正义","邪恶","五岳剑派","日月神教","官府","武林",
"少林寺","武当派","铁掌帮","普通百姓","峨嵋派","姑苏慕容","古墓派","华山派","嵩山派",
"明教","神龙教","星宿派",
// 重要人物名字
"金庸","邓小平","江泽民","毛泽东","朱榕基","皇帝","总理", "主席",
// 小说人物
"张三丰","张无忌","郭靖","杨过","令狐冲","胡斐","苗人凤","韦小宝","袁承志","胡一刀",
"陈家洛","段誉","萧锋","乔锋","虚竹","东方不败","欧阳锋","洪七公","黄药师","段皇爷",
"一灯大师","王重阳","周伯通","黄蓉","风清扬","独孤求败",
// 脏话
"统一","法轮","法轮研究","法轮大","吃人","他妈的","去你的","操你妈","干你娘","废物",
"混蛋","坏蛋","杀人","抢劫","强奸","妓女","台独","领导","中央","屁眼","屁股","裸体",
"放屁","鸡巴","阴道","婊子","你丫","日你","赤佬","瘪三","傻逼","蠢蛋","操他","我操",
"太监","宦官","阉割","阉人","鸡", "奸淫", "淫荡", "轮奸", "奸", "三级", "政治",
});

nosave string *banned_name2 = ({
// 兵器名
"打狗棒",
"哭丧棒",
"狼牙棒",
"玉竹棒",

"青焰刀",
"屠龙刀",
"血刀",
"鸯刀","鸳刀","鸳鸯刀",
"紫金刀",

"黄金棍",

"白虹剑","碧玉剑","碧水剑","碧血剑",
"东灵铁剑",
"观日剑",
"冷月宝刀","绿波香露刀",
"金蛇剑","君子剑",
"青冥剑",
"辟邪剑",
"书剑","淑女剑",
"无名宝剑",
"玄铁剑",
"倚天剑","游龙剑",
"真武剑","周公剑",

"碧玉箫",
"洞箫",
"紫玉箫",

"九环锡杖",
});

int do_rename(string arg)
{
    object me = this_player() ,obj,obj2,weapon;
    int delay,level,i;
    string str,wp,name,oldname,name2;
    mapping mp;

    if (me->is_busy()) return notify_fail("你正忙着呢！\n");
    if (me->is_fight()) return notify_fail("你正忙着呢！\n");
    if (!arg) return notify_fail("你要把什么名字刻在什么兵器上？\n");
    if (sscanf(arg,"%s %s",name,wp)<2) return notify_fail("你要把什么名字刻在什么兵器上？\n");
    if ( !objectp(obj = present(wp, me)) )
        return notify_fail("你身上没有这样东西。\n");
    if ( !mapp(obj->query("weapon_prop")) || !(int)obj->query("imbued") )
        return notify_fail("你只能为玩家制造的兵器改名。\n");
    if ( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="tiechui" )
        return notify_fail("你必须装备铁锤才能来为兵器改名。\n");
    if ( obj->query("imbued") >3 )
        return notify_fail("你不能修改高等级兵器的名字。\n");

    name=replace_string(name,"$RED$",RED,0); name=replace_string(name,"$HIR$",HIR,0);
    name=replace_string(name,"$GRN$",GRN,0); name=replace_string(name,"$HIG$",HIG,0);
    name=replace_string(name,"$YEL$",YEL,0); name=replace_string(name,"$HIY$",HIY,0);
    name=replace_string(name,"$BLU$",BLU,0); name=replace_string(name,"$HIB$",HIB,0);
    name=replace_string(name,"$MAG$",MAG,0); name=replace_string(name,"$HIM$",HIM,0);
    name=replace_string(name,"$CYN$",CYN,0); name=replace_string(name,"$HIC$",HIC,0);
    name=replace_string(name,"$WHT$",WHT,0); name=replace_string(name,"$HIW$",HIW,0);

    name2 = strip(name);
    i = strlen(name2);
    if ( i<2 || i>8 || i%2==1 )
        return notify_fail("你要改的名字长度不符合规定。\n");
    while(i--) {
        if (i%2==0 && !is_chinese(name2[i..<1]))
            return notify_fail("对不起，请您用「中文」取武器名字。\n");
    }
    if ( member_array(name2, banned_name)!=-1 )
        return notify_fail("这种武器名字会造成其他人的困扰，想个其它的吧。\n");

    mp = obj->query("weapon_mp");
    if( !mapp(mp) )	{
        write("错误！请通知巫师：No weapon mapping status！\n");
        return 1;
    }

    oldname = strip(mp["name"]);
    if( mp["skill_type"] == "dagger" ) {
        name += "匕";
        name2 += "匕";
    }
    else {
        name += oldname[<2..<1];
        name2 += oldname[<2..<1];
    }
    name += NOR;

    if ( member_array(name2, banned_name2)!=-1 )
        return notify_fail("这种武器名字会造成其他人的困扰，想个其它的吧。\n");

    switch( (string)obj->query("material") ){
        case "xuantie":	  str = WHT"玄铁"NOR; break;
        case "shentie":   str = RED"万年神铁"NOR; break;
        case "jintie":    str = HIY"金铁"NOR; break;
        case "ruanying":   str = HIW"软银"NOR; break;
        case "liuhuashi": str = RED"流花石"NOR; break;
        case "lushi":     str = HIG"绿石"NOR; break;
        case "ruantie":   str = YEL"软铁"NOR; break;
        case "shengtie":  str = YEL"生铁"NOR; break;
        case "qingtong":  str = GRN"青铜"NOR; break;
        default: str =	"精钢";	break;
    }
    if ( !objectp(obj2 = present((string)obj->query("material"), me)) )
        return notify_fail("你需要一块"+str+"，才能为这件兵器改名。\n");

    level = (int)me->query_skill("duanzao",1);
    switch( (int)obj2->query_level() ) {
        case 1: if(level<10)  return notify_fail("你的锻造技能不够！\n"); break;
        case 2: if(level<40)  return notify_fail("你的锻造技能不够！\n"); break;
        case 3: if(level<80)  return notify_fail("你的锻造技能不够！\n"); break;
        case 4: if(level<120) return notify_fail("你的锻造技能不够！\n"); break;
        case 5: if(level<170) return notify_fail("你的锻造技能不够！\n"); break;
        case 6: if(level<220) return notify_fail("你的锻造技能不够！\n"); break;
        case 7: if(level<270) return notify_fail("你的锻造技能不够！\n"); break;
        case 8: if(level<330) return notify_fail("你的锻造技能不够！\n"); break;
        case 9: if(level<390) return notify_fail("你的锻造技能不够！\n"); break;
    }

    message_vision(HIY"$N开始一笔一划的往"+obj->query("name")+HIY"上刻字......\n\n"NOR, me);
    delay = 15 + random(30);
    if(wizardp(me) && (int)me->query("env/test")) delay = 3;
    me->start_busy(delay);
    destruct(obj2);
    call_out("rename_finish",delay*2-1,me,obj,name);
    return 1;
}

void rename_finish(object me,object obj,string name)
{
    object tools;
    mapping mp;
    string * ids;

    if(!objectp(me) || !userp(me) || !objectp(obj) ) return;

    mp = obj->query("weapon_mp");
    mp["name"] = name;
    ids = mp["id"];
    ids[0] = geteuid(me) + " " + ids[2];
    mp["id"] = ids;
    obj->set_name(name, ids);

    obj->save_weapon(me);
    message_vision(HIY"$N把兵器的名字修改为"+obj->query("name")+"。\n"NOR, me);

    tools = me->query_temp("weapon");
    if ( objectp(tools) && tools->query("id")=="tiechui" )
        tools->use();
}

#define SAVE_DIR	DATA_DIR + "career/"

int do_recover(string arg)
{
    string str,st;
    mapping mp;
    object ob;
    object me = this_player();

    if( !wizardp(me) ) return 0;
    if( !arg || strlen(arg)<11 ) return notify_fail("无此物品！\n");

    seteuid(geteuid(me));

    str = read_file(SAVE_DIR+arg+SAVE_EXTENSION);
    if( strlen(str) < 11 ) return notify_fail("无此物品！\n");
    mp = restore_variable( str );
    mp["utime"] = time();

    str = WORKER_D->imbued_object_type(mp["save_id"]);
    if( str == "weapon" )
        ob = WORKER_D->make_weapon(me,mp,0,0);
    else if( str == "armor" )
        ob = WORKER_D->make_armor(me,mp,0,0);
    else
        return notify_fail("物品格式错误！\n");

    if(!ob) return notify_fail("生成物品时发生错误！\n");
    ob->move(me);
    tell_object(me,"你使用神的力量恢复出一"+ob->query("unit")+ob->query("name")+NOR+"。\n");
    rm(SAVE_DIR+arg+SAVE_EXTENSION);

    if(ob->query("imbued")<=3) return 1;

    if( str == "weapon" ) {
        if ( stringp(ob->query("name_st")) && strlen(ob->query("name_st"))>3 )
            st = ob->query("name_st");
        else
            st = "";
        str = sprintf("save_id=%s&time=%d&level=%d&wscore=%d&wuser=%s&wname=%s&details=%s",ob->query("weapon_mp/save_id"),time(),ob->query("imbued"),
            WORKER_D->weapon_rank(ob),ob->query("maker"),ob->query("name")+"("+ob->query("id")+")",st);
        WORKER_D->update_UniqueValues("addweapon",str,ob->query("weapon_mp/save_id"));
    }
    else {
        if ( stringp(ob->query("name_st")) && strlen(ob->query("name_st"))>3 )
            st = ob->query("name_st");
        else
            st = "";
        str = sprintf("save_id=%s&time=%d&level=%d&wscore=%d&wuser=%s&wname=%s&details=%s",ob->query("armor_mp/save_id"),time(),ob->query("imbued"),
            WORKER_D->armor_rank(ob),ob->query("maker"),ob->query("name")+"("+ob->query("id")+")",st);
        WORKER_D->update_UniqueValues("addarmor",str,ob->query("armor_mp/save_id"));
    }

    return 1;
}
