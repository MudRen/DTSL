// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// chinese_d.c
// A minor chinese-english or english-chinese converter.
// by Annihilator@Eastern.Stories 09-27-93
// adapted for ES2-lib 01-18-95
// last modify by lanxin 99-03-06
// Last modified by Gmm 99-08-06 Add vocations' chinese name

#include <localtime.h>

#define DICTIONARY DATA_DIR + "chinese"

inherit F_SAVE;

static string *c_digit = ({ "��","ʮ","��","ǧ","��","��","��" });
static string *c_num = ({"��","һ","��","��","��","��","��","��","��","��","ʮ"});
static string *sym_tien = ({ "��","��","��","��","��","��","��","��","��","��" });
static string *sym_dee = ({ "��","��","��","î","��","��","��","δ","��","��","��","��" });
static mapping newname = ([
"swordman":"����","robber":"ǿ��","fighter":"����","official":"���",
"shaman":"������ʿ","bandit":"����","beggar":"��ؤ","doctor":"ҽ��",
"weaponman":"����ʦ","businessman":"����","taijian":"̫��","bonze":"ɮ��",
]);

mapping dict = ([]);

void add_translate( string key, string chinz );
void remove_translate( string key );
string chinese_period( int t );

void create()
{
	seteuid(getuid());
	restore();
}

void remove() { save(); }
string chinese_year ( int i )
{
	if( i == 0 ) return ""; 

	if( i < 0 ) return "��" + chinese_year ( -i );	

	if( i > 0 )
		return chinese_year( i / 10 ) + c_num[i % 10];
}

string chinese_number(int i)
{
	if( i<0 ) return "��" + chinese_number(-i);
	if( i<11 ) return c_num[i];
	if( i<20 ) return c_num[10] + c_num[i-10];
	if( i<100 ) {
		if( i%10 ) return c_num[i/10] + c_digit[1] + c_num[i%10];
		else return c_num[i/10] + c_digit[1];
	}
	if( i<1000 ) {
		if( i%100==0 )
			return c_num[i/100] + c_digit[2];
		else if( i%100 < 10 )
			return c_num[i/100] + c_digit[2] + c_num[0] + chinese_number(i%100);
		else if( i%100 < 20 )
			return c_num[i/100] + c_digit[2] + c_num[1] + chinese_number(i%100);
		else return c_num[i/100] + c_digit[2] + chinese_number(i%100);
	}
	if( i<10000 ) {
		if( i%1000==0 )
			return c_num[i/1000] + c_digit[3];
		else if( i%1000 < 100 )
			return c_num[i/1000] + c_digit[3] + c_digit[0] + chinese_number(i%1000);
		else
			return c_num[i/1000] + c_digit[3] + chinese_number(i%1000);
	}
	if( i<100000000 ) {
		if( i%10000==0 )
			return chinese_number(i/10000) + c_digit[4];
		else if( i%10000 < 1000 )
			return chinese_number(i/10000) + c_digit[4] + c_digit[0] + chinese_number(i%10000);
		else
			return chinese_number(i/10000) + c_digit[4] + chinese_number(i%10000);
	}
	if( i<1000000000000 ) {
		if( i%100000000==0 )
			return chinese_number(i/100000000) + c_digit[5];
		else if( i%100000000 < 10000000 )
			return chinese_number(i/100000000) + c_digit[5] + c_digit[0] + chinese_number(i%100000000);
		else
			return chinese_number(i/100000000) + c_digit[5] + chinese_number(i%100000000);
	}
		if( i%1000000000000==0 )
			return chinese_number(i/1000000000000) + c_digit[6];
		else if( i%1000000000000 < 100000000000 )
			return chinese_number(i/1000000000000) + c_digit[6] + c_digit[0] + chinese_number(i%1000000000000);
		else
			return chinese_number(i/1000000000000) + c_digit[6] + chinese_number(i%1000000000000);
}

string query_save_file() { return DICTIONARY; }

// This is called by to_chinese() simul_efun
string chinese(string str)
{
	if( !undefinedp( dict[str] ) ) return dict[str];
//      else return str;
        else
        {
               if ( !undefinedp( newname[str] ) ) return newname[str];
               else return str;
        } 
}

void remove_translate( string key )
{
	map_delete( dict, key );
	save();
}

void add_translate( string key, string chinz )
{
	dict[key] = chinz;
	save();
}

void dump_translate()
{
	string *k, str;
	int i;

	str = "";
	k = keys(dict);
	for(i=0; i<sizeof(k); i++)
		str += sprintf("%-30s %s\n", k[i], dict[k[i]]);
	write_file("/CHINESE_DUMP", str);
}


string chinese_date(int date,int real_time )
{
	/*mixed *local;

	local = localtime(date);

	return sprintf("%s%s��%s��%s��%sʱ%s��",
		sym_tien[local[LT_YEAR]%10], sym_dee[local[LT_YEAR]%12],
		chinese_number(local[LT_MON]+1),
		chinese_number(local[LT_MDAY] + (local[LT_HOUR]>23? 1 : 0)),
		sym_dee[((local[LT_HOUR]+1)%24)/2],
		local[LT_HOUR]%2==0?chinese_number((local[LT_MIN]%15>0?local[LT_MIN]/15+1:local[LT_MIN]/15)+4):
		chinese_number((local[LT_MIN]%15>0?local[LT_MIN]/15+1:local[LT_MIN]/15)));
	
	this is the dt1 code
       */
       mixed *local;
	int i;

	local = localtime(date);
	i = (local[LT_HOUR]+1) % 2 * 2 + local[LT_MIN] / 30;
	return sprintf("%s%s��%s��%s��%sʱ%s",
                sym_tien[local[LT_YEAR] % 10], sym_dee[local[LT_YEAR] % 12],
                chinese_number(local[LT_MON] + 1),
                chinese_number(local[LT_MDAY]),
                sym_dee[((local[LT_HOUR] + 1) % 24) / 2],
		i?chinese_number((local[LT_HOUR]+1) % 2 * 2 + 
		local[LT_MIN] / 30 ) + "��":"��");
}
varargs string chinese_newdate( int date, int real_time )
{
	mixed *local;

	local = localtime(date);

	return sprintf ( "��Ԫ%s��%s��%s��%sʱ%s��",
		chinese_year ( real_time ? local[LT_YEAR] : ( local[LT_YEAR] + 300 ) ),
		chinese_number ( local[LT_MON] + 1 ),
		chinese_number ( local[LT_MDAY] ),
		chinese_number ( local[LT_HOUR] ),
		chinese_number ( local[LT_MIN] ) );
}

string chinese_period(int t)
{
	int y, n, d, h, m, s;
	string time;

	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t % 30;		t /= 30;
	n = t % 12;		t /= 12;
	y = t;

	time = "";

	if(y) time = chinese_number(y) + "����";
	if(n) time += chinese_number(n) + "����"	+ (strlen(time)?"":"��");
	if(d) time += chinese_number(d) + "��"		+ (strlen(time)?"":"��");
	if(h) time += chinese_number(h) + "Сʱ"	+ (strlen(time)?"":"��");
	if(m) time += chinese_number(m) + "��"		+ (strlen(time)?"":"��");
	time += chinese_number(s) + "��";

	return time;
}

string chinese_month(int date)
{
        mixed *local;
        local = localtime(date);
        return sprintf("%s",chinese_number(local[LT_MON] + 1));
}
string chinese_monthday(int date)
{
        mixed *local;
        local = localtime(date);
        return sprintf("%s��%s��",chinese_number(local[LT_MON] + 1),
                chinese_number(local[LT_MDAY]+1));
}
string string_number(int i)
{
string newstring;
int j,k;
newstring="";
for(j=0;i/10>0;){
k=i%10;
i=i/10;
newstring=k+newstring;
j++;
if(j%3==0)
newstring=","+newstring;}
newstring=i+newstring;
return newstring;
}
