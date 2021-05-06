#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char street [30];
    char flat [10];
    char city [30];
} Address;

typedef struct
{
    char F_Name [30];
    char L_Name [30];
    Address Adrs;
    char phone [10];
    char email [30];

} Contact;
Contact C[100];
int counter=0;
FILE *f;
void Load ()
{

    FILE *f;
    f = fopen("contacts.txt", "r");
    if (f != NULL)
    {
        while (!feof(f))
        {

            fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s",C[counter].F_Name,C[counter].L_Name,
                   C[counter].Adrs.street,&C[counter].Adrs.flat,C[counter].Adrs.city,C[counter].phone,C[counter].email);
            fscanf(f, "\n");
            counter++;
        }
        fclose(f);
    }
}
void Query ()
{
    char S[30];
    printf("Enter First Name: ");
    gets(S);
    int i,f=1;
    for (i=0; i<counter; i++)
    {
        if(strcmp(C[i].F_Name,S)==0)
            {
                printf("%s, %s, %s, %s, %s, %s\n",C[i].F_Name,C[i].L_Name,
                   C[i].Adrs.street,C[i].Adrs.flat,C[i].Adrs.city,C[i].phone);
                   f=0;
            }
    }
    if (f==1)
        printf("Contact not found.\n");
}
void Add ()
{
    printf("First Name: ");
    gets(C[counter].F_Name);
    printf("Last Name: ");
    gets(C[counter].L_Name);
    printf("Street: ");
    gets(C[counter].Adrs.street);
    printf("Flat: ");
    gets(C[counter].Adrs.flat);
    printf("City: ");
    gets(C[counter].Adrs.city);
    printf("Phone Number: ");
    gets(C[counter].phone);
    printf("E-mail: ");
    gets(C[counter].email);
    counter ++;
}
void Save ()
{
    f = fopen("contacts.txt", "w");
    int i;
    for (i=0;i<counter;i++)
    {
        fprintf(f,"%s,%s,%s,%s,%s,%s,%s\n",C[i].F_Name,C[i].L_Name,
                C[i].Adrs.street,C[i].Adrs.flat,C[i].Adrs.city,C[i].phone,C[i].email);
    }
fclose(f);
printf("Saved.");
}
void Delete ()
{
    char Name1 [30]; char Name2 [30];
    printf("First Name: ");
    gets (Name1);
    printf("Last Name: ");
    gets(Name2);
    int i,j,f=1;
    for (i=0;i<counter;i++)
    {
        if (strcmp (Name1,C[i].F_Name)==0 && strcmp(Name2,C[i].L_Name)==0)
        {
            for (j=i;j<counter-1;j++)
                C[j]=C[j+1];
            counter--;
            f=0;
        }
    }
    if (f==1)
        printf("Contact not found.\n");
    else
        printf("Contact successfully deleted.\n");
}
void swap (int i)
{
    Contact T;
    T=C[i];
    C[i]=C[i+1];
    C[i+1]=T;
}

void Print ()
{
    int i,pass;
    for (pass=1;pass<counter;pass++)
    {
        for (i=0;i<counter-pass;i++)
        {
            if (strcmp(C[i].F_Name,C[i+1].F_Name)==1)
                swap(i);
            else if (strcmp(C[i].F_Name,C[i+1].F_Name)==0)
            {
                if (strcmp(C[i].L_Name,C[i+1].L_Name)==1)
                swap(i);
            }
        }
    }

    printf("\nComplete Phonebook: \n");
    for (i=0;i<counter;i++)
    {
        printf("%s, %s, %s, %s, %s, %s, %s\n",C[i].F_Name,C[i].L_Name,
                C[i].Adrs.street,C[i].Adrs.flat,C[i].Adrs.city,C[i].phone,C[i].email);
    }

}
int Quit ()
{
    printf("Are you sure you want to quit? All your changes will be discarded! Enter okay or cancel. ");
    char c[10];
    gets(c);
    if (strcmp(c,"okay")==0)
        return 1;
    else
        return 0;

}
void Modify ()
{
    char first [30], last[30];
    printf("Enter First Name: ");
    gets(first);
    printf("Enter Last Name: ");
    gets(last);
    char mod [30];
    int i,f=1;
    for (i=0; i<counter; i++)
    {
        if(strcmp(C[i].F_Name,first)==0&&strcmp(C[i].L_Name,last)==0)
            {
                   f=0;

                   printf("Press enter for no modification in a certain field,\nFirst Name: ");
                   gets(mod);
                   if (strlen(mod)!=0)
                    strcpy(C[i].F_Name,mod);
                   printf("Last Name: ");
                   gets(mod);
                   if (strlen(mod)!=0)
                    strcpy(C[i].L_Name,mod);
                   printf("Street: ");
                   gets(mod);
                   if (strlen(mod)!=0)
                    strcpy(C[i].Adrs.street,mod);
                   printf("Flat: ");
                   gets(mod);
                   if (strlen(mod)!=0)
                    strcpy(C[i].Adrs.flat,mod);
                   printf("City: ");
                   gets(mod);
                   if (strlen(mod)!=0)
                    strcpy(C[i].Adrs.city,mod);
                   printf("Phone Number: ");
                   gets(mod);
                   if (strlen(mod)!=0)
                    strcpy(C[i].phone,mod);
                   printf("E-mail: ");
                   gets(mod);
                   if (strlen(mod)!=0)
                    strcpy(C[i].email,mod);
                    f=0;
            }
    } if (f==1)
    printf("Contact not Found.");

}
int main()
{
    char Menu [30];
    int x=0;
    Load();
    do
    {
        printf("\n\nMenu:\nChoose Operation:\nQuery\tAdd\tDelete\tModify\tPrint\tSave\tQuit\n");
        gets(Menu);
        if (strcmp(Menu,"Query")==0)
            Query();
        else if (strcmp(Menu,"Add")==0)
            Add();
        else if (strcmp(Menu,"Delete")==0)
            Delete();
        else if (strcmp(Menu,"Modify")==0)
            Modify();
        else if (strcmp(Menu,"Print")==0)
            Print();
        else if (strcmp(Menu,"Save")==0)
            Save();
        else if (strcmp(Menu,"Quit")==0)
            {
                x=Quit();
                if (x==1)
                    break;
            }

    }while (x==0);

    return 0;
}
