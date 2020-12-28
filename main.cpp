#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct student
{
    char regno[10];
    char password[20];
    char name[30];
    char email[50];
    char address[100];
    char fathername[30];
    int age;
    int mobile;
    int fathermobile;
    int roomno;
    char block[1];
    char log[1000];
    struct student *left;
    struct student *right;
}node;
node *root=NULL;
void login()
{
    node *troot=root;
    int flag=0;
    printf("ENTER YOUR REGISTRATION NUMBER : ");
    char rno[10];char pass[20];
    scanf("%s",rno);
    getchar();
    printf("ENTER PASSWORD : ");
    scanf("%s",pass);
    getchar();
    while(troot!=NULL)
    {
        if(strcmp(rno,troot->regno)<0)
            troot=troot->left;
        else if((strcmp(rno,troot->regno)==0)&&(strcmp(pass,troot->password)==0))
            {
                flag=1;
                break;
            }
        else
            troot=troot->right;
    }
if(flag==1)
{
    printf("%s",troot->password);
}
else
{
    printf("ENTER CORRECT REGISTRATION NUMBER OR PASSWORD");
}
}
node *create()
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    printf("ENTER REGISTERATION NUMBER: ");
    scanf("%s",temp->regno);
    getchar();
   // printf("ENTER STUDENT'S NAME: ");
  //  scanf("%[^\n]s",temp->name);
  //  getchar();
 //   printf("ENTER STUDENT'S AGE: ");
 //   scanf("%d",&(temp->age));
  //  getchar();
    printf("ENTER PASSWORD THAT STUDENT WANT TO SET: ");
    scanf("%[^\n]s",temp->password);
    getchar();
    /*printf("ENTER STUDENT'S EMAIL ID: ");
    scanf("%[^\n]s",temp->email);
    getchar();
    printf("ENTER STUDENT'S ADDRESS: ");
    scanf("%[^\n]s",temp->address);
    getchar();
    printf("ENTER STUDENT'S MOBILE NUMBER: ");
    scanf("%d",&(temp->mobile));
    getchar();
    printf("ENTER STUDENT'S FATHER'S NAME: ");
    scanf("%[^\n]s",temp->fathername);
    getchar();
    printf("ENTER STUDENT'S FATHER'S MOBILE NUMBER: ");
    scanf("%d",&(temp->fathermobile));
    printf("ENTER BLOCK ALLOTED THE STUDENT: ");
    scanf("%s",&(temp->block));
    printf("ENTER ROOM NUMBER ALLOTED TO STUDENT: ");
    scanf("%d",&(temp->roomno));*/
    temp->left=temp->right=NULL;
   // system("cls");
    return(temp);
}
void insert(node *r,node *temp)
{
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        printf("%d",strcmp((r->regno),(temp->regno)));
        if(strcmp((r->regno),(temp->regno))<0)
        {
            if(r->right!=NULL)
            {
             insert(r->right,temp);
            }
            else
            {
            r->right=temp;
            }
        }
        else
        {
            if(r->left!=NULL)
            {
                insert(r->left,temp);
            }
            else
            {
                r->left=temp;
            }
        }
    }
}
node *findmax(node *l)
{
    node *r=NULL;
    char *m="00aaa0000";
    while(l!=NULL)
    {
        if(strcmp(l->regno,m)>0)
        {
            r=l;
            m=l->regno;
            l=l->right;
        }
    }
    return r;
}
void removest()
{
    char rn[10];
    int pos=0;
    printf("ENTER THE REGISTRATION NUMBER OF THE STUDENT TO BE REMOVED : ");
    scanf("%s",rn);
    getchar();
    node *troot=root;
    node *prev=root;
    while(troot!=NULL)
    {
     if(strcmp(rn,troot->regno)==0)
     {
        if(troot->left==NULL&&troot->right==NULL)
            free(troot);
        else if(troot->left==NULL||troot->right==NULL)
        {
            if(troot->left==NULL&&pos==1)
            {
                prev->right=troot->right;
            }
            else if(troot->right==NULL&&pos==1)
            {
                prev->right=troot->left;
            }
            else if(troot->left==NULL&&pos==2)
            {
                prev->left=troot->right;
            }
            else if(troot->right==NULL&&pos==2)
            {
                prev->left=troot->left;
            }
        free(troot);
        }
        else
        {
            if(pos==1)
            {
            prev->right=troot->left;
            node *p=findmax(troot->left);
            p->right=troot->right;
            free(troot);
            }
            if(pos==2)
            {
            prev->left=troot->left;
            node *p=findmax(troot->left);
            p->right=troot->right;
            free(troot);
            }
        }
     }
     else if(strcmp(rn,troot->regno)>0)
        {prev=troot;troot=troot->right;pos=1;}
     else
        {prev=troot;troot=troot->left;pos=2;}
    }
printf("\nSTUDENT SUCCESSFULLY REMOVED\n");
}
int main()
{
    int ch=0;
    do
    {
        for(int i=0;i<10;i++)
            printf("__________________________________________");
        printf("\t\t\t\t\t\t\t\t\t\t     VIT HOSTEL MANAGEMENT SYSTEM\n");
        for(int i=0;i<10;i++)
            printf("__________________________________________");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t  ENTER:- \n\n\t\t\t\t\t\t\t\t\t\t\t1.TO LOGIN\n\t\t\t\t\t\t\t\t\t\t\t2.TO ADD A NEW STUDENT\n\t\t\t\t\t\t\t\t\t\t\t3.TO REMOVE A STUDENT\n\t\t\t\t\t\t\t\t\t\t\t4.TO SHUT DOWN THE HOSTEL\n\n\t\t\t\t\t\t\t\t\t\t\t  CHOICE: ");
    scanf("%d",&ch);
    //system("cls");
    switch(ch)
    {
        case 1:
            {
                login();
                break;
            }
        case 2:
            {
                node *temp=NULL;
                temp=create();
                insert(root,temp);
                break;
            }
        case 3:
            {
                removest();
                break;
            }
        case 4:
            {
                exit(0);
            }
        default:printf("\nENTER CORRECT CHOICE");
    }
    }while(5>1);
    return 0;
}
