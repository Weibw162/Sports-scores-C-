#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
struct xx
{
	int a[20];
	int n,bh,man,woman;//bh 编号
	string name;xx*next;
};
struct xm
{
	int m,hb;
	int n1,n2,n3,n4,n5;
	string xiangmu;string d[5];xm*next;
};
void shuru(xx*first,xm*head);//声明赛前准备
void chengjiluru(xx*first,xm*head);//声明成绩录入
void paixu(xx*first,xm*head);//声明成绩排序
void chaxun(xx*first,xm*head);//声明成绩查询
void shuchuliu(xx*first,xm*head);//声明文件导出
int main()
{
	xm*head=new xm;
	head->next=NULL;
	xx*first=new xx;
	first->next=NULL;
	while(1)
	{
		cout<<"|----------------------------|"<<endl;
		cout<<"|欢迎来到东北高校大学生运动会|"<<endl;
		cout<<"|----------------------------|"<<endl;
		cout<<"| 1.  赛  前  准  备         |"<<endl;
		cout<<"| 2.  成  绩  录  入         |"<<endl;
		cout<<"| 3.  查  询  成  绩         |"<<endl;
		cout<<"| 4.  成  绩  排  序         |"<<endl;
		cout<<"| 5.  文  件  储  存         |"<<endl;
		cout<<"|----------------------------|"<<endl;
		int g;cin>>g;
		switch(g)
		{
		case 1:
			{
				system("cls");shuru(first,head);system("pause");system("cls");break;
			}
		case 2:
			{
			    system("cls");chengjiluru(first,head);system("pause");system("cls");break;
			}
		case 3:
			{
				system("cls");chaxun(first,head);system("pause");system("cls");break;
			}
		case 4:
			{
				system("cls");paixu(first,head);system("pause");system("cls");break;
			}
		case 5:
			{
				system("cls");shuchuliu(first,head);system("pause");system("cls");break;
			}
			break;
		}}
	return 0;}
int i,w,t,y,ji1=1,ji2=1;
void shuru(xx *first,xm *head)//赛前准备
{
	xx *r=new xx;r=first;
	cout<<"----------------------------"<<endl;
	cout<<"请输入参赛学校的数目"<<endl;
	cout<<"----------------------------"<<endl;
	cin>>w;
	for(i=0;i<w;i++)
	{
		xx *q=new xx;
		cout<<"-------------------------------"<<endl;
		cout<<"请输入参赛学校"<<ji1<<"的名称"<<endl;
		cout<<"-------------------------------"<<endl;
		cin>>q->name;
		q->n=0;q->man=0;q->woman=0;q->bh=ji1;
		q->a[0]=q->a[1]=q->a[2]=q->a[3]=q->a[4]=q->a[5]=q->a[6]=q->a[7]=q->a[8]=q->a[9]=q->a[10]=q->a[11]=q->a[12]=q->a[13]=q->a[14]=q->a[15]=q->a[16]=q->a[17]=q->a[18]=q->a[19]=0;
		r->next=q;r=q;q->bh=ji1;ji1++;q=q->next;
		}//初始化学校（除编号及学校名称以外）链表所有数据为零
		system("cls");
		xm *o=new xm;o=head;
		cout<<"-------------------------------"<<endl;
		cout<<"请输入男子项目的数目"<<endl;
		cout<<"-------------------------------"<<endl;
		cin>>t;
		for(i=0;i<t;i++)
		{
			xm *u=new xm;
			cout<<"---------------------------------"<<endl;
			cout<<"请输入男子项目"<<ji2<<"的名称"<<endl;
			cout<<"---------------------------------"<<endl;
			cin>>u->xiangmu;
            o->next=u;o=u;u->hb=ji2;u=u->next;ji2++;//将上下链表连接起来
		}
		system("cls");xm *oo=new xm;oo=o;
		cout<<"---------------------------------"<<endl;
		cout<<"请输入女子项目的数目"<<endl;
		cout<<"---------------------------------"<<endl;
		cin>>y;
		int ji3=ji2-1;
		for(int ii=0;ii<y;ii++)
		{
			xm *u=new xm;
			cout<<"-----------------------------------"<<endl;
			cout<<"请输入女子项目"<<ji2-ji3<<"的名称"<<endl;
			cout<<"-----------------------------------"<<endl;
			cin>>u->xiangmu;
			oo->next=u;oo=u;u->hb=ji2;u=u->next;ji2++;
		}}
void chengjiluru(xx *first,xm *head)//成绩录入
{
	xx *zz=new xx;zz=first;xm *bb=new xm;bb=head->next;
	int cc,ccc=0;
	cout<<"-------------------------------------"<<endl;
	cout<<" 请 输 入 各 个 名 次 的 学 校 名 称 "<<endl;
	cout<<"-------------------------------------"<<endl;
	while(ccc<t+y)
	{
		cout<<"-----------------------------------"<<endl;
		cout<<"请输入项目"<<bb->xiangmu<<"的成绩"<<endl;
		cout<<"-----------------------------------"<<endl;
			bb->n1=5;bb->n2=3;bb->n3=2;bb->n4=0;bb->n5=0;
			cout<<"----------------------------------"<<endl;
			cout<<"请输入第一名的学校"<<endl;
			cout<<"----------------------------------"<<endl;
			cin>>bb->d[0];
			xx*vv=new xx;vv=first->next;cc=0;
			while(cc<w&&vv!=NULL)//逐个匹配学校名字  字符串
			{
				if(vv->name==bb->d[0])
				{
					vv->a[ccc]=vv->a[ccc]+bb->n1;
					if(ccc<t)
					{
						vv->man=vv->man+bb->n1;
					}
					if(ccc>=t&&ccc<t+y)
					{
						vv->woman=vv->woman+bb->n1;
					}
					break;
				}
				vv=vv->next;cc++;	
			}
			if(cc==w)
			{
				cout<<"---------------------------------"<<endl;
				cout<<"该学校没有参加比赛，请重新输入"<<endl;
				cout<<"---------------------------------"<<endl;
				break;
			}
			cout<<"---------------------------------"<<endl;
			cout<<"请输入第二名的学校"<<endl;
			cout<<"---------------------------------"<<endl;
			cin>>bb->d[1];
			xx*vvv=new xx;vvv=first->next;
			int cc=0;
			while(cc<w&&&vvv!=NULL)
			{
				if(vvv->name==bb->d[1])
				{
					vvv->a[ccc]=vvv->a[ccc]+bb->n2;
					if(ccc<t)
					{
						vvv->man=vvv->man+bb->n2;
					}
					if(ccc>=t&&ccc<t+y)
					{
						vvv->woman=vvv->woman+bb->n2;
					}
					break;
				}
				cc++;vvv=vvv->next;
			}
			if(cc==w)
			{
				cout<<"------------------------------------"<<endl;
				cout<<"该学校没有参加比赛，请重新输入"<<endl;
				cout<<"------------------------------------"<<endl;
				delete vvv;break;
			}
			cout<<"----------------------------------"<<endl;
			cout<<"请输入第三名的学校"<<endl;
			cout<<"----------------------------------"<<endl;
			cin>>bb->d[2];
			xx*vvvv=new xx;vvvv=first->next;cc=0;
			while(cc<w&&vvvv!=NULL)
			{
				if(vvvv->name==bb->d[2])
				{
					vvvv->a[ccc]=vvvv->a[ccc]+bb->n3;
					if(ccc<t)
					{
						vvvv->man=vvvv->man+bb->n3;
					}
					if(ccc>=t&&ccc<t+y)
					{
						vvvv->woman=vvvv->woman+bb->n3;
					}
					break;
				}
				cc++;vvvv=vvvv->next;
			}
			if(cc==w)
			{
				cout<<"--------------------------------------"<<endl;
				cout<<"该学校没有参加比赛，请重新输入"<<endl;
				cout<<"-------------------------------------"<<endl;
				break;
			}
		bb=bb->next;ccc++;system("cls");
	}
	xx *q1=new xx;q1=first->next;
	for(int zzz=0;zzz<w;zzz++)
	{
		for(int xxx=0;xxx<t+y;xxx++)
		{
			q1->n=q1->n+q1->a[xxx];
		}
		q1=q1->next;
	}}
int aa,ww=1;
void chaxun(xx *first,xm *head)//成绩查询
{
	while(1)
	{
		cout<<"------------------------------------"<<endl;
		cout<<"请选择查找方式"<<endl;
		cout<<"1.通过学校编号查找"<<endl;
		cout<<"2.通过项目查找"<<endl;
		cout<<"------------------------------------"<<endl;
		cin>>aa;
		if(aa==1)
		{
			xx *ee=new xx;ee=first->next;xm *tt=new xm;tt=head->next;
			cout<<"请输入编号"<<endl;
			int aaa;
			cin>>aaa;
			while(ee!=NULL&&ww<aaa)
			{
				ee=ee->next;ww++;
			}
			if(ee==NULL)
			{
				cout<<"------------------------------------"<<endl;
				cout<<"无此编号"<<endl;
				cout<<"------------------------------------"<<endl;
				break;
			}
			else
			{
				ee->n=0;
				cout<<"学校名"<<ee->name<<"  "<<"学校编号"<<ee->bh<<"  "<<endl;
				for(int rr=0;rr<t+y;rr++)
				{
					ee->n=ee->n+ee->a[rr];
				}
				for(int yy=0;yy<t+y;yy++)
				{
					cout<<tt->xiangmu<<" : "<<ee->a[yy]<<"    ";tt=tt->next;
				}
				cout<<"总分 : "<<ee->n<<"男子团体总分 : "<<ee->man<<"女子团体总分 : "<<ee->woman<<endl;  
				system("pause");system("cls");break;
			}}
		if(aa==2)
		{
			xm *ttt=new xm;ttt=head->next;
			cout<<"请输入项目名称"<<endl;
			string aaaa;
			cin>>aaaa;
			while(ttt!=NULL&&ttt->xiangmu!=aaaa)
			{
				ttt=ttt->next;
			}
			if(ttt==NULL)
			{
				cout<<"本次运动会无此项目"<<endl;break;
			}
			else
			{
				cout<<"项目名称"<<ttt->xiangmu<<"  "<<"项目编号"<<ttt->hb<<"  "<<endl;
					cout<<"-----------------------------------"<<endl;
					cout<<"本项目第一名的学校是 ："<<ttt->d[0]<<endl;
					cout<<"本项目第二名的学校是 ："<<ttt->d[1]<<endl;
					cout<<"本项目第三名的学校是 ："<<ttt->d[2]<<endl;
					cout<<"-----------------------------------"<<endl;
				system("pause");system("cls");break;
			}}}}
void paixu(xx *first,xm *head)//成绩排序
{
	cout<<"-------------------------------------"<<endl;
	cout<<"1.按编号排序"<<endl;
	cout<<"2.按男子团体总分排序"<<endl;
	cout<<"3.按女子团体总分排序"<<endl;
	cout<<"4.按总分排序"<<endl;
	cout<<"-------------------------------------"<<endl;
	int nvnv;
	cout<<"请选择！！！"<<endl;
	cin>>nvnv;
	switch(nvnv)
	{
	case 1:
		{
			system("cls");xx *qwe=new xx;qwe=first->next;
			for(int gg=0;gg<w;gg++)
			{
				cout<<"学校名"<<qwe->name<<"  "<<"学校编号"<<qwe->bh<<"  "<<endl;
				cout<<"总分 : "<<qwe->n<<"男子团体总分 : "<<qwe->man<<"女子团体总分 : "<<qwe->woman<<endl;
				qwe=qwe->next;
			}
			system("pause");system("cls");break;
		}
	case 2:
		{
			system("cls");xx *wer=new xx;wer=first->next;
			int shu[20];
			for(int shen=0;shen<w;shen++)
			{
				shu[shen]=wer->man;wer=wer->next;
			}
			for(int xi=0;xi<w-1;xi++)
			{
				for(int dao=xi+1;dao<w;dao++)
				{
					if(shu[xi]<shu[dao])
					{
						int so;
						so=shu[xi];shu[xi]=shu[dao];shu[dao]=so;
					}}}//冒泡
			for(int sasa=0;sasa<w-1;sasa++)
			{
				for(int asas=sasa+1;asas<w;asas++)
				{
					if(shu[sasa]==shu[asas])
					{
						for(int jian=asas+1;jian<w+1;jian++)
						{
							shu[asas]=shu[asas+1];
						}}}}
				for(int haha=0;haha<w;haha++)
				{
					xx *hei=new xx;hei=first->next;
					for(int ieh=0;ieh<w;ieh++)
					{
						if(hei->man==shu[haha])
						{
							cout<<"学校名"<<hei->name<<"  "<<"学校编号"<<hei->bh<<"  "<<endl;
							cout<<"总分 : "<<hei->n<<"男子团体总分 : "<<hei->man<<"女子团体总分 : "<<hei->woman<<endl;
						}
						hei=hei->next;
					}
				}
				system("pause");system("cls");break;
		}
	case 3:
		{
			system("cls");xx *wer=new xx;wer=first->next;
			int shu[20];
			for(int shen=0;shen<w;shen++)
			{
				shu[shen]=wer->woman;
				wer=wer->next;
			}
			for(int xi=0;xi<w-1;xi++)
			{
				for(int dao=xi+1;dao<w;dao++)
				{
					if(shu[xi]<shu[dao])
					{
						int so;
						so=shu[xi];shu[xi]=shu[dao];shu[dao]=so;
					}}}
			for(int sasa=0;sasa<w-1;sasa++)
			{
				for(int asas=sasa+1;asas<w;asas++)
				{
					if(shu[sasa]==shu[asas])
					{
						for(int jian=asas+1;jian<w+1;jian++)
						{
							shu[asas]=shu[asas+1];
						}}}}
				for(int haha=0;haha<w;haha++)
				{
					xx *hei=new xx;hei=first->next;	
					for(int ieh=0;ieh<w;ieh++)
					{
						if(hei->woman==shu[haha])
						{
							cout<<"学校名"<<hei->name<<"  "<<"学校编号"<<hei->bh<<"  "<<endl;
							cout<<"总分 : "<<hei->n<<"男子团体总分 : "<<hei->man<<"女子团体总分 : "<<hei->woman<<endl;
						}
						hei=hei->next;
					}}
				system("pause");system("cls");break;
		}
	case 4:
		{
			system("cls");	xx *wer=new xx;wer=first->next;
			int shu[20];
			for(int shen=0;shen<w;shen++)
			{
				shu[shen]=wer->n;wer=wer->next;
			}
			for(int xi=0;xi<w-1;xi++)
			{
				for(int dao=xi+1;dao<w;dao++)
				{
					if(shu[xi]<shu[dao])
					{
						int so;
				        so=shu[xi];shu[xi]=shu[dao];shu[dao]=so;
					}}}
			for(int sasa=0;sasa<w-1;sasa++)
			{
				for(int asas=sasa+1;asas<w;asas++)
				{
					if(shu[sasa]==shu[asas])
					{
						for(int jian=asas+1;jian<w+1;jian++)
						{
							shu[asas]=shu[asas+1];
						}}}}
				for(int haha=0;haha<w;haha++)
				{
					xx *hei=new xx;hei=first->next;
					for(int ieh=0;ieh<w;ieh++)
					{
						if(hei->n==shu[haha])
						{
							cout<<"学校名"<<hei->name<<"  "<<"学校编号"<<hei->bh<<"  "<<endl;
							cout<<"总分 : "<<hei->n<<"男子团体总分 : "<<hei->man<<"女子团体总分 : "<<hei->woman<<endl;
						}
						hei=hei->next;
					}}
				system("pause");system("cls");break;
		}}}
void shuchuliu(xx *first,xm *head)//文件输出
{
	fstream myfile;
	myfile.open("f:\\数据结构练习\\运动会\\运动会.txt",ios::out|ios::trunc);
	if(!myfile)
	{
		cerr<<"文件输出失败!"<<endl;
		exit(1);
	}
	int jian=0;
	xx *wen=new xx;
	wen=first->next;
	while(jian<w)
	{
			
			xm *tian=new xm;
			tian=head->next;
				wen->n=0;

				myfile<<"学校名"<<wen->name<<"  "<<"学校编号"<<wen->bh<<"  "<<endl;
				for(int yy=0;yy<t+y;yy++)
				{
					myfile<<tian->xiangmu<<" : "<<wen->a[yy]<<"    ";
					tian=tian->next;
				}
				for(int rr=0;rr<t+y;rr++)
				{
					wen->n=wen->n+wen->a[rr];
				}
				myfile<<"总分 : "<<wen->n<<"男子团体总分 : "<<wen->man<<"女子团体总分 : "<<wen->woman<<endl; 
				wen=wen->next;
				jian++;
				}
		}