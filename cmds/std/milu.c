#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;


void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object ob,env;
        string pla, here;
	if( environment(me)->query("no_rideto")||
	 environment(me)->query("no_quit") )
		return notify_fail("�������񲻻����㡣\n");
        

                
        if (! arg)
                return notify_fail("��Ҫȥ���\n");
        if (me->is_fighting())
                return notify_fail("���������ں��˼Ҷ��֣� ���񲻻����㡣\n");
      
        if(me->query_temp("dtsl_job"))
                return notify_fail("������������ ���񲻻����㡣\n");
	if( me->is_ghost() )
		return notify_fail("���˹��ˣ�����ʵ��ɣ�\n");
       if (me->query_temp("quest_biao"))
                return notify_fail("�ú�����,������.\n");

           env = environment(me); 

       if (file_name(env)[0..5] == "/d/pk/") 
                return notify_fail("���ﲻ���ٻ�����\n");        

        if (me->is_busy())
                return notify_fail("����һ��������û����ɣ��ȵȵȰɡ�\n");

          else {
          message_vision(HIY
"$N���һ��������HELP�������������һ�������У�����һָ,��ʱ$N��ʧ�ڿ����У�\n"NOR, me);
}
          if(arg=="yz") pla = "/d/yangzhou/hotel";
     else if(arg=="baling") pla = "/d/baling/kezhan";
     else if(arg=="changan") pla = "/d/changan/guangchang";
     else if(arg=="haisha") pla = "/d/haisha/cunxi";
     else if(arg=="changbaishan") pla = "/d/changbaishan/tianchi";
     else if(arg=="chanyuan") pla = "/d/chanyuan/miaodoor";
     else if(arg=="chengdu") pla = "/d/chengdu/kedian";
     else if(arg=="dabashan") pla = "/d/dabashan/shanjiao";
     else if(arg=="dajianglian") pla = "/d/dajianglian/mumen";
     else if(arg=="dingxiang") pla = "/d/dingxiang/kezhan.c";
     else if(arg=="dongming") pla = "/d/dongming/pinglu";
     else if(arg=="emeishan") pla = "/d/emeishan/liangting";
     else if(arg=="chatroom") pla = "/u/kouzhong/chatroom";
     else if(arg=="feima") pla = "/d/feima-muchang/door";
     else if(arg=="gaoli") pla = "/d/gaoli/qinglongmen";
     else if(arg=="haisha") pla = "/d/haisha/cunxi";
     else if(arg=="hangzhou") pla = "/d/hangzhou/center";
     else if(arg=="hefei") pla = "/d/hefei/ximen";
     else if(arg=="hengshan") pla = "/d/hengshan/beiyuedian";
     else if(arg=="huashan") pla = "/d/huashan/shanlu1";
     else if(arg=="jingzhai") pla = "/d/jingzhai/door";
     else if(arg=="jiujiang") pla = "/d/jiujiang/ximen";
     else if(arg=="leshou") pla = "/d/leshou/ximen";
     else if(arg=="lingnan") pla = "/d/lingnan/wuchang";
     else if(arg=="mayi") pla = "/d/mayi/beimen";
     else if(arg=="luoyang") pla = "/d/luoyang/kedian";
     else if(arg=="pengliang") pla = "/d/pengliang/kezhan";
     else if(arg=="taiyuan") pla = "/d/taiyuan/beimen";
     else if(arg=="xiangyang") pla = "/d/xiangyang/nanmen";
     else if(arg=="xucheng") pla = "/d/xucheng/ximen";
     else if(arg=="yinkui") pla = "/d/yinkui/door";
     else if(arg=="yuyang") pla = "/d/yuyang/guangchang";
             else {
               message_vision(HIR
"����ŭ��������û������ط����㵽��Ҫȥ����?\n"NOR, me);
}
       me->move(pla);
     return 1;
}


int help(object me)
{
        write(@HELP
ָ���ʽ : milu <�ص�>
���ָ����Ե���ĳ���ص�.
���Ե���ĵص��У�
������<chatroom> 

��    ��<yz>         ��    ��<baling>      ��    ��<luoyang>    ��    ��<yuyang>   
�� �� ��<yinkui>     ��    ��<xucheng>     ̫    ԭ<taiyuan>    ��    ��<pengliang>   
��    ��<mayi>       ��    ��<lingnan>     ��    ��<leshou>     ��    ��<jiujiang>  
�Ⱥ���ի<jingzhai>   ��    ɽ<huashan>     ��    ɽ<hengshan>   ��    ��<hefei>      
��    ��<hangzhou>   ��    ��<gaoli>       ��������<feima>      ��    ��<emeishan>
�� �� ��<dongming>   �� ͻ ��<dingxiang>   ��    ��<changan>    �� �� ɽ<changbaishan>
������Ժ<chanyuan>   ��    ��<chengdu>     �� �� ɽ<dabashan>   �� �� ��<dajianglian>
��  ��<xiangyang>  
 
HELP
    );
    return 1;
}


