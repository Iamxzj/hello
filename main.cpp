#include<stdio.h>
#include<string.h>
#include <cstdlib>
struct Student
//ѧ���ṹ��
{
char ID[20];
//ѧ��
char Name[20];
//����
float scor_eng;
//Ӣ�����
float scor_math;
//��ѧ����
float scor_phy;
//�������
float Average;
//ƽ����
};
struct Student students[1000];
//ѧ���ṹ�����飬������¼ѧ������Ϣ��һ������Ϊһ��ѧ����������Ϣ
int num=0;
//����num��ʹnum=0��������¼ѧ������

float Avg(struct Student stu)
{
return (stu.scor_eng+stu.scor_math+stu.scor_phy)/3;
//��ƽ����
}

int Student_SearchByIndex(char id[])
{
int i;
//����i
for (i=0;i<num;i++)
//ѭ��
{
if (strcmp(students[i].ID,id)==0)
//�˶�ѧ��ѧ��
{
return i;
//�˶���ȷ����i
}
}
return -1;
//���󷵻�-1
}

int Student_SearchByName(char name[])
{
int i;
//����i
for (i=0;i<num;i++)
//ѭ��
{
if (strcmp(students[i].Name,name)==0)
//�˶�ѧ������
{
return i;
//�˶���ȷ����i
}
}
return -1;
//���󷵻�-1
}

void Student_DisplaySingle(int index)
{
printf("%10s%10s%8s%8s%8s%10s\n","ѧ��","����","Ӣ��ɼ�","��ѧ�ɼ�","����ɼ�","ƽ���ɼ�");
//��ӡ"ѧ��","����","Ӣ��ɼ�","��ѧ�ɼ�","����ɼ�","ƽ���ɼ�"
printf("-------------------------------------------------------------\n");
//��ӡ-------------------------------------------------------------
printf("%10s%10s%8.2f%8.2f%8.2f%10.2f\n",students[index].ID,students[index].Name,
students[index].scor_eng,students[index].scor_math,students[index].scor_phy,students[index].Average);
//���"ѧ��","����","Ӣ��ɼ�","��ѧ�ɼ�","����ɼ�","ƽ���ɼ�"�ľ�����Ϣ
}

void Student_Insert()
{
while(1)
//ѭ��
{
printf("������ѧ��:");
//��ӡ������ѧ�ţ�

scanf("%s",&students[num].ID);
//¼����ֵ��ѧ��

getchar();
//�����س����߿ո�

printf("����������:");
//��ӡ����������:

scanf("%s",&students[num].Name);
//¼����ֵ������

getchar();
//�����س����߿ո�

printf("������Ӣ��ɼ�:");
//��ӡ������Ӣ��ɼ�:

scanf("%f",&students[num].scor_eng);
//¼����ֵ��Ӣ��ɼ���

getchar();
//�����ո���߻س�

printf("��������ѧ�ɼ�:");
//��ӡ��������ѧ�ɼ�:

scanf("%f",&students[num].scor_math);
//¼����ֵ����ѧ�ɼ�

getchar();
//�����س����߿ո�

printf("����������ɼ�:");
//��ӡ����������ɼ�:

scanf("%f",&students[num].scor_phy);
//¼����ֵ������ɼ�

getchar();
//�����س����߿ո�

students[num].Average=Avg(students[num]);
//��¼ƽ����

num++;
//num=num+1
printf("�Ƿ����?(y/n)");
//��ӡ�Ƿ����?(y/n)
if (getchar()=='n')
//�����n
{
break;
//����
}
}
}

void Student_Modify()
//�޸�ѧ����Ϣ
{
while(1)
//ѭ��
{
char id[20];
//ѧ��ѧ��
int index;
//�����Ӻ���Student_SearchByIndex(id)�ķ���ֵ
printf("������Ҫ�޸ĵ�ѧ����ѧ��:");
//��ӡ������Ҫ�޸ĵ�ѧ����ѧ��:
scanf("%s",&id);
//����Ҫ�ĵ�ѧ��
getchar();
//�����س���ո�
index=Student_SearchByIndex(id);
if (index==-1)
    //�������ֵΪ-1
{
printf("ѧ��������!\n");
//��ӡѧ��������!
}
else
{
printf("��Ҫ�޸ĵ�ѧ����ϢΪ:\n");
//��ӡ��Ҫ�޸ĵ�ѧ����ϢΪ:
Student_DisplaySingle(index);
//��ӡҪ�޸ĵ�ѧ����Ϣ
printf("-- ��������ֵ--\n");
//��ӡ-- ��������ֵ--
printf("������ѧ��:");
//��ӡ������ѧ�ţ�
scanf("%s",&students[index].ID);
//¼���޸�ѧ����ѧ��
getchar();
//�����س����߿ո�
printf("����������:");
//��ӡ����������:
scanf("%s",&students[index].Name);
//¼���޸�ѧ��������
getchar();
//�����س����߿ո�
printf("������Ӣ��ɼ�:");
//��ӡ������Ӣ��ɼ���
scanf("%f",&students[index].scor_eng);
//¼���޸�ѧ����Ӣ��ɼ�
getchar();
//�����س����߿ո�
printf("��������ѧ�ɼ�:");
//��������ѧ�ɼ���
scanf("%f",&students[index].scor_math);
//¼���޸�ѧ������ѧ�ɼ�
getchar();
//�����س����߿ո�
printf("����������ɼ�:");
//��ӡ����������ɼ���
scanf("%f",&students[index].scor_phy);
//¼���޸�ѧ��������ɼ�
getchar();
//�����س����߿ո�
students[index].Average=Avg(students[index]);
//¼��ƽ����
}
printf("�Ƿ����?(y/n)");
//��ӡ�Ƿ����?(y/n)
if (getchar()=='n')
    //�������n
{
break;
//����
}
}
}

void Student_Delete()
{
int i;
//����i
while(1)
//ѭ��
{
char id[20];
//����ѧ��
int index;
//����index
printf("������Ҫɾ����ѧ����ѧ��:");
//��ӡ������Ҫɾ����ѧ����ѧ�ţ�
scanf("%s",&id);
//��¼ѧ��ѧ�ŵ�id
getchar();
//�����س����߿ո�
index=Student_SearchByIndex(id);
//�˶�ѧ��ѧ�ţ��������ȷ����-1
if (index==-1)
//�������ֵΪ-1
{
printf("ѧ��������!\n");
//��ӡ��ѧ��������!
}
else
{
printf("��Ҫɾ����ѧ����ϢΪ:\n");
//��ӡ����Ҫɾ����ѧ����ϢΪ��
Student_DisplaySingle(index);
//չʾҪɾ��ѧ������Ϣ
printf("�Ƿ����Ҫɾ��?(y/n)");
//��ӡ���Ƿ����Ҫɾ��?(y/n)
if (getchar()=='y')
    //�������y
{
for (i=index;i<num-1;i++)
//ѭ��
{
students[i]=students[i+1];
//����һλѧ������Ϣ�ŵ�ɾ����λ����
}
num--;
//num=num-1
}
getchar();
//�����س���ո�
}
printf("�Ƿ����?(y/n)");
//��ӡ���Ƿ����?(y/n��
if (getchar()=='n')
//�����ӡn

{
break;
//����
}
}
}

void Student_Select()
{
while(1)
    //ѭ��
{
char name[20];
//����
int index;
printf("������Ҫ��ѯ��ѧ��������:");
//��ӡ��������Ҫ��ѯ��ѧ��������:
scanf("%s",&name);
//��¼��ֵ������
getchar();
//�����س���ո�
index=Student_SearchByName(name);
//�˶�ѧ��������������󷵻�-1
if (index==-1)
//�������Ϊ-1
{
printf("ѧ��������!\n");
//��ӡ��ѧ��������!
}
else
{
printf("��Ҫ��ѯ��ѧ����ϢΪ:\n");
//��ӡ����Ҫ��ѯ��ѧ����ϢΪ:
Student_DisplaySingle(index);
//չʾѧ������Ϣ
}
printf("�Ƿ����?(y/n)");
//��ӡ���Ƿ����?(y/n)
if (getchar()=='n')
//�������n
{
break;
//����
}
}
}

void Student_SortByAverage()
{
int i,j;
//����i,j
struct Student tmp;
//�ṹ�� tmp
for (i=0;i<num;i++)
//ð������
{
for (j=1;j<num-i;j++)
{
if (students[j-1].Average<students[j].Average)
//���students[j-1].Average<students[j].Average
{
tmp=students[j-1];
//��students[j-1]��tmp
students[j-1]=students[j];
//��studengts[j]��students[j-1]
students[j]=tmp;
//��tmp��students[j]
}
}
}
}

void Student_Display()
{
int i;
//����i
printf("%10s%10s%8s%8s%8s%10s\n","ѧ��","����","Ӣ��ɼ�","��ѧ�ɼ�","����ɼ�","ƽ���ɼ�");
//��ӡ��"ѧ��","����","Ӣ��ɼ�","��ѧ�ɼ�","����ɼ�","ƽ���ɼ�"
printf("-------------------------------------------------------------\n");
//��ӡ��-------------------------------------------------------------
for (i=0;i<num;i++)
{
printf("%10s%10s%8.2f%8.2f%8.2f%10.2f\n",students[i].ID,students[i].Name,
students[i].scor_eng,students[i].scor_math,students[i].scor_phy,students[i].Average);
//��ӡ��"ѧ��","����","Ӣ��ɼ�","��ѧ�ɼ�","����ɼ�","ƽ���ɼ�"�ľ�����ֵ
}
}

void IO_ReadInfo()
{
FILE *fp;
//�����ļ���ָ��
int i;
//����i
if ((fp=fopen("Database.txt","rb"))==NULL)
    //�ж�fpָ���ļ��Ƿ�ɹ�

{
printf("\n");
//����
return;
}
if (fread(&num,sizeof(int),1,fp)!=1)

{
num=-1;
//��-1��num
}

else
{
for(i=0;i<num;i++)
    //ѭ��
{
fread(&students[i],sizeof(struct Student),1,fp);
}
}
fclose(fp);
//�ر��ļ�
}

void IO_WriteInfo()
{
FILE *fp;
//�����ļ���ָ��
int i;
//����i
if ((fp=fopen("Database.txt","wb"))==NULL)
    //�ж�fpָ���ļ��Ƿ�ɹ�
{
printf("���ܴ��ļ�!\n");
//��ӡ�����ܴ��ļ�!
return;
}
if (fwrite(&num,sizeof(int),1,fp)!=1)
//���������1
{
printf("д���ļ�����!\n");
//��ӡ��д���ļ�����!
}
for (i=0;i<num;i++)
//ѭ��
{
if (fwrite(&students[i],sizeof(struct Student),1,fp)!=1)
//���������1
{
printf("д���ļ�����!\n");
//��ӡ��д���ļ�����!
}
}
fclose(fp);
//�ر��ļ�
}

int main()
{
int choice;
//�û�ѡ����
IO_ReadInfo();
while(1)
{
printf("\n------ ѧ���ɼ�����ϵͳ------\n");
//��ӡ��------ ѧ���ɼ�����ϵͳ------
printf("1. ����ѧ����¼\n");
//��ӡ��1. ����ѧ����¼
printf("2. �޸�ѧ����¼\n");
//��ӡ��2. �޸�ѧ����¼
printf("3. ɾ��ѧ����¼\n");
//��ӡ��3. ɾ��ѧ����¼
printf("4. ��������ѯѧ����¼\n");
//��ӡ��4. ��������ѯѧ����¼
printf("5. ��ƽ���ɼ�����\n");
//��ӡ��5. ��ƽ���ɼ�����
printf("6. �����ļ�\n");
//��ӡ��6. �����ļ�
printf("7. �˳�\n");
//��ӡ��7. �˳�
printf("��ѡ��(1-7):");
//��ӡ����ѡ��(1-7):
scanf("%d",&choice);
//�ٴ��������־�������
getchar();
//�����س�
switch(choice)
{
case 1:
//����1
Student_Insert();
//����ѧ����¼
break;
//�����˴�ѭ��
case 2:
//����2
Student_Modify();
//�޸�ѧ����¼
break;
//�����˴�ѭ��
case 3:
//����3
Student_Delete();
//ɾ��ѧ����¼
break;
//�����˴�ѭ��
case 4:
//����4
Student_Select();
//��������ѯѧ����¼
break;
//�����˴�ѭ��
case 5:
//����5
Student_SortByAverage();
//��ƽ��������
Student_Display();
//չʾѧ���ɼ�
break;
//�����˴�ѭ��
case 6:
//����6
IO_WriteInfo();
//�����ļ�
break;
//�����˴�ѭ��
case 7:
//����7
exit(0);
//�˳�ѭ��
break;
//�����˴�ѭ��
}
}
}

