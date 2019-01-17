// go.c
// #pragma optimize all
//last modify by mudadm
//last modify by yanyan, 2001/,for guanchai_yunyan job.
#include <ansi.h>
#include <localtime.h>

#define TIME_TICK1 ((time())*60)

inherit F_CLEAN_UP;
mapping default_dirs = ([
	"north":		"��",
	"south":		"��",
	"east":			"��",
	"west":			"��",
	"northup":		"����",
	"southup":		"�ϱ�",
	"eastup":		"����",
	"westup":		"����",
	"northdown":	"����",
	"southdown":	"�ϱ�",
	"eastdown":		"����",
	"westdown":		"����",
	"northeast":	"����",
	"northwest":	"����",
	"southeast":	"����",
	"southwest":	"����",
        "enter":                "��",
	"up":			"��",
	"down":			"��",
	"out":			"��",
]);

void create() { seteuid(getuid()); }
int drop_things(object me)
{
	int i,max;
	object *inv;
	object env;

	env = environment(me);
	max = me->query_max_encumbrance();
	inv = all_inventory(me);
	for(i=0;i<sizeof(inv);i++){
		if(inv[i]->query("equipped")) continue;
		if(inv[i]->query("owner")) continue;
		if(inv[i]->query("no_get")) continue;
		if(inv[i]->query("no_drop")) continue;
		if(inv[i]->query("no_give")) continue;
		if(random(max) < inv[i]->weight())
		{
			tell_object(env,"�ڻ����У�");
			me->ccommand("drop "+inv[i]->query("id"));
		}
		
	}				

}
int check_flee(object me, string arg) 
{
   mapping 	my, your;
   object 	*enemy;object track;
   int		fp, bp, i;

   i = me->query("combat_exp");
   if ( (random(i) < 300) && userp(me) ) return 1;
   enemy = me->query_enemy();
   for(i=0; i<sizeof(enemy); i++) {
      if( objectp(enemy[i]) && environment(enemy[i])== environment(me) && living(enemy[i])) { 
         fp = me->query_dex();
         if(fp<1) fp = 1;
         bp = enemy[i]->query_dex();
         if(bp<1) bp = 1;
         if(random(fp*2+bp) > fp*2||!userp(me)) {
            message_vision(YEL "$N��" + arg + "��ȥ��\n" NOR, me);
            message_vision(RED "$N��Ӱһ����������$n����ǰ��\n" NOR, enemy[i], me);
            return 0;
         }
      }
   }
   return 1;
}

int is_night(object me,object env)
{

	return NATURE_D->is_night(me,env);
	
}


int main(object me, string arg)
{
        string dest, mout, min, dir,dir1,blk,ridemsg,str,str1;
        object env, obj, blocker,ridee;object track;
        int count = 0, my_dex, i,n,i_env,i_obj,date;
		mapping exit;
		mapping block;
        mapping gt;
        mixed *local;
        mixed old_target;
        n=NATURE_D->night();



	if( !arg ) return notify_fail("��Ҫ���ĸ������ߣ�\n");

	if( me->over_encumbranced() )
		return notify_fail("��ĸ��ɹ��أ��������á�\n");
	
	if(me->query_temp("no_move")){
	   if(stringp(me->query_temp("no_move")))
	    return notify_fail(me->query_temp("no_move"));
	   else
	   return notify_fail("���޷��߶���\n");
        }
	if( me->is_busy() )
		return notify_fail("������æ�úܣ������ƶ���\n");

        if( me->query("sen") < 3 && !me->is_ghost())
                return notify_fail("�������۵ø������߲���·�ˡ�\n");
                
        if(me->query("food")<=0||me->query("water")<=0)
           if(time()-me->query_temp("no_food_busy")>40)
             if(userp(me)){
         me->set_temp("no_food_busy",time());
         me->start_busy(2);
         return notify_fail("�㼢���ޱȣ������߲���·�ˣ�\n");}

	env = environment(me);
	if(!env) return notify_fail("������Ҳȥ���ˡ�\n");

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
		if( query_verb()=="go")
			return notify_fail("�������û�г�·��\n");
		else
			return 0;
	}

/*      if( mapp(block = env->query("blocks"))&& blk=block[arg]) {
        if( objectp(blocker = present(blk, env)) &&  living(blocker)) 
                return notify_fail("��������·��"+ blocker->name() + "��ס�� ��\n");
*/
       
    if ( old_target = me->query_temp("guardfor") )
    {
    	if(objectp(old_target))
    	{
    		if( living(old_target) )
               {
                    tell_object(me,"���������"+old_target->name()+"��\n");
                    me->delete_temp("guardfor");
             }
		    else
              {
                    tell_object(me,"�㲻�����"+old_target->name()+"����ֱ���ˡ�\n");
                    me->delete_temp("guardfor");
              }
          }
    }

	dest = exit[arg];

        if( !(obj = load_object(dest)) )
           return notify_fail("��Ҫȥ������û����ͨ��\n");

	if( !(obj = find_object(dest)) )
		return notify_fail("�޷��ƶ���\n");


	if( !env->valid_leave(me, arg) ) return 0;
    if( env->valid_leave(me, arg)>1) return 1;
	//if(obj->query("makelove_room"))
	// return notify_fail("��һ�Է������棬�㻹���Ȳ�Ҫȥ�ˣ�\n");

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;

        if (ridee = me->ride())
          ridemsg = ridee->query("ride/msg")+"��"+ridee->name();
        else  
          ridemsg = "";

	n=NATURE_D->night();
	i_env=(int)env->query("outdoors");
	i_obj=(int)obj->query("outdoors");

	if( me->is_fighting() )
	{ 
        if(check_flee(me, dir) == 0) {
        return notify_fail("�㱻���˻�����\n");
		}
        drop_things(me);
		if(objectp(track=me->query_temp("track")))
		{
			str1=ridemsg+"����"+track->name()+"��"+dir+"��Ķ����ˡ�\n";
			str=ridemsg+"����"+track->name()+"����ײײ�����˹�����ģ����Щ�Ǳ���\n";
		}
		else
		{str1 = ridemsg + "��" + dir + "��Ķ����ˡ�\n";
        str = ridemsg + "����ײײ�����˹�����ģ����Щ�Ǳ���\n";}
    }
	else if ( ridee = me->ride() ){
		str1 = ridemsg+ "��" + dir + "���۶�ȥ��\n";
        str = ridemsg+ "���۶�����\n";
    }
    else if(objectp(track=me->query_temp("track"))){
		str1=ridemsg+"����"+track->name()+"��"+dir+"�뿪�ˡ�\n";
		str=ridemsg+"����"+track->name()+"���˹�����\n";
	}else if(me->query("pker")){
		str  = "�Ż����ŵش�"+env->query("short")+"���˹�����\n";
		str1 ="��" + dir + "�Ż����ŵ��뿪�ˡ�\n";	
	}  
	else{
		str  = "��"+env->query("short")+"���˹�����\n";
		str1 ="��" + dir + "�뿪�ˡ�\n";
	}
	   
	if(is_night(me,env)){

		if(me->query("gender") == "Ů��"){
			mout = "һ��ٻӰ" + str1;
		}
		else{
			mout = "һ����Ӱ" + str1;
		}
	}
	else{
		mout = str1;
	}
	if(is_night(me,obj)){

		if(me->query("gender") == "Ů��"){
			min =  "һ��ٻӰ" + str;
		}
		else{
			min  = "һ����Ӱ" + str;
		}
	}
	else{
		min = str;
	}


	if (!userp(me) && obj->query("NONPC"))
			return notify_fail("�㲻��ȥ���\n");
	else if(obj->valid_enter(me))
			return notify_fail("�㲻��ȥ���˵�˽լ��\n");
	
	if(!is_night(me,env))
    	message( "vision", me->name() + mout, environment(me), ({me}) );
    else 
    	message( "vision", mout, environment(me), ({me}) );
	
	if(me->move(obj) ) {
		me->remove_all_enemy();
		if(!is_night(me,obj))
			message( "vision", me->name() + min, environment(me), ({me}) );
		else 
			message( "vision", min, environment(me), ({me}) );
		me->set_temp("pending", 0);
		if(env != obj)
			all_inventory(env)->follow_me(me, arg);
		if(track){
			me->receive_damage("sen",5+random(5));
			track->move(obj);
		}  //add by yanyan
		if (objectp(track))
			tell_object (me,"��"+min);
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if( !environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	tell_object(me, "�������һ���������...\n");
	main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
	write(@HELP
ָ���ʽ : go <����>
 
������ָ���ķ����ƶ���
 
HELP
    );
    return 1;
}
