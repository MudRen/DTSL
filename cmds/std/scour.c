// ��ʬ��������ѵ�������

inherit F_CLEAN_UP;

int main(object me, string arg)
{
     object corpse;
     int i,flag=0;
     object obj;
         
     if(!arg)
     return notify_fail("��Ҫ�Ѳ�ʲô������\n");
     if(!objectp(corpse=present(arg,environment(me))))
     return notify_fail("����Χû�����������\n");
     if(!corpse->is_corpse())
     return notify_fail("�Ǹ���������ʬ�壬�����Ѳ飡\n");
     /*
     if(corpse->query("killed_by")!=me->query("id"))
     return notify_fail("���������ɱ��ʬ�壬���ܴ������Ѷ�����\n");
     */
     if(corpse->query("have_scoured"))
     return notify_fail("���ʬ���Ѿ����ѹ��ˣ�û��ʲô�����ˡ�\n");
     corpse->set("have_scoured",1);
     message_vision("$N����������ʬ���﷭�˼��¡�\n",me);
     i=random(5);
     if(random(100)<70||corpse->query("player_corpse")) i=0;
     if(i>0) flag=1;
     while(i--){
     	switch(random(2)){
     	   case 0: obj=new(__DIR__"misc/tiekuang");break;
     	   case 1: obj=new(__DIR__"misc/medicine");
     	}
     	obj->set_status(me);
     	obj->move(corpse);
     }
     if(flag)
     tell_object(me,"ʬ���������ʲô������\n");
     else
     tell_object(me,"ʬ����ʲôҲû�С�\n");
    return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : scour corpse

���ָ�������ʬ����Ѱ��һЩ��Ʒ�����ʯ��ҩ�ĵȡ�����ʬ����
���ֵĿ�ʯ��ҩ�ģ�������ȿ��ɵ��ġ��ڵ��ĺá�
��ʬ���еõ���Ʒ���м��ʵģ�����ÿ�ζ��ܵõ�������ÿ��ʬ��ֻ
����һ�Ρ�

HELP
    );
    return 1;
}
