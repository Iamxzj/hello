#include<stdio.h>
#include<string.h>
#include <cstdlib>
struct Student
//学生结构体
{
char ID[20];
//学号
char Name[20];
//姓名
float scor_eng;
//英语分数
float scor_math;
//数学分数
float scor_phy;
//物理分数
float Average;
//平均分
};
struct Student students[1000];
//学生结构体数组，用来记录学生的信息，一个数组为一个学生的总体信息
int num=0;
//定义num，使num=0，用来记录学生个数

float Avg(struct Student stu)
{
return (stu.scor_eng+stu.scor_math+stu.scor_phy)/3;
//算平均分
}

int Student_SearchByIndex(char id[])
{
int i;
//定义i
for (i=0;i<num;i++)
//循环
{
if (strcmp(students[i].ID,id)==0)
//核对学生学号
{
return i;
//核对正确返回i
}
}
return -1;
//错误返回-1
}

int Student_SearchByName(char name[])
{
int i;
//定义i
for (i=0;i<num;i++)
//循环
{
if (strcmp(students[i].Name,name)==0)
//核对学生姓名
{
return i;
//核对正确返回i
}
}
return -1;
//错误返回-1
}

void Student_DisplaySingle(int index)
{
printf("%10s%10s%8s%8s%8s%10s\n","学号","姓名","英语成绩","数学成绩","物理成绩","平均成绩");
//打印"学号","姓名","英语成绩","数学成绩","物理成绩","平均成绩"
printf("-------------------------------------------------------------\n");
//打印-------------------------------------------------------------
printf("%10s%10s%8.2f%8.2f%8.2f%10.2f\n",students[index].ID,students[index].Name,
students[index].scor_eng,students[index].scor_math,students[index].scor_phy,students[index].Average);
//输出"学号","姓名","英语成绩","数学成绩","物理成绩","平均成绩"的具体信息
}

void Student_Insert()
{
while(1)
//循环
{
printf("请输入学号:");
//打印请输入学号：

scanf("%s",&students[num].ID);
//录入数值到学号

getchar();
//消掉回车或者空格

printf("请输入姓名:");
//打印请输入姓名:

scanf("%s",&students[num].Name);
//录入数值到姓名

getchar();
//消掉回车或者空格

printf("请输入英语成绩:");
//打印请输入英语成绩:

scanf("%f",&students[num].scor_eng);
//录入数值到英语成绩：

getchar();
//消掉空格或者回车

printf("请输入数学成绩:");
//打印请输入数学成绩:

scanf("%f",&students[num].scor_math);
//录入数值到数学成绩

getchar();
//消掉回车或者空格

printf("请输入物理成绩:");
//打印请输入物理成绩:

scanf("%f",&students[num].scor_phy);
//录入数值到物理成绩

getchar();
//消掉回车或者空格

students[num].Average=Avg(students[num]);
//记录平均分

num++;
//num=num+1
printf("是否继续?(y/n)");
//打印是否继续?(y/n)
if (getchar()=='n')
//如果打n
{
break;
//返回
}
}
}

void Student_Modify()
//修改学生信息
{
while(1)
//循环
{
char id[20];
//学生学号
int index;
//用来接函数Student_SearchByIndex(id)的返回值
printf("请输入要修改的学生的学号:");
//打印请输入要修改的学生的学号:
scanf("%s",&id);
//输入要改的学号
getchar();
//消掉回车或空格
index=Student_SearchByIndex(id);
if (index==-1)
    //如果返回值为-1
{
printf("学生不存在!\n");
//打印学生不存在!
}
else
{
printf("你要修改的学生信息为:\n");
//打印你要修改的学生信息为:
Student_DisplaySingle(index);
//打印要修改的学生信息
printf("-- 请输入新值--\n");
//打印-- 请输入新值--
printf("请输入学号:");
//打印请输入学号：
scanf("%s",&students[index].ID);
//录入修改学生的学号
getchar();
//消掉回车或者空格
printf("请输入姓名:");
//打印请输入姓名:
scanf("%s",&students[index].Name);
//录入修改学生的姓名
getchar();
//消掉回车或者空格
printf("请输入英语成绩:");
//打印请输入英语成绩：
scanf("%f",&students[index].scor_eng);
//录入修改学生的英语成绩
getchar();
//消掉回车或者空格
printf("请输入数学成绩:");
//请输入数学成绩：
scanf("%f",&students[index].scor_math);
//录入修改学生的数学成绩
getchar();
//消掉回车或者空格
printf("请输入物理成绩:");
//打印请输入物理成绩：
scanf("%f",&students[index].scor_phy);
//录入修改学生的物理成绩
getchar();
//消掉回车或者空格
students[index].Average=Avg(students[index]);
//录入平均分
}
printf("是否继续?(y/n)");
//打印是否继续?(y/n)
if (getchar()=='n')
    //如果输入n
{
break;
//返回
}
}
}

void Student_Delete()
{
int i;
//定义i
while(1)
//循环
{
char id[20];
//定义学号
int index;
//定义index
printf("请输入要删除的学生的学号:");
//打印请输入要删除的学生的学号：
scanf("%s",&id);
//记录学生学号到id
getchar();
//消掉回车或者空格
index=Student_SearchByIndex(id);
//核对学生学号，如果不正确返回-1
if (index==-1)
//如果返回值为-1
{
printf("学生不存在!\n");
//打印出学生不存在!
}
else
{
printf("你要删除的学生信息为:\n");
//打印出你要删除的学生信息为：
Student_DisplaySingle(index);
//展示要删除学生的信息
printf("是否真的要删除?(y/n)");
//打印出是否真的要删除?(y/n)
if (getchar()=='y')
    //如果输入y
{
for (i=index;i<num-1;i++)
//循环
{
students[i]=students[i+1];
//把下一位学生的信息放到删除的位置上
}
num--;
//num=num-1
}
getchar();
//消掉回车或空格
}
printf("是否继续?(y/n)");
//打印出是否继续?(y/n）
if (getchar()=='n')
//如果打印n

{
break;
//返回
}
}
}

void Student_Select()
{
while(1)
    //循环
{
char name[20];
//姓名
int index;
printf("请输入要查询的学生的姓名:");
//打印出请输入要查询的学生的姓名:
scanf("%s",&name);
//记录数值到姓名
getchar();
//消掉回车或空格
index=Student_SearchByName(name);
//核对学生姓名，如果错误返回-1
if (index==-1)
//如果返回为-1
{
printf("学生不存在!\n");
//打印出学生不存在!
}
else
{
printf("你要查询的学生信息为:\n");
//打印出你要查询的学生信息为:
Student_DisplaySingle(index);
//展示学生的信息
}
printf("是否继续?(y/n)");
//打印出是否继续?(y/n)
if (getchar()=='n')
//如果输入n
{
break;
//返回
}
}
}

void Student_SortByAverage()
{
int i,j;
//定义i,j
struct Student tmp;
//结构体 tmp
for (i=0;i<num;i++)
//冒泡排序
{
for (j=1;j<num-i;j++)
{
if (students[j-1].Average<students[j].Average)
//如果students[j-1].Average<students[j].Average
{
tmp=students[j-1];
//把students[j-1]给tmp
students[j-1]=students[j];
//把studengts[j]给students[j-1]
students[j]=tmp;
//把tmp给students[j]
}
}
}
}

void Student_Display()
{
int i;
//定义i
printf("%10s%10s%8s%8s%8s%10s\n","学号","姓名","英语成绩","数学成绩","物理成绩","平均成绩");
//打印出"学号","姓名","英语成绩","数学成绩","物理成绩","平均成绩"
printf("-------------------------------------------------------------\n");
//打印出-------------------------------------------------------------
for (i=0;i<num;i++)
{
printf("%10s%10s%8.2f%8.2f%8.2f%10.2f\n",students[i].ID,students[i].Name,
students[i].scor_eng,students[i].scor_math,students[i].scor_phy,students[i].Average);
//打印出"学号","姓名","英语成绩","数学成绩","物理成绩","平均成绩"的具体数值
}
}

void IO_ReadInfo()
{
FILE *fp;
//定义文件流指针
int i;
//定义i
if ((fp=fopen("Database.txt","rb"))==NULL)
    //判断fp指向文件是否成功

{
printf("\n");
//换行
return;
}
if (fread(&num,sizeof(int),1,fp)!=1)

{
num=-1;
//把-1给num
}

else
{
for(i=0;i<num;i++)
    //循环
{
fread(&students[i],sizeof(struct Student),1,fp);
}
}
fclose(fp);
//关闭文件
}

void IO_WriteInfo()
{
FILE *fp;
//定义文件流指针
int i;
//定义i
if ((fp=fopen("Database.txt","wb"))==NULL)
    //判断fp指向文件是否成功
{
printf("不能打开文件!\n");
//打印出不能打开文件!
return;
}
if (fwrite(&num,sizeof(int),1,fp)!=1)
//如果不等于1
{
printf("写入文件错误!\n");
//打印出写入文件错误!
}
for (i=0;i<num;i++)
//循环
{
if (fwrite(&students[i],sizeof(struct Student),1,fp)!=1)
//如果不等于1
{
printf("写入文件错误!\n");
//打印出写入文件错误!
}
}
fclose(fp);
//关闭文件
}

int main()
{
int choice;
//用户选择功能
IO_ReadInfo();
while(1)
{
printf("\n------ 学生成绩管理系统------\n");
//打印出------ 学生成绩管理系统------
printf("1. 增加学生记录\n");
//打印出1. 增加学生记录
printf("2. 修改学生记录\n");
//打印出2. 修改学生记录
printf("3. 删除学生记录\n");
//打印出3. 删除学生记录
printf("4. 按姓名查询学生记录\n");
//打印出4. 按姓名查询学生记录
printf("5. 按平均成绩排序\n");
//打印出5. 按平均成绩排序
printf("6. 保存文件\n");
//打印出6. 保存文件
printf("7. 退出\n");
//打印出7. 退出
printf("请选择(1-7):");
//打印出请选择(1-7):
scanf("%d",&choice);
//再次输入数字决定功能
getchar();
//消掉回车
switch(choice)
{
case 1:
//输入1
Student_Insert();
//增加学生记录
break;
//跳过此次循环
case 2:
//输入2
Student_Modify();
//修改学生记录
break;
//跳过此次循环
case 3:
//输入3
Student_Delete();
//删除学生记录
break;
//跳过此次循环
case 4:
//输入4
Student_Select();
//按姓名查询学生记录
break;
//跳过此次循环
case 5:
//输入5
Student_SortByAverage();
//按平均数排序
Student_Display();
//展示学生成绩
break;
//跳过此次循环
case 6:
//输入6
IO_WriteInfo();
//保存文件
break;
//跳过此次循环
case 7:
//输入7
exit(0);
//退出循环
break;
//跳过此次循环
}
}
}

