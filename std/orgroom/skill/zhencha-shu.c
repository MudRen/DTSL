//


inherit SKILL;

string query_type()
{
   return "literate";
}

int valid_learn(object me)
{
    if(me->query_skill("zhencha-shu",1)>=me->query("max_pot")-100)
     return notify_fail("�����ѧ��Ϊ̫���ˣ��޷����������������ˣ�\n");
    
    if(me->query_skill("war-heal",1)||
       me->query_skill("bafang-zhenfa",1)||
       me->query_skill("liaoyuan-tianshu",1)||
       me->query_skill("wuxing-qishu",1)||
       me->query_skill("junxie-xue",1)||
       me->query_skill("qianjun-shu",1)||
       me->query_skill("dadao-qishu",1)
      )
      return notify_fail("�����ѧ̫���ˣ�����רһѧһ�Űɣ�\n");
    
    if(me->query("family/family_name")!="�μұ�"){
      me->add("potential",-10);
      if(me->query("potential")<0)
       me->set("potential",0);
    }
    
    return 1;
}


string help_action()
{
write(@LONG
    �����

    �˼��ܿ��������׼ȷ�Ĳ鿴�Է����е���Ϣ
    ��������μұ��ĵ��ӣ���ѧ����Ҫ�������Щ��
        
LONG);
return "\n";
}

