



string help()
{
  return "ʹ����������������ı��Լ�
  �İ�ᣬ�� chorg ��߸�.
  ʹ��chorg none �򲻳�Ϊ�κΰ��ĳ�Ա��
  
  Ŀǰ�İ����:
  
  ��߸�
  ��������
  ����
  ����
  �μұ�
  ��ɱ��
  
  ע�⣺�ڸı���֮�󣬲�Ҫ��PK������������
  �İ��������ġ�\n";
}
string convert(string arg)
{
   switch(arg){
   
   case "��߸�": return "lifa_b";
   case "��������": return "feima_b";
   case "����": return "duzun_b";
   case "����": return "dajiang_b";
   case "�μұ�": return "songjia_b";
   case "��ɱ��": return "haisha_b";
   default: return "none";}
}

int main(object ob,string arg)
{
  
  string org;
  if(!arg){
  tell_object(ob,help());
  return 1;}
  if(arg=="none"){
  ob->delete("shili");
  tell_object(ob,"������û�г�Ϊ�κΰ��ĳ�Ա��\n");
  return 1;}
  org=convert(arg);
  if(org=="none"){
  tell_object(ob,help());
  return 1;}
  ob->set("shili/name",org);
  tell_object(ob,"��������ϡ�\n");
  return 1;
   
}

