#include"student.h"

void add(ssl **head)
{
    ssl *new,*temp,*last;
    int r=1;

    new=malloc(sizeof(ssl));

    if(new==0)
    {
        printf("Memory Allocation Failed\n\n");
        return;
    }

    while(1)
    {
        temp=*head;

        while(temp!=0)
        {
            if(temp->rollno==r)
            {
                r++;
                break;
            }
            temp=temp->next;
        }

        if(temp==0)
            break;
    }

    new->rollno=r;

    printf("Enter name & Percentage:");
    scanf("%s %f",new->name,&new->percentage);

    new->next=0;

    if (*head==0)
    {
        *head=new;
    }
    else
    {
        last=*head;

        while(last->next!=0)
            last=last->next;

        last->next=new;
    }
}

void display(ssl *ptr)
{
    if(ptr==0)
    {
        printf("No records found\n");
        return;
    }

    printf("Student Records present are:\n");

    while(ptr)
    {
        printf("%d %s %f\n",
               ptr->rollno,ptr->name,ptr->percentage);

        ptr=ptr->next;
    }
}

void save_file(ssl *ptr)
{
    if(ptr==0)
    {
        printf("No records found\n");
        return;
    }

    FILE *fp=fopen("student.dat","w");

    while(ptr)
    {
        fprintf(fp,"%d %s %f\n",
                ptr->rollno,ptr->name,ptr->percentage);

        ptr=ptr->next;
    }

    printf("File saved Sucessfully\n");

    fclose(fp);
}

void del(ssl **head)
{
    if(*head==0)
    {
        printf("No records found\n");
        return;
    }

    ssl *temp,*prev;
    int rollno;
    char op,name[50];

    printf("R/r : Delete by roll number\n");
    printf("N/n : Delete by name\n");
    printf("Enter your choice: ");
    scanf(" %c",&op);

    if(op=='r'||op=='R')
    {
        printf("Enter roll number: ");
        scanf("%d",&rollno);

        temp=*head;
        prev=0;

        while(temp)
        {
            if(temp->rollno==rollno)
            {
                if(prev==0)
                    *head=temp->next;
                else
                    prev->next=temp->next;

                free(temp);

                printf("Record deleted successfully\n");
                return;
            }

            prev=temp;
            temp=temp->next;
        }

        printf("Record not found\n");
    }

    else if(op=='n'||op=='N')
    {
        printf("Enter name: ");
        scanf(" %s",name);

        temp=*head;

        while(temp)
        {
            if(strcmp(temp->name,name)==0)
                printf("Roll No: %d Name: %s Percentage: %f\n",
                       temp->rollno,temp->name,temp->percentage);

            temp=temp->next;
        }

        printf("Enter roll number to delete: ");
        scanf("%d",&rollno);

        temp=*head;
        prev=0;

        while(temp)
        {
            if(temp->rollno==rollno)
            {
                if(prev==0)
                    *head=temp->next;
                else
                    prev->next=temp->next;

                free(temp);

                printf("Record deleted successfully\n");
                return;
            }

            prev=temp;
            temp=temp->next;
        }

        printf("Record not found\n");
    }

    else
        printf("Invalid option\n");
}

void del_all(ssl **head)
{
    ssl *temp,*next;

    if(*head==0)
    {
        printf("No records found\n");
        return;
    }

    temp=*head;

    while(temp)
    {
        next=temp->next;
        free(temp);
        temp=next;
    }

    *head=0;

    printf("All records deleted successfully\n");
}

void rev(ssl **head)
{
    ssl *prev=0,*temp,*next;

    if(*head==0)
    {
        printf("No records found\n");
        return;
    }

    temp=*head;

    while(temp)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }

    *head=prev;

    printf("List reversed successfully\n");
}

void modify(ssl **head)
{
    ssl *temp;
    int rollno;
    float percentage;
    char op,name[50];

    if(*head==0)
    {
        printf("No records found\n");
        return;
    }

    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");
    printf("Enter your choice: ");
    scanf(" %c",&op);

    if(op=='r'||op=='R')
    {
        printf("Enter roll number: ");
        scanf("%d",&rollno);

        temp=*head;

        while(temp)
        {
            if(temp->rollno==rollno)
            {
                printf("Current: %d %s %f\n",
                       temp->rollno,temp->name,temp->percentage);

                printf("Enter new name & Percentage: ");
                scanf("%s %f",temp->name,&temp->percentage);

                printf("Record modified successfully\n");
                return;
            }

            temp=temp->next;
        }

        printf("Record not found\n");
    }

    else if(op=='n'||op=='N')
    {
        printf("Enter name: ");
        scanf("%s",name);

        temp=*head;

        while(temp)
        {
            if(strcmp(temp->name,name)==0)
                printf("Roll No: %d Name: %s Percentage: %f\n",
                       temp->rollno,temp->name,temp->percentage);

            temp=temp->next;
        }

        printf("Enter roll number to modify: ");
        scanf("%d",&rollno);

        temp=*head;

        while(temp)
        {
            if(temp->rollno==rollno)
            {
                printf("Enter new name & Percentage: ");
                scanf("%s %f",temp->name,&temp->percentage);

                printf("Record modified successfully\n");
                return;
            }

            temp=temp->next;
        }

        printf("Record not found\n");
    }

    else if(op=='p'||op=='P')
    {
        printf("Enter percentage: ");
        scanf("%f",&percentage);

        temp=*head;

        while(temp)
        {
            if(temp->percentage==percentage)
                printf("Roll No: %d Name: %s Percentage: %f\n",
                       temp->rollno,temp->name,temp->percentage);

            temp=temp->next;
        }

        printf("Enter roll number to modify: ");
        scanf("%d",&rollno);

        temp=*head;

        while(temp)
        {
            if(temp->rollno==rollno)
            {
                printf("Enter new name & Percentage: ");
                scanf("%s %f",temp->name,&temp->percentage);

                printf("Record modified successfully\n");
                return;
            }

            temp=temp->next;
        }

        printf("Record not found\n");
    }

    else
        printf("Invalid option\n");
}

void sort(ssl **head)
{
    ssl *temp,*next;
    int rollno;
    char name[50];
    float percentage;
    char op;

    if(*head==0)
    {
        printf("No records found\n");
        return;
    }

    printf("N/n : Sort by name\n");
    printf("P/p : Sort by percentage\n");
    printf("Enter your choice: ");
    scanf(" %c",&op);

    if(op=='n'||op=='N')
    {
        for(temp=*head;temp!=0;temp=temp->next)
        {
            for(next=temp->next;next!=0;next=next->next)
            {
                if(strcmp(temp->name,next->name)>0)
                {
                    rollno=temp->rollno;
                    strcpy(name,temp->name);
                    percentage=temp->percentage;

                    temp->rollno=next->rollno;
                    strcpy(temp->name,next->name);
                    temp->percentage=next->percentage;

                    next->rollno=rollno;
                    strcpy(next->name,name);
                    next->percentage=percentage;
                }
            }
        }

        printf("Records sorted by name\n");
    }

    else if(op=='p'||op=='P')
    {
        for(temp=*head;temp!=0;temp=temp->next)
        {
            for(next=temp->next;next!=0;next=next->next)
            {
                if(temp->percentage<next->percentage)
                {
                    rollno=temp->rollno;
                    strcpy(name,temp->name);
                    percentage=temp->percentage;

                    temp->rollno=next->rollno;
                    strcpy(temp->name,next->name);
                    temp->percentage=next->percentage;

                    next->rollno=rollno;
                    strcpy(next->name,name);
                    next->percentage=percentage;
                }
            }
        }

        printf("Records sorted by percentage\n");
    }

    else
        printf("Invalid option\n");
}