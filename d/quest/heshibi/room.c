inherit ROOM;
void create()
{
	int time;
	object ob;
	set("short","����");
	set("long", @LONG
�����Ƿ��ź���赵ķ��䡣Ŀǰ�趨ÿ������Сʱ����赳�
��һ�Ρ�
LONG);
        time=uptime();
        if((time/3600)%9==0){
        ob=new(__DIR__"heshibi");
        CHANNEL_D->do_channel( this_object(), "rumor","��˵����赳����ڽ���֮���ˡ�\n");
        ob->move("/d/chanyuan/tongdian");}
	setup();      
}
