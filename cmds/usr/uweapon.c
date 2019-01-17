// weapon.c
// ���й����������������
// Created by snowman@SJ 01/05/2001
// Last modified by snowman@SJ 25/06/2001

#include <ansi.h>

#include <user_weapon.h>
#define USER_WEAPOND    "/adm/daemons/user_weapond"
#define NAMED   "/adm/daemons/named2"

void help(object me);
string get_save_weapon(object wp);
private void confirm_delete(string yn, object me, object wp);
private void confirm_save(string yn, object me, object wp);
private void confirm_name(string yn, object me, object wp, string name);
private void confirm_name_again(string yn, object me, object wp, string name);

static string *banned_name = ({
// Mud ��������
"�Լ�","ɱ��","����","ѩ��","��ң","����","����","����","����","���","ĳ��","ʬ��",
"����","�ܹ�","����","����","��ʦ","�ſ�","���","��","�齣","���ִ���","����ͨ","����",
"������","�̿�","����","��ʦ","���","ͷ­","ɱ�˷�","����",
// Mud ������������
"��ɽ","��ɽ","��ɽ","��ɽ","̩ɽ","ѩɽ","��ɽ","��ɽ","����","�置","����","��ԭ",
"�Ͻ�","����","�ƺ�","�й�","�л�","����ɽ","����ɽ","����ɽ","�䵱ɽ","����ɽ",
"����","�һ���","��ľ��",
"����","ؤ��","����","����","Ľ��","��Ĺ","ȫ��","����","����","����","�һ�","����",
"������","������","�嶾��","����","а��","��������","�������","�ٸ�","����",
"������","�䵱��","���ư�","��ͨ����","������","����Ľ��","��Ĺ��","��ɽ��","��ɽ��",
"����","������","������",
// ��Ҫ��������
"��ӹ","��Сƽ","������","ë��","���Ż�","�ʵ�","����", "��ϯ",
// С˵����
"������","���޼�","����","���","�����","���","���˷�","ΤС��","Ԭ��־","��һ��",
"�¼���","����","����","�Ƿ�","����","��������","ŷ����","���߹�","��ҩʦ","�λ�ү",
"һ�ƴ�ʦ","������","�ܲ�ͨ","����","������","�������",
// �໰
"ͳһ","����","�����о�","���ִ�","����","�����","ȥ���","������","������","����",
"�쵰","����","ɱ��","����","ǿ��","��Ů","̨��","�쵼","����","ƨ��","ƨ��","����",
"��ƨ","����","����","���","��Ѿ","����","����","����","ɵ��","����","����","�Ҳ�",
"̫��","�¹�","�˸�","����","��", "����", "����", "�ּ�", "��", "����", "����",
});


int main(object me, string arg)
{
int i;
object wp;
string name;

if (!arg) {
if (!me->query("user_weapon"))
return notify_fail("��Ŀǰû���Լ���������\n");
write("��Ŀǰ�Ѿ�ӵ����һ��˽��������\n");
write("�������ۣ�"+me->query("user_weapon_score")+"\n");
return 1;
}

if (me->is_busy() || me->is_fighting())
return notify_fail("����æ���أ�\n");

if (sscanf(arg, "delete %s", arg)) {
if (!objectp(wp = present(arg, me)))
return notify_fail("������û������������\n");
if (!wp->query("imbued"))
return notify_fail("�ⲻ��һ�������������\n");
if (wp->query("user_weapon") != geteuid(me))
return notify_fail("�ⲻ��������������\n");
if (wp->query("saved") == geteuid(me)) {
write("�㼴��ɾ��˽��������"+wp->name()+"�����ȷ�������� "HIY"Y"NOR"������ȡ����\n");
input_to((: confirm_delete :), me , wp);
}
else
confirm_delete("y", me , wp);
} else if(arg == "list")
write(USER_WEAPOND->show_rank(me, 0));
else if (sscanf(arg, "list %d", i))
me->start_more(USER_WEAPOND->show_rank(me, i));
else if(  arg=="login" ){ 
        wp = USER_WEAPOND->check_user_weapon(me);   
        write("�����Ѿ��һء�\n"); 
}
else if (sscanf(arg, "save %s", arg)) {
if (me->query("user_weapon"))
return notify_fail("���Ѿ�ӵ��һ��˽�������ˡ�\n");
if (!objectp(wp = present(arg, me)))
return notify_fail("������û������������\n");
if (!wp->query("imbued"))
return notify_fail(wp->name()+"����һ�������������\n");
if (wp->query("user_weapon") && wp->query("user_weapon") != geteuid(me))
return notify_fail(wp->name()+"����������������\n");
if (wp->query("saved") == geteuid(me))
return notify_fail(wp->name()+"�Ѿ������˽�������ˣ�\n");
write("�㼴����"+wp->name()+"��Ϊ�Լ���˽�����������ȷ����� "HIY"Y"NOR"������ȡ����\n");
input_to((: confirm_save :), me, wp);
} else if (sscanf(arg, "rename %s %s", arg, name)==2) {
mapping mp;
string oldname;

if (!objectp(wp = present(arg, me)))
return notify_fail("������û������������\n");
if( !wp->query("imbued") )
return notify_fail(wp->name()+"����һ�������������\n");
if( wp->query("user_weapon") && wp->query("user_weapon") != geteuid(me))
return notify_fail(wp->name()+"����������������\n");
if( wp->query("saved") != geteuid(me) )
return notify_fail(wp->name()+"�������˽��������\n");
if( wp->query("imbued") >= 5 )
return notify_fail("�������������������\n");
i = (me->query("imbue_money") + 1) * 1000000;
if (me->query("balance") < i)
return notify_fail("Ϊ������������˴���Ҫ"+chinese_number(i/10000)+"���ƽ�\n");

i = strlen(name);
if (i < 2 || i > 6 || i%2)
return notify_fail("�Բ����������ֱ����� 1 �� 3 �������֡�\n");

while(i--) {
if (i%2==0 && !is_chinese(name[i..<1]))
return notify_fail("�Բ��������á����ġ�ȡ�������֡�\n");
}

mp = wp->query("weapon_mp");
if( !mapp(mp) ){
write("������֪ͨ��ʦ��No weapon mapping status��\n");
return 1;
}
oldname = strip(mp["name"]);
if( mp["skill_type"] == "dagger" )
name += "ذ";
else
name += oldname[<2..<1];

if (!wiz_level(me->query("id")) && member_array(name, banned_name)!=-1)
return notify_fail("�����������ֻ���������˵����ţ���������ġ�\n");

write(
"\n�㼴����"+wp->name()+"������\n"
"�����֣�"+name+"��\n"
HIR"ע�⣡��Ҫ�������������硺����������֮�࣬ϵͳ���Զ����ϣ�\n"NOR
"��������ID������� ID + ���� ID��\n"
"���η���Ϊ" + chinese_number((me->query("imbue_money") + 1)*100) + "���ƽ�\n"
"ȷ����� "HIY"Y"NOR"������ȡ����\n"
);
input_to((: confirm_name :), me, wp, name);
} else
help(me);
return 1;
}

private void confirm_delete(string yn, object me, object wp)
{
if( yn[0]!='y' && yn[0]!='Y' )
write("��ȡ���˲�����\n");
else {
wp->delete("user_weapon");
if (wp->query("saved") == geteuid(me)) {
me->delete("user_weapon");
USER_WEAPOND->weapon_rank(0, me);
me->delete("imbue_money");
me->save();
log_file("quest/i_delete", sprintf("%s deleted user weapon %s on %s.\n",
geteuid(me), wp->name(), ctime(time())));
write("���Ѿ�ɾ����˽��������"+wp->name()+"\n");
} else {
log_file("quest/i_abandon", sprintf("%s abandoned user weapon %s on %s.\n",
geteuid(me), wp->name(), ctime(time())));
write("���Ѿ������"+wp->name()+"��˽�б�־��\n");
}
wp->delete("saved");
}
me->add_busy(1);
}

private void confirm_color(string yn, object me, object wp, string name)
{
string color;

me->add_busy(1);

switch (yn) {
case "RED" : color = RED; break;
case "GRN" : color = GRN; break;
case "YEL" : color = YEL; break;
case "BLU" : color = BLU; break;
case "MAG" : color = MAG; break;
case "CYN" : color = CYN; break;
case "WHT" : color = WHT; break;
case "HIR" : color = HIR; break;
case "HIG" : color = HIG; break;
case "HIY" : color = HIY; break;
case "HIB" : color = HIB; break;
case "HIM" : color = HIM; break;
case "HIC" : color = HIC; break;
case "HIW" : color = HIW; break;
case "y":
case "Y": write("���ٴ�ȷ���Ƿ������������ȷ�����"WHT" Y"NOR"�����������ȡ����\n");
input_to( (: confirm_name_again :), me, wp, name );
return;
default :
write("\n��û��������ɫ������ȡ���˸�˽�����������Ĳ�����\n");
return;
}
name = color + name;
write(
"\n��Ϊ����ѡ����"+color+"��"NOR"���Ƿ�ȷ��������\n"
"��ѡ�� "HIY"Y"NOR"���������ȡ����\n"
);
input_to( (: confirm_name_again :), me, wp, name );
}

private void confirm_name(string yn, object me, object wp, string name)
{
me->add_busy(1);
if( yn[0]!='y' && yn[0]!='Y' ) {
write("��ȡ���˸�˽�����������Ĳ�����\n");
} else {
write("
���Ѿ�ȷ���������ǡ�"+name+"����������ѡȡ��ɫ��

RED - "RED"��"NOR"��ɫ              HIR - "HIR"��"NOR"����ɫ
GRN - "GRN"��"NOR"��ɫ              HIG - "HIG"��"NOR"����ɫ
YEL - "YEL"��"NOR"����ɫ            HIY - "HIY"��"NOR"����ɫ
BLU - "BLU"��"NOR"����ɫ            HIB - "HIB"��"NOR"����ɫ
MAG - "MAG"��"NOR"ǳ��ɫ            HIM - "HIM"��"NOR"�ۺ�ɫ
CYN - "CYN"��"NOR"����ɫ            HIC - "HIC"��"NOR"����ɫ
WHT - "WHT"��"NOR"��ɫ              HIW - "HIW"��"NOR"����ɫ

�������Ҫ��ɫ����� "HIY"Y"NOR"������ȡ����\n");
input_to((: confirm_color :), me, wp, name);
}
}

private void confirm_name_again(string yn, object me, object wp, string name)
{
mapping mp;
string *ids;
int i;

if( yn[0]!='y' && yn[0]!='Y' ) {
write("��ȡ���˸�˽�����������Ĳ�����\n");
} else {
mp = wp->query("weapon_mp");
if( !mapp(mp) ){
write("������֪ͨ��ʦ��No weapon mapping status��\n");
return;
}

name += NOR;

i = (me->query("imbue_money") + 1) * 1000000;
me->add("balance", -i);
me->add("imbue_money", 1);

log_file("quest/i_rename", sprintf("%-8s used %d gold rename %s with %s on %s.\n",
geteuid(me), i/10000, mp["name"], name, ctime(time()) ));
mp["name"] = name;
ids = mp["id"];
ids[0] = geteuid(me) + " " + ids[2];
ids[1] = geteuid(me) + " " + ids[3];
mp["id"] = ids;
wp->set_name(name, ids);

confirm_save("y", me, wp);

write("�㻨��" + chinese_number(i/10000) + "���ƽ�����������֣��µ��������֣�" + name + " ��\n");
}
me->add_busy(1);
}

private void confirm_save(string yn, object me, object wp)
{
mapping mp, my_mp = ([]);
string str;

if( yn[0]!='y' && yn[0]!='Y' ) {
write("��ȡ���˱���˽�������Ĳ�����\n");
return;
}

mp = wp->query("weapon_mp");
if (!mapp(mp))
return;

if( stringp(mp["name_st"]) )
str = mp["name_st"];
else if( sizeof(mp["name_st"]) > 0)
str = implode(mp["name_st"][0..<1], "��");

my_mp["skill_type"] = mp["skill_type"]; // ���
my_mp["imbued"] =mp["imbued"];  // ����
my_mp["weight"] =mp["weight"];  // ����
my_mp["broken"] =mp["broken"];  // �Ƿ���
my_mp["flag"] =mp["flag"];    // �Ƿ���
my_mp["rigidity"] =mp["rigidity"];  // Ӳ��
my_mp["sharpness"] =mp["sharpness"]; // ������
my_mp["wield_str"] =mp["wield_str"]; // װ�� str Ҫ��
my_mp["wield_maxneili"] =mp["wield_maxneili"]; // װ�� maxneili Ҫ��
my_mp["wield_neili"] =mp["wield_neili"];    // װ�� neili Ҫ��
my_mp["value"] =mp["value"];  // ��ֵ
my_mp["name"] =mp["name"];   // ����
my_mp["id"] =mp["id"];  // ��ID
my_mp["long2"] =mp["long2"];  // ����
my_mp["poisoned"] =mp["poisoned"];  // �Ƿ����
my_mp["poison_number"] =mp["poison_number"]; // ����
my_mp["weapon_prop"] =wp->query("weapon_prop");
my_mp["hammer_count"]= mp["hammer_count"];
my_mp["dagger_count"]= mp["dagger_count"];
my_mp["name_st"] = str; // ��������������
my_mp["saved"]= geteuid(me);  // �Ƿ񴢴�
/*
if( (int)mp["weapon_prop"]["damage"] > 0 )
my_mp["weapon_prop"]["damage"]= mp["weapon_prop"]["damage"];
*/
if( wizardp(me) )
write(sprintf("%O\n", my_mp["weapon_prop"]));
me->set("user_weapon", copy(my_mp));
log_file("quest/i_saved", sprintf("%-8s saved user weapon %s(%d) on %s.\n",
geteuid(me), wp->name(), mp["weapon_prop/damage"], ctime(time()) ));

wp->set("saved", geteuid(me));
wp->set("user_weapon", geteuid(me));
USER_WEAPOND->weapon_rank(wp, me);

me->save();
if (previous_object())
return;
write("\n"+wp->name()+"�������Ѿ�������ϣ���Ϊ��Ŀǰ��˽��������\n");
me->add_busy(1);
}

void help(object me)
{
write(@HELP
ָ���ʽ : uweapon save| delete| rename|list <����>

���ָ��������㴢���ɾ���Լ���˽��������

����:  �� uweapon save <����>
ȷ�Ϻ󣬴˽����Ϊ��˽�����У���¼ʱ���Զ������������ϡ�

�� uweapon delete <����>
ȷ�Ϻ����˽��������־����������Ը�����ˡ�

�� uweapon rename <����> <����>
Ϊ�Լ�������������

�� uweapon list <����>
�鿴��ǰ����������

ע�⣺���Ŀǰ��Ϸ���������������¼ʱ�㲻������������ϡ�

   by snowman@SJ 26/05/2001

   Copyright 1997-2001 ShuJian MUD Wizard Group.
   All rights reserved.
HELP
);
}
