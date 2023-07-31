/*
    Busra Bebek         Cemal Celimli
    21110131070         18110131059
*/

#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 33
#define kisiSayisi 33

void friendDisplay(int G[MAX][MAX],int startnode,int dista);
void friendRecommend(int G[MAX][MAX],int startnode,int dista);
void printPerson();

int main()
{
    char friend[][33]={"Kevin","Charlize","Stuart",
                       "Pruitt","Falconer","Morris",
                       "Jomo","Winston","Connie",
                       "Ken","Keith","Benjamin",
                       "Karen","Verna","Bruce",
                       "Robert","Joshua","Cesare",
                       "James","Katherina","Jebidiah",
                       "Reginald","Stephen","Rick",
                       "Ivan","David","Thom",
                       "Xander","Steve","John",
                       "Geoffrey","Ben","Wendell"};

    int friends[MAX][MAX]={{0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                           {1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                           {1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
                           {1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0},
                           {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
                           {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                           {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                           {0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
                           {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
                           {0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
                           {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
                           {0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                           {0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
                           {0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
                           {0,0,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0},
                           {0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                           {0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
                           {0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                           {0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                           {0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                           {0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                           {0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
                           {0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
                           {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},
                           {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
                           {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},
                           {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0},
                           {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
                           {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0}};

    int i,j,startnode,dista;
    int secim;
    char answer;
    start:
    printf("1-Arkadaslari Goster\n");
    printf("2-Arkadas Onerileri\n");
    printf("3-Programdan cik\n");
    printf("\n\nSeciminiz: ");
        scanf("%d",&secim);

    switch(secim){
        case 1:
            printPerson();
            printf("\nKisi Sec(0-32):");
                scanf("%d",&startnode);
            printf("\nBaslangic kisisi: %s\n",friend[startnode]);
            printf("\n\nArkadaslar: ");
            friends:
            friendDisplay(friends,startnode,1);
            friendDisplay:
            printf("\n\nYeni bir islem yapmak ister misiniz?(Y/N):");
                        scanf("%s",&answer);
                    if(answer=='Y'||answer=='y'){
                        goto start;
                    }
                    else if(answer=='N'||answer=='n'){
                        printf("\n\nGood Bye...");
                    exit(EXIT_SUCCESS);
                    }
                    else{
                        printf("Gecerli bir cevap veriniz(Y/N):");
                    }
            break;
        case 2:
            printPerson();
            printf("\nKisi Sec(0-32):");
            scanf("%d",&startnode);

            printf("\nMesafe gir: ");
            scanf("%d",&dista);
                if(dista==1){
                    printf("\n\nMesafesi 1 olan kisiler arkadaslaridir!\n");
                    goto friends;
                }
                else if(dista==0){
                    printf("\n\nMesafesi 0 olan kisi kendisidir.");
                    printf("\n\nBaslangic kisisi: %s\n",friend[startnode]);
                }
                else{
                    printf("\nBaslangic kisisi: %s\n",friend[startnode]);
                    printf("\n\nOnerilen Arkadaslar:");

                    friendRecommend(friends,startnode,dista);
                    friendRecommend:
                    printf("\n\nYeni bir islem yapmak ister misiniz?(Y/N):");
                        scanf("%s",&answer);
                    if(answer=='Y'||answer=='y'){
                        goto start;
                    }
                    else if(answer=='N'||answer=='n'){
                        printf("\n\nGood Bye...");
                    exit(EXIT_SUCCESS);
                    }
                    else{
                        printf("\nGecerli bir cevap veriniz(Y/N):");
                        goto friendRecommend;
                    }
                }
            break;
        case 3:
            printf("\n\nGood Bye...");
            exit(EXIT_SUCCESS);
            break;
        default:
                printf("\n\nLutfen Gecerli bir giris yapiniz!\n\n");
                goto start;
    }
    return 0;
}
//Secilen Kisinin arkadaşlarını gösteren fonksiyon
void friendDisplay(int friends[MAX][MAX],int startnode, int dista)
{
	char friend[][33]={"Kevin","Charlize","Stuart",
                       "Pruitt","Falconer","Morris",
                       "Jomo","Winston","Connie",
                       "Ken","Keith","Benjamin",
                       "Karen","Verna","Bruce",
                       "Robert","Joshua","Cesare",
                       "James","Katherina","Jebidiah",
                       "Reginald","Stephen","Rick",
                       "Ivan","David","Thom",
                       "Xander","Steve","John",
                       "Geoffrey","Ben","Wendell"};
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;

    //pred[] her dugumunun atasini saklar
    //simdiye kadar verilen dugum sayisini verir.
    //maliyet matrisini olusturur.

    for(i=0;i<kisiSayisi;i++){
        for(j=0;j<kisiSayisi;j++){
             if(friends[i][j]==0){
                cost[i][j]=INFINITY;
            }
            else{
                cost[i][j]=friends[i][j];
            }
        }
    }

//pred[],distance[] ve visited[] baslatmak
    for(i=0; i<kisiSayisi; i++){
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }

    distance[startnode]=0;
    visited[startnode]=1;
    count=1;

    while(count<kisiSayisi-1){
        mindistance=INFINITY;
//nextnode dugumu min mesafede verir.
        for(i=0;i<kisiSayisi;i++)
            if(distance[i]<mindistance&&!visited[i]){
                mindistance=distance[i];
                nextnode=i;
            }
//nextnode araciligiyla daha iyi bir yol olup olmadigini kontrol et
            visited[nextnode]=1;
        for(i=0;i<kisiSayisi;i++)
            if(!visited[i])
            if(mindistance+cost[nextnode][i]<distance[i]){
                distance[i]=mindistance+cost[nextnode][i];
                pred[i]=nextnode;
            }
            count++;
    }

//Her dügümün yolunu ve mesafesinin yazdır
    for(i=0;i<kisiSayisi;i++){
        if(i!=startnode){
            if(dista==distance[i]){
                printf("\n-%s", friend[i]);
            }
        }
    }
}
//Arkadas onerisinde bulunan fonksiyon. Yukaridaki fonksiyondan farki onerilen arkadasa hangi yolla ulasılacagini gosterir.
void friendRecommend(int friends[MAX][MAX],int startnode, int dista)
{
	char friend[][33]={"Kevin","Charlize","Stuart",
                       "Pruitt","Falconer","Morris",
                       "Jomo","Winston","Connie",
                       "Ken","Keith","Benjamin",
                       "Karen","Verna","Bruce",
                       "Robert","Joshua","Cesare",
                       "James","Katherina","Jebidiah",
                       "Reginald","Stephen","Rick",
                       "Ivan","David","Thom",
                       "Xander","Steve","John",
                       "Geoffrey","Ben","Wendell"};
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;

    //pred[] her dugumunun atasini saklar
    //simdiye kadar verilen dugum sayisini verir.
    //maliyet matrisini olusturur.

    for(i=0;i<kisiSayisi;i++){
        for(j=0;j<kisiSayisi;j++){
             if(friends[i][j]==0){
                cost[i][j]=INFINITY;
            }
            else{
                cost[i][j]=friends[i][j];
            }
        }
    }

//initialize pred[],distance[] and visited[]
    for(i=0; i<kisiSayisi; i++){
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }

    distance[startnode]=0;
    visited[startnode]=1;
    count=1;

    while(count<kisiSayisi-1){
        mindistance=INFINITY;
//nextnode dugumu min mesafede verir.
        for(i=0;i<kisiSayisi;i++)
            if(distance[i]<mindistance&&!visited[i]){
                mindistance=distance[i];
                nextnode=i;
            }
//nextnode araciligiyla daha iyi bir yol olup olmadigini kontrol et
            visited[nextnode]=1;
        for(i=0;i<kisiSayisi;i++)
            if(!visited[i])
            if(mindistance+cost[nextnode][i]<distance[i]){
                distance[i]=mindistance+cost[nextnode][i];
                pred[i]=nextnode;
            }
            count++;
    }

//Her dügümün yolunu ve mesafesinin yazdır
    for(i=0;i<kisiSayisi;i++){
        if(i!=startnode){
            if(dista==distance[i]){

            printf("\n-%s", friend[i]);
            j=i;
            printf("\n Yol: %s",friend[i]);
            do
            {
                j=pred[j];
                printf("<-%s",friend[j]);
            }
            while(j!=startnode);
            }

        }
    }
}
//Menude kullanıcının secebilecegi kisileri gosterir.
void printPerson(){
    char friend[][33]={"Kevin","Charlize","Stuart",
                       "Pruitt","Falconer","Morris",
                       "Jomo","Winston","Connie",
                       "Ken","Keith","Benjamin",
                       "Karen","Verna","Bruce",
                       "Robert","Joshua","Cesare",
                       "James","Katherina","Jebidiah",
                       "Reginald","Stephen","Rick",
                       "Ivan","David","Thom",
                       "Xander","Steve","John",
                       "Geoffrey","Ben","Wendell"};
    printf("\n");
    for(int i=0; i<33; i++){
        printf("%d- %s\n",i,friend[i]);
    }
}
