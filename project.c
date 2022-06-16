#include<stdio.h>

typedef struct hostel{
    int rno;
    char name[30];
    char location[30];
    char gender[6];
    int roomno;
}hostel;

int lower=1, upper=5;
int rand();
int getroomno();
void create(){
    
    hostel h;
    FILE *fp = fopen("hostel.txt","a+");
    
    printf("Enter Rollno: ");
    scanf("%d",&h.rno);
    printf("Enter Name: ");
    scanf("%s",h.name);
    printf("Enter Location: ");
    scanf("%s",h.location);
    printf("Enter Gender: ");
    scanf("%s",h.gender);
    h.roomno=getroomno(((rand()%(upper-lower+ 1))+lower));
    if(h.roomno!=0)
        fwrite(&h,sizeof(hostel),1,fp);
    
    fclose(fp);
}

int getroomno(int roomno){
    int allocated= 0;
    FILE *fp = fopen("hostel.txt","r");
    hostel h1;
    while(fread(&h1,sizeof(hostel),1,fp))
     { 
        if(h1.roomno== roomno){
              allocated= 1;
            
        }
     } 
     if (allocated==0)
            return roomno;
     else 
            return getroomno(((rand()%(upper-lower+ 1))+lower));
     fclose(fp);
}

void display(){
    hostel h1;
    FILE *fp = fopen("hostel.txt","r");
    printf("\n-----------------------------------------------------------------------\n");
    printf("%-10s%-20s%-15s%-10s%-5s","Rollno","Name","Location","Gender","Roomno");
    printf("\n-----------------------------------------------------------------------\n");
    while(fread(&h1,sizeof(hostel),1,fp))
        printf("%-10d%-20s%-15s%-10s%-5d\n",h1.rno,h1.name,h1.location,h1.gender,h1.roomno);
}

int main() {
    int ch;
    do{
        printf("\n1.Allocate Room");
        printf("\n2.Display ");
        printf("\n0.To exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        
        switch(ch) {
            case 1: 
                 create();
                 break;
            case 2: 
                  display();
                  break;
            case 0: printf("\n thanks..");        }
    }while(ch!=0);
    
}
